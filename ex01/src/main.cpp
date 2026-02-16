/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 09:42:59 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/16 10:37:00 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "data.hpp"
#include <stdint.h>
#include <iostream>

int main()
{
	Data* data = new Data;
	data->valI = 124;
	data->valC = 'a';
	data->valStr.append("hello");
	data->valF = 14.36;
	
	std::cout << "DATA (before)\nint= " << data->valI << "\nchar= '" << data->valC << "'\nstr= \"" <<
				data->valStr << "\"\nfloat= " << data->valF << std::endl;

	data = Serializer::deserialize(Serializer::serialize(data));

	std::cout << "DATA (after)\nint= " << data->valI << "\nchar= '" << data->valC << "'\nstr= \"" <<
				data->valStr << "\"\nfloat= " << data->valF << std::endl;

	delete data;
	return (0);
}
