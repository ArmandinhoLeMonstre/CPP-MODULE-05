/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:37:27 by armitite          #+#    #+#             */
/*   Updated: 2025/04/04 14:40:31 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {

	std::cout << "Intern constructor called" << std::endl;

	return ;
}

Intern::Intern(Intern const &copy) {

	std::cout << "Intern copy constructor";
	if (this != &copy)
	{
		std::cout << "Nothing" << std::endl;
	}

	return ;
}

Intern&		Intern::operator=(Intern const &assign) {

	std::cout << "Operator = called" << std::endl;
	if (this != &assign)
	{
		std::cout << "Nothing" << std::endl;
	}

	return (*this);
}

Intern::~Intern() {

	std::cout << "Destructor" << std::endl;

	return ;
}

AForm*	Intern::newRobotomy(std::string target) {

	return (new RobotomyRequestForm(target));
}

AForm*	Intern::newPresidential(std::string target) {
	
	return (new PresidentialPardonForm(target));
}

AForm*	Intern::newShrubbery(std::string target) {

	return (new ShrubberyCreationForm(target));
}

AForm*	Intern::createForm(std::string name, std::string target) {

	std::string form_list[] = {
		"RobotomyForm",
		"PresidentialForm",
		"ShrubberyForm"
	};
	AForm* (Intern::*Form_Functions[]) (std::string) = {
		&Intern::newRobotomy, 
		&Intern::newPresidential, 
		&Intern::newShrubbery
	};
	for (int i = 0; i < 3; i++) {
		if (name == form_list[i])
		{
			return (this->*Form_Functions[i])(target);
		}
	}
	throw BadName();
	
	return (NULL);
}

AForm*	Intern::makeForm(std::string name, std::string target) {

	try
	{
		return (createForm(name, target));
		std::cout << "Intern creates : " << name << std::endl; 
	}
	catch (std::exception &e)
	{
		throw BadName();
	}

	return (NULL);
}