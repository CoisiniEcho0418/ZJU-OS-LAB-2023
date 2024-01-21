// trap.c 
#include "printk.h"
#include "clock.h"

unsigned long flag1 = 0x8000000000000000;
unsigned long flag2 = 0x5;

void trap_handler(unsigned long scause, unsigned long sepc) {
    // 通过 `scause` 判断trap类型
    // 如果是interrupt 判断是否是timer interrupt
    // 如果是timer interrupt 则打印输出相关信息, 并通过 `clock_set_next_event()` 设置下一次时钟中断
    // `clock_set_next_event()` 见 4.3.4 节
    // 其他interrupt / exception 可以直接忽略
    
    // YOUR CODE HERE
    printk("scause: %x\n",scause);
    if(scause&flag1){
    	scause=scause-flag1;
    	if(scause&flag2){
	   printk(" Supervisor Mode Time Interrupt!\n");
	   clock_set_next_event();
	}else{
	    return;
	}
    }
    
}
