#include "Lexer.h"
#include "Token.h"
#include<fstream>
#include<iostream>
#include<regex>


    Token getToken(std::string buffer, LineNo line)
    {

        std::regex id("[a-zA-Z][a-zA-Z0-9_]*");
        std::regex str(R"("[^"]+")");
        std::regex int_d(R"(0|([1-9][0-9]*))");
        std::regex double_d(R"((0|([1-9][0-9]*))\.*[0-9]*)");
        std::regex keywords(R"(if|while|print)");

        if (std::regex_match(buffer, keywords))
        {
            return Token(buffer, TokenType::Keyword);
        }

        else if (ops.find(buffer) != ops.end())
        {
            return Token(buffer, TokenType::Op);
        }
        else if (brack.find(buffer) != brack.end())
        {
            return Token(buffer, TokenType::Brack);
        }
        else if (brc.find(buffer) != brc.end())
        {
            return Token(buffer, TokenType::Brc);
        }
        else if (operators.find(buffer) != operators.end())
        {
            return Token(buffer, TokenType::Operator);
        }

        if (std::regex_match(buffer, id))
        {
            return Token(buffer, TokenType::Identifier);
        }

        if (std::regex_match(buffer, str))
        {
            return Token(buffer, TokenType::String);
        }
        if (std::regex_match(buffer, int_d))
        {
            return Token(buffer, TokenType::Int_D);
        }
        if (std::regex_match(buffer, double_d))
        {
            return Token(buffer, TokenType::Double_D);
        }

        std::cout << "Invalid expression at line number " << line << " : " << buffer;
        std::cin.get();
        exit(0);

    }


    std::vector<Token> Tokenize(std::string filename)
    {
        std::ifstream file(filename, std::ios::in);

        if (file.fail())
        {
            std::cout << "Unable to open file!\n";
            std::cin.get();
            exit(0);
        }

        LineNo line = 1;
        std::string buffer = "";

        char ch;
        std::string ch1;
        std::vector<Token> tokens;
        char twoCh;
        twoCh = '\0';
        while (file >> ch)
        {
            ch1 = ch;
            if (ch == '\n' || ch == '\r')
                line += 1;
            if(twoCh!='\0')
            {
                std::string s;
                s = twoCh;
                s+= ch;
                if(ops.find(s)!=ops.end()){
                    tokens.push_back(Token((1, s), TokenType::Op));
                    twoCh = '\0';
                    continue;
                }
                s = twoCh;
                if(operators.find(s)!=operators.end()){
                    tokens.push_back(Token((1, s), TokenType::Operator));
                    twoCh = '\0';
                }
                if (brack.find(buffer) != brack.end())
                {
                    tokens.push_back(Token((1, s), TokenType::Brack));
                    twoCh = '\0';
                }
                if (brc.find(buffer) != brc.end())
                {
                    tokens.push_back(Token((1, s), TokenType::Brc));
                    twoCh = '\0';
                }
                if (twoCh==';')
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::Semicolons));
                if (twoCh == '(')
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::L_br));
                if (twoCh == '{')
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::L_brc));
                if (twoCh == '}')
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::R_brc));
                if (twoCh==')')
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::R_br));
                twoCh = '\0';
            }
            if ((delims.find(ch) != delims.end()) || (operators.find(ch1) != operators.end()) || brack.find(ch1) != brack.end())
            {
                if (buffer != "")
                {
                    tokens.push_back(getToken(buffer, line));
                    buffer = "";
                }
                twoCh += ch;
                continue;
            }

            else if (whitespace.find(ch) != whitespace.end())
            {
                if (buffer != "")
                {
                    tokens.push_back(getToken(buffer, line));
                    buffer = "";
                }
                continue;
            }

            else
            {
                buffer += ch;
            }

        }
        if(buffer!="\0")
            tokens.push_back(getToken(buffer, line));
        if(twoCh!='\0')
        {
            switch (twoCh) {
                case ';':
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::Semicolons));
                    break;
                case '(':
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::L_br));
                    break;
                case '{':
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::L_brc));
                    break;
                case ')':
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::R_br));
                    break;
                case '}':
                    tokens.push_back(Token(std::string(1, twoCh), TokenType::R_brc));
                    break;
            }
        }
        return tokens;
    }
