/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:02:27 by armitite          #+#    #+#             */
/*   Updated: 2025/04/02 19:25:58 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"

int	main ()
{
	AForm *test	= new PresidentialPardonForm("Alo");
	Bureaucrat Candidate("Alo", 33);

	std::cout << test->getName() << std::endl;
	test->execute(Candidate);

	return (0);
}