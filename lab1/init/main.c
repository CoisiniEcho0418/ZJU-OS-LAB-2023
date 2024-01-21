#include "printk.h"
#include "sbi.h"
#include "defs.h"

extern void test();

int start_kernel() {
    printk("2023");
    printk(" Hello RISC-V\n");
    
    uint64 result = csr_read(sstatus);
    printk("15: %x\n",15);   // Verify the usage of the printk function:
    printk("sstatus: %x\n",result);
    
    result = csr_read(sie);
    printk("sie: %x\n",result);
    
    result = csr_read(sscratch);
    printk("prev sscratch: %x\n",result);
    csr_write(sscratch, 0x1);
    result = csr_read(sscratch);
    printk("later sscratch: %x\n",result);
    

    test(); // DO NOT DELETE !!!

	return 0;
}
