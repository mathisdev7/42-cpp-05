/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 21:51:13 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/27 14:38:40 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"
#include "Form.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main(void)
{
	Intern	bob;
	Form	*form;
		delete form;
		delete form;
		delete form;
		delete form;
	delete	form;
	delete	form;

	BureauCrat karen("Karen", 50);
	// Test how all forms are created properly except for the last one
	try
	{
		form = bob.makeForm("robotomy request", "Alice");
		form = bob.makeForm("shrubbery creation", "Charlie");
		form = bob.makeForm("presidential pardon", "David");
		form = bob.makeForm("random request", "Elisa");
	}
	catch (std::exception &e)
	{
		std::cout << "Caught exception: " << e.what() << std::endl;
	}
	// Test some Actions with available form
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("shrubbery creation", "Fred");
	form->beSigned(karen);
	karen.executeForm(*form);
	std::cout << "------------------------------------" << std::endl;
	form = bob.makeForm("presidential pardon", "Georgia");
	karen.signForm(*form);
	karen.executeForm(*form);
	return (0);
}
