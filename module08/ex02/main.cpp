#include "MutantStack.hpp"
#include "MutantStack.tpp"
int main()
{
	{
		std::cout << "---List---" << std::endl;
		std::list<int> mstack;
		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(mstack);
	}
	{
		std::cout << "---MutantStack---" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "---------------------" << std::endl;
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		mstack.push(3);
		std::cout << "Top: " << mstack.top() << std::endl;
		std::cout << "Size: " << mstack.size() << std::endl;
		MutantStack<int>::iterator it = mstack.end();
		MutantStack<int>::iterator ite = mstack.begin();
		it--;
		int i = 2;
		while (it != ite)
		{
			std::cout << "Stack Index[" << i << "] Value: " << *it << std::endl;
			--it;
			i--;
		}
		if (*it)
			std::cout << "Stack Index[" << i << "] Value: " << *it << std::endl;
		mstack.pop();
		std::cout << "Size: " << mstack.size() << std::endl;
		i = 0;
		it = mstack.begin();
		ite = mstack.end();
		while (it != ite)
		{
			std::cout << "Stack Index[" << i << "] Value: " << *it << std::endl;
			++it;
			i++;
		}
	}
	return 0;
}