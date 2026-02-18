/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlouis <mlouis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/16 10:36:35 by mlouis            #+#    #+#             */
/*   Updated: 2026/02/18 12:59:34 by mlouis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

unsigned bounded_rand(unsigned range)
{
	unsigned x, r;
	while (1)
	{
		x = rand();
		r = x % range;
		if (x -r <= -range)
			return (r);
	}
}

Base*	generate()
{
	Base* base;
	unsigned	rng = bounded_rand(3);
	switch	(rng)
	{
		case 0:
			base = new A();
			// std::cout << "new A" << std::endl;
			break ;
		case 1:
			base = new B();
			// std::cout << "new B" << std::endl;
			break ;
		case 2:
			base = new C();
			// std::cout << "new C" << std::endl;
			break ;
		default:
			base = 0;
			// std::cout << "Nothing\n";
	}
	return (base);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else if (dynamic_cast<C*>(p))
		std::cout << "C";
}

void	identify(Base& p)
{
	try
	{
		A a = dynamic_cast<A&>(p);
		static_cast<void>(a);
		std::cout << "A";
	}
	catch (const std::exception& e)
	{
		// std::cout << "error (not A): " << e.what() << std::endl;
	}

	try
	{
		B b = dynamic_cast<B&>(p);
		static_cast<void>(b);
		std::cout << "B";
	}
	catch (const std::exception& e)
	{
		// std::cout << "error (not B): " << e.what() << std::endl;
	}

	try
	{
		C c = dynamic_cast<C&>(p);
		static_cast<void>(c);
		std::cout << "C";
	}
	catch (const std::exception& e)
	{
		// std::cout << "error (not C): " << e.what() << std::endl;
	}
}

int	main()
{
	std::srand(std::time(0));

	Base *guess = generate();
	std::cout << "ptr= ";
	identify(guess);
	std::cout << std::endl;

	std::cout << "ref= ";
	identify(*guess);
	std::cout << std::endl;

	delete guess;
}
