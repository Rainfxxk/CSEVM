#ifndef __CPU_H__
#define __CPU_H__

#include <common.h>
#include <inst.h>

#define NUM_GPR 9

#define GPR cpu.gpr
#define PC  cpu.pc

#define ZR GPR[0]
#define SP GPR[1]
#define R0 GPR[2]
#define R1 GPR[3]
#define R2 GPR[4]
#define R3 GPR[5]
#define A0 GPR[6]
#define A1 GPR[7]
#define RA GPR[8]

typedef struct cpu_t {
    uint32_t gpr[NUM_GPR];
    uint32_t pc;
} cpu_t;

extern cpu_t cpu;

void init_cpu();

void display_regs();

void execute();

#endif // __CPU_H__
