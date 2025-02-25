/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:43:03 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 20:51:21 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include "BureauCrat.hpp"
#include "Form.hpp"
#include <iostream>
#include <string>

class	BureauCrat;

class	From;

class PresidentialPardonForm : public Form
{
  private:
	const std::string _target;
	PresidentialPardonForm(void);

  public:
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(PresidentialPardonForm &src);

	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &src);

	void execute(BureauCrat const &executor) const;
	std::string getTarget(void) const;
};

std::ostream &operator<<(std::ostream &o, PresidentialPardonForm *a);
