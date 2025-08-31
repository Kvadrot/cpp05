/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/28 11:53:24 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 10:02:35 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <fstream>
#include "AForm.hpp"

class ShrubberyCreationForm: public AForm {
    private:
        const std::string _target;

    protected:
        virtual void doExecute(const Bureaucrat& executor) const;
        
    public:
        ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();
        
        ShrubberyCreationForm(const std::string target);
};

#endif