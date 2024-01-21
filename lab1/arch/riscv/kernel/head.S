.extern start_kernel
# .extern clock_set_next_event
# .extern set_time
.extern csr_write

    .section .text.init
    .globl _start
_start:
    la sp, boot_stack_top
    # ------------------
    # - your code here -
    # ------------------
     
    # set stvec = _traps   
    la t0, _traps
    csrw stvec, t0
    # ------------------
    
    # set sie[STIE] = 1
    csrr t0, sie
	ori t0, t0, 1<<5  
	csrw sie, t0
    # ------------------
    
    # set first time interrupt 
    #jal ra, clock_set_next_event
    #rdtime a0
    #li a1, 10000000
    #add a1,a0,a1
    #mv a0,mtimecmp
    li a7, 0x0000000000000000
    li a6, 0x0000000000000000
    rdtime a5
    li t0, 100000000
    add a5, a5, t0
    ecall
    
    # ------------------
    
    # set sstatus[SIE] = 1
    li t0,0x2
    csrrs t0,sstatus ,t0
    # ------------------
    
    #la sp, boot_stack_top 
    jal ra, start_kernel
    # ------------------
   

    .section .bss.stack
    .globl boot_stack
boot_stack:
    .space 4096 # <-- change to your stack size

    .globl boot_stack_top
boot_stack_top:
