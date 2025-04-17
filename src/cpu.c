#include <cpu.h>
#include <inst.h>
#include <mem.h>

cpu_t cpu;

// gpr
// -----------------------------------------
// |NO |name   |descrpition                |
// -----------------------------------------
// |0  |zr     |always equals zero         |
// -----------------------------------------
// |1  |sp     |stack pointer              |
// -----------------------------------------
// |2-5|r0-r3  |temporaries                |
// -----------------------------------------
// |6-7|a0-a1  |function arg/return values |
// -----------------------------------------
// |8  |ra     |function return address    |
// -----------------------------------------

char *regs[] = {
    "zr", "sp", "r0", "r1", "r2", "r3", "a0", "a1", "ra"
};

void init_cpu() {
    for (int i = 0; i < NUM_GPR; i++) {
        GPR[i] = 0;
    }
    PC = 0;
    SP = MEMSIZE - 1;
}

void display_regs() {
    printf("pc: 0x%08x\n", cpu.pc);
    for (int i = 0; i < NUM_GPR; i++) {
        // printf("%s: %#010x\n", regs[i], cpu.gpr[i]);
    }
}

void execute() {
    while (1) {
    // for (int i = 0; i < 3; i++) {
        inst_fetch.pc = cpu.pc;
        // display_regs();
        inst_exec();
        cpu.pc = inst_fetch.dnpc;
    }
}
