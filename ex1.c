//Implement a C function called ex1 such that it achieves 
//the same functionality as the machine code of objs/ex1_sol.o
//Note: you need to figure out ex1()'s function signature yourself; 
//the signature is not void ex1()
  
#include <assert.h>


/*
  40076d:       48 01 f7                add    %rsi,%rdi : b = a + b
  400770:       48 39 d7                cmp    %rdx,%rdi : compares the third parameter ( c ) with b
  400773:       0f 94 c0                sete   %al : sets the return value of that is an a 8bit register
  400776:       0f b6 c0                movzbl %al,%eax : puts the 8bit register %al into a 32 bit return register
  400779:       c3                      retq  : returns result of the compare
*/

long
ex1(long a, long b, long c) {
	b = a+b;
	return (b==c);
}


