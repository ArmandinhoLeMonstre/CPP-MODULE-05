/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:23:06 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 14:00:33 by armitite         ###   ########.fr       */
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
		std::cout << "Exception found during creation : " << e.what() << std::endl;
	}
	
	return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const &copy) : _name(copy._name){

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

int	const &Bureaucrat::getGrade()const {

	return (_grade);
}

std::string const &Bureaucrat::getName() const {

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
		std::cout << "Exception found during changing : " << e.what() << std::endl;
	}
}

void	Bureaucrat::decrement() {

	int tmp;
	
	tmp = _grade;
	tmp++;
	if (tmp > 150)
		throw GradeTooHighException();
	else
		_grade = tmp;

	return ;
}

void	Bureaucrat::increment() {

	int tmp;
	
	tmp = _grade;
	tmp--;
	if (tmp <= 0)
		throw GradeTooLowException();
	else
		_grade = tmp;

	return ;
}

std::ostream &operator<<(std::ostream & o, Bureaucrat &assign) {

	o << assign.getName() << ", bureaucrat grade " << assign.getGrade() << std::endl;
	
	return o;
}

void	Bureaucrat::signForm(AForm &AForm) {

	AForm.beSigned(*this);
}

void	Bureaucrat::executeForm(AForm const & form) const {

	form.execute(*this);
}