/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:36:26 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 01:20:08 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("RobotomyRequestForm[default_target]", "default_target", 145, 137) {};
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target): AForm(std::string("ShrubberyCreationForm").append("[").append(target).append("]"), target, 145, 137) {};
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other): AForm(other) {};
ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
	std::cout << "Destroying::ShrubberyCreationForm(" << getName() << ")" << std::endl;
};

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	AForm::operator=(other);
	return (*this);
};

void					ShrubberyCreationForm::execute(const Bureaucrat &bureucrat)
{
	if (bureucrat.getGrade() > getMinGradeToExecute()) throw GradeTooLowException();
	if (!getIsSigned()) throw FormNotSignedException();
	std::string		file_name = getTarget().substr(0, getTarget().length());
	std::ofstream	file(file_name.append("_shrubbery").c_str(), std::ios::app);
	if (!file.is_open())
	{
		std::cerr << "Error: Unalble to open the file " << file_name << std::endl;
		return ;
	}
	file << "Tree(" << getTarget() << ")" << std::endl;
	file.close();
};
