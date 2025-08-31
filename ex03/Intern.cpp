/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 15:13:27 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 16:08:18 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

static int find_index(const std::string &n)
{
	const std::string names[3] = {
		"shrubbery creation",
		"robotomy request",
		"presidential pardon"
	};
	int i;

	i = 0;
	while (i < 3)
	{
		if (n == names[i])
			return i;
		i++;
	}
	return -1;
}

Intern:: Intern() {
    
}

Intern:: Intern(const Intern&) {
    
}

Intern& Intern:: operator=(const Intern&) {
    return (*this);
}

Intern:: ~Intern() {
    
}

AForm *Intern:: makeForm(const std::string &name, const std::string &target) const {
	int idx;

	idx = find_index(name);
	switch (idx)
	{
		case 0:
			std::cout << "Intern creates " << name << std::endl;
			return new ShrubberyCreationForm(target);
		case 1:
			std::cout << "Intern creates " << name << std::endl;
			return new RobotomyRequestForm(target);
		case 2:
			std::cout << "Intern creates " << name << std::endl;
			return new PresidentialPardonForm(target);
		default:
			std::cout << "Intern: unknown form name \""
			          << name << "\"" << std::endl;
			return 0;
	}
}
