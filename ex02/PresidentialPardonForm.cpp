/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:00:13 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 21:59:56 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm",
														25, 5),
												   _target("default")
{
	std::cout << "PresidentialPardonForm Default Constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm",
																		  25, 5),
																	 _target(target)
{
	std::cout << "PresidentialPardonForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm &src) : Form("PresidentialPardonForm",
																				   25, 5),
																			  _target(src.getTarget())
{
	std::cout << "PresidentialPardonForm Copy Constructor called to copy " << src.getName() << " into " << this->getName() << std::endl;
	*this = src;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm Deconstructor " << this->getName() << " called" << std::endl;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	std::cout << "PresidentialPardonForm Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void PresidentialPardonForm::execute(BureauCrat const &executor) const
{
	if (executor.getGrade() > this->getExecGrade())
		throw(BureauCrat::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		throw(Form::FormNotSignedException());
	else
		std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

std::string PresidentialPardonForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &str, PresidentialPardonForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSignedBool() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
