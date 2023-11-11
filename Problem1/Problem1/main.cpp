#include<iostream>
#include <vector>

#include "UserInputFactory.h"

int main(int argc, const char* argv[])
{
    // Ask the user for the input method
    std::cout << "Choose input method (Random/STDIN/File): ";
    std::string input_type;
    std::cin >> input_type;

    // Create an InputFactory based on user input
    const UserInputFactory inputFactory;
    const std::unique_ptr<FigureFactory> figureFactory = inputFactory.create_figure_factory(input_type);

    // Read the number of figures to generate
    int numFigures;
    std::cout << "Enter the number of figures: ";
    std::cin >> numFigures;

    // Create a vector to store the figures
    std::vector<std::unique_ptr<Figure>> figures(numFigures);

    // Generate or read figures
    for (int i = 0; i < numFigures; ++i) {
         // Create a figure using the chosen factory
        figures.push_back(figureFactory->create_figure());
    }

    // List figures to STDOUT
    for (const auto& figure : figures) {
        std::cout << figure->toString() << " Perimeter: " << figure->perimeter() << std::endl;
    }

    // Additional operations like delete, duplicate, store to file can be implemented here

    return 0;
}
