/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:43:50 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 22:04:23 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <stdexcept>

// ---------------------------------- CONSTRUCTORS ----------------------------------

Form::Form(void) : _name("Untitled"), _signed(false), _sign_grade(1),
				   _exec_grade(1)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(const Form &src) : _name(src._name), _signed(src._signed),
							  _sign_grade(src._sign_grade), _exec_grade(src._exec_grade)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(int sign_grade, int exec_grade) : _name("Untitled"), _signed(false),
											 _sign_grade(sign_grade), _exec_grade(exec_grade)
{
	if (checkGrade(sign_grade) && checkGrade(exec_grade))
		std::cout << "Form created with sign_grade: " << sign_grade << " and exec_grade: " << exec_grade << std::endl;
}

Form::Form(const std::string name) : _name(name), _signed(false),
									 _sign_grade(1), _exec_grade(1)
{
	std::cout << "Form constructor with name called" << std::endl;
}

Form::Form(const std::string name, int sign_grade,
		   int exec_grade) : _name(name), _signed(false), _sign_grade(sign_grade),
							 _exec_grade(exec_grade)
{
	if (checkGrade(sign_grade) && checkGrade(exec_grade))
		std::cout << "Form created with name: " << name << ", sign_grade : " << sign_grade << " and exec_grade : " << exec_grade << std::endl;
}

// ---------------------------------- DESTRUCTOR ----------------------------------

Form::~Form()
{
	std::cout << "Form destructor called for " << _name << std::endl;
}

// ---------------------------------- OPERATOR OVERLOAD ----------------------------------

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		_signed = rhs._signed;
	}
	return (*this);
}

std::ostream &operator<<(std::ostream &o, const Form &i)
{
	o << "Form Name: " << i.getName() << "\n"
	  << "Signed: " << (i.getSignedStatus() ? "Yes" : "No") << "\n"
	  << "Sign Grade: " << i.getSignGrade() << "\n"
	  << "Execution Grade: " << i.getExecGrade();
	return (o);
}

// ---------------------------------- MEMBER FUNCTIONS ----------------------------------

std::string Form::getName() const
{
	return (_name);
}

bool Form::getSignedStatus() const
{
	return (_signed);
}

int Form::getSignGrade() const
{
	return (_sign_grade);
}

int Form::getExecGrade() const
{
	return (_exec_grade);
}

bool Form::getIsSignedBool(void) const
{
	return (this->_signed);
}

bool Form::beSigned(BureauCrat &signer)
{
	if (signer.getGrade() > this->getSignGrade())
		throw(Form::GradeTooLowException());
	else if (this->getSignedStatus() == false)
	{
		this->_signed = true;
		std::cout << this->getName() << " Form was signed by " << signer.getName() << std::endl;
		return (true);
	}
	else
		std::cout << this->getName() << " Form is already signed" << std::endl;
	throw Form::FormAlreadySignedException();
}

bool Form::checkGrade(int grade) const
{
	if (grade < 1)
		throw Form::GradeTooHighException();
	else if (grade > 150)
		throw Form::GradeTooLowException();
	return (true);
}

Form *Form::makeForm(const std::string &type, const std::string &target)
{
	Form *form;

	form = NULL;
	form = ShrubberyCreationForm::makeForm(form, type, target);
	form = RobotomyRequestForm::makeForm(form, type, target);
	form = PresidentialPardonForm::makeForm(form, type, target);
	return (form);
}

void Form::execute(BureauCrat const &executor) const
{
	if (!this->_signed)
		throw Form::FormNotSignedException();
	if (executor.getGrade() > this->_exec_grade)
		throw Form::GradeTooLowException();
	std::cout << executor.getName() << " executes form: " << this->_name << std::endl;
	this->beExecuted(executor);
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *Form::FormAlreadySignedException::what(void) const throw()
{
	return ("Form already signed");
};

const char *Form::FormNotSignedException::what(void) const throw()
{
	return ("Form not signed");
};

const char *Form::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

char const *Form::InvalidFormException::what(void) const throw()
{
	return ("Invalid Form Request");
}
