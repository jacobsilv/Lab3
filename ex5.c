//Implement a C function called ex5 such that it achieves 
//the same functionality as the machine code of objs/ex5_sol.o
//Note: you need to figure out ex5()'s function signature yourself; 
//the signature is not void ex5(node *n). However, as a hint, 
//ex5 does take node * as an argument.
 
#include <assert.h>
#include "ex5.h"
#include <stdlib.h> // or you can convert all the NULLs to zeros

/*
  400800:       48 85 ff                test   %rdi,%rdi                : test if that register is equal to zero
  400803:       75 0d                   jne    400812 <ex5+0x12>        : 1 jump if it is not equal or not zero
  400805:       eb 17                   jmp    40081e <ex5+0x1e>        : 2 jump unconditional 
  400807:       48 8b 17         *jne   mov    (%rdi),%rdx              : 4th jump: rdx = *rdi
  40080a:       48 89 c7                mov    %rax,%rdi                : rdi = rax
  40080d:       48 3b 10                cmp    (%rax),%rdx              : compare rdx with *rax
  400810:       7f 12                   jg     400824 <ex5+0x24>        : 3 jump is greater than sign
  400812:       48 8b 47 08      *jne   mov    0x8(%rdi),%rax           : 1st jump: rax = pointer next
  400816:       48 85 c0                test   %rax,%rax                : test if that register is equal to zero
  400819:       75 ec                   jne    400807 <ex5+0x7>         : 4 jump if not equal/ not zero
  40081b:       b0 01                   mov    $0x1,%al                 : make the lower register equal to 1
  40081d:       c3                      retq                            :return
  40081e:       b8 01 00 00 00   *jmp   mov    $0x1,%eax                : 2nd jump: arrives here and eax = 1
  400823:       c3                      retq                            :return
  400824:       b8 00 00 00 00   *jg    mov    $0x0,%eax                : 3rd jump: goes here and eax = 0
  400829:       c3                      retq                            :return
*/

int
ex5(node *n) {
	if (n== NULL /*0*/){
		return 1;
	}
	while ( n->next != NULL){
		if (n->value > n->next->value){
			return 0;
		}
		n = n->next;
	}
	
	return 1;
}

