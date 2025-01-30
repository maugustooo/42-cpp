#pragma once
#include <iostream>
#include <string>

template <typename T>

void iter(T *array, int size, void (*f)(T &))
{
	if (array == NULL || f == NULL || size < 0)
		return ;
	for (int i = 0; i < size; i++)
		f(array[i]);
}