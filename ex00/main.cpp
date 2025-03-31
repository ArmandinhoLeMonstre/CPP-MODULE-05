/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:50:47 by armitite          #+#    #+#             */
/*   Updated: 2025/03/31 16:17:38 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ()
{
	std::string plus = "+";
	std::string minus = "-";
	std::string bad_sign = "=";
	Bureaucrat A("Test", 150);
	Bureaucrat B(A);
	Bureaucrat C("Alo", 1);

	std::cout << "A :" << A.getName() << std::endl;
	std::cout << "A :" << A.getGrade() << std::endl;

	std::cout << "B :" << B.getName() << std::endl;
	std::cout << "B :" << B.getGrade() << std::endl;

	std::cout << "C :" << C.getName() << std::endl;
	std::cout << "C :" << C.getGrade() << std::endl;
	A.ChangeGrade(minus);
	B.ChangeGrade(plus);
	C.ChangeGrade(minus);
	//B.increment();
	std::cout << "A new grade :" << A.getGrade() << std::endl;
	std::cout << "B new grade :" << B.getGrade() << std::endl;
	std::cout << "C new grade :" << C.getGrade() << std::endl;

	return (0);
}