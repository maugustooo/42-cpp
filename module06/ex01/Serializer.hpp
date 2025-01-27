#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

struct Data
{
	std::string str;
	int n;

	Data() : str(""), n(0) {}
	Data(std::string str, int n) : str(str), n(n) {}
};

class Serializer
{
	public:
		Serializer();
		Serializer(const Serializer &src);
		~Serializer();
		Serializer &operator=(const Serializer &src);

		uintptr_t serialize(Data *data);
		Data *deserialize(uintptr_t raw);
};