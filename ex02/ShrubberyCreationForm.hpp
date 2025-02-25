/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:50:42 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 21:00:22 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "BureauCrat.hpp"
#include "Form.hpp"
#include <fstream>
#include <iostream>
#include <string>

class	BureauCrat;

class	From;

class ShrubberyCreationForm : public Form
{
  private:
	const std::string _target;
	ShrubberyCreationForm(void);

  public:
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(ShrubberyCreationForm &src);

	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);

	void execute(BureauCrat const &executor) const;
	std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, ShrubberyCreationForm *a);
