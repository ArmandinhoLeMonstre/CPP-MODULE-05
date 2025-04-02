/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:57:02 by armitite          #+#    #+#             */
/*   Updated: 2025/04/02 19:04:41 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "AForm.hpp"

class PresidentialPardonForm : public AForm{
	
	private:

		std::string const	_name;
		std::string const	_target;
		bool				_signed;
		int	const			_required_to_sign;
		int	const			_required_to_execute;
		
		void				TryToSign(Bureaucrat &Candidate);
	
	public:
		
		PresidentialPardonForm(std::string Target);
		PresidentialPardonForm(PresidentialPardonForm const &copy);
		PresidentialPardonForm &operator=(PresidentialPardonForm const &assign);
		
		~PresidentialPardonForm();
		
		void	execute(Bureaucrat const & executor) const;
		void	ability(Bureaucrat const & executor) const;
};