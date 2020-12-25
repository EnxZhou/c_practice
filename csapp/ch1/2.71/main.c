#include<stdio.h>
#include<assert.h>

/* Declaration of data type where 4 bytes are packed
 * into an unsigned.*/
typedef unsigned packed_t;

/* The unsigned(32 bits) is split to 4 part,
 * every part represent a signed byte.
 * Extract byte from word. Return as signed integer */
int xbyte(packed_t word, int bytenum){
    int off = 24-(bytenum<<3);
    return (int)(word<<off)>>24;
}

int main(void){
    packed_t word;
    word = 0x12345678;
    assert(xbyte(word,0) == 0x78);
    assert(xbyte(word,1) == 0x56);
    assert(xbyte(word,2) == 0x34);
    assert(xbyte(word,3) == 0x12);
    word = 0xfedcba87;
    assert(xbyte(word,0) == 0xffffff87);
    assert(xbyte(word,1) == 0xffffffba);
    assert(xbyte(word,2) == 0xffffffdc);
    assert(xbyte(word,3) == 0xfffffffe);
    return 0;
}
