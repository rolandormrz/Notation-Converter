#include "NotationConverterInterface.hpp"
#include "DLDeque.hpp"
#include <algorithm>
#include <stdexcept>
#include <iostream>

class NotationConverter : public NotationConverterInterface {
public:

    std::string postfixToInfix(std::string inStr);
    std::string postfixToPrefix(std::string inStr);

    std::string infixToPostfix(std::string inStr);
    std::string infixToPrefix(std::string inStr); 

    std::string prefixToInfix(std::string inStr);
    std::string prefixToPostfix(std::string inStr);
};