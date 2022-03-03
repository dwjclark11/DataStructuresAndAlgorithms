#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "CPP_Style/Queue_wStack.h"

int main()
{
	Queue_S<int> q;
	q.enqueue(15);
	q.enqueue(25);
	q.enqueue(35);
	q.enqueue(45);
	q.dequeue();
	q.enqueue(55);
	q.enqueue(65);
	q.dequeue();
	q.enqueue(55);
	q.enqueue(65);
	q.enqueue(55);
	q.enqueue(65);
	q.Display();

	return 0;
} 