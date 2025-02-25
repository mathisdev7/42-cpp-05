/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 15:43:44 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 21:43:47 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class BureauCrat;

class Form
{
private:
	const std::string _name;
	bool _signed;
	const int _sign_grade;
	const int _exec_grade;

public:
	Form(void);
	Form(const Form &src);
	Form(int sign_grade, int exec_grade);
	Form(const std::string name);
	Form(const std::string name, int sign_grade, int exec_grade);

	~Form();

	Form &operator=(const Form &);

	bool checkGrade(int grade) const;

	std::string getName() const;
	bool getSignedStatus() const;
	int getSignGrade() const;
	int getExecGrade() const;

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
};

std::ostream &operator<<(std::ostream &str, Form const &form);
