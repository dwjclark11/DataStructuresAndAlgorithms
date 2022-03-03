#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>

#include "CPP_Style/Queue_wArray.h"

int main()
{
	Queue<float> q;
	q.push(75.f);
	q.push(175.f);
	q.push(175.f);
	q.push(175.f);
	q.push(175.f);
	q.push(275.f);
	q.push(375.f);
	q.Display();

	q.push(275.f);
	q.Display();

	std::cout << "Front: " << q.get_front() << std::endl;
	std::cout << "back: " << q.get_back() << std::endl;
	return 0;
} 