/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:02:27 by armitite          #+#    #+#             */
/*   Updated: 2025/04/04 14:50:23 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main ()
{
	try 
	{
		Intern Intern;
		AForm *Pardon = Intern.makeForm("PresidentialForm", "Evil");
		AForm *Robotomy = Intern.makeForm("RobotomyForm", "Evil");
		AForm *Shrubbery = Intern.makeForm("ShrubberyForm", "Evil");
		Bureaucrat King("King", 1);
		King.signForm(*Pardon);
		King.executeForm(*Pardon);
		King.signForm(*Robotomy);
		King.executeForm(*Robotomy);
		King.signForm(*Shrubbery);
		King.executeForm(*Shrubbery);
		
		delete Pardon;
		delete Robotomy ;
		delete Shrubbery;

		AForm *Fail = Intern.makeForm("Oups", "Evil");
		delete Fail ;
	}
	catch (std::exception &e)
	{
		std::cout << "Intern couldn't create form because : " << e.what() << std::endl;
	}
	
	return (0);
}