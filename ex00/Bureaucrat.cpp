/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:23:06 by armitite          #+#    #+#             */
/*   Updated: 2025/03/31 16:09:10 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string const name, int grade) : _name(name) {

	std::cout << "Constructor called" << std::endl;
	
	try 
	{
		if (grade > 150)
		{
			throw GradeTooHighException();
		}
		else if (grade <= 0)
		{
			throw GradeTooLowException();
		}
		else
			_grade = grade;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception found : " << e.what() << std::endl;
	}
	
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) {

	std::cout << "Copy constructor called" << std::endl;
	*this = copy;

	return ;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &assign) {

	std::cout << "Operator '=' called" << std::endl;
	if (this != &assign)
	{
		_grade = assign._grade;
	}

	return (*this);
}

Bureaucrat::~Bureaucrat () {

	std::cout << "Destructor Called" << std::endl;

	return ;
}

int	&Bureaucrat::getGrade() {

	return (_grade);
}

std::string const &Bureaucrat::getName() {

	return (_name);
}

void	Bureaucrat::ChangeGrade(std::string method) {

	try
	{
		if (method == "+")
			increment();
		else if (method == "-")
			decrement();
		else
			throw BadSignException();
	}
	catch (std::exception &e)
	{
		std::cout << "Exception found : " << e.what() << std::endl;
	}
}

void	Bureaucrat::increment() {

	int tmp;
	
	tmp = _grade;
	tmp++;
	if (tmp > 150)
		throw GradeTooHighException();
	else
		_grade = tmp;

	return ;
}

void	Bureaucrat::decrement() {

	int tmp;
	
	tmp = _grade;
	tmp--;
	if (tmp <= 0)
		throw GradeTooLowException();
	else
		_grade = tmp;

	return ;
}