/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:17:25 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 21:48:47 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void): _name("brunofer"), _grade(1) {};
Bureaucrat::Bureaucrat(const std::string &name, int grade): _name(name)
{
	if (grade < 1) throw GradeTooHighException();
	if (grade > 150) throw GradeTooLowException();
	_grade = (unsigned short)grade;
};

Bureaucrat::Bureaucrat(const Bureaucrat &other): _name(other._name), _grade(other._grade) {};

Bureaucrat::~Bureaucrat(void)
{
	std::cout << "Destroying::Bureaucrat(" << _name << ")" << std::endl;
};

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	_grade = other._grade;
	return (*this);
};

const std::string	&Bureaucrat::getName(void) const
{
	return (_name);
};

unsigned short		Bureaucrat::getGrade(void) const
{
	return (_grade);
};

void				Bureaucrat::incremment(void)
{
	if (_grade - 1 < 1) throw GradeTooHighException();
	_grade--;
};

void				Bureaucrat::decremment(void)
{
	if (_grade + 1 > 150) throw GradeTooLowException();
	_grade++;
};

const char	*Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureucrat)
{
	os << bureucrat.getName() << ", burocrata com classificação " << bureucrat.getGrade();
	return (os);
};
