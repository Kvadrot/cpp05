/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:58:14 by ufo               #+#    #+#             */
/*   Updated: 2025/08/25 22:27:58 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

//Constructors
//
Form:: Form(): _name("default"),  _gradeToSign(1), _gradeToExec(1), _isSigned(false) {
}

Form:: Form(const std::string name, int gradeToSign, int gradeToExec):
     _name(name),  _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExec);
}

Form:: Form(const Form& other):
     _name(other._name),  _gradeToSign(other._gradeToSign),
          _gradeToExec(other._gradeToExec), _isSigned(other._isSigned) {
     validateGrade(other._gradeToSign);
     validateGrade(other._gradeToExec);
}

Form:: ~Form() {
     
}

Form& Form:: operator=(const Form &other) {
     if (this != &other) {
          this->_isSigned = other._isSigned;
     }
     return (*this);
}

std::ostream& operator<<(std::ostream& os, const Form& fo) {
     os << "Form: " << fo.getName() << ", grade to exec " << fo.getGradeToExec()
          << ", grade to sign " << fo.getGradeToSign() << " ,is signed " << fo.getIsSigned() << ".\n";
     return os;
}


//Errors
//
const char* Form::GradeTooHighException:: what() const throw() {
    return "Grade in Form is too high";
}

const char* Form:: GradeTooLowException:: what() const throw() {
    return "Grade in Form is too low";
}


// Private func
//
void Form:: validateGrade(const int grade) {
    if (grade < 1) {
        throw(Form:: GradeTooHighException());
    } else if (grade > 150) {
        throw(Form:: GradeTooLowException());
    }
}

// Public func
//
const std::string& Form:: getName() const {
    return (this->_name);
}

bool Form:: getIsSigned() const {
    return (this->_isSigned);
}

int Form:: getGradeToSign() const {
    return (this->_gradeToSign);
}

int Form:: getGradeToExec() const {
    return (this->_gradeToExec);
}

void Form:: beSigned(const Bureaucrat& bureaucrat) {
     if (bureaucrat.getGrade() <= this->getGradeToSign()) {
          this->_isSigned = true;
     } else {
          throw(Form:: GradeTooLowException());
     }
}
