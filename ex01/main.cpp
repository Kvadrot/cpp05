/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:08:09 by ufo               #+#    #+#             */
/*   Updated: 2025/08/25 22:25:13 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

static void title(const char* t) {
	std::cout << "\n=== " << t << " ===\n";
}

int main() {
	// 1) Valid constructions + operator<<
	try {
		title("Valid constructions");
		Bureaucrat a("Alice", 42);
		Form f("Tax-Form", 45, 50);
		std::cout << a;
		std::cout << f;
	} catch (std::exception& e) {
		std::cout << "Unexpected: " << e.what() << "\n";
	}

	// 2) Invalid Bureaucrat constructions (too high / too low)
	try {
		title("Invalid Bureaucrat: grade 0");
		Bureaucrat x("X", 0);
		std::cout << x;
	} catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << "\n";
	}
	try {
		title("Invalid Bureaucrat: grade 151");
		Bureaucrat y("Y", 151);
		std::cout << y;
	} catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << "\n";
	}

	// 3) Invalid Form constructions (too high / too low)
	try {
		title("Invalid Form: sign grade 0");
		Form badSign("BadSign", 0, 50);
		std::cout << badSign;
	} catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << "\n";
	}
	try {
		title("Invalid Form: exec grade 151");
		Form badExec("BadExec", 50, 151);
		std::cout << badExec;
	} catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << "\n";
	}

	// 4) Signing success (bureaucrat grade <= gradeToSign)
	try {
		title("Signing: success path");
		Bureaucrat pro("Pro", 10);
		Form easy("Easy", 20, 30);
		std::cout << pro << easy;
		pro.signForm(easy);      // should succeed
		std::cout << easy;       // isSigned should be true
	} catch (std::exception& e) {
		std::cout << "Unexpected: " << e.what() << "\n";
	}

	// 5) Signing failure (bureaucrat grade too low)
	try {
		title("Signing: failure path");
		Bureaucrat junior("Junior", 75);
		Form hard("Hard", 50, 40);
		std::cout << junior << hard;
		junior.signForm(hard);   // should throw inside beSigned
		std::cout << hard;
	} catch (std::exception& e) {
		std::cout << "Caught outside: " << e.what() << "\n";
	}

	// 6) Grade changes: hit boundaries and throw
	try {
		title("Increment to 1, then fail");
		Bureaucrat top("Top", 2);
		std::cout << top;
		top.incrementGrade();    // 2 -> 1 OK
		std::cout << top;
		top.incrementGrade();    // 1 -> 0 throws
		std::cout << top;        // not reached
	} catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << "\n";
	}
	try {
		title("Decrement to 150, then fail");
		Bureaucrat low("Low", 149);
		std::cout << low;
		low.decrementGrade();    // 149 -> 150 OK
		std::cout << low;
		low.decrementGrade();    // 150 -> 151 throws
		std::cout << low;        // not reached
	} catch (std::exception& e) {
		std::cout << "Caught: " << e.what() << "\n";
	}

	// 7) Copy/assignment behavior
	try {
		title("Copy & assignment");
		Bureaucrat a("A", 60);
		Bureaucrat b(a);         // copy ctor
		Bureaucrat c("C", 10);
		std::cout << a << b << c;
		c = a;                   // copy assign (name stays "C", grade becomes 60)
		std::cout << c;
		Form f1("F1", 30, 40);
		Form f2(f1);             // copy ctor
		std::cout << f1 << f2;
	} catch (std::exception& e) {
		std::cout << "Unexpected: " << e.what() << "\n";
	}

	return 0;
}
