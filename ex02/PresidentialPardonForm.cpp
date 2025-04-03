/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 18:04:17 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 16:36:49 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string Target) : AForm("PresidentialPardonForm", 25, 5), _name("PresidentialPardonForm"), _target(Target), _required_to_sign(25), _required_to_execute(5) {

	std::cout << "PresidentialPardonForm Default constructor called" << std::endl;
	
	return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &copy) : AForm(copy), _name(copy._name), _target(copy._target), _required_to_sign(copy._required_to_sign), _required_to_execute(copy._required_to_execute) {

	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		*this = copy;
	}
	
	return ;
}

PresidentialPardonForm	&PresidentialPardonForm::operator=(PresidentialPardonForm const &assign) {

	std::cout << "Operator = called" << std::endl;
	if (this != &assign) 
	{
		_signed = assign._signed;
	}

	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm() {

	std::cout << "Presidential destructor called" << std::endl;
	return ;
}

void	PresidentialPardonForm::ability(Bureaucrat const & executor) const {
	
	if (executor.getGrade() <= _required_to_execute)
		std::cout << "informs that " <<  _target << " has been pardoned by Zaphod Beeblebro" << std::endl;
	else
		throw GradeTooLowException();

	return ;
}