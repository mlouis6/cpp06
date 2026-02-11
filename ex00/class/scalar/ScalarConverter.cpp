/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:06:35 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/11 14:57:22 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>

namespace utils
{
	bool	allPrintable(const std::string& str)
	{
		for (size_t i = 0 ; i < str.length() ; i++)
		{
			if (!std::isprint(str[i]))
				return (false);
		}
		return (true);
	}

	bool	allDigits(const std::string& str)
	{
		for (size_t i = 0 ; i < str.length() ; i++)
		{
			if (!std::isdigit(str[i]))
				return (false);
		}
		return (true);
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	bool	isChar = false;
	bool	isInt = false;
	bool	isFloat = false;
	bool	isDouble = false;

	if (!utils::allPrintable(str))
	{
		std::cout << "Error\nNon-printable characters shouldn't be used" << std::endl;
		return ;
	}
	if (!str[1])
		isChar = true;

	// check -, +, digit then if for 3 next type
	if (utils::allDigits(str) ||
		(str[0] == '-' && utils::allDigits(&str[1])) ||
		(str[0] == '+' && utils::allDigits(&str[1])))
		isInt = true;
	//if () find '.' all digit til point, all digit from point 
	//	isFloat = true;
	// char: more than one char
	// int: only number (- and +)
	// double: same as int but add .
	// float: same as double but add at the end

	

	std::cout << "my str: " << str << std::endl;
	// std::cout << "char: " << static_cast<char>(str) << std::endl;
	// std::cout << "int: " << static_cast<int>(str) << std::endl;
	// std::cout << "float: " << static_cast<float>(str) << std::endl;
	// std::cout << "double: " << static_cast<double>(str) << std::endl;

	std::cout << "char: " << dynamic_cast<char>(str) << std::endl;
	std::cout << "int: " << dynamic_cast<int>(str) << std::endl;
	std::cout << "float: " << dynamic_cast<float>(str) << std::endl;
	std::cout << "double: " << dynamic_cast<double>(str) << std::endl;

	std::cout << "char: " << reinterpret_cast<char>(str) << std::endl;
	std::cout << "int: " << reinterpret_cast<int>(str) << std::endl;
	std::cout << "float: " << reinterpret_cast<float>(str) << std::endl;
	std::cout << "double: " << reinterpret_cast<double>(str) << std::endl;
}
