#include <common.h>
#include <cpu.h>
#include <mem.h>
#include <syscall.h>


inst_fetch_t inst_fetch;

static char op, rd, rs1, rs2;
static int immr, immi;

static void decode() {
    op = OP;
    rd = RD;
    rs1 = RS1;
    rs2 = RS2;
    immr = IMMR;
    immi = IMMI;
    // printf("%016b %011b %05b, %05b %05b %06b\n", immi, immr, rs2, rs1, rd, op);
    return;
}

void exec() {
    inst_fetch.dnpc = inst_fetch.snpc;
    // printf("--------------0x%08x---------------\n", INST);
    switch(op) {
        case ADD:   GPR[rd] = GPR[rs1] + GPR[rs2]; break;
        case SUB:   GPR[rd] = GPR[rs1] - GPR[rs2]; break;
        case ADDI:  GPR[rd] = GPR[rs1] + immi; break;
        case SUBI:  GPR[rd] = GPR[rs1] - immi; break;
        case BEQ:   if (GPR[rs1] == GPR[rs2]) inst_fetch.dnpc = PC + immr; break;
        case BNEQ:  if (GPR[rs1] != GPR[rs2]) inst_fetch.dnpc = PC + immr; break;
        case BLT:   if (GPR[rs1] < GPR[rs2]) inst_fetch.dnpc = PC + immr; break;
        case BGE:   if (GPR[rs1] >= GPR[rs2]) inst_fetch.dnpc = PC + immr; break;
        case STORE: mem_write(GPR[rs1] + immi, GPR[rd]); break;
        case LOAD:  GPR[rd] = mem_read(GPR[rs1] + immi); break;
        case JMP:   inst_fetch.dnpc = PC + immi;  GPR[rd] = PC + 4;break;
        case JMPR:  inst_fetch.dnpc = GPR[rs1] + immi; GPR[rd] = PC + 4; break;
        case SCALL: cpu.gpr[6] = syscall(GPR[6], GPR[7]); break;
        case AUIPC: GPR[rd] = PC + immi << 16; break;
        default: fprintf(stderr, "Unknown instruction %#08b at pc = %#010x\n", op, PC); exit(-1); break;
    }
    GPR[0] = 0;
}

void inst_exec() {
    *(uint32_t *)&inst_fetch.inst = mem_read(inst_fetch.pc);
    decode();
    inst_fetch.snpc = inst_fetch.pc + 4;
    exec();
}
