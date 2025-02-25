/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:49:48 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 22:03:02 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "BureauCrat.hpp"
#include "Form.hpp"
#include <cstdlib>
#include <iostream>
#include <string>

class BureauCrat;

class From;

class RobotomyRequestForm : public Form
{
private:
	const std::string _target;
	RobotomyRequestForm(void);

public:
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(RobotomyRequestForm &src);

	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
	static Form *makeForm(Form *form, std::string const &type, std::string const &target);
	void execute(BureauCrat const &executor) const;
	void beExecuted(BureauCrat const &bureaucrat) const;
	std::string const &getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, RobotomyRequestForm *a);
