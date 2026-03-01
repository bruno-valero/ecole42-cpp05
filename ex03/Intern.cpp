/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 18:08:11 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 19:02:40 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

const std::string	Intern::_forms[Intern::_forms_amount] = {"pedido de robotomia", "criação de arbustos", "perdão presidencial"};
AForm				* const Intern::_formFactory[Intern::_forms_amount] = {new RobotomyRequestForm(), new ShrubberyCreationForm(), new PresidentialPardonForm()};

Intern::Intern(void) {};
Intern::Intern(const Intern &other) {(void)other;};
Intern::~Intern(void)
{
	std::cout << "Destroying::Intern()" << std::endl;
	for (short i = 0; i < Intern::_forms_amount; i++)
		if (Intern::_formFactory[i])
			delete Intern::_formFactory[i];
};

Intern	&Intern::operator=(const Intern &other) {
	(void)other;
	return (*this);
};

AForm	*Intern::makeForm(const std::string &form_name, const std::string &target) const
{
	for (short i = 0; i < Intern::_forms_amount; i++)
		if (Intern::_forms[i] == form_name)
			return (Intern::_formFactory[i]->clone(target.c_str()));
	throw AForm::InvalidFormException();
};
