#include "Serializer.hpp"

Serializer::Serializer()
{
}

Serializer::Serializer(const Serializer &src)
{
	*this = src;
}

Serializer::~Serializer()
{
}

Serializer &Serializer::operator=(const Serializer &src)
{
	if (this != &src)
	{
	}
	return *this;
}

uintptr_t Serializer::serialize(Data *data)
{
	uintptr_t raw = reinterpret_cast<uintptr_t>(data);
	return raw;
}

Data *Serializer::deserialize(uintptr_t raw)
{
	Data *data = reinterpret_cast<Data *>(raw);
	return data;
}
