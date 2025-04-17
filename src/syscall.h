#ifndef __SYSCALL_H__
#define __SYSCALL_H__

#include <common.h>

#define VM_EXIT     0
#define PRINTINT    1
#define PRINTCHAR   2

void init_scall();

uint32_t syscall(uint32_t no, uint32_t arg);

#endif // __SYSCALL_H__
