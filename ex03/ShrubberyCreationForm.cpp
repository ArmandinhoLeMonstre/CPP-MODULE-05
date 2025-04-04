/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:03:52 by armitite          #+#    #+#             */
/*   Updated: 2025/04/04 13:28:33 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string Target) : AForm("ShrubberyCreationForm", 145, 137), _name("ShrubberyCreationForm"), _target(Target), _required_to_sign(137), _required_to_execute(45) {

	std::cout << "ShrubberyCreationForm Default constructor called" << std::endl;
	
	return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &copy) : AForm(copy), _name(copy._name), _target(copy._target), _required_to_sign(copy._required_to_sign), _required_to_execute(copy._required_to_execute) {

	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		*this = copy;
	}
	
	return ;
}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=(ShrubberyCreationForm const &assign) {

	std::cout << "Operator = called" << std::endl;
	if (this != &assign) 
	{
		_signed = assign._signed;
	}

	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {

	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
	
	return ;
}


void	ShrubberyCreationForm::ability(Bureaucrat const & executor) const {
	
	if (executor.getGrade() <= _required_to_execute)
	{
		std::ofstream	ofs(_target.c_str());
		if (ofs.is_open())
		{
			ofs << "    ###\n   #o###\n #####o###\n#o#\\#|#/###\n ###\\|/#o#\n  # }|{  #\n    }|{\n";
			ofs.close();
		}
		else
			throw GradeTooLowException();
	}
	else
		throw GradeTooLowException();

	return ;
}