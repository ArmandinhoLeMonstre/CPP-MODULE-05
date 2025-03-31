/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:02:27 by armitite          #+#    #+#             */
/*   Updated: 2025/03/31 20:07:53 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

int	main ()
{
	std::cout << std::endl << "Test 1 trying to sign too high: " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Form Basic("Basic", 155, 40);
		}
		catch (std::exception &e) {
			
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "Test 2 trying to execute too high: " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Form Basic("Basic", 40, 151);
		}
		catch (std::exception &e) {
			
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}
	std::cout << std::endl << "Test 3 All good : " << std::endl << "-----------------------" << std::endl;
	{	
		try {
			Form Basic("Basic", 125, 40);
			Bureaucrat A("Good", 2);
			std::cout << "Sign status : " << Basic.getSignStatus() << std::endl;
			Basic.beSigned(A);
			std::cout << "Sign status 2 : " << Basic.getSignStatus() << std::endl;
		}
		catch (std::exception &e) {
			
			std::cout << "Exception caught : " << e.what() << std::endl;
		}
	}

	return (0);
}