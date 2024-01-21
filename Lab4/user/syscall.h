#include "types.h"
#define SYS_WRITE   64
#define SYS_GETPID  172
struct pt_regs {
  uint64 x[32];
  uint64 sepc;
  uint64 scause;
  //uint64 sstatus;
  //uint64 stval;
};
void syscall(struct pt_regs* regs);
