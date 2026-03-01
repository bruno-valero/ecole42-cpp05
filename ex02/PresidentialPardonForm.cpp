/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:36:26 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 00:09:32 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
# include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm(void): AForm("brunofer", 25, 5) {};
PresidentialPardonForm::PresidentialPardonForm(const std::string &name): AForm(name, 25, 5) {};
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other): AForm(other) {};
PresidentialPardonForm::~PresidentialPardonForm(void)
{
	std::cout << "Destroying::PresidentialPardonForm(" << getName() << ")" << std::endl;
};

PresidentialPardonForm	&PresidentialPardonForm::operator=(const PresidentialPardonForm &other)
{
	AForm::operator=(other);
	return (*this);
};

void					PresidentialPardonForm::execute(const Bureaucrat &bureucrat)
{
	if (bureucrat.getGrade() > getMinGradeToExecute()) throw GradeTooLowException();
	if (!getIsSigned()) throw FormNotSignedException();
	std::cout << getName() << "foi perdoado por Zaphod Beeblebrox" << std::endl;
};
