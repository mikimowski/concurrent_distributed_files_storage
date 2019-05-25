#ifndef _ERR_
#define _ERR_

#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>

///* Display information about system function error and ends the program */
//extern void syserr(const char *fmt, ...);
//
///* Displays information about error and ends the program */
//extern void fatal(const char *fmt, ...);
//
///* Displays information about error */
//extern void msgerr(const char *fmt, ...);

void syserr(const char *fmt, ...) {
    va_list fmt_args;
    int errno1 = errno;

    fprintf(stderr, "ERROR: ");
    va_start(fmt_args, fmt);
    vfprintf(stderr, fmt, fmt_args);
    va_end(fmt_args);
    fprintf(stderr, " (%d; %s)\n", errno1, strerror(errno1));
    exit(EXIT_FAILURE);
}

//void syserr(const char *fmt, ...) {
//    va_list fmt_args;
//    int errno1 = errno;
//
//    va_start(fmt_args, fmt);
//    BOOST_LOG_TRIVIAL(error) << fmt << " " << errno << " " << strerror(errno1);
//    va_end(fmt_args);
//    exit(EXIT_FAILURE);
//}


void fatal(const char *fmt, ...){
    va_list fmt_args;

    fprintf(stderr, "ERROR: ");
    va_start(fmt_args, fmt);
    vfprintf(stderr, fmt, fmt_args);
    va_end(fmt_args);
    fprintf(stderr, "\n");
    exit(EXIT_FAILURE);
}

void msgerr(const char *fmt, ...) {
    va_list fmt_args;
    int errno1 = errno;

    fprintf(stderr, "ERROR: ");
    va_start(fmt_args, fmt);
    vfprintf(stderr, fmt, fmt_args);
    va_end(fmt_args);
    fprintf(stderr, " (%d; %s)\n", errno1, strerror(errno1));
}

#endif
