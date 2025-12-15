/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:40:42 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:40:43 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
#define HARL_HPP

#include <string>

class Harl {
    private:
        void debug(void);
        void info(void);
        void warning(void);
        void error(void);
    public:
        void complain(const std::string& level);
};

#endif