/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 12:09:06 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 12:09:07 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main (int argc, char **argv) {

    if(argc == 1) {
        
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    } else {

        for(int i = 1; i < argc; ++i) {

            std::string sentence = argv[i];
            for(size_t j = 0; j < sentence.length(); ++j) {
                std::cout << (char)std::toupper(sentence[j]);
            }
        }
        std::cout << std::endl;
    }
    return 0;
}