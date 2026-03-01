/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:40:17 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 21:52:00 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	too_high("too_high", 0);
		std::cout << too_high << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	too_low("too_low", 151);
		std::cout << too_low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	brunofer("brunofer", 3);
		std::cout << brunofer << std::endl;
		brunofer.incremment();
		std::cout << brunofer << std::endl;
		Bureaucrat	stuntman("stuntman", 1);
		stuntman.incremment();
		std::cout << stuntman << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Bureaucrat	stuntman("stuntman", 15);
		std::cout << stuntman << std::endl;
		stuntman.incremment();
		std::cout << stuntman << std::endl;
		Bureaucrat	splinter_cell("splinter_cell", 149);
		std::cout << splinter_cell << std::endl;
		splinter_cell.decremment();
		std::cout << splinter_cell << std::endl;
		splinter_cell.decremment();
		std::cout << splinter_cell << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
