/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:19:13 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 14:00:43 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <ostream>
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm;

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

	std::string const	&getName() const;
	int	const			&getGrade() const;
	void				ChangeGrade(std::string method);
	void				signForm(AForm &AForm);
	void				executeForm(AForm const & form) const;
	
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