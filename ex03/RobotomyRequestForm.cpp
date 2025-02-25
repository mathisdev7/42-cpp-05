/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:53:56 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 22:03:18 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 72,
												  45),
											 _target("default")
{
	std::cout << "RobotomyRequestForm Default Constructor called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm",
																	72, 45),
															   _target(target)
{
	std::cout << "RobotomyRequestForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm &src) : Form("RobotomyRequestForm",
																		  72, 45),
																	 _target(src.getTarget())
{
	std::cout << "RobotomyRequestForm Copy Constructor called to copy " << src.getName() << " into " << this->getName() << std::endl;
	*this = src;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm Deconstructor " << this->getName() << " called" << std::endl;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &src)
{
	std::cout << "RobotomyRequestForm Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

static int robot_fail = 0;

void RobotomyRequestForm::execute(BureauCrat const &executor) const
{
	Form::execute(executor);
}

void RobotomyRequestForm::beExecuted(BureauCrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw(BureauCrat::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		throw(Form::FormNotSignedException());
	else if (robot_fail++ % 2)
		std::cout << this->getTarget() << " got robotomized" << std::endl;
	else
		std::cout << "Robotomy failed" << std::endl;
}

Form *RobotomyRequestForm::makeForm(Form *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "robotomy request")
		return (new RobotomyRequestForm(target));
	return (form);
}

std::string const &RobotomyRequestForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &str, RobotomyRequestForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSignedBool() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
