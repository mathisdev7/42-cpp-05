/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BureauCrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:15:48 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 16:35:27 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "Form.hpp"
#include <string>
#include <cstdlib>

class BureauCrat
{

public:
	BureauCrat();
	BureauCrat(const BureauCrat &src);
	BureauCrat(int grade);
	BureauCrat(const std::string name);
	BureauCrat(const std::string name, int grade);
	~BureauCrat();
	BureauCrat &operator=(BureauCrat const &rhs);
	std::string getName() const;
	int getGrade() const;
	bool incrementGrade();
	bool decrementGrade();
	void signForm(Form &form);
	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

private:
	bool checkGrade(int grade);
	const std::string _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &o, BureauCrat const &i);
