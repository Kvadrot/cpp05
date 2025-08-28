/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:15:23 by ufo               #+#    #+#             */
/*   Updated: 2025/08/28 10:27:38 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

//
//Constructors
//

Bureaucrat:: Bureaucrat() : _name("test"), _grade(1) {

}

Bureaucrat:: Bureaucrat(const std::string& name, int grade) :
 _name(name), _grade(grade) {
    validateGrade(grade);
}

Bureaucrat:: Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    validateGrade(other._grade);
}

Bureaucrat:: ~Bureaucrat() {
}

// Operator OverWrite

Bureaucrat& Bureaucrat:: operator=(const Bureaucrat &other) {
    if (this != &other)
    {
        validateGrade(other._grade);
        this->_grade = other._grade;
    }
    return (*this);
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b) {
    os << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return os;
}




// Exeption func "what()"

const char* Bureaucrat::GradeTooHighException:: what() const throw() {
    return "Grade is too high";
}

const char* Bureaucrat:: GradeTooLowException:: what() const throw() {
    return "Grade is too low";
}




// Private func

void Bureaucrat:: validateGrade(const int grade) {
    if (grade < 1) {
        throw(Bureaucrat:: GradeTooHighException());
    } else if (grade > 150) {
        throw(Bureaucrat:: GradeTooLowException());
    }
}




// Public func

const std::string& Bureaucrat:: getName() const {
    return (this->_name);
}

int Bureaucrat:: getGrade() const {
    return (this->_grade);
}

void Bureaucrat:: incrementGrade() {
    validateGrade(_grade - 1);
    this->_grade -= 1;
}

void Bureaucrat:: decrementGrade() {
    validateGrade(_grade + 1);
    this->_grade += 1;
}

void Bureaucrat:: signAForm(AForm& form) {
    try {
        form.beSigned(*this);
        std::cout << this->_name << " signed " << form.getName() << "\n";
    } catch (std::exception& e) {
         std::cout << this->_name << " couldn’t sign " 
                  << form.getName() << " because " << e.what() << "\n";
    }
}
