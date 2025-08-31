/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 12:31:20 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 13:34:33 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// OFC Constructors
//
RobotomyRequestForm:: RobotomyRequestForm():
    AForm("RobotomyRequestForm", 72, 45), _target("DefaultRobotomyRequestForm") {
    
}

RobotomyRequestForm:: RobotomyRequestForm(const RobotomyRequestForm& other):
     AForm(other), _target(other._target) {
    
}

RobotomyRequestForm& RobotomyRequestForm:: operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

RobotomyRequestForm:: ~RobotomyRequestForm() {
    
}

// Task Constructor
//
RobotomyRequestForm:: RobotomyRequestForm(std::string target): 
    AForm("RobotomyRequestForm", 72, 45), _target(target) {
    
}


// Func
//
void RobotomyRequestForm:: doExecute(const Bureaucrat&) const  {
    std::cout << "driiiiiillll .... driiiiiill..." << std::endl;
    int randNum = std::rand();

    if (randNum % 2 == 0) {
        std::cout <<  this->_target << " has been robotomized successfully" << std::endl;
    } else {
        std::cout <<  this->_target << " robotomy failed" << std::endl;
    }
}