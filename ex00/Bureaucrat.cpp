/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/04 15:15:23 by ufo               #+#    #+#             */
/*   Updated: 2025/06/06 13:06:26 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

//
//Constructors
//

Bureaucrat:: Bureaucrat() : _name("test"), _grade(1) {

}

Bureaucrat:: Bureaucrat(const std::string name, int grade) : _name(name) {
    this->_grade = 1;
}

Bureaucrat:: Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade) {
    
}

Bureaucrat& Bureaucrat:: operator=(const Bureaucrat &other) {
    if (this != &other)
    {
        this->_grade = other._grade;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat() {
}