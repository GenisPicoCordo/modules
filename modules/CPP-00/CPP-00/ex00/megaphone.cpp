/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:44:44 by gpico-co          #+#    #+#             */
/*   Updated: 2025/06/19 17:25:37 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv) {
    if (argc == 1) {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {
        for (int i = 1; i < argc; ++i) {
            std::string arg = argv[i];
            for (size_t j = 0; j < arg.length(); ++j) {
                std::cout << (char)std::toupper(arg[j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}
