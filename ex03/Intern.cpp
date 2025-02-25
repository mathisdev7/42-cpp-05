/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:32:46 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 22:01:23 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(void) {}

Intern::Intern(Intern const &copy)
{
	*this = copy;
}

Intern::~Intern(void) {}

Intern const &Intern::operator=(const Intern &copy)
{
	(void)copy;
	return (*this);
}

Form *Intern::makeForm(const std::string &type, const std::string &target)
{
	Form *form;

	form = Form::makeForm(type, target);
	if (!form)
		throw(Form::InvalidFormException());
	else
		std::cout << "Intern creates form: " << form->getName() << " with target: " << form->getTarget() << std::endl;
	return (form);
}
