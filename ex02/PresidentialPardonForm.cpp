/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:48:02 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 14:21:21 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

//OCF Constructor
//
PresidentialPardonForm:: PresidentialPardonForm():
    AForm("PresidentialPardonForm", 25, 5), _target("DefaultTargPresidentialPardonForm") {
    
}

PresidentialPardonForm:: PresidentialPardonForm(const PresidentialPardonForm& other):
    AForm(other), _target(other._target) {
    
}

PresidentialPardonForm& PresidentialPardonForm:: operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm:: operator=(other);
    }
    return *this;
}

PresidentialPardonForm:: ~PresidentialPardonForm() {
    
}

//Task Constructor
//
PresidentialPardonForm:: PresidentialPardonForm(const std::string target):
    AForm("PresidentialPardonForm", 25, 5),  _target(target) {
    
}

// Func
//
void PresidentialPardonForm:: doExecute(const Bureaucrat&) const {
    std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}