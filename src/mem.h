#ifndef __MEM_H__
#define __MEM_H__

#include <common.h>

#define MEMSIZE 65535

bool in_mem(uint32_t addr);

long load_prog(char *file);

uint32_t mem_read(uint32_t addr);

void mem_write(uint32_t addr, uint32_t data);

#endif // __MEM_H__
