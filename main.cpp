#include "Token.h"
#include "Lexer.h"
#include "Parser.h"
#include "Interpreter.h"
#include "ExpBlock.h"
#include<iostream>
#include<unordered_map>

int main() {
    std::unordered_map<TokenType, std::string> tokenMap = {{TokenType::If, "If"},
                                                           {TokenType::While, "While"},
                                                           {TokenType::Identifier, "Identifier"},
                                                           {TokenType::Operator, "Operator"},
                                                           {TokenType::Int_D, "Int_D"},
                                                           {TokenType::Double_D, "Double_D"},
                                                           {TokenType::Semicolons, "Semicolon"},
                                                           {TokenType::L_br, "L_br"},
                                                           {TokenType::R_br, "R_br"},
                                                           {TokenType::Print, "print"},
                                                           {TokenType::L_brc, "L_brc"},
                                                           {TokenType::Brack, "Brack"},
                                                           {TokenType::R_brc, "R_brc"},
                                                           {TokenType::String, "String"},
                                                           {TokenType::Op, "Ops"},
                                                           {TokenType::Delims, "Delim"} };

    auto vec =  Tokenize("C:\\Users\\Alina\\Documents\\prov.txt");

    for (auto x : vec)
    {
        std::cout << x.tokenValue << "->" << tokenMap.find(x.tokenType)->second << "\n";
    }

    Node *root= new Node(new ExpBlock("main"));
    Parser h(root);
    h.addTokens(vec);

    Interpreter compiler;
    compiler.execute(root);
    std::cout << std::endl;
    for (const auto& var : *compiler.getVariables()) {
        std::cout << std::endl << var.first << " = " << (std::string)*var.second;
    }
    std::cout << std::endl;

    return 0;
}
