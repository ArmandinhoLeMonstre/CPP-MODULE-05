/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 14:33:54 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 14:34:26 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class RobotomyRequestForm : public AForm{
	
	private:

		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		int	const			_required_to_sign;
		int	const			_required_to_execute;
	
	public:
		
		RobotomyRequestForm(std::string Target);
		RobotomyRequestForm(RobotomyRequestForm const &copy);
		RobotomyRequestForm &operator=(RobotomyRequestForm const &assign);
		
		~RobotomyRequestForm();
		
		void	execute(Bureaucrat const & executor) const;
		void	ability(Bureaucrat const & executor) const;
};