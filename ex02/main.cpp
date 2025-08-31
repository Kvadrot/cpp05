/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:08:09 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 14:24:18 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


static void title(const char* t) {
	std::cout << "\n=== " << t << " ===\n";
}

int main() {
    //test00
    // should sign and exec
    title("test00");
    Bureaucrat superBur = Bureaucrat("super", 1);
    ShrubberyCreationForm shrubForm = ShrubberyCreationForm("gamno");
    superBur.signAForm(shrubForm);
    superBur.executeForm(shrubForm);

    //test01
    // should sign fail execute
    title("test01");
    Bureaucrat semiBur = Bureaucrat("semi", 138);
    ShrubberyCreationForm shrubFormSemi = ShrubberyCreationForm("gamno2");
    semiBur.signAForm(shrubFormSemi);
    semiBur.executeForm(shrubFormSemi);

 // test02
    title("test02");
    // Robotomy: should sign and exec (success/fail 50% each run)
    Bureaucrat roboBur("robo", 1);
    RobotomyRequestForm roboForm("Bender");
    roboBur.signAForm(roboForm);
    roboBur.executeForm(roboForm);

    // test03
    // Robotomy: should fail to execute (grade too low)
    title("test03");
    Bureaucrat weakBur("weak", 100); // 100 is > 45 → too low to execute
    RobotomyRequestForm roboFormWeak("Fry");
    weakBur.signAForm(roboFormWeak);     // should succeed (needs 72 to sign)
    weakBur.executeForm(roboFormWeak);   // should fail (needs 45 to exec)

    // test04
    // Presidential: should sign and exec
    title("test04");
    Bureaucrat prezBoss("prezBoss", 1);
    PresidentialPardonForm pardon1("Arthur Dent");
    prezBoss.signAForm(pardon1);
    prezBoss.executeForm(pardon1);

    // test05
    // Presidential: should sign, fail execute (needs 5 to exec)
    title("test05");
    Bureaucrat midManager("midManager", 10); // OK to sign (<=25), too low to exec (>5)
    PresidentialPardonForm pardon2("Ford Prefect");
    midManager.signAForm(pardon2);
    midManager.executeForm(pardon2);

    // test06
    // Presidential: should fail to sign (needs 25 to sign)
    title("test06");
    Bureaucrat lowClerk("lowClerk", 50); // too low to sign
    PresidentialPardonForm pardon3("Trillian");
    lowClerk.signAForm(pardon3);
    lowClerk.executeForm(pardon3);


    return 0;
}
