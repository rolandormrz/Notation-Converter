#include "NotationConverter.hpp"

std::string NotationConverter::postfixToInfix(std::string inStr) {

    int i;

    // check for invalid characters
    for (i = 0; i < inStr.length(); i++) {

        if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')  {
            throw std::invalid_argument("invalid character");
        }
    }

    DLDeque newDeque;
    
    // iterate through the given string
    for (i = 0; i < inStr.length(); i++) {

        // checks for operands, if so insert them into the front of the deque
        if ((inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z')) {
            
            std::string s(1, inStr[i]);             // cast to string
            newDeque.insertFront(s);                // insert front
        }

        // any spaces encountered are skipped
        else if(inStr[i] == ' ') {
            continue;
        }

        // pops the last two operands from the front then concatenates them using parentheses
        // and the operator encountered 
        else {

            std::string secondOperand = newDeque.front();
            newDeque.removeFront();

            std::string firstOperand = newDeque.front();
            newDeque.removeFront();

            newDeque.insertFront("(" + firstOperand + " " + inStr[i] + " " + secondOperand + ")");
        }
    }

    return newDeque.front();
}


std::string NotationConverter::postfixToPrefix(std::string inStr) {

    int i;

    // check for invalid characters
    for (i = 0; i < inStr.length(); i++) {

        if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')  {
            throw std::invalid_argument("invalid character");
        }
    }

    NotationConverter postToInfix;
    NotationConverter inToPrefix;
    std::string tempString;

    tempString = postToInfix.postfixToInfix(inStr);     // convert from postfix to infix
    tempString = inToPrefix.infixToPrefix(tempString);  // convert from infix to prefix

    return tempString;
}


std::string NotationConverter::infixToPostfix(std::string inStr) {

    int i;

    
    // check for invalid characters
    for (i = 0; i < inStr.length(); i++) {

        if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')  {
            throw std::invalid_argument("invalid character");
        }
    }

    DLDeque newDeque;
    std::string tempString;

    newDeque.insertFront("bottomOfStack");              // used to check for the bottom of the stack

    for (i = 0; i < inStr.length(); i++) {
        
        if(inStr[i] == ' ') {
            continue;
        }

        // operands are added to the temp string
        if ((inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z')) {
            
            std::string s(1, inStr[i]);                 // cast to string
            tempString = tempString + s + " ";       
        }
        else if (inStr[i] == '(') {

            std::string s(1, inStr[i]);                 // cast to string
            newDeque.insertFront(s);

        }

        // pop all elements from stack and append to temp string until the character '(' 
        else if (inStr[i] == ')') {

            while ((newDeque.front() != "(")) {
                
                tempString = tempString + newDeque.front() + " ";   
                newDeque.removeFront();
            }
            if (newDeque.front() == "(") {
                newDeque.removeFront();                 // get rid of the (
            }
        }

        // insert * and / if greater precedence
        else if ((inStr[i] == '*') || (inStr[i] == '/')) {

            if ((newDeque.front() != "*" && newDeque.front() != "/") || newDeque.empty()) {

                std::string s(1, inStr[i]);             // cast to string
                newDeque.insertFront(s);
            }
            else {
                while ((newDeque.front() == "*" || newDeque.front() == "/") && newDeque.front() != "bottomOfStack") {

                    tempString = tempString + newDeque.front() + " "; 
                    newDeque.removeFront();
                }

                std::string s(1, inStr[i]);             // cast to string
                newDeque.insertFront(s);
            }
        }

        // insert + or - if greater precedence
        else if ((inStr[i] == '+') || (inStr[i] == '-')) {

            if ((newDeque.front() != "*" && newDeque.front() != "/" && newDeque.front() != "+" && newDeque.front() != "-") || newDeque.empty()) {

                std::string s(1, inStr[i]);             // cast to string
                newDeque.insertFront(s);
            }
            else {
                while ((newDeque.front() == "*" || newDeque.front() == "/" || newDeque.front() == "+" || newDeque.front() == "-") && newDeque.front() != "bottomOfStack") {

                    tempString = tempString + newDeque.front() + " "; 
                    newDeque.removeFront();
                }

                std::string s(1, inStr[i]);             // cast to string
                newDeque.insertFront(s);
            }
        }
    }

    
    // pop everything from the stack until you reach the bottom
    while(newDeque.front() != "bottomOfStack") {

        tempString = tempString + newDeque.front() + " ";  
        newDeque.removeFront();
    }
    

    return tempString;
}


std::string NotationConverter::infixToPrefix(std::string inStr) {

    int i;
    
    // check for invalid characters
    for (i = 0; i < inStr.length(); i++) {

        if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')  {
            throw std::invalid_argument("invalid character");
        }
    }
    
    DLDeque newDeque;
    NotationConverter infixToPost;
    std::string tempString;

    std::reverse(inStr.begin(), inStr.end());       // reverse the string

    // reverse all the parentheses
    for (i = 0; i < inStr.length(); i++) {

        if (inStr[i] == '(') {
            inStr[i] = ')';
        }
        else if (inStr[i] == ')') {
            inStr[i] = '(';
        }
    }

    tempString = infixToPost.infixToPostfix(inStr);     // convert from infix to postfix

    std::reverse(tempString.begin(), tempString.end()); // reverse the string to convert to prefix

    return tempString;    
}


std::string NotationConverter::prefixToInfix(std::string inStr) {
    
    int i;

    // check for invalid characters
    for (i = 0; i < inStr.length(); i++) {

        if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')  {
            throw std::invalid_argument("invalid character");
        }
    }
    
    NotationConverter preToPost;
    NotationConverter postToInfix;
    std::string tempString;

    tempString = preToPost.prefixToPostfix(inStr);           // use method to convert from prefix to postfix

    tempString = postToInfix.postfixToInfix(tempString);     // use method to convert from postfix to infix

    return tempString;
}


std::string NotationConverter::prefixToPostfix(std::string inStr) { 
    
    int i;

    // check for invalid characters
    for (i = 0; i < inStr.length(); i++) {

        if (inStr[i] == '[' || inStr[i] == ']' ||inStr[i] == '^' ||inStr[i] == '\\')  {
            throw std::invalid_argument("invalid character");
        }
    }

    DLDeque newDeque;
    std::string tempString;

    std::reverse(inStr.begin(), inStr.end());       // reverse the string

    for (i = 0; i < inStr.length(); i++) {
        
        if (inStr[i] == ' ') {
            continue;
        }

        // push all operands to stack
        if ((inStr[i] >= 'A' && inStr[i] <= 'Z') || (inStr[i] >= 'a' && inStr[i] <= 'z')) {
            
            std::string s(1, inStr[i]);             // cast to string
            newDeque.insertFront(s);
        }

        // (operator) pop the last two elements from stack and concatenate them with the current operator, push 
        // the concatenated string onto the stack
        else {
            std::string firstOperand = newDeque.front();
            newDeque.removeFront();

            std::string secondOperand = newDeque.front();
            newDeque.removeFront();

            newDeque.insertFront(firstOperand + " " + secondOperand + " " + inStr[i]);
        }
    }

    return newDeque.front();
}

