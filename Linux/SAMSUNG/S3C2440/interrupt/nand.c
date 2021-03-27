#define NAND_SECTOR_SIZE    2048
#define NAND_BLOCK_MASK     (NAND_SECTOR_SIZE - 1)

typedef struct {
    unsigned int   NFCONF;
    unsigned int   NFCONT;
    unsigned int   NFCMD;
    unsigned int   NFADDR;
    unsigned int   NFDATA;
    unsigned int   NFMECCD0;
    unsigned int   NFMECCD1;
    unsigned int   NFSECCD;
    unsigned int   NFSTAT;
    unsigned int   NFESTAT0;
    unsigned int   NFESTAT1;
    unsigned int   NFMECC0;
    unsigned int   NFMECC1;
    unsigned int   NFSECC;
    unsigned int   NFSBLK;
    unsigned int   NFEBLK;
} NAND;

static NAND *nand = (NAND *)0x4e000000;

static void wait_idle(void)
{
    int i;
    volatile unsigned char *p = (volatile unsigned char *)&nand->NFSTAT;
    while(!(*p & 0x01))
        for(i=0; i<10; i++);
}

static void nand_select_chip(void)
{
    int i;
    nand->NFCONT &= ~(1<<1);
    for(i=0; i<10; i++);    
}

static void nand_deselect_chip(void)
{
    nand->NFCONT |= (1<<1);
}

static void write_cmd(int cmd)
{
    volatile unsigned char *p = (volatile unsigned char *)&nand->NFCMD;
    *p = cmd;
}

static void write_addr(unsigned int addr)
{
	int i;
	volatile unsigned char *p = (volatile unsigned char *)&nand->NFADDR;
	int col, page;

	col = addr & NAND_BLOCK_MASK;
	page = addr / NAND_SECTOR_SIZE;
	
	*p = col & 0xff;			/* Column Address A0~A7 */
	for(i=0; i<10; i++);		
	*p = (col >> 8) & 0x0f; 	/* Column Address A8~A11 */
	for(i=0; i<10; i++);
	*p = page & 0xff;			/* Row Address A12~A19 */
	for(i=0; i<10; i++);
	*p = (page >> 8) & 0xff;	/* Row Address A20~A27 */
	for(i=0; i<10; i++);
	*p = (page >> 16) & 0x03;	/* Row Address A28~A29 */
	for(i=0; i<10; i++);
}


static unsigned char read_data(void)
{
    volatile unsigned char *p = (volatile unsigned char *)&nand->NFDATA;
    return *p;
}

static void nand_reset(void)
{
    nand_select_chip();
    write_cmd(0xff); 
    wait_idle();
    nand_deselect_chip();
}

void nand_init(void)
{
    #define TACLS   0   
    #define TWRPH0  3
    #define TWRPH1  0


    nand->NFCONF = (TACLS<<12)|(TWRPH0<<8)|(TWRPH1<<4);
    nand->NFCONT = (1<<4)|(1<<1)|(1<<0);
    
    nand_reset();
}

void nand_read(unsigned char *buf, unsigned long start_addr, int size)
{
    int i, j;
     
    if ((start_addr & NAND_BLOCK_MASK) || (size & NAND_BLOCK_MASK)) {
        return ;   
    }	
    nand_select_chip();

    for(i=start_addr; i < (start_addr + size);) {
      write_cmd(0);
      write_addr(i);
      write_cmd(0x30);	
      wait_idle();

      for(j=0; j < NAND_SECTOR_SIZE; j++, i++) {
          *buf = read_data();
          buf++;
      }
    }
    nand_deselect_chip();
    
    return ;
}
