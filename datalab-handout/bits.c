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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) { 
  return ~(~((~x)&y)&~((~y)&x));
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return (1<<31);
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
// write up:
// max_int: 011111..., and it plus 1 equals 10000..., which all bits differ with max_int.
// so ~(x^(x+1)) will be 0
// we can find that most of numbers can do this.
// Only 111111... is the same, so we handle it specially.
int isTmax(int x) {
  return !(~(x^(x+1)) | !(x+1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
  return !((x | 0x55 | 0x55<<8 | 0x55<<16 | 0x55<<24)+1);
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
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */

// write up:
// This problem equals to 'is x between 110000b to 111001b',10 nums are not convenient for bit
// operation, so I dicided to divide this problem into 'is x between 110000b to 110111b (0x30->0x37)'
// or 'x == 0x38' or 'x == 0x39'
// How to determine if x in [0x30, 0x37]? There I give a solution:
// if x in [0x30, 0x37] <=> if x-0x30 in [0b, 111b]
// -x == ~x+1; a == b <=> !(a^b)
// and then the problem becomes easy.
// !a | !b | !c <=> if and only if not all of (a,b,c) are 1 that return 1   
int isAsciiDigit(int x) {
  return !((x+(~0x30+1))>>3) | !(x^0x38) | !(x^0x39);
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
// write up:
// it's easy to think that the answer can be '(a) | (b)'. 
// When x, a==y and b==0, otherwise a==0 and b==z.
// I think I should make a mask to check the num, and the best answer is that 1111&y | 0&z,
// -1 == 1111, -0 == 0
// !!x can transfer the x(not zero) to 1
// but the compiler will give a warning...because then will ~ a boolen.
// so we can understand the answer.
int conditional(int x, int y, int z) {
  //return 2;
  return ((~(!!x)+1)&y) | ((~(!x)+1)&z);
}

/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
// write up:
// a difficult problem...
// the basic thought is to judge the sign of y-x, it can be represented as ((y+~x+1)>>31)&1
// when y-x<0, it would be 1
// the special case is that y<0&&x>0 as well as y>0&&x<0, which may overflow,
// when y>0&&x<0 return 1, and when y<0&&x>0 return 0;
// y<0&&x>0 should use & to connect other expressions because y-x is positive(return 1) but we
// want to get a 0;
int isLessOrEqual(int x, int y) {
  return (!((y>>31)&!(x>>31))) & (((!(y>>31))&(x>>31)) | !(((y+~x+1)>>31)&1));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
// write up:
// a little difficult...
// the key thought is to use the arithmetic right shift.(reserve the sign bit)
// this can zip all the int into one bit.
// so our target is to make the 0 and not 0 differs on the sign bit.
// a negative number and a positive number differs on the sign bit.
// so i use (x>>31) and ((~x+1)>>31) to get their sign.
// if not 0 or 0x80000..., there will be a 0 and a 1 on the bit0.
// so the thought depends on the sign bit
// 0, 1 => 0 (normal number)
// 0, 0 => 1 (zero)
// 1, 1 => 0 (0x80000...)
// it's difficult to make 0[]0=>1 and 1[]1=>0, 
// but we can use (m+1)&1 to make 0 to 1 and 1 to 0;
// so i can 0^1=>1, 1&1=>1, 0^0=>0, 0&0=>0
// the first solution is => (((x>>31)^((~x+1)>>31) | (x>>31)&((~x+1)>>31))+1) & 1
// but this uses 13ops... and there are repeated content.
// On the venn graph, I can find that a^b | a&b == a|b, and solve this problem. 
int logicalNeg(int x) {
  return ((((x>>31)|((~x+1)>>31)))+1)&1 ;
}


/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
// write up:
// not my work
// the problem can be divided into two cases: positive and negative.
// when x > 0: we should find the highest bit with 1, and the result is n+1(sign bit);
// such as 0x70, we need 7 + 1 bits;
// when x < 0: we should find the highest bit with 0, and the result is n+1(sign bit):
// such as 1001, it's -7 and 11001 is also -7, 111001 is -7, we need 3+1 bits to represent it.
// to convenient our operation, we can make `x = (sign&(~x)) | (~sign&x)`, this can change x to ~x 
// when negative and x when positive. (great daze!) Now our target is to find the highest bit with 1
// and then we use binary search to find whether the high m bits include 1
// b16 equals 16 when the highest 16bits have 1, otherwise equals 0;
// it means we need at least 16 bits to show.
// and others are the same.
int howManyBits(int x) {
  int b16, b8, b4, b2, b1, b0;
  int sign = x >> 31;
  x = (sign&(~x)) | (~sign&x);
  b16 = !!(x>>16)<<4;
  x = x >> b16;
  b8 = !!(x>>8)<<3;
  x = x >> b8;
  b4 = !!(x>>4)<<2;
  x = x >> b4;
  b2 = !!(x>>2)<<1;
  x = x >> b2;
  b1 = !!(x>>1);
  x = x >> b1;
  b0 = x;
  return b16+b8+b4+b2+b1+b0+1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
// write up:
// it's not my work
// for normal cases: return the (sign,exp+1,num) 
// there are 4 special cases: +-inf, 0, NaN,
// for inf and NaN we need only return itself;
// as for -inf and 0, we make uf*2|sign (it would not overflow)
unsigned floatScale2(unsigned uf) {
  int exp = (uf&0x7f800000) >> 23;
  int sign = uf&(1<<31);
  if (exp == 0) return (uf<<1) | sign;
  if (exp == 255) return uf;
  exp++;
  if (exp == 255) return 0x7f800000 | sign;

  return (exp<<23)|(uf&0x807fffff);
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
// write up:
// the presentation of single-precision floating point value:
// -,--------,-----------------------(sign[1], offset[8], num[23])
// s,   x    ,    num
// the problem can be divided to 3 cases:
// 1. offset < 0: return 0;(because 1.xxx * 2^-m must be 0(int))
// 2. offset >= 23: out of range of num, so should be 0x80000000u
// 3. normal:
// 	we make the left offset bits of num into the result and then result<<=30-offset
// 	to ensure the num can be behind the sign bit, such as 1,111,000, so that we can 
// 	get a normal negation.
// 	last we make result>>=30-offset to ensure it ok.
int floatFloat2Int(unsigned uf) {
  int offset = (uf>>23) & 0xff;
  offset -= 127;
  if (offset < 0) return 0;
  if (offset >= 23) return 0x80000000u; 
  int result = 0;
  int i = 0; 
  while (i < offset) {
    result |= (offset>>(23-offset)) | (1<<i);
    i++;
  }
  result |= 1<<offset;
  result <<= 30-offset;
  result |= (uf & (1<<31));
  result >>= 30-offset;
  return result;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
// write up:
// it's clear
// return (0,x+127,0)
// special cases: too small and too large
unsigned floatPower2(int x) {
  int inf = 0xff << 23;
  int exp = x + 127;
  if (exp <= 0) return 0;
  if (exp >= 255) return inf;
  return exp << 23;
}
