#include <cpu.h>
#include <mem.h>

int main(int argc, char **argv) {
    // if (argc == 1) {
    //     printf("parameter are required!\n   eg: csec main.cse");
    // }

    load_prog(argv[1]);

    init_cpu();
    init_scall();
    execute();
}
