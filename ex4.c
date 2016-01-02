//Implement a C function called ex4 such that it achieves 
//the same functionality as the machine code of objs/ex4_sol.o
//Note: you need to figure out ex4()'s function signature yourself; 
//the signature is not void ex4()
  
#include <assert.h>

/*
   0:   55                      push   %rbp                     : push rbp onto the stack
   1:   53                      push   %rbx                     : push rbx onto the stack
   2:   48 83 ec 08             sub    $0x8,%rsp                : make the stack have 8 bytes
   6:   48 89 fb                mov    %rdi,%rbx                : rbx = rdi // do this for your second recursive parameter
   9:   48 89 f8                mov    %rdi,%rax                : rax = rdi // separates the function from param
   c:   48 83 ff 01             cmp    $0x1,%rdi                : comparing 1 and rdi
  10:   7e 18                   jle    2a <ex4+0x2a>            : jump less than or equal to for base case
  12:   48 8d 7f ff             lea    -0x1(%rdi),%rdi          : rdi = rdi - 1 //  setting the parameter to n-1
  16:   e8 00 00 00 00          callq  1b <ex4+0x1b>            : first recursive function call
  1b:   48 89 c5                mov    %rax,%rbp                : rbp = rax
  1e:   48 8d 7b fe             lea    -0x2(%rbx),%rdi          : rdi = rbx -2 // setting the parameter to n-2
  22:   e8 00 00 00 00          callq  27 <ex4+0x27>            : second recursive function call
  27:   48 01 e8                add    %rbp,%rax                : rax = rax + rbp // the tw  calls added together
  2a:   48 83 c4 08     *jle    add    $0x8,%rsp                : rsp = rsp + 8
  2e:   5b                      pop    %rbx                     : pop rbx off the stack
  2f:   5d                      pop    %rbp                     : pop rbp off the stack

*/

long
ex4(long n){
	if (n <= 1){
		return n;
	}
	return ex4(n-1)+ex4(n-2);

}





