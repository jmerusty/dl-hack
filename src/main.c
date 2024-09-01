#include <string.h>
#include <unistd.h>

int main()
{
    char s[] = "Hello, World!\n";
    write(STDOUT_FILENO, s, strlen(s));

    return 0;
}
