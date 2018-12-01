#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>

void dtob(char *num, size_t size)
{
	int i;
	bool binary;
	
	for ( ; size; size--, num++) {
		for (i = 7; i > -1; i--) {
			binary = *num & (1 << i);
			printf("%d", binary);
			
		}
		printf(" ");
	}
	printf("\n");
}

int main(void)
{
	int i;
	
	uintmax_t num1 = 0;
	uintmax_t num2 = 0;
	uintmax_t num3 = 0;
	
	char *ptr1 = (char *)&num1;
	char *ptr2 = (char *)&num2;
	char *ptr3 = (char *)&num3;
	
	
	for (i = 0; i < 65; i++) {
		num1 = ((uintmax_t)1 << i);
		num2 = ((uintmax_t)1 << i) - 1;
		num3 |= ((uintmax_t)1 << i);
		
		printf("\n%d: \n", i);
		printf("%ju\n", num1);
		printf("%ju\n", num2);
		printf("%ju\n", num3);
		
		dtob(ptr1, sizeof(uintmax_t));
		dtob(ptr2, sizeof(uintmax_t));
		dtob(ptr3, sizeof(uintmax_t));
	}
	
	return 0;
}
