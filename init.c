#include <unistd.h>
#include <sys/mount.h>
#include <sys/stat.h>
#include <stdio.h>

#include <sys/types.h>
#include <dirent.h>

void ls(const char *d)
{
    printf("ls %s -> ", d);
    DIR *here = opendir(d);
    if(here){
        struct dirent *entry;
        while((entry = readdir(here))){
            printf("%s ", entry->d_name);
    }
    }else{
        printf("ls %s -> not found", d);
    }
    printf("\n");
}

void create_and_mount(const char *dev)
{
    printf("%s %s\n", __func__, dev);
    if(mknod (dev, S_IFBLK|0644, 8 << 8 | 5))
        perror("mknod");
    if(mount (dev, "/root", "fat32", MS_RDONLY, NULL))
        perror("mount");
}

int
main (int argc, char *argv[])
{

    printf("initramfs (%d): ", argc);
    for (int i = 0; i < argc; ++i)
        printf("%s", argv[i]);
    printf("\n");
    /*
    ls(".");

    create_and_mount("/dev/sda");
    ls("dev");
    create_and_mount("/dev/sda1");
    ls("dev");
    create_and_mount("/dev/sda2");
    ls("dev");
    create_and_mount("/dev/sda5");
    ls("dev");

    ls(".");
//    printf("dev\n");
//    chdir("dev");
    ls("dev");
//    chdir("..");
//    ls();
    
//    printf("root\n");
//    chdir("root");
    ls("root");
//    chdir("..");
//    ls();

    //unlink ("/dev/sda1");

    if (chdir("/root") != 0)
        perror("chdir");
    ls(".");

    if(mount(".", "/", NULL, MS_MOVE, NULL))
        perror("mount");

    if (chroot(".") != 0)
        perror("chroot");
    ls(".");

    if (chdir("/") != 0)
        perror("chdir");
    ls(".");

    execl("/sbin/init", "/sbin/init", NULL);
*/
    ls(".");
    ls("genode");
    printf("chdir genode: %d\n", chdir("genode"));
    ls(".");
}
