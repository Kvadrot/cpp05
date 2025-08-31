/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ufo <ufo@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 13:43:26 by ufo               #+#    #+#             */
/*   Updated: 2025/08/31 14:13:59 by ufo              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDETIALPARDONFORM_HPP
#define PRESIDETIALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm: public AForm {
    private:
        const std::string _target;

    protected:
        void doExecute(const Bureaucrat& executor) const;
        
    public:
        PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        ~PresidentialPardonForm();

        PresidentialPardonForm(std::string target);
};

#endif