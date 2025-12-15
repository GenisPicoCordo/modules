/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpico-co <gpico-co@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 15:34:18 by gpico-co          #+#    #+#             */
/*   Updated: 2025/12/10 15:34:19 by gpico-co         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(){
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;

    std::cout << "The memory address of the string variable: " << &brain << std::endl;
    std::cout << "The memory address held by stringPTR:      " << stringPTR << std::endl;
    std::cout << "The memory address held by stringREF:      " << &stringREF << std::endl;

    std::cout << "The value of the string variable:          " << brain << std::endl;
    std::cout << "The value pointed to by stringPTR:         " << *stringPTR << std::endl;
    std::cout << "The value pointed to by stringREF:         " << stringREF << std::endl;
}