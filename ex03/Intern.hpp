/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:33:08 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 21:33:17 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

class Form;

class Intern
{
public:
	Intern(void);
	Intern(Intern const &copy);
	~Intern(void);

	Intern const &operator=(Intern const &copy);

	Form *makeForm(std::string const &type, std::string const &target);
};
