/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/06 10:08:09 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 10:46:33 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// main.cpp
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"

// static void title(const char* t) {
// 	std::cout << "\n=== " << t << " ===\n";
// }

int main() {
    Bureaucrat superBur = Bureaucrat("super", 1);
    ShrubberyCreationForm shrubForm = ShrubberyCreationForm("gamno");
    superBur.signAForm(shrubForm);
    superBur.executeForm(shrubForm);
}
