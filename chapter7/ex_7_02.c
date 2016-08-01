/*

Write a program that will print arbitrary input in a sensible way. As a
minimum, it should print non-graphic characters in octal or hexadecimal
according to local custom, and break long text lines.

*/

#include <stdio.h>
#include <string.h>

int is_printable_ascii(int c);
int is_printable_ascii(int c)
{
	return (c >= 32 && c <= 126);
}

static char *test1 = "Here is a string.";

int main()
{
	strlen(test1);

	int c;
	int i = 0;

	while ((c = getchar()) != EOF) {
		if (is_printable_ascii(c))
			printf("%4c ", c);
		else
			printf("0x%2.2x ", c);

		if (i++ == 10) {
			printf("\n");
			i = 0;
		}
	}
}

/*

$ clang -Weverything chapter7/ex_7_02.c && cat a.out | ./a.out | head -n 10
0xcf 0xfa 0xed 0xfe 0x07 0x00 0x00 0x01 0x03 0x00 
0x00 0x80 0x02 0x00 0x00 0x00 0x0f 0x00 0x00 0x00 
0x00 0x05 0x00 0x00 0x85 0x00      0x00 0x00 0x00 
0x00 0x00 0x19 0x00 0x00 0x00    H 0x00 0x00 0x00 
   _    _    P    A    G    E    Z    E    R    O 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x01 0x00 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 
0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 0x00 

*/
