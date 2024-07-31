#include <iostream>
#include <Vector>
#include <stack>
#include <queue>

int main()
{
	//Vector
	std::vector<int> vectorT;

	for (int i = 1; i <= 15; i++)
	{
		vectorT.push_back(i);
	}

	std::cout << "Vector Contains: " << std::endl;

	std::vector<int>::iterator iter = vectorT.begin();

	while (iter != vectorT.end())
	{
		std::cout << " " << *iter;
		++iter;
	}

	std::cout << std::endl;

	//Stack
	std::stack<int> stackT;

	for (int i = 1; i <= 15; i++)
	{
		stackT.push(i);
	}

	std::cout << "Stack Contains: " << std::endl;

	while (!stackT.empty())
	{
		std::cout << " " << stackT.top();
		stackT.pop();
	}

	std::cout << std::endl;

	//Queue
	std::queue<int> queueT;

	for (int i = 1; i <= 15; i++)
	{
		queueT.push(i);
	}

	std::cout << "Queue Contains: " << std::endl;

	while (!queueT.empty())
	{
		std::cout << " " << queueT.front();
		queueT.pop();
	}

	std::cout << std::endl;

	return 0;
}