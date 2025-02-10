#pragma once
#include <iostream>
#include <string>
#include <stack>
#include <list>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		MutantStack(MutantStack const &other);
		MutantStack &operator=(MutantStack const &other);
		~MutantStack();
		typedef typename std::stack<T>::container_type::iterator iterator;
		iterator begin();
		iterator end();
};