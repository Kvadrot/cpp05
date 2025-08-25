/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:58:38 by ufo               #+#    #+#             */
/*   Updated: 2025/08/25 21:34:32 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

class Form {
    private:
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExec;
        bool _isSigned;

        void validateGrade(const int grade);

    public:
    //Constructors
        Form();
        Form(const std::string name, int gradeToSign, int gradeToExec, bool isSigned);
        Form(const Form &other);
        ~Form();

    // Operator overload
        Form& operator=(const Form& other);

    // Exception classes
        class GradeTooHighException: public std::exception {
            public:
                virtual const char* what() const throw();
        };
        
        class GradeTooLowException: public std::exception {
            public:
                virtual const char* what() const throw();
        };

    // Funcs
        const std::string&  getName() const;
        bool          getIsSigned() const;
        int           getGradeToSign() const;
        int           getGradeToExec() const;
        void                beSigned(const Bureaucrat& bureaucrat);
};

#endif
