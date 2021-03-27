void clean_bss(void)
{
    extern int __bss_start, __bss_end;
    int *p = &__bss_start;
    
    for (; p < &__bss_end; p++)
        *p = 0;
}

int CopyCode2SDRAM(unsigned char *buf, unsigned long start_addr, int size)
{
    nand_read(buf, start_addr, size);
    return 0;
}
