#include "NotationConverter.hpp"
#include <iostream>


int main() {
  NotationConverter converter;
  int choice;
  std::string inputString;
  std::string defaultPost = "c d / a b * r r * / *";
  std::string defaultPrefix = "* + A B - C D";
  std::string defaultInfix = "(( a / f) ((a * b) / (r * r)))";

  std::cout << "\nWhat is the format of your input?\n";
  std::cout << "Type 1 for postfix, 2 for prefix, and 3 for infix: "; 
  std::cin >> choice;

  while(choice < 1 && choice < 3) {
    std::cout << "Invalid input. Valid inputs are 1, 2, or 3. Please try again:";
    std::cin >> choice;
  }
  std::cin.ignore();

  switch(choice) {
    case 1:
      std::cout << "If you would like to use the default postfix string ";
      std::cout << "type 1, if you would like to enter your own string, type 2: ";
      std::cin >> choice;

      while(choice < 1 && choice > 2) {
        std::cout << "Invalid input. Valid inputs are 1 or 2. Please try again:";
        std::cin >> choice;
      }

      std::cin.ignore();

      if(choice == 1) {
        std::cout << "Postfix: " << defaultPost << "\n";
        std::cout << "Infix: " << converter.postfixToInfix(defaultPost) << "\n";
        std::cout << "Prefix: " << converter.postfixToPrefix(defaultPost) << std::endl;
      }
      else {
        std::cout << "Enter the string you would like to convert in postfix notation: ";
        getline(std::cin, inputString);

        std::cout << "Postfix: " << inputString << "\n";
        std::cout << "Infix: " << converter.postfixToInfix(inputString) << "\n";
        std::cout << "Prefix: " << converter.postfixToPrefix(inputString) << std::endl;
      }
      break;

    case 2:
      std::cout << "If you would like to use the default prefix string ";
      std::cout << "type 1, if you would like to enter your own string, type 2: ";
      std::cin >> choice;

      while(choice < 1 || choice > 2) {
        std::cout << "Invalid input. Valid inputs are 1 or 2. Please try again:";
        std::cin >> choice;
      }

      std::cin.ignore();

      if(choice == 1) {
        std::cout << "Prefix: " << defaultPrefix << "\n";
        std::cout << "Infix: " << converter.prefixToInfix(defaultPrefix) << "\n";
        std::cout << "Postfix: " << converter.prefixToPostfix(defaultPrefix) << std::endl;
      }
      else {
        std::cout << "Enter the string you would like to convert in prefix notation: ";
        getline(std::cin, inputString);

        std::cout << "Prefix: " << inputString << "\n";
        std::cout << "Infix: " << converter.prefixToInfix(inputString) << "\n";
        std::cout << "Postfix: " << converter.prefixToPostfix(inputString) << std::endl;
      }
      break;

    case 3:
      std::cout << "If you would like to use the default infix string ";
      std::cout << "type 1, if you would like to enter your own string, type 2: ";
      std::cin >> choice;

      while(choice < 1 || choice > 2) {
        std::cout << "Invalid input. Valid inputs are 1 or 2. Please try again:";
        std::cin >> choice;
      }

      std::cin.ignore();

      if(choice == 1) {
        std::cout << "Infix: " << defaultInfix << "\n";
        std::cout << "Postfix: " << converter.infixToPostfix(defaultInfix) << "\n";
        std::cout << "Prefix: " << converter.infixToPrefix(defaultInfix) << std::endl;
      }
      else {
        std::cout << "Enter the string you would like to convert in infix notation: ";
        getline(std::cin, inputString);

        std::cout << "Infix: " << inputString << "\n";
        std::cout << "Postfix: " << converter.infixToPostfix(inputString) << std::endl;
        std::cout << "Prefix: " << converter.infixToPrefix(inputString) << std::endl;
      }
  }

  return 0;
}