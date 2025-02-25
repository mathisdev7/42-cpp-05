/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 14:17:19 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 15:10:15 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BureauCrat.hpp"

int main()
{
	try
	{
		BureauCrat b1("Alice", 42);
		BureauCrat b2("Bob", 1);
		BureauCrat b3("Charlie", 150);

		std::cout << "BureauCrat 1: " << b1 << std::endl;
		std::cout << "BureauCrat 2: " << b2 << std::endl;
		std::cout << "BureauCrat 3: " << b3 << std::endl;

		std::cout << "Incrémentation du grade de b1..." << std::endl;
		try
		{
			b1.incrementGrade();
			std::cout << "BureauCrat 1 après incrémentation: " << b1 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Erreur lors de l'incrémentation du grade: " << e.what() << std::endl;
		}

		std::cout << "Décrémentation du grade de b3..." << std::endl;
		try
		{
			b3.decrementGrade();
			std::cout << "BureauCrat 3 après décrémentation: " << b3 << std::endl;
		}
		catch (const std::exception &e)
		{
			std::cerr << "Erreur lors de la décrémentation du grade: " << e.what() << std::endl;
		}

		BureauCrat b4 = b2;
		std::cout << "Bureaucrat 4 (copie de Bob): " << b4 << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception lors de la création d'un BureauCrat: " << e.what() << std::endl;
	}

	try
	{
		BureauCrat b5("Invalid", 200);
	}
	catch (const std::exception &e)
	{
		std::cerr << "Exception lors de la création de 'Invalid': " << e.what() << std::endl;
	}

	return 0;
}
