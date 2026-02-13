/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:06:35 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/13 15:02:31 by mlouis           ###   ########.fr       */
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

enum e_type { NONE = 0, CHAR, INT, FLOAT, DOUBLE, ERROR };

static	e_type	getType(const std::string& str)
{
	if (!str[0])
		return (NONE);
	if (!utils::allPrintable(str))
	{
		std::cout << "Error\nNon-printable characters shouldn't be used" << std::endl;
		return (ERROR);
	}

	int i = 0;
	if (isdigit(str[0]) || str[0] == '+' || str[0] == '-')
		++i;

	size_t	dot_index = str.find(".");
	if (dot_index != std::string::npos)
	{
		if (dot_index == 0)
		{
			if (utils::digitsTil(&str[dot_index + 1], str.length() - 2 - dot_index) && str[str.length() - 1] == 'f')
				return (FLOAT);
			if (utils::digitsTil(&str[dot_index + 1], str.length() - 1 - dot_index))
				return (DOUBLE);
		}
		else
		{
			if (utils::digitsTil(&str[i], dot_index - 1))
			{
				if (str[dot_index + 1] == 'f' && !str[dot_index + 2])
					return (FLOAT);
				if (!str[dot_index + 1])
					return (DOUBLE);
				if (utils::digitsTil(&str[dot_index + 1], str.length() - 2 - dot_index) && str[str.length() - 1] == 'f')
					return (FLOAT);
				if (utils::digitsTil(&str[dot_index + 1], str.length() - 1 - dot_index))
					return (DOUBLE);
			}
		}
	}

	if (utils::allDigits(&str[i]))
		return (INT);

	if (!str[1])
		return (CHAR);
	
	if (str == "+inff" || str == "-inff" || str == "nanf")
		return (FLOAT);
	if (str == "+inf" || str == "-inf" || str == "nan")
		return (DOUBLE);
	
	return (NONE);
}
#include <sstream>
static void	convertInt(const std::string& str)
{
	std::istringstream iss(str);
	int iVal = 0;
	iss >> iVal;
	std::string cmp = static_cast<std::ostringstream&>(std::ostringstream() << std::dec << iVal).str();
	if (str == cmp)
		std::cout << "int= " << iVal << std::endl;
	else
		std::cout << "int= overflow" << std::endl;
}
#include <limits>
static void	convertFloat(const std::string& str)
{
	std::istringstream iss(str);
	float fVal = 0.0f;
	iss >> fVal;
	// std::string cmp = static_cast<std::ostringstream&>(std::ostringstream() << std::dec << fVal).str();
	if (fVal + std::numeric_limits<float>::epsilon() >= fVal)
		std::cout << "float= " << fVal << std::endl;
	else
		std::cout << "float= +inff" << std::endl;
}

static void	convertDouble(const std::string& str)
{
	std::istringstream iss(str);
	double dVal = 0.0;
	iss >> dVal;
	std::cout << "double= " << dVal << std::endl;
}


void	ScalarConverter::convert(const std::string& str)
{
	e_type type = getType(str);

	std::cout << "type= ";
	switch (type)
	{
		case NONE:
			std::cout << "none";
			break ;
		case CHAR:
			std::cout << "char";
			break ;
		case INT:
			std::cout << "int";
			convertInt(str);
			break ;
		case FLOAT:
			std::cout << "float";
			convertFloat(str);
			break ;
		case DOUBLE:
			std::cout << "double";
			convertDouble(str);
			break ;
		case ERROR:
			std::cout << "error";
			break ;
	}
	std::cout << std::endl;
}
