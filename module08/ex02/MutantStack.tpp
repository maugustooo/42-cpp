#include "MutantStack.hpp"

template <typename T>
MutantStack<T>::MutantStack() : std::stack<T>()
{
	std::cout << "MutantStack constructor called" << std::endl;
}

template <typename T>
MutantStack<T>::MutantStack(MutantStack const &other) : std::stack<T>(other)
{
	std::cout << "MutantStack copy constructor called" << std::endl;
}

template <typename T>
MutantStack<T> &MutantStack<T>::operator=(MutantStack const &other)
{
	std::cout << "MutantStack assignation operator called" << std::endl;
	this->c = other.c;
	return *this;
}

template <typename T>
MutantStack<T>::~MutantStack()
{
	std::cout << "MutantStack destructor called" << std::endl;
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::begin()
{
	return this->c.begin();
}

template <typename T>
typename MutantStack<T>::iterator MutantStack<T>::end()
{
	return this->c.end();
}