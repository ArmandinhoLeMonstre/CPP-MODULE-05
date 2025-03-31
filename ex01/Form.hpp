/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: armitite <armitite@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 18:34:49 by armitite          #+#    #+#             */
/*   Updated: 2025/03/31 19:56:35 by armitite         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Bureaucrat.hpp"

class Form {
	
	private:
		
		std::string const	_name;
		bool				_signed;
		int	const			_required_to_sign;
		int	const			_required_to_execute;
	
	public:
	
		Form(std::string FormName, int to_sign, int to_execute);
		Form(const Form &copy);
		Form &operator=(const Form &assign);

		~Form();

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
		
		void	beSigned(Bureaucrat &Candidate);
};