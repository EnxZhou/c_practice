/* p2.h */
#ifndef P2_H
#define p2_H
typedef unsigned float_bits;
typedef enum {NEG,ZERO,POS,OTHER} range_t;
extern range_t find_range(float);
#endif