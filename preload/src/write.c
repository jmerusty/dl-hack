#include <unistd.h>
#include <dlfcn.h>
#include <stdio.h>

int g_first = 0;
void *g_h;
ssize_t (*g_f)(int, const void *, size_t);

void __attribute__((constructor)) unset_ld_preload()
{
    unsetenv("LD_PRELOAD");
}

ssize_t write(int fd, const void *buf, size_t count)
{
    if (g_first == 0)
    {
        g_first = 1;

        g_h = dlopen("libc.so.6", RTLD_LAZY);
        g_f = dlsym(g_h, "write");
    }

    fprintf(stdout, "Hello Hack\n");

    return (*g_f)(fd, buf, count);
}
