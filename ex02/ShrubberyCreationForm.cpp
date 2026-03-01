/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:36:26 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 00:19:09 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
# include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void): AForm("brunofer", 145, 137) {};
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &name): AForm(name, 145, 137) {};
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
	std::string		file_name = getName().substr(0, getName().length());
	std::ofstream	file(file_name.append("_shrubbery").c_str(), std::ios::app);
	if (!file.is_open())
	{
		std::cerr << "Error: Unalble to open the file " << file_name << std::endl;
		return ;
	}
	file << "Tree(" << getName() << ")" << std::endl;
	file.close();
};
