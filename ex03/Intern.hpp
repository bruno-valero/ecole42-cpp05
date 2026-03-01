/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/01 16:58:17 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/03/01 18:44:48 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "PresidentialPardonForm.hpp"

class Intern
{
private:
	static const short			_forms_amount = 3;
	static const std::string	_forms[_forms_amount];
	static AForm				* const _formFactory[_forms_amount];
public:
	Intern(void);
	Intern(const Intern &other);
	~Intern(void);
	Intern	&operator=(const Intern &other);
	AForm	*makeForm(const std::string &form_name, const std::string &target) const;
};

#endif
