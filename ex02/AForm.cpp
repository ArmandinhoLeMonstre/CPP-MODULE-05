/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:44:42 by armitite          #+#    #+#             */
/*   Updated: 2025/04/02 19:21:05 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(std::string FormName, int to_sign, int to_execute) : _name(FormName), _required_to_sign(to_sign), _required_to_execute(to_execute) {

	std::cout << "Default constructor called" << std::endl;
	try 
	{
		if (to_sign > 150 || to_execute > 150)
		{
			throw GradeTooHighException();
		}
		else if (to_sign <= 0 || to_execute <= 0)
		{
			throw GradeTooLowException();
		}
		else
		{
			_signed = false;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception found during creation : " << e.what() << std::endl;
	}
	
	return ;
}

AForm::AForm(AForm const &copy) : _name(copy._name), _required_to_sign(copy._required_to_sign), _required_to_execute(copy._required_to_execute){

	std::cout << "Copy constructor called" << std::endl;
	if (this != &copy)
		*this = copy;
	
	return ;
}

AForm	&AForm::operator=(AForm const &assign) {

	std::cout << "Operator '=' called" << std::endl;
	if (this != &assign) {
		_signed = assign._signed;
	}

	return (*this);
}

AForm::~AForm() {

	std::cout << "Destructor called" << std::endl;
	
	return ;
}

int	const &AForm::getToSign() {

	return (_required_to_sign);
}

int	const &AForm::getToExecute() {

	return (_required_to_execute);
}

std::string const &AForm::getName() {

	return (_name);
}

bool const &AForm::getSignStatus() {

	return (_signed);
}

void	AForm::beSigned(Bureaucrat &Candidate) {

	try
	{
		TryToSign(Candidate);
		std::cout << Candidate.getName() << " signed " << getName() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << Candidate.getName() << " couldn't sign " << getName() << " because " << e.what() << std::endl;
	}
}

void	AForm::TryToSign(Bureaucrat &Candidate) {

	int grade = Candidate.getGrade();
	
	if (grade > _required_to_sign)
	{
		throw GradeTooLowException();
	}
	else
	{
		_signed = true;
	}
}

std::ostream &operator<<(std::ostream & o, AForm &assign) {

	o << assign.getName() << ", form To sign required is : " << assign.getToSign();
	o << ", form To execute required is : " << assign.getToExecute();
	o << ", form status is : " << assign.getSignStatus() << std::endl;
	
	return o;
}