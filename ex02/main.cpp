/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:02:27 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 17:06:47 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int	main ()
{

	AForm *Pardon	= new PresidentialPardonForm("Alo");
	AForm *Robotomy = new RobotomyRequestForm("Hello");
	AForm *Shrubbery = new ShrubberyCreationForm("Croco");
	Bureaucrat King("King", 1);
	Bureaucrat Mid("Mid", 20);
	Bureaucrat Ok("Ok", 50);
	Bureaucrat None("None", 150);

	std::cout << std::endl << "Test 1 : unsigned" << std::endl << "-----------------------" << std::endl;
	King.executeForm(*Pardon);
	None.executeForm(*Robotomy);
	Mid.executeForm(*Shrubbery);

	std::cout << std::endl << "Test 2 : cannot sign" << std::endl << "-----------------------" << std::endl;
	Mid.signForm(*Pardon);
	Mid.executeForm(*Pardon);

	std::cout << std::endl << "Test 3 : Sign but cannot execute" << std::endl << "-----------------------" << std::endl;
	Ok.signForm(*Robotomy);
	Ok.executeForm(*Robotomy);
	
	std::cout << std::endl << "Test 4 : Mid sign, king execute" << std::endl << "-----------------------" << std::endl;
	Ok.signForm(*Robotomy);
	King.executeForm(*Robotomy);
	
	std::cout << std::endl << "Test 5 : King execute everything" << std::endl << "-----------------------" << std::endl;
	King.signForm(*Pardon);
	King.executeForm(*Pardon);
	King.signForm(*Robotomy);
	King.executeForm(*Robotomy);
	King.signForm(*Shrubbery);
	King.executeForm(*Shrubbery);
	
	std::cout << std::endl;
	
	delete Pardon;
	delete Robotomy ;
	delete Shrubbery;

	return (0);
}