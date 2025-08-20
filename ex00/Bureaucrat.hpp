/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:08:38 by ufo               #+#    #+#             */
/*   Updated: 2025/08/20 14:14:28 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat {
private:
    const std::string _name;
    int _grade;

    void validateGrade(const int grade);

public:
    // Constructors
    Bureaucrat();
    Bureaucrat(const std::string& name, int grade);
    Bureaucrat(const Bureaucrat& other);
    ~Bureaucrat();
    
    // Operator overload
    Bureaucrat& operator=(const Bureaucrat& other);
    
    // Member functions
    const std::string& getName() const;
    int getGrade() const;
    void incrementGrade();
    void decrementGrade();
    
    // Exception classes
    class GradeTooHighException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class GradeTooLowException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Operator overload for output stream
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);

#endif
