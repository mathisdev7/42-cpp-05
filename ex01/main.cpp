/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:19 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 21:00:35 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"
#include "Form.hpp"
#include <iostream>

void	printFormStatus(const Form &form)
{
	std::cout << "\n-------------- FORM STATUS --------------\n";
	std::cout << form << std::endl;
	std::cout << "-----------------------------------------\n";
}

int	main(void)
{
	try
	{
		BureauCrat bureaucrat1("Alice", 42);
		BureauCrat bureaucrat2("Bob", 150);
		BureauCrat bureaucrat3("Charlie", 1);
		Form form1("Form1", 43, 30);
		Form form2("Form2", 100, 80);
		std::cout << "-------------- INITIAL STATUS --------------\n";
		printFormStatus(form1);
		printFormStatus(form2);
		std::cout << "\nAlice (Grade 42) attempts to sign Form1:\n";
		bureaucrat1.signForm(form1);
		printFormStatus(form1);
		std::cout << "\nBob (Grade 150) attempts to sign Form2:\n";
		bureaucrat2.signForm(form2);
		printFormStatus(form2);
		std::cout << "\nCharlie (Grade 1) attempts to sign Form1:\n";
		bureaucrat3.signForm(form1);
		printFormStatus(form1);
	}
	catch (const std::exception &e)
	{
		std::cout << "\nException caught: " << e.what() << std::endl;
	}
	return (0);
}
