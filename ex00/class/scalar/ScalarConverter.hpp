/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:06:24 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/11 13:41:14 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_CONVERTER_HPP
# define SCALAR_CONVERTER_HPP

# include <string>

class ScalarConverter
{
	public:
		static void convert(const std::string& str);
	
	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter& cpy);
		ScalarConverter& operator=(const ScalarConverter& cpy);
		~ScalarConverter();

};

#endif
