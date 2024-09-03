#include <iostream>
#include <string>
#include <limits>

int main() {
    std::string name;
    int id;
    std::cin.ignore();
    std::cout << "Enter name: ";
    std::getline(std::cin, name);

    std::cout << "Enter ID: ";
    std::cin >> id;

    std::cout << "Name: " << name << ", ID: " << id << std::endl;

    return 0;
}