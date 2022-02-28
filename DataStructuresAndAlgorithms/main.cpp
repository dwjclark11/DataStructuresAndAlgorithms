#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "C_Style/C_Stack_wLinkedList.h"


int main()
{
	struct Node* top = NULL;
	if(empty(top))
		push(&top, 5);
	else
	{

		push(&top, 25);
		push(&top, 35);
		push(&top, 45);

	}

	printf("Top: %d\n", GetTop(top));
	Display(top);
	pop(&top);
	Display(top);

	return 0;
}