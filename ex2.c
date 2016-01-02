//Implement a C function called ex2 such that it achieves 
//the same functionality as the machine code of objs/ex2_sol.o
//Note: you need to figure out ex2()'s function signature yourself; 
//the signature is not void ex2()
  
#include <assert.h>
/*
  40077a:       b8 00 00 00 00          mov    $0x0,%eax :assigns the return value to zero
  40077f:       ba 00 00 00 00          mov    $0x0,%edx : makes a iterator initialized at zero
  400784:       eb 0e                   jmp    400794 <ex2+0x1a> : jumps to line 400794
  400786:       80 f9 61     *jne       cmp    $0x61,%cl : compare 8 bit cl with 61 as 8 bits so it is hex
  400789:       0f 94 c1                sete   %cl : sets the four address 8 bits to equal/zero
  40078c:       0f b6 c9                movzbl %cl,%ecx : putting the cl 8 bits into a 32 bit fourth address
  40078f:       01 c8                   add    %ecx,%eax : adds the return value += the 32 bit fourth address
  400791:       83 c2 01                add    $0x1,%edx : increments the counter by one
  400794:       48 63 ca     *jmp       movslq %edx,%rcx : assign rcx to edx the counter
  400797:       0f b6 0c 0f             movzbl (%rdi,%rcx,1),%ecx : ecx = rdi + (rcx * 1) // fourthArg=fourth arg*1 + 1st arg
  40079b:       84 c9                   test   %cl,%cl : test if that fourth arg register is equal to zero
  40079d:       75 e7                   jne    400786 <ex2+0xc> : jump not equal / not zero
  40079f:       f3 c3                   repz retq: return the number of 'a's found
*/
int
ex2(char* string) {


	int result= 0;	
	int i;
	for (i= 0;string[i] != '\0'; i++){
		
		result += (string[i] == 'a');
	}
	return result;
}

/*

// another way of doing this that isnt the exact assembly code but passes the test
//int ex2(char* string){
	int result = 0;
	int i=0;
	while (string[i] != '\0'){
		if (string[i] == 'a'){
			result+=1;
		}
		i++;
	}

	return result;
*/





