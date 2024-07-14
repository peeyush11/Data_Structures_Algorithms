#include <iostream>
#include <string>
#include <stack>

// Problem: https://www.geeksforgeeks.org/problems/parenthesis-checker2744/1?page=1&category=Stack&sortBy=submissions

bool matchSymbols(const char& opening, const char& closing){
    
    if(opening == '(' && closing == ')') return 1;

    if(opening == '{' && closing == '}' ) return 1;

    if(opening == '[' && closing == ']') return 1;

    return 0;
}

bool isBalanced(const std::string& expr){
    std::stack<char> set_chars;

    for(const auto& element:expr){
        if(element == '(' || element == '{' || element == '[')
            set_chars.push(element);
        else
        if(element == ')' || element == '}' || element == ']'){

            if(set_chars.empty()) return 0;
            else{
                char opening_symbol = set_chars.top();
                set_chars.pop();
                if(!matchSymbols(opening_symbol, element)) return 0;
            }
        }
    }

    
    return set_chars.empty();
}
int main(){

    std::string expr;

    std::cout<<"Enter string of parenthesis to evaulate: ";
    // using only cin causes problem with space in between chars, use getline
    std::getline(std::cin, expr);

    std::cout<<"Is expression is balanced?: "<<(isBalanced(expr)?"yes":"no")<<std::endl;

    return 0;

}