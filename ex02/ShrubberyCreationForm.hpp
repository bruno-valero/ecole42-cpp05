/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bruno-valero <bruno-valero@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 23:26:57 by bruno-valer       #+#    #+#             */
/*   Updated: 2026/02/28 23:49:12 by bruno-valer      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"
# include <fstream>

class ShrubberyCreationForm: public AForm
{
private:

public:
	ShrubberyCreationForm(void);
	ShrubberyCreationForm(const std::string &name);
	ShrubberyCreationForm(const ShrubberyCreationForm &other);
	~ShrubberyCreationForm(void);
	ShrubberyCreationForm	&operator=(const ShrubberyCreationForm &other);
	void					execute(const Bureaucrat &bureucrat);
};

#endif
