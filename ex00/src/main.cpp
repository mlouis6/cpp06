/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 11:02:05 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/11 13:46:26 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

int	main(int argc, char** argv)
{
	if (argc != 2)
	{
		std::cout << "Error\nProgram needs a single argument" << std::endl;
		return (1);
	}

	ScalarConverter::convert(argv[1]);	
	return (0);
}
