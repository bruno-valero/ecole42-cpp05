/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:02:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 22:58:39 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(void): _name("aform_default"), _target("default_target"), _is_signed(false), _min_grade_to_sign(3), _min_grade_to_execute(2) {};
AForm::AForm(const std::string &name, const std::string &target, int grade_to_sign, int grade_to_execute): _name(name), _target(target), _is_signed(false), _min_grade_to_sign(grade_to_sign), _min_grade_to_execute(grade_to_execute)
{
	if (_min_grade_to_sign < 1 || _min_grade_to_execute < 1) throw GradeTooHighException();
	if (_min_grade_to_sign > 150 || _min_grade_to_execute > 150) throw GradeTooLowException();
};

AForm::AForm(const AForm &other): _name(other._name), _is_signed(other._is_signed), _min_grade_to_sign(other._min_grade_to_sign), _min_grade_to_execute(other._min_grade_to_execute) {};
AForm::~AForm(void)
{
	std::cout << "Destroying::AForm(" << _name << ")" << std::endl;
};

AForm	&AForm::operator=(const AForm &other)
{
	_is_signed = other._is_signed;
	return (*this);
};

const std::string	&AForm::getName(void) const
{
	return (_name);
};

const std::string	&AForm::getTarget(void) const
{
	return (_target);
};

unsigned short		AForm::getIsSigned(void) const
{
	return (_is_signed);
};

unsigned short		AForm::getMinGradeToSign(void) const
{
	return (_min_grade_to_sign);
};

unsigned short		AForm::getMinGradeToExecute(void) const
{
	return (_min_grade_to_execute);
};

void				AForm::beSigned(const Bureaucrat &bureucrat)
{
	if (bureucrat.getGrade() > _min_grade_to_sign) throw GradeTooLowException();
	_is_signed = true;
};

const char	*AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

const char	*AForm::FormNotSignedException::what() const throw()
{
	return ("Form is not signed!");
}

std::ostream	&operator<<(std::ostream &os, const AForm &aform)
{
	os << "[ \n  " << aform.getName()
		<< " formulário "
		<< (aform.getIsSigned() ? "assinado." : "não assinado.") << std::endl
		<< "  Cuja classificação mínima para assinatura é " << aform.getMinGradeToSign() << ";" << std::endl
		<< "  E cuja classificação mínima para execussão é " << aform.getMinGradeToExecute() << "\n]";
	return (os);
}

