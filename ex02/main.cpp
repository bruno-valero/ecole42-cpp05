/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 00:24:22 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 00:56:57 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

void	test1();
void	test2();
void	test3();
void	test4();

int main(void)
{
	test1();
	test2();
	test3();
	test4();
}

void	test1()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------" << std::endl;
		std::cout << "Try: sign and execute the first two Forms and fail the last one." << std::endl;
		Bureaucrat				brunofer("brunofer", 44);
		std::cout << brunofer << std::endl;
		ShrubberyCreationForm	creation("Eucalipto");
		RobotomyRequestForm		request("Bender do Futurama");
		PresidentialPardonForm	pardon("Ramsy Bolton");

		std::cout << creation << std::endl;
		std::cout << request << std::endl;
		std::cout << pardon << std::endl;

		brunofer.signForm(creation);
		brunofer.signForm(request);
		brunofer.signForm(pardon);

		std::cout << creation << std::endl;
		std::cout << request << std::endl;
		std::cout << pardon << std::endl;

		brunofer.executeForm(creation);
		brunofer.executeForm(creation);
		brunofer.executeForm(creation);
		brunofer.executeForm(request);
		brunofer.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test2()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------" << std::endl;
		std::cout << "Try: execute not signed Forms." << std::endl;
		Bureaucrat				brunofer("brunofer", 44);
		std::cout << brunofer << std::endl;
		ShrubberyCreationForm	creation("Eucalipto");
		RobotomyRequestForm		request("Bender do Futurama");
		PresidentialPardonForm	pardon("Ramsy Bolton");

		std::cout << creation << std::endl;
		std::cout << request << std::endl;
		std::cout << pardon << std::endl;

		brunofer.executeForm(creation);
		brunofer.executeForm(request);
		brunofer.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test3()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------" << std::endl;
		std::cout << "Try: sign all three Forms, but fail to execute the last one." << std::endl;
		Bureaucrat				littleFinger("littleFinger", 6);
		std::cout << littleFinger << std::endl;
		ShrubberyCreationForm	creation("Limoeiro");
		RobotomyRequestForm		request("Asta la vista Baby");
		PresidentialPardonForm	pardon("Ramsy Bolton");

		std::cout << creation << std::endl;
		std::cout << request << std::endl;
		std::cout << pardon << std::endl;

		littleFinger.signForm(creation);
		littleFinger.signForm(request);
		littleFinger.signForm(pardon);

		std::cout << creation << std::endl;
		std::cout << request << std::endl;
		std::cout << pardon << std::endl;

		littleFinger.executeForm(creation);
		littleFinger.executeForm(creation);
		littleFinger.executeForm(creation);
		littleFinger.executeForm(request);
		littleFinger.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	test4()
{
	try
	{
		std::cout << "\n------------------------------------------------------------------" << std::endl;
		std::cout << "Try: sign and execute all three Forms." << std::endl;
		Bureaucrat				brunofer("brunofer", 5);
		std::cout << brunofer << std::endl;
		ShrubberyCreationForm	creation("Laranjeira");
		RobotomyRequestForm		request("T1000");
		PresidentialPardonForm	pardon("Sansa Stark");

		std::cout << creation << std::endl;
		std::cout << request << std::endl;
		std::cout << pardon << std::endl;

		brunofer.signForm(creation);
		brunofer.signForm(request);
		brunofer.signForm(pardon);

		std::cout << creation << std::endl;
		std::cout << request << std::endl;
		std::cout << pardon << std::endl;

		brunofer.executeForm(creation);
		brunofer.executeForm(creation);
		brunofer.executeForm(creation);
		brunofer.executeForm(request);
		brunofer.executeForm(pardon);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
