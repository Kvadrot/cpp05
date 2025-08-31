/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:08:09 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 16:10:22 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static void title(const char* t) {
	std::cout << "\n=== " << t << " ===\n";
}

int main() {
	std::srand(std::time(NULL)); // for Robotomy 50%

	Intern intern;

	// test00
	// Intern creates Shrubbery, super signs and executes
	title("test00");
	Bureaucrat superBur("super", 1);
	AForm *f0 = intern.makeForm("shrubbery creation", "gamno");
	if (f0) {
		superBur.signAForm(*f0);
		superBur.executeForm(*f0);
		delete f0;
	}

	// test01
	// Shrubbery: sign ok (<=145), exec fails (>137)
	title("test01");
	Bureaucrat semiBur("semi", 138);
	AForm *f1 = intern.makeForm("shrubbery creation", "gamno2");
	if (f1) {
		semiBur.signAForm(*f1);
		semiBur.executeForm(*f1);
		delete f1;
	}

	// test02
	// Robotomy: super signs and executes (random success/fail)
	title("test02");
	Bureaucrat roboBur("robo", 1);
	AForm *f2 = intern.makeForm("robotomy request", "Bender");
	if (f2) {
		roboBur.signAForm(*f2);    // needs 72 to sign
		roboBur.executeForm(*f2);  // needs 45 to exec
		delete f2;
	}

	// test03
	// Robotomy: sign ok (<=72), exec fails (>45)
	title("test03");
	Bureaucrat weakBur("weak", 60);
	AForm *f3 = intern.makeForm("robotomy request", "Fry");
	if (f3) {
		weakBur.signAForm(*f3);    // ok: 60 <= 72
		weakBur.executeForm(*f3);  // fail: 60 > 45
		delete f3;
	}

	// test04
	// Presidential: sign and exec ok
	title("test04");
	Bureaucrat prezBoss("prezBoss", 1);
	AForm *f4 = intern.makeForm("presidential pardon", "Arthur Dent");
	if (f4) {
		prezBoss.signAForm(*f4);   // needs 25 to sign
		prezBoss.executeForm(*f4); // needs 5 to exec
		delete f4;
	}

	// test05
	// Presidential: sign ok (<=25), exec fails (>5)
	title("test05");
	Bureaucrat midManager("midManager", 10);
	AForm *f5 = intern.makeForm("presidential pardon", "Ford Prefect");
	if (f5) {
		midManager.signAForm(*f5);   // ok: 10 <= 25
		midManager.executeForm(*f5); // fail: 10 > 5
		delete f5;
	}

	// test06
	// Unknown form name: Intern should print error and return NULL
	title("test06");
	AForm *f6 = intern.makeForm("tax evasion", "Zaphod");
	if (f6) {
		std::cout << "ERROR: should not create unknown form\n";
		delete f6;
	}

	// test07
	// Presidential: fail to sign (grade too low), exec also fails (not signed)
	title("test07");
	Bureaucrat lowClerk("lowClerk", 50);
	AForm *f7 = intern.makeForm("presidential pardon", "Trillian");
	if (f7) {
		lowClerk.signAForm(*f7);     // fail: 50 > 25
		lowClerk.executeForm(*f7);   // will fail: not signed
		delete f7;
	}

	return 0;
}

