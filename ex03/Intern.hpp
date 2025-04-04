/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 13:37:24 by armitite          #+#    #+#             */
/*   Updated: 2025/04/04 14:33:25 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern {

	private:
		
		AForm*	createForm(std::string name, std::string target);

	public:
		
		Intern();
		Intern(Intern const &copy);
		Intern& operator=(Intern const &assign);
		
		~Intern();

		AForm*	makeForm(std::string name, std::string target);
		AForm*	newRobotomy(std::string target);
		AForm*	newPresidential(std::string target);
		AForm*	newShrubbery(std::string target);

		class BadName : public std::exception {
			
			virtual const char* what() const throw()
			{
				return ("Requested form can't be created !");
			}
		};
};