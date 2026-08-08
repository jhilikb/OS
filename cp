#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char buf[4096];
    ssize_t n;

    int src = open(argv[1], O_RDONLY);              // open() → openat()
    int dst = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644); // open() → openat()

    while ((n = read(src, buf, sizeof(buf))) > 0)   // read() → __NR_read
        write(dst, buf, n);                         // write() → __NR_write

    close(src);                                     // close() → __NR_close
    close(dst);                                     // close() → __NR_close

    return 0;
}
