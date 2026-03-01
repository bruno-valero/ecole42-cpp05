/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 22:02:31 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 22:58:39 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::Form(void): _name("form_default"), _is_signed(false), _min_grade_to_sign(3), _min_grade_to_execute(2) {};
Form::Form(const std::string &name, int grade_to_sign, int grade_to_execute): _name(name), _is_signed(false), _min_grade_to_sign(grade_to_sign), _min_grade_to_execute(grade_to_execute)
{
	if (_min_grade_to_sign < 1 || _min_grade_to_execute < 1) throw GradeTooHighException();
	if (_min_grade_to_sign > 150 || _min_grade_to_execute > 150) throw GradeTooLowException();
};

Form::Form(const Form &other): _name(other._name), _is_signed(other._is_signed), _min_grade_to_sign(other._min_grade_to_sign), _min_grade_to_execute(other._min_grade_to_execute) {};
Form::~Form(void)
{
	std::cout << "Destroying::Form(" << _name << ")" << std::endl;
};

Form	&Form::operator=(const Form &other)
{
	_is_signed = other._is_signed;
	return (*this);
};

const std::string	&Form::getName(void) const
{
	return (_name);
};

unsigned short		Form::getIsSigned(void) const
{
	return (_is_signed);
};

unsigned short		Form::getMinGradeToSign(void) const
{
	return (_min_grade_to_sign);
};

unsigned short		Form::getMinGradeToExecute(void) const
{
	return (_min_grade_to_execute);
};

void				Form::beSigned(const Bureaucrat &bureucrat)
{
	if (bureucrat.getGrade() > _min_grade_to_sign) throw GradeTooLowException();
	_is_signed = true;
};

const char	*Form::GradeTooHighException::what() const throw()
{
	return ("Grade is too high!");
}

const char	*Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too low!");
}

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "[ \n  " << form.getName()
		<< " formulário "
		<< (form.getIsSigned() ? "assinado." : "não assinado.") << std::endl
		<< "  Cuja classificação mínima para assinatura é " << form.getMinGradeToSign() << ";" << std::endl
		<< "  E cuja classificação mínima para execussão é " << form.getMinGradeToExecute() << "\n]";
	return (os);
}

