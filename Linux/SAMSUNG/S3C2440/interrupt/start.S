@代表接下来的内容放入代码段
.text 
@声明全局start标号
.global _start 
_start:
    bl reset

HandleUndef:
    b   HandleUndef 
 
HandleSWI:
    b   HandleSWI

HandlePrefetchAbort:
    b   HandlePrefetchAbort

HandleDataAbort:
    b   HandleDataAbort

HandleNotUsed:
    b   HandleNotUsed

    b   HandleIRQ

HandleFIQ:
    b   HandleFIQ
    
reset:
    @watching dog   
    ldr r0,=0x53000000
    ldr r1,=0
    str r1,[r0]

    @clock setting
    ldr r0,=0x4C000014
    ldr r1,=(1<<1) | (1<<0)
    str r1,[r0]

    mrc p15,0,r0,c1,c0,0
	orr r0,r0,#0xC0000000
	mcr p15,0,r0,c1,c0,0

    @m=42+8=50 p=1+2=3 s=1 MPLL=2*50*12/(3*2^1)=200M 
    ldr r0,=0x4C000004
    ldr r1,=(0x2A<<12) | (0x01<<4) | (0x01<<0)
    str r1,[r0]
    
    ldr sp,=4096

    bl sdram_init
    bl nand_init

    ldr r0, =0x30000000     
    mov r1, #4096           
    mov r2, #512*1024       
    bl  CopyCode2SDRAM 

    bl clean_bss

    msr cpsr_c, #0x52   @0101 0011
    ldr sp,=0x30000000 + 48*1024*1024

    ldr lr,=halt_loop
    ldr pc,= main     

halt_loop:
    b halt_loop

HandleIRQ:
    sub lr, lr, #4
    stmdb sp!, { r0-r12, lr } 

    ldr lr,=irq_return
    ldr pc,=IRQ

irq_return:
    ldmia sp!, { r0-r12, pc }^



