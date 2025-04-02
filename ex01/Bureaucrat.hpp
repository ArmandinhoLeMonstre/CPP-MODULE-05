/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:19:13 by armitite          #+#    #+#             */
/*   Updated: 2025/04/02 14:33:44 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat {

private :
	
	std::string const	_name;
	int					_grade;
	void				increment();
	void				decrement();

public :

	Bureaucrat(std::string const name, int grade);
	Bureaucrat(const Bureaucrat &copy);
	Bureaucrat &operator=(const Bureaucrat &copy);

	~Bureaucrat();

	std::string const	&getName();
	int	const			&getGrade();
	void				ChangeGrade(std::string method);
	void				signForm(Form &Form, Bureaucrat &Candidate);
	
	class GradeTooHighException : public std::exception {

		virtual const char* what() const throw()
		{
			return ("Grade too high");
		}
	};
	class GradeTooLowException : public std::exception {

		virtual const char* what() const throw()
		{
			return ("Grade too low");
		}
	};
	class BadSignException : public std::exception {

		virtual const char* what() const throw()
		{
			return ("Wrong sign for changing grade");
		}
	};
};

std::ostream&   operator<<(std::ostream& o, Bureaucrat &assign);