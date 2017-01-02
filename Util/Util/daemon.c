/**
 * @file daemon.c
 *
 * Daemon class.
 */

#include "daemon.h"

#ifdef __linux__
#include <fcntl.h>
#include <unistd.h>
#endif

int glibc_daemon(int nochdir, int noclose)
{
#ifdef __linux__
    int fd;

    switch (fork()) {
    case -1:
        return (-1);
    case 0:
        break;
    default:
        _exit(0);
    }

    if (setsid() == -1)
        return (-1);

    if (!nochdir)
        (void)chdir("/");

    if (!noclose && (fd = open("/dev/null", O_RDWR, 0)) != -1) {
        (void)dup2(fd, STDIN_FILENO);
        (void)dup2(fd, STDOUT_FILENO);
        (void)dup2(fd, STDERR_FILENO);
        if (fd > 2)
            (void)close (fd);
    }
    return (0);
#else
	return -1;
#endif
}

