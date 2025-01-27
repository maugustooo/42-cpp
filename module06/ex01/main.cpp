/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gude-jes <gude-jes@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 12:09:11 by gude-jes          #+#    #+#             */
/*   Updated: 2025/01/09 09:14:14 by gude-jes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

void testSerialization(const std::string& str, int n)
{
    Data *data = new Data(str, n);
	Serializer serializer;
    uintptr_t raw = serializer.serialize(data);
    std::cout << "raw: " << raw << std::endl;

    Data *deserializedData = serializer.deserialize(raw);

    std::cout << "Original Data: " << std::endl;
    std::cout << "str: " << data->str << ", n: " << data->n << std::endl;

    std::cout << "Deserialized Data: " << std::endl;
    std::cout << "str: " << deserializedData->str << ", n: " << deserializedData->n << std::endl;

	std::cout << "raw: " << raw << std::endl;
    delete data;
	std::cout << std::endl;
}

int main()
{
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("World", 42);
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("Bar", 123);
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("Serialization", 999);
	std::cout << "-----------------------------------" << std::endl;
    testSerialization("Ano", -1);

    return 0;
}