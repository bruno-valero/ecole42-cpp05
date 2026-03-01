/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:36:26 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 00:09:32 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
# include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm(void): AForm("RobotomyRequestForm[default_target]", "default_target", 72, 45) {};
RobotomyRequestForm::RobotomyRequestForm(const std::string &target): AForm(std::string("RobotomyRequestForm").append("[").append(target).append("]"), target, 72, 45) {};
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other): AForm(other) {};
RobotomyRequestForm::~RobotomyRequestForm(void)
{
	std::cout << "Destroying::RobotomyRequestForm(" << getName() << ")" << std::endl;
};

RobotomyRequestForm	&RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	AForm::operator=(other);
	return (*this);
};

void					RobotomyRequestForm::execute(const Bureaucrat &bureucrat)
{
	if (bureucrat.getGrade() > getMinGradeToExecute())
	{
		std::cerr << "robotomia falhou." << std::endl;
		throw GradeTooLowException();
	}
	if (!getIsSigned())
	{
		std::cerr << "robotomia falhou." << std::endl;
		throw FormNotSignedException();
	}
	std::cout << "RrrrrrRRRrrrRRR! ";
	std::cout << getTarget() << " foi robotomizado com sucesso!" << std::endl;
};

AForm					*RobotomyRequestForm::clone(const char *target) const
{
	if (!target)
		return (new RobotomyRequestForm(*this));
	return (new RobotomyRequestForm(target));
};
