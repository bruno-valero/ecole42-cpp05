/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:53:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 22:48:21 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class Form
{
private:
	const std::string		_name;
	bool					_is_signed;
	const unsigned short	_min_grade_to_sign;
	const unsigned short	_min_grade_to_execute;

public:
	Form(void);
	Form(const std::string &name, int grade_to_sign, int grade_to_execute);
	Form(const Form &name);
	~Form(void);
	Form	&operator=(const Form &name);

	const std::string	&getName(void) const;
	unsigned short		getIsSigned(void) const;
	unsigned short		getMinGradeToSign(void) const;
	unsigned short		getMinGradeToExecute(void) const;

	void				beSigned(const Bureaucrat &bureucrat);

	class GradeTooHighException: public std::exception
	{
		public:
			const char	*what(void) const throw();
	};

	class GradeTooLowException: public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif
