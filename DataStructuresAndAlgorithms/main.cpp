#include <stdlib.h>
#include <crtdbg.h>
#include <iostream>
#include "CPP_Style/Queue.h"

int main()
{
	Queue<int> q;

	q.push_back(7);
	q.push_back(6);
	q.push_back(9);
	q.push_back(1);

	q.Display();
	std::cout << "Size: " << q.size() << std::endl;
	std::cout << "front: " << q.pop_front() << std::endl;
	std::cout << "Size: " << q.size() << std::endl;

	q.Display();

	return 0;
} 