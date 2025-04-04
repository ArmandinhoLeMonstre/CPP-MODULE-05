/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 16:03:55 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 16:18:52 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
	
	private:

		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		int	const			_required_to_sign;
		int	const			_required_to_execute;
	
	public:
		
		ShrubberyCreationForm(std::string Target);
		ShrubberyCreationForm(ShrubberyCreationForm const &copy);
		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &assign);
		
		~ShrubberyCreationForm();
		
		void	ability(Bureaucrat const & executor) const;
};