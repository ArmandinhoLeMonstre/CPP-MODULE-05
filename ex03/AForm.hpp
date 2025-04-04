/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:34:49 by armitite          #+#    #+#             */
/*   Updated: 2025/04/03 16:29:10 by armitite         ###   ########.fr       */
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
		
		
	protected:
		
		void			TryToSign(Bureaucrat &Candidate);
		void			call_ability(Bureaucrat const & executor) const;
		void virtual	ability(Bureaucrat const & executor) const = 0;
	
	public:
		
		AForm(std::string FormName, int to_sign, int to_execute);
		AForm(const AForm &copy);
		AForm &operator=(const AForm &assign);
		
		virtual ~AForm();
		
		std::string const	&getName() const;
		int			const	&getToSign() const;
		int			const	&getToExecute() const;
		bool		const	&getSignStatus() const;
		
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
		class UnsignedForm : public std::exception {
			
			virtual const char* what() const throw()
			{
				return ("Unsigned Form");
			}
		};
		
		void			beSigned(Bureaucrat &Candidate);
		void			execute(Bureaucrat const & executor) const;
};

std::ostream&   operator<<(std::ostream& o, AForm &assign);