/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:43:44 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 22:02:52 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>
#include <string>

class BureauCrat;

class Form
{
protected:
	const std::string _name;
	bool _signed;
	const int _sign_grade;
	const int _exec_grade;
	Form(void);
	Form(int sign_grade, int exec_grade);
	Form(const std::string name);
	Form(const std::string name, int sign_grade, int exec_grade);

public:
	Form(const Form &src);

	virtual ~Form();

	Form &operator=(const Form &src);
	static Form *makeForm(std::string const &type, std::string const &target);
	bool checkGrade(int grade) const;
	void execute(BureauCrat const &executor) const;
	std::string getName() const;
	bool getSignedStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool getIsSignedBool(void) const;
	virtual void beExecuted(BureauCrat const &bureaucrat) const = 0;
	virtual std::string const &getTarget(void) const = 0;

	bool beSigned(BureauCrat &signer);

	class GradeTooLowException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
	class GradeTooHighException : public std::exception
	{
	public:
		const char *what(void) const throw();
	};
	class FormAlreadySignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class FormNotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
	class InvalidFormException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

std::ostream &operator<<(std::ostream &str, Form const &form);
