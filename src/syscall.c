#include <syscall.h>

uint32_t vm_exit(uint32_t arg) {
    exit(arg);
    return 0;
}

uint32_t printint(uint32_t arg) {
    return printf("%d", arg);
}

uint32_t printchar(uint32_t arg) {
    return printf("%c", arg);
}

uint32_t (*scall[])(uint32_t arg) = {
    [VM_EXIT]   = vm_exit,
    [PRINTINT]  = printint,
    [PRINTCHAR] = printchar,
};

void init_scall() {
    scall[VM_EXIT] = vm_exit;
}

uint32_t syscall(uint32_t no, uint32_t arg) {
    // printf("syscall[%d], arg=%#010x\n", no, arg);
    // printf("0x%08x, 0x%08x", scall[0], vm_exit);
    
    // I don't know what's problem here, but when call scall[0](arg), segmentation fault
    if (no == 0) vm_exit(arg);
    return scall[no](arg);
}
