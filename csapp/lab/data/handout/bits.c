/* 
 * CS:APP Data Lab 
 * 
 * <Please put your name and userid here>
 * 
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.  
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:
 
  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code 
  must conform to the following style:
 
  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>
    
  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.

 
  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to 
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function. 
     The max operator count is checked by dlc. Note that '=' is not 
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies 
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 * 
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce 
 *      the correct answers.
 */


#endif
/* 
 * bitAnd - x&y using only ~ and | 
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    return ~(~x|~y);
}
/* 
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    return (x>>(n<<3))&(0xff);
}
/* 
 * logicalShift - shift x to the right by n, using a logical shift
 *   Can assume that 0 <= n <= 31
 *   Examples: logicalShift(0x87654321,4) = 0x08765432
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3 
 */
int logicalShift(int x, int n) {
    int mask = ~(((0x1<<31)>>n)<<1);
    return (mask)&(x>>n);
}
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    int rmask1 = (0x55<<8)+0x55;
    int mask1 = (rmask1<<16)+rmask1;
    int rmask2 = (0x33<<8)+0x33;
    int mask2 = (rmask2<<16)+rmask2;
    int rmask3 = (0x0f<<8)+0x0f;
    int mask3 = (rmask3<<16)+rmask3;
    int mask4 = (0xff<<16)+0xff;
    int mask5 = (0xff<<8)+0xff;
    int count = (x&mask1)+((x>>1)&mask1);
    count = (count&mask2)+((count>>2)&mask2);
    count = (count&mask3)+((count>>4)&mask3);
    count = (count&mask4)+((count>>8)&mask4);
    count = (count&mask5)+((count>>16)&mask5);
    return count;
}
/* 
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int bang(int x) {
    x = (x>>16)|x;
    x = (x>>8)|x;
    x = (x>>4)|x;
    x = (x>>2)|x;
    x = (x>>1)|x;
    return ~x&0x01;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
    int x = 0x1<<31;
    return x;
}
/* 
 * fitsBits - return 1 if x can be represented as an 
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /* (-n)可以用(~n+1)表示
     *  左移32-n位，再右移32-n位，看是否不变
     */
    int m=33+~n;
    int y =(x<<m)>>m;
    return !(x^y);
}
/* 
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *  Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) {
    int e = (~(0x01<<31>>31<<n))&(x>>31);
    int y = (x+e)>>n;
    return y;
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
    return ~x+1;
}
/* 
 * isPositive - return 1 if x > 0, return 0 otherwise 
 *   Example: isPositive(-1) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 3
 */
int isPositive(int x) {
    int sign = (x>>31)&0x01;
    return !(sign|(!x));
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int sign_x = (x>>31)&0x01;
    int sign_y = (y>>31)&0x01;
    int sign = ((x+(~y+1))>>31)&0x01;// x-y 的符号
    int xnyp = sign_x&(!sign_y);// x为负，y为正
    int xpyn = (!sign_x)&sign_y;// x为正，y为负
    return (!xpyn)&(xnyp|sign|(!(x^y)));
}
/*
 * ilog2 - return floor(log base 2 of x), where x > 0
 *   Example: ilog2(16) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 90
 *   Rating: 4
 */
int ilog2(int x) {
    /* 结果可用5位表示，最大为(31)0b11111,
     * 因此需要判断这5位是0还是1;
     * ans = 16*a+8*b+4*c+2*d+1*e
     * 右移16得到a，右移16*a+8得到b,
     */
    int ans = 0;
    // a = !!(x>>16);
    // 16*a == a<<4 = ans
    ans = (!!(x>>16))<<4;
    ans = ans + ((!!(x>>(ans+8)))<<3);
    ans = ans + ((!!(x>>(ans+4)))<<2);
    ans = ans + ((!!(x>>(ans+2)))<<1);
    ans = ans + ((!!(x>>(ans+1))));
    return ans;
}
/* 
 * float_neg - Return bit-level equivalent of expression -f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representations of
 *   single-precision floating point values.
 *   When argument is NaN, return argument.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 10
 *   Rating: 2
 */
unsigned float_neg(unsigned uf) {
    //unsigned exp = uf&0x7F800000;
    //unsigned frac =uf&0x007FFFFF;
    //if ((exp==0x7F800000)&&(frac!=0)){
    //    return uf;
    //}
    /* 若uf为NaN，则uf的exp全为1，frac不为零，
     * 可以将uf的低31位取反，则低31位小于0x007FFFFF,
     */
    if (((uf<<1)^0xFFFFFFFF)<0x00FFFFFF){
        return uf;
    }
    return uf^0x80000000;
}
/* 
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    /* csapp practice 2.97 */
    /* 为了满足Max ops为30这一要求，合并了操作，增加了中间变量 */
    int sign = x&0x80000000;
    int length = 0;
    int tmp;
    int fbits1;
    unsigned exp;
    unsigned frac;
    unsigned exp_frac;
    unsigned round_mid;
    unsigned round_part;
    unsigned addition;
    if (x==0x80000000) {
        return 0xCF000000;;
    }else if(x==0){
        return 0x0;;
    }else if(sign){
        x=-x;//x=abs(x)
    }
    tmp = x;
    while(tmp){
        tmp = tmp >>1;
        length++;
    }
    fbits1 = length-24;
    exp = (length+126)<<23;
    if (fbits1 == 8){
        exp_frac = exp | 0x0;
    }else if(fbits1>=0){
        frac = (x>>(fbits1))&0x7FFFFF;
        round_mid = 1<<(fbits1-1);
        round_part = x&((0x1<<(fbits1))-1);
        if (round_mid>round_part){
            addition = 0;
        }else if(round_mid<round_part){
            addition = 1;
        }else {
            addition = (frac&0x1)==0x1;
        }
        exp_frac = (exp | frac)+addition;
    }else{
        frac = (x<<(-fbits1))&0x7FFFFF;
        exp_frac = exp | frac;
    }
    return sign | exp_frac;
}
/* 
 * float_twice - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_twice(unsigned uf) {
    unsigned sign = uf&0x80000000;
    unsigned exp = uf&0x7F800000;
    unsigned frac = uf&0x007FFFFF;
    if (exp==0x7F800000){
        return uf;
    }
    if (exp == 0x0) {
        return sign | frac<<1;
    }else if(exp==0x7F000000) {
        return sign | 0x7F800000 | 0x0;
    }
    return sign | (exp+0x00800000) | frac;
}
