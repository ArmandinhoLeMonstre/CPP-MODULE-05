/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:34:49 by armitite          #+#    #+#             */
/*   Updated: 2025/04/02 19:21:32 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm {
	
	private:
		
		std::string const	_name;
		bool				_signed;
		int	const			_required_to_sign;
		int	const			_required_to_execute;
		
		void				TryToSign(Bureaucrat &Candidate);
		
	public:
		
		AForm(std::string FormName, int to_sign, int to_execute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &assign);
		
		virtual ~AForm();
		
		std::string const	&getName();
		int			const	&getToSign();
		int			const	&getToExecute();
		bool		const	&getSignStatus();
		
		class GradeTooHighException : public std::exception {
			
			virtual const char* what() const throw()
			{
				return ("Grade too high");
			}
		};
		class GradeTooLowException : public std::exception {
			
			virtual const char* what() const throw()
			{
				return ("Grade too low");
			}
		};
		
		void			beSigned(Bureaucrat &Candidate);
		void virtual	execute(Bureaucrat const & executor) const = 0;
		void virtual	ability(Bureaucrat const & executor) const = 0;
};

std::ostream&   operator<<(std::ostream& o, AForm &assign);