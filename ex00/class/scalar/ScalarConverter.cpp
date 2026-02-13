/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:06:35 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/13 13:06:57 by mlouis           ###   ########.fr       */
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

	bool	digitsTil(const std::string& str, size_t end)
	{
		if (str.length() <= end)
		{
			return (allDigits(str));
		}
		for (size_t i = 0 ; i < end ; i++)
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

	if (!str[0])
	{
		std::cout << "my str: '" << str << "'" << std::endl;
		std::cout << "char: " << isChar << std::endl;
		std::cout << "int: " << isInt << std::endl;
		std::cout << "float: " << isFloat << std::endl;
		std::cout << "double: " << isDouble << std::endl;
		
		return ;
	}
	if (!utils::allPrintable(str))
	{
		std::cout << "Error\nNon-printable characters shouldn't be used" << std::endl;
		return ;
	}
	if (!str[1])
		isChar = true;
	int i = 0;
	if (isdigit(str[0]) || str[0] == '+' || str[0] == '-')
		++i;
	if (utils::allDigits(&str[i]))
		isInt = true;
	size_t	dot_index = str.find(".");
	if (dot_index == std::string::npos)
		return ;
	if (utils::digitsTil(&str[i], dot_index - 1))
	{
		std::cout << "DOT POS = " << str[str.length() - 1] << " (" << str.length() - 1 << ")" << std::endl;
		if (utils::digitsTil(&str[dot_index + 1], str.length() - 1 - dot_index))
			isDouble = true;
		if (utils::digitsTil(&str[dot_index + 1], str.length() - 2 - dot_index) && str[str.length() - 1] == 'f')
			isFloat = true;
	}
	//if () find '.' all digit til point, all digit from point 
	//	isFloat = true;
	// char: more than one char
	// int: only number (- and +)
	// double: same as int but add .
	// float: same as double but add at the end

	

	std::cout << "my str: " << str << std::endl;
	std::cout << "char: " << isChar << std::endl;
	std::cout << "int: " << isInt << std::endl;
	std::cout << "float: " << isFloat << std::endl;
	std::cout << "double: " << isDouble << std::endl;

	// std::cout << "char: " << static_cast<char>(str) << std::endl;
	// std::cout << "int: " << static_cast<int>(str) << std::endl;
	// std::cout << "float: " << static_cast<float>(str) << std::endl;
	// std::cout << "double: " << static_cast<double>(str) << std::endl;
}
