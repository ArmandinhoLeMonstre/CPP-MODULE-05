/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 12:50:47 by armitite          #+#    #+#             */
/*   Updated: 2025/03/31 18:12:21 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main ()
{
	std::string plus = "+";
	std::string minus = "-";
	std::string bad_sign = "=";
	
	std::cout << "Test 1, constructor with too high grade : " << std::endl << "-----------------------" << std::endl;
	{
		try {
			Bureaucrat Z("Test", 153);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 2 constructor with too low grade : " << std::endl << "-----------------------" << std::endl;
	{
		try {
			Bureaucrat X("Test", 0);
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 3 trying to go too high + minus + testing copy contructor : " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Bureaucrat A("Test", 150);
			Bureaucrat B(A);
			std::cout << A;
			std::cout << B;
			A.ChangeGrade(plus);
			B.ChangeGrade(minus);
			std::cout << "A new grade : " << A;
			std::cout << "B new grade : " << B;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 4 trying to go too low : " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Bureaucrat C("Alo", 1);
			std::cout << C;
			C.ChangeGrade(plus);
			std::cout << "C new grade : " << C;
		}
		catch (std::exception &e)
		{
			std::cout << "Exception found during creation : " << e.what() << std::endl;
		};
	}
	std::cout << std::endl << "Test 5 tryng bad sign + plus: " << std::endl << "-----------------------" << std::endl;
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