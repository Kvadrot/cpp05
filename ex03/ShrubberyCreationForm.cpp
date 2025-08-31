/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:53:22 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 10:30:21 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

//Othdx Constructors
//

ShrubberyCreationForm :: ShrubberyCreationForm(): 
    AForm("ShrubberyCreationForm", 145, 137),  
        _target("DefaultTargetForShrubbery") {
            
};

ShrubberyCreationForm:: ShrubberyCreationForm(const ShrubberyCreationForm& other):
    AForm(other), _target(other._target) {
        
};

ShrubberyCreationForm ShrubberyCreationForm:: operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
    }
    return *this;
}

ShrubberyCreationForm:: ~ShrubberyCreationForm() {
    
}

// Subject Constructor
//
ShrubberyCreationForm:: ShrubberyCreationForm(const std::string target): 
    AForm("ShrubberyCreationForm", 145, 137), _target(target) {
};

// Func
//
void ShrubberyCreationForm:: doExecute(const Bureaucrat&) const {
    std::ofstream outFile((_target + std::string("_shrubbery")).c_str());
    	if (!outFile) {
		std::cerr << "Error: cannot open output file\n";
		return;
	}
	outFile << "   ccee88oo\n"
	       "  C8O8O8Q8PoOb o8oo\n"
	       " dOB69QO8PdUOpugoO9bD\n"
	       "CgggbU8OU qOp qOdoUOdcb\n"
	       "     6OuU  /p u gcoUodpP\n"
	       "        \\\\\\//  /douUP\n"
	       "          \\\\\\////\n"
	       "           |||/\\\n"
	       "           |||\\/\n"
	       "           |||||\n"
	       "     .....//||||\\....\n";
	outFile.close();
}
