/* bitshow.h */
#ifndef BITSHOW_H
#define BITSHOW_H
#include<string.h>
typedef unsigned char * byte_pointer;

extern void show_bytes(byte_pointer,size_t);
extern void show_short(short x);
extern void show_int(int x);
extern void show_long(long x);
extern void show_double(double x);
extern void show_float(float x);
extern void show_pointer(void *x);
extern void show_unsigned(unsigned x);
extern int uadd_ok(unsigned x,unsigned y);
extern int tadd_ok(int x, int y);
extern int tsub_ok(int x,int y);
extern int is_little_endian();
#endif
