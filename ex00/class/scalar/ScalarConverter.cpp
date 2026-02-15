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
#include <sstream>
#include <limits>
#include <cmath>

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

enum e_type { CHAR = 0, INT, FLOAT, DOUBLE, ERROR_NONPRINT, ERROR_TYPE };

static	e_type	getType(const std::string& str)
{
	if (!str[0])
		return (ERROR_TYPE);
	if (!utils::allPrintable(str))
		return (ERROR_NONPRINT);

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
	
	return (ERROR_TYPE);
}


namespace check
{
	void	forChar(const int val)
	{
		if (val < 0 || val > 128)
			std::cout << "impossible" << std::endl;
		else if (std::isprint(val))
			std::cout << "'" << static_cast<char>(val) << "'" << std::endl;
		else
			std::cout << "Non displayable" << std::endl;
	}

	void	forInt(const double val)
	{
		if (std::isnan(val) || std::isinf(val) ||
			val > std::numeric_limits<int>::max() || val < std::numeric_limits<int>::min())
			std::cout << "impossible" << std::endl;
		else
			std::cout << static_cast<int>(val) << std::endl;
	}

	void	forFloat(const double val)
	{
		if (std::isnan(val))
			std::cout << "nan"; 
		else if ((std::isinf(val) && val >= 0) || val > std::numeric_limits<float>::max())
			std::cout << "+inf";
		else if ((std::isinf(val) && val < 0) || val < std::numeric_limits<float>::min())
			std::cout << "-inf";
		else
			std::cout << static_cast<float>(val);
		std::cout << "f" << std::endl;
	}
}

namespace print
{
	void	fromChar(const char val)
	{
		std::cout << "char: '" << val << "'" << std::endl;
		std::cout << "int: " << static_cast<int>(val) << std::endl;
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;

	}

	void	fromInt(const long long val, std::istringstream& iss)
	{
		std::cout << "char: ";
		check::forChar(val);
		if (iss.fail() || !iss.eof())
			std::cout << "int: impossible" << std::endl;
		else
			std::cout << "int: " << val << std::endl;
		std::cout << "float: " << static_cast<float>(val) << ".0f" << std::endl;
		std::cout << "double: " << static_cast<double>(val) << ".0" << std::endl;
	}

	void	fromFloat(const float val, std::istringstream& iss)
	{
		std::cout << "char: ";
		check::forChar(val);
		
		std::cout << "int: " << static_cast<int>(val)<< std::endl;

		if (std::isnan(val))
			std::cout << "nanf" << std::endl;
		else if (val >= 0 && (std::isinf(val) || (iss.fail())))
				std::cout << "float: +inff" << std::endl;
		else if (val < 0 && (std::isinf(val) || (iss.fail())))
				std::cout << "float: -inff" << std::endl;
		else
			std::cout << "float: " << val << "f"  << std::endl;

		std::cout << "double: " << static_cast<double>(val) << std::endl;
	}

	void	fromDouble(const double val, std::istringstream& iss)
	{
		std::cout << "char: ";
		check::forChar(val);

		std::cout << "int: ";
		check::forInt(val);
		
		std::cout << "float: ";
		check::forFloat(val);

		if (std::isnan(val))
			std::cout << "double: nan" << std::endl;
		else if (val >= 0 && (std::isinf(val) || (iss.fail())))
			std::cout << "double: +inf" << std::endl;
		else if (val < 0 && (std::isinf(val) || (iss.fail())))
			std::cout << "double: -inf" << std::endl;
		else
			std::cout << "double: " << val << std::endl;
	}

	void	fromError(e_type type)
	{
		if (type == ERROR_TYPE)
			std::cout << "Error\nAccepted types are CHAR, INT, FLOAT, DOUBLE" << std::endl;
		else if (type == ERROR_NONPRINT)
			std::cout << "Error\nNon-printable characters shouldn't be used" << std::endl;
	}
}


namespace convertStr
{
	char	toChar(const std::string& str)
	{
		char val = str[0];
		return (val);
	}

	int	toInt(const std::string& str, std::istringstream& iss)
	{
		iss.str(str);
		int val = 0;
		iss >> val;
		return (val);
	}

	float	toFloat(const std::string& str, std::istringstream& iss)
	{
		if (str == "nan" || str == "nanf")
			return (0.0 / 0.0);
		else if (str == "+inf" || str == "+inff")
			return (1.0 / 0.0);
		else if (str == "-inf" || str == "-inff")
			return (-1.0 / 0.0);
		std::string tmp = str;
		tmp.erase(tmp.length() - 1);
		iss.str(tmp);
		float val = 0.0f;
		iss >> val;
		return (val);
	}

	double	toDouble(const std::string& str, std::istringstream& iss)
	{
		if (str == "nan" || str == "nanf")
			return (0.0 / 0.0);
		else if (str == "+inf" || str == "+inff")
			return (1.0 / 0.0);
		else if (str == "-inf" || str == "-inff")
			return (-1.0 / 0.0);
		iss.str(str);
		double val = 0.0;
		iss >> val;
		return (val);
	}
}

void	ScalarConverter::convert(const std::string& str)
{
	e_type type = getType(str);
	std::istringstream iss;

	switch (type)
	{
		case CHAR:
			print::fromChar(convertStr::toChar(str));
			break ;
		case INT:
			print::fromInt(convertStr::toInt(str, iss), iss);
			break ;
		case FLOAT:
			print::fromFloat(convertStr::toFloat(str, iss), iss);
			break ;
		case DOUBLE:
			print::fromDouble(convertStr::toDouble(str, iss), iss);
			break ;
		case ERROR_NONPRINT:
			print::fromError(type);
			break ;
		case ERROR_TYPE:
			print::fromError(type);
	}
}
