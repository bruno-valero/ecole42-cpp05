/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:53:56 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 22:48:21 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include <string>
# include <iostream>

class Bureaucrat;

class AForm
{
private:
	const std::string		_name;
	const std::string		_target;
	bool					_is_signed;
	const unsigned short	_min_grade_to_sign;
	const unsigned short	_min_grade_to_execute;

public:
	AForm(void);
	AForm(const std::string &name, const std::string &target, int grade_to_sign, int grade_to_execute);
	AForm(const AForm &name);
	~AForm(void);
	AForm	&operator=(const AForm &name);

	const std::string	&getName(void) const;
	const std::string	&getTarget(void) const;
	unsigned short		getIsSigned(void) const;
	unsigned short		getMinGradeToSign(void) const;
	unsigned short		getMinGradeToExecute(void) const;

	void				beSigned(const Bureaucrat &bureucrat);
	virtual void		execute(const Bureaucrat &bureucrat) = 0;

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

	class FormNotSignedException: public std::exception
	{
		public:
			const char	*what(void) const throw();
	};
};

std::ostream	&operator<<(std::ostream &os, const AForm &aform);

#endif
