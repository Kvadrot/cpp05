/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:58:38 by ufo               #+#    #+#             */
/*   Updated: 2025/08/25 22:09:04 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

#include <iostream>
#include <string>

class Bureaucrat;

class AForm {
    private:
        const std::string _name;
        const int _gradeToSign;
        const int _gradeToExec;
        bool _isSigned;

        void validateGrade(const int grade);

    public:
    //Constructors
        AForm();
        AForm(const std::string name, int gradeToSign, int gradeToExec);
        AForm(const AForm &other);
        ~AForm();

    // Operator overload
        AForm& operator=(const AForm& other);

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


std::ostream& operator<<(std::ostream& os, const AForm& fo);

#endif
