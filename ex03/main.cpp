/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 00:24:22 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 20:32:54 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	Intern		bob;
	AForm		*form;
	Bureaucrat	karen("Karen", 50);

	std::cout << "\n------------------------------------------------------------------" << std::endl;
	std::cout << "Try: all forms are created properly execpt for the last one." << std::endl;
	try
	{
		form = bob.makeForm("pedido de robotomia", "Alice");
		std::cout << *form << std::endl;
		delete form;
		form = bob.makeForm("criação de arbustos", "Charlie");
		std::cout << *form << std::endl;
		delete form;
		form = bob.makeForm("perdão presidencial", "David");
		std::cout << *form << std::endl;
		delete form;
		form = bob.makeForm("pedido aleatório", "Elisa");
		std::cout << *form << std::endl;
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "\n**********************" << std::endl;
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "**********************" << std::endl;
	}

	try
	{
		std::cout << "\n------------------------------------------------------------------" << std::endl;
		std::cout << "Try: some Actions with available form." << std::endl;
		form = bob.makeForm("criação de arbustos", "Fred");
		std::cout << *form << std::endl;
		form->beSigned(karen);
		std::cout << *form << std::endl;
		karen.executeForm(*form);
		delete form;
		std::cout << "------------------------------------" << std::endl;
		form = bob.makeForm("perdão presidencial", "Georgia");
		std::cout << *form << std::endl;
		karen.signForm(*form);
		std::cout << *form << std::endl;
		karen.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << "\n**********************" << std::endl;
		std::cout << "Caught exception: " << e.what() << std::endl;
		std::cout << "**********************" << std::endl;
	}
	return (0);
}
