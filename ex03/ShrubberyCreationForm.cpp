/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mazeghou <mazeghou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 20:56:06 by mazeghou          #+#    #+#             */
/*   Updated: 2025/02/25 22:03:42 by mazeghou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm",
													  145, 137),
												 _target("default")
{
	std::cout << "ShrubberyCreationForm Default Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm",
																		145, 137),
																   _target(target)
{
	std::cout << "ShrubberyCreationForm Constructor for target " << this->getTarget() << " called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm &src) : Form("ShrubberyCreationForm",
																				145, 137),
																		   _target(src.getTarget())
{
	std::cout << "ShrubberyCreationForm Copy Constructor called to copy " << src.getName() << " into " << this->getName() << std::endl;
	*this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm Deconstructor " << this->getName() << " called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	std::cout << "ShrubberyCreationForm Assignation operator called" << std::endl;
	if (this == &src)
		return (*this);
	return (*this);
}

void ShrubberyCreationForm::execute(BureauCrat const &executor) const
{
	Form::execute(executor);
}

void ShrubberyCreationForm::beExecuted(BureauCrat const &bureaucrat) const
{
	if (bureaucrat.getGrade() > this->getExecGrade())
		throw(BureauCrat::GradeTooLowException());
	else if (this->getIsSignedBool() == false)
		throw(Form::FormNotSignedException());
	else
	{
		std::string filename = this->getTarget() + "_shrubbery";
		std::ofstream outfile(filename.c_str());

		for (int i = 0; i < 5; i++)
		{
			outfile << "         v" << std::endl
					<< "        >X<" << std::endl
					<< "         A" << std::endl
					<< "        d$b" << std::endl
					<< "      .d\\$$b." << std::endl
					<< "    .d$i$$\\$$b." << std::endl
					<< "       d$$@b" << std::endl
					<< "      d\\$$$ib" << std::endl
					<< "    .d$$$\\$$$b" << std::endl
					<< "  .d$$@$$$$\\$$ib." << std::endl
					<< "      d$$i$$b" << std::endl
					<< "     d\\$$$$@$b" << std::endl
					<< "  .d$@$$\\$$$$$@b." << std::endl
					<< ".d$$$$i$$$\\$$$$$$b." << std::endl
					<< "        ###" << std::endl
					<< "        ###" << std::endl
					<< "        ###" << std::endl
					<< std::endl;
		}
		outfile.close();
	}
}

Form *ShrubberyCreationForm::makeForm(Form *form, std::string const &type, std::string const &target)
{
	if (form == NULL && type == "shrubbery creation")
		return (new ShrubberyCreationForm(target));
	return (form);
}

std::string const &ShrubberyCreationForm::getTarget(void) const
{
	return (this->_target);
}

std::ostream &operator<<(std::ostream &str, ShrubberyCreationForm const &form)
{
	return (str << form.getName() << " form, signed: " << form.getIsSignedBool() << ", sign grade: " << form.getSignGrade() << ", exec grade: " << form.getExecGrade());
}
