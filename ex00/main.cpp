/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:08:09 by ufo               #+#    #+#             */
/*   Updated: 2025/08/20 15:11:56 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <istream>

void printCaseName(std::string name) {
    std::cout << "\n ============================"  << name << " ============================\n";
}

int main() {
    try {
        printCaseName("Validate good constructor");
        Bureaucrat a ("Alice", 2);
        std::cout << a; // should print Alice 2
    } catch (std::exception &e) {
        std::cout << "Cought: " << e.what() << "\n";
    }

    try {
        printCaseName("Validate invalid constructor");
        Bureaucrat b ("Balice", 0);
        std::cout << b; // should through the error
    } catch (std::exception &e) {
        std::cout << "Cought: " << e.what() << "\n";
    }

	// 3) Invalid construction: grade too low (> 150)
	try {
		printCaseName("Invalid: grade 151 (too low)");
		Bureaucrat c("Cindy", 151);
		std::cout << c;
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << "\n";
	}

	// 4) Increment down to 1, then one more (should throw too high)
	try {
		printCaseName("Increment to upper bound, then fail");
		Bureaucrat d("Dan", 2);
		std::cout << d;
		d.incrementGrade();     // 2 -> 1 (ok)
		std::cout << d;
		d.incrementGrade();     // 1 -> 0 (throw)
		std::cout << d;         // not reached
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << "\n";
	}

	// 5) Decrement up to 150, then one more (should throw too low)
	try {
		printCaseName("Decrement to lower bound, then fail");
		Bureaucrat e("Eve", 149);
		std::cout << e;
		e.decrementGrade();     // 149 -> 150 (ok)
		std::cout << e;
		e.decrementGrade();     // 150 -> 151 (throw)
		std::cout << e;         // not reached
	} catch (std::exception &ex) {
		std::cout << "Caught: " << ex.what() << "\n";
	}

	// 6) Copy constructor & copy assignment keep valid grade
	try {
		printCaseName("Copy ctor and assignment");
		Bureaucrat f("Frank", 100);
		Bureaucrat g(f);        // copy ctor
		std::cout << g;
		Bureaucrat h("Hank", 50);
		std::cout << h;
		h = f;                  // copy assign (name stays Hank, grade from f)
		std::cout << h;
	} catch (std::exception &e) {
		std::cout << "Caught: " << e.what() << "\n";
	}

	return 0;
}