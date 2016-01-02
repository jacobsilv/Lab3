//Implement a C function called ex3 such that it achieves 
//the same functionality as the machine code of objs/ex3_sol.o
//Note: you need to figure out ex3()'s function signature yourself; 
//the signature is not void ex3()
  
#include <assert.h>

/*

  4007a1:       b8 00 00 00 00          mov    $0x0,%eax                : set eax = 0 return value is incrementer
  4007a6:       eb 1b                   jmp    4007c3 <ex3+0x22>        : jump to the compare, for loop first check
  4007a8:       48 63 c8                movslq %eax,%rcx                : set rcx = eax :64bit reg set the 32bit return reg
  4007ab:       4c 8d 04 0f             lea    (%rdi,%rcx,1),%r8        : r8 = rcx*1 + rdi 5th arg set to 4th plus 1st
  4007af:       45 0f b6 08             movzbl (%r8),%r9d               : r9d = *r8 assign 6th arg dereferenced 5th arg
  4007b3:       48 01 f1                add    %rsi,%rcx                : rcx = rsi + rcx 4th arg = 2nd arg + 4th arg
  4007b6:       44 0f b6 11             movzbl (%rcx),%r10d             : r10d = *rcx 32 bit caller = deferenced 4th arg
  4007ba:       45 88 10                mov    %r10b,(%r8)              : *r8 = r10b caller 8bits is value of 5th 
  4007bd:       44 88 09                mov    %r9b,(%rcx)              : *rcx = r9b val of 4th arg is 6th arg 8 bits
  4007c0:       83 c0 01                add    $0x1,%eax                : eax = eax +1 return value is incremented
  4007c3:       39 d0         *jmp      cmp    %edx,%eax                : comp edx with eax, for loop checker : i < len
  4007c5:       7c e1                   jl     4007a8 <ex3+0x7>         : jump less, repeat if the compare is less than 1
  4007c7:       f3 c3                   repz retq                       : return i which is len-1
*/

int
ex3(char* a, char* b, int len) {

	int i;
	for (i =0; i < len ; i++){
		//checking to see the values given by the params
		//printf("%c - ", a[i]);
		//printf("%c, ", b[i]);

		char temp1 = b[i];
		b[i] = a[i];
		a[i] = temp1;
	
	}
	return i;
}
