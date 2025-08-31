/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 08:58:14 by ufo               #+#    #+#             */
/*   Updated: 2025/08/28 10:28:59 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

//Constructors
//
AForm:: AForm(): _name("default"),  _gradeToSign(1), _gradeToExec(1), _isSigned(false) {
}

AForm:: AForm(const std::string &name, int gradeToSign, int gradeToExec):
     _name(name),  _gradeToSign(gradeToSign), _gradeToExec(gradeToExec), _isSigned(false) {
    validateGrade(gradeToSign);
    validateGrade(gradeToExec);
}

AForm:: AForm(const AForm& other):
     _name(other._name),  _gradeToSign(other._gradeToSign),
          _gradeToExec(other._gradeToExec), _isSigned(other._isSigned) {
     validateGrade(other._gradeToSign);
     validateGrade(other._gradeToExec);
}

AForm:: ~AForm() {
     
}

AForm& AForm:: operator=(const AForm &other) {
     if (this != &other) {
          this->_isSigned = other._isSigned;
     }
     return (*this);
}

std::ostream& operator<<(std::ostream& os, const AForm& fo) {
     os << "AForm: " << fo.getName() << ", grade to exec " << fo.getGradeToExec()
          << ", grade to sign " << fo.getGradeToSign() << " , is signed " << fo.getIsSigned() << ".\n";
     return os;
}


//Errors
//
const char* AForm::GradeTooHighException:: what() const throw() {
    return "Grade is too high";
}

const char* AForm:: GradeTooLowException:: what() const throw() {
    return "Grade is too low";
}

const char* AForm:: FormIsNotSignedException:: what() const throw() {
    return "Form is not signed!";
}


// Private func
//
void AForm:: validateGrade(const int grade) {
    if (grade < 1) {
        throw(AForm:: GradeTooHighException());
    } else if (grade > 150) {
        throw(AForm:: GradeTooLowException());
    }
}

// Public func
//
const std::string& AForm:: getName() const {
    return (this->_name);
}

bool AForm:: getIsSigned() const {
    return (this->_isSigned);
}

int AForm:: getGradeToSign() const {
    return (this->_gradeToSign);
}

int AForm:: getGradeToExec() const {
    return (this->_gradeToExec);
}

void AForm:: beSigned(const Bureaucrat& bureaucrat) {
     if (bureaucrat.getGrade() <= this->getGradeToSign()) {
          this->_isSigned = true;
     } else {
          throw(AForm:: GradeTooLowException());
     }
}

void AForm:: execute(Bureaucrat const & executor) const {
    if (this->getIsSigned() == false) {
        throw(AForm:: FormIsNotSignedException());
    }

    if (executor.getGrade() <= this->getGradeToExec()) {
        doExecute(executor);
    } else {
        throw (AForm:: GradeTooLowException());
    }
        
}
