#include <unistd.h>
#include <stdio.h>

#include <sys/io.h>

int
main (int argc __attribute__((unused)), char *argv[] __attribute__((unused)))
{
    /*
    char *args = "core";
    printf("loading Genode on Linux\n");
    if (chdir("/genode")){
        perror("failed to chdir into /genode");
        return 1;
    }
    printf("acquiring priviledges: %d\n", iopl(3));
    if(execve("core", &args, NULL)){
        perror("failed to start core");
        return 1;
    }
    */
    short port = 0x70;
    printf("ioperm on port %d -> %d\n", port, ioperm(port, 1, 1));
    printf("inb on port %d -> %d\n", port, inb(port));
    outb(inb(port), port);
    printf("io port test successful, exiting...\n");
}
