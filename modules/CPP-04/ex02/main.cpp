#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    std::cout << "=== Array of AAnimals ===" << std::endl;
    const int N = 4;
    AAnimal* animals[N];

    for (int i = 0; i < N; ++i) {
        if (i < N / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "\n=== Sounds ===" << std::endl;
    for (int i = 0; i < N; ++i) {
        animals[i]->makeSound();
    }

    std::cout << "\n=== Deleting ===" << std::endl;
    for (int i = 0; i < N; ++i) {
        delete animals[i];
    }

    std::cout << "\n=== Deep copy test (Dog) ===" << std::endl;
    Dog basic;
    basic.setIdea(0, "Chase the cat");
    basic.setIdea(1, "Eat food");

    Dog copyDog = basic;

    std::cout << "basic idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "copyDog  idea[0]: " << copyDog.getIdea(0) << std::endl;

    copyDog.setIdea(0, "Sleep all day");

    std::cout << "After modification:" << std::endl;
    std::cout << "basic idea[0]: " << basic.getIdea(0) << std::endl;
    std::cout << "copyDog  idea[0]: " << copyDog.getIdea(0) << std::endl;

    //std::cout << "\n=== Abstract class test ===" << std::endl;
    //AAnimal test;            // da error de compilación si se descomenta
    //AAnimal* p = new AAnimal(); //también

    return 0;
}
