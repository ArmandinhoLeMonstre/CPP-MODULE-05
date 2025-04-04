/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:34:33 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 17:24:24 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string Target) : AForm("RobotomyRequestForm", 72, 45), _name("RobotomyRequestForm"), _target(Target), _required_to_sign(72), _required_to_execute(45) {

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

	std::cout << "RobotomyRequestForm destructor called" << std::endl;
	return ;
}


void	RobotomyRequestForm::ability(Bureaucrat const & executor) const {
	
	if (executor.getGrade() <= _required_to_execute)
	{
		std::srand(std::time(0));
		int num = (std::rand() % 100) + 1;
		if (num % 2 == 0)
			std::cout << "Makes some drilling noises... " << _target << " has been robotomized" << std::endl;
		else
			std::cout << "Robotomy failed !" << std::endl;
	}
	else
		throw GradeTooLowException();

	return ;
}