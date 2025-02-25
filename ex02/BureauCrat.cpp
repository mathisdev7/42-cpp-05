/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureauCrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:15:53 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 21:11:14 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

BureauCrat::BureauCrat(std::string name, int grade) : _name(name)
{
	if (checkGrade(grade))
		this->_grade = grade;
	std::cout << "BureauCrat Default Constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

BureauCrat::BureauCrat(int grade) : _name("default")
{
	if (checkGrade(grade))
		this->_grade = grade;
	std::cout << "BureauCrat Default Constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

BureauCrat::BureauCrat(const BureauCrat &src)
{
	std::cout << "BureauCrat Copy Constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
	*this = src;
}

BureauCrat::BureauCrat(std::string name) : _name(name), _grade(150)
{
	std::cout << "BureauCrat Default Constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

BureauCrat::BureauCrat(void) : _name("default"), _grade(150)
{
	std::cout << "BureauCrat Default Constructor called for " << this->getName() << " with grade of " << this->getGrade() << std::endl;
}

/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

BureauCrat::~BureauCrat()
{
	std::cout << "BureauCrat Default Destructor called" << std::endl;
}

/*
** --------------------------------- OVERLOAD ---------------------------------
*/

BureauCrat &BureauCrat::operator=(BureauCrat const &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
}

std::ostream &operator<<(std::ostream &o, BureauCrat const &i)
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

bool BureauCrat::checkGrade(int grade)
{
	if (grade < 1)
		throw BureauCrat::GradeTooHighException();
	else if (grade > 150)
		throw BureauCrat::GradeTooLowException();
	return (true);
}

void BureauCrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << this->getName() << " couldn’t sign " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

void BureauCrat::executeForm(Form &form) const
{
	form.execute(*this);
}

bool BureauCrat::incrementGrade()
{
	int newGrade = this->getGrade() - 1;
	if (newGrade < 1)
		throw BureauCrat::GradeTooHighException();
	else if (newGrade > 150)
		throw BureauCrat::GradeTooLowException();
	this->_grade--;
	return (true);
}

bool BureauCrat::decrementGrade()
{
	int newGrade = this->getGrade() + 1;
	if (newGrade < 1)
		throw BureauCrat::GradeTooHighException();
	else if (newGrade > 150)
		throw BureauCrat::GradeTooLowException();
	this->_grade++;
	return (true);
}

std::string BureauCrat::getName() const
{
	return (this->_name);
}

int BureauCrat::getGrade() const
{
	return (this->_grade);
}

const char *BureauCrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low");
};

const char *BureauCrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high");
};

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

/* ************************************************************************** */
