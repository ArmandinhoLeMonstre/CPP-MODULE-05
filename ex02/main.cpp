/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:02:27 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 14:40:35 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int	main ()
{
	AForm *test	= new PresidentialPardonForm("Alo");
	AForm *test2 = new RobotomyRequestForm("Robotomy");
	Bureaucrat Candidate("Alo", 1);

	std::cout << test->getName() << std::endl;
	Candidate.signForm(*test);
	test->execute(Candidate);
	Candidate.executeForm(*test);
	Candidate.executeForm(*test2);

	return (0);
}