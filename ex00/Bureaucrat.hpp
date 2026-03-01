/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 21:04:26 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 21:40:05 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREUCRAT_HPP
# define BUREUCRAT_HPP

# include <string>
# include <iostream>

class Bureaucrat
{
private:
	const std::string	_name;
	unsigned short		_grade;
public:
	Bureaucrat(void);
	Bureaucrat(const std::string &name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat(void);
	Bureaucrat	&operator=(const Bureaucrat &other);
	const std::string	&getName(void) const;
	unsigned short		getGrade(void) const;
	void				incremment(void);
	void				decremment(void);

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

std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureucrat);

#endif
