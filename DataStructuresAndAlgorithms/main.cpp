#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "C_Style/C_Stack_wArray.h"


int main()
{
	struct Stack st;
	Create(&st);

	push(&st, 10);
	push(&st, 20);
	push(&st, 30);
	push(&st, 40);

	Display(st);

	printf("%d\n", pop(&st));
	
	printf("peek: %d", peek(st, 2));

	return 0;
}