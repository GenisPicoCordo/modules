#define RED "\033[31m"
#define GREEN "\033[32m"
#define RESET "\033[0m"

#include <iostream>
#include "Array.hpp"

int main() {
    // Test case: Creation of Array with default constructor (empty array)
    {
        Array<int> arr;
        std::cout << "Test 1: Default constructor (empty array), size: " << arr.size() << std::endl;
    }

    // Test case: Creation of Array with size n (default-initialized elements)
    {
        Array<int> arr(5);
        std::cout << "Test 2: Array with 5 elements, size: " << arr.size() << std::endl;

        // Accessing valid elements
        for (unsigned int i = 0; i < arr.size(); ++i) {
            arr[i] = i + 1;
            std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
        }
    }

    // Test case: Checking bounds and exception for invalid index
    {
        try {
            Array<int> arr(5);
            std::cout << "Test 3: Attempting to access out-of-bounds index..." << std::endl;
            arr[10] = 100;  // Should throw an exception
        } catch (std::exception& e) {
            std::cout << RED << "Caught exception for out-of-bounds access: " << e.what() << RESET << std::endl;
        }
    }

    // Test case: Copy constructor (deep copy check)
    {
        Array<int> arr(3);
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        
        Array<int> arrCopy(arr);
        std::cout << "Test 4: Copy constructor" << std::endl;
        
        std::cout << "arrCopy[0] = " << arrCopy[0] << std::endl;
        std::cout << "arrCopy[1] = " << arrCopy[1] << std::endl;
        std::cout << "arrCopy[2] = " << arrCopy[2] << std::endl;
    }

    // Test case: Assignment operator (deep copy check)
    {
        Array<int> arr(3);
        arr[0] = 10;
        arr[1] = 20;
        arr[2] = 30;
        
        Array<int> arrAssigned;
        arrAssigned = arr;
        std::cout << "Test 5: Assignment operator" << std::endl;
        
        std::cout << "arrAssigned[0] = " << arrAssigned[0] << std::endl;
        std::cout << "arrAssigned[1] = " << arrAssigned[1] << std::endl;
        std::cout << "arrAssigned[2] = " << arrAssigned[2] << std::endl;
    }

    return 0;
}