/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:50:47 by armitite          #+#    #+#             */
/*   Updated: 2025/03/31 17:48:05 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ()
{
	std::string plus = "+";
	std::string minus = "-";
	std::string bad_sign = "=";
	
	std::cout << "Test 1 : " << std::endl << "-----------------------" << std::endl;
	{
		try {
			Bureaucrat Z("Test", 153);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 2 : " << std::endl << "-----------------------" << std::endl;
	{
		try {
			Bureaucrat X("Test", 0);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 3 : " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Bureaucrat A("Test", 150);
			Bureaucrat B(A);
			std::cout << A;
			std::cout << B;
			A.ChangeGrade(minus);
			B.ChangeGrade(plus);
			std::cout << "A new grade : " << A;
			std::cout << "B new grade : " << B;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 4 : " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Bureaucrat C("Alo", 1);
			std::cout << C;
			C.ChangeGrade(minus);
			std::cout << "C new grade : " << C;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 5 : " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Bureaucrat D("Quatre", 10);
			std::cout << D;
			D.ChangeGrade(plus);
			D.ChangeGrade(bad_sign);
			std::cout << "D new grade : " << D;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}

	return (0);
}