/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:39:39 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 23:03:06 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		std::cout << "\ntry with too_high:" << std::endl;
		Form	too_high("form_too_high", 0, 10);
		std::cout << too_high << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\ntry with too_low:" << std::endl;
		Form	too_low("form_too_low", 15, 151);
		std::cout << too_low << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\ntry signament not allowed:" << std::endl;
		Form	form("form_to_sigh", 5, 2);
		std::cout << form << std::endl;
		Bureaucrat	cannot_sign("brunofer", 6);
		std::cout << cannot_sign << std::endl;
		cannot_sign.signForm(form);
		std::cout << form << std::endl;
		std::cout << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		std::cout << "\ntry signing successfully:" << std::endl;
		Form	form("form_to_sigh", 5, 2);
		std::cout << form << std::endl;
		Bureaucrat	can_sign("La Place", 5);
		std::cout << can_sign << std::endl;
		can_sign.signForm(form);
		std::cout << form << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
}
