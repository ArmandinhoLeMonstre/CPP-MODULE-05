/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:34:33 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 14:35:05 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("RobotomyRequestForm", 25, 5), _name("RobotomyRequestForm"), _target(Target), _required_to_sign(25), _required_to_execute(5) {

	std::cout << "RobotomyRequestForm Default constructor called" << std::endl;
	
	return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &copy) : AForm(copy), _name(copy._name), _target(copy._target), _required_to_sign(copy._required_to_sign), _required_to_execute(copy._required_to_execute) {

	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
	{
		*this = copy;
	}
	
	return ;
}

RobotomyRequestForm	&RobotomyRequestForm::operator=(RobotomyRequestForm const &assign) {

	std::cout << "Operator = called" << std::endl;
	if (this != &assign) 
	{
		_signed = assign._signed;
	}

	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm() {

	return ;
}

void 	RobotomyRequestForm::execute(Bureaucrat const & executor) const {

	try
	{
		ability(executor);
	}
	catch (std::exception &e)
	{
		throw GradeTooLowException();
	}

	return ;
}

void	RobotomyRequestForm::ability(Bureaucrat const & executor) const {
	
	if (executor.getGrade() <= _required_to_execute)
		std::cout << "informs that " <<  _target << " has been pardoned by Zaphod Beeblebro" << std::endl;
	else
		throw GradeTooLowException();

	return ;
}