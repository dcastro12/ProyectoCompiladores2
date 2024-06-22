#ifndef __MINI_LPP__PARSE_HPP__
#define __MINI_LPP__PARSE_HPP__


#include "Mini_LPP_Lexer.hpp"
#include "Mini_LPP_ParserImpl.hpp"
#include "Mini_LPP_Ast.hpp"
#include <string>
#include <iostream>
#include <fstream>
#include <string>

class Mini_LPP_Parser
{
private:
   Mini_LPP_Lexer& lexer;
   AstNode* ast;
   Types_vars types_ide;
public:
    Mini_LPP_Parser(Mini_LPP_Lexer& lexer): lexer(lexer){};

    int parse();


    Mini_LPP_Lexer& getLexer() const
    {
        return lexer;
    }

    void setRoot(AstNode* root)
    {
        ast = root;
        
    }

    AstNode* getRoot() const
    {
        return ast;
    }


    
    void Add_var_type(std::string tipos, std::string variable)
    {
        bool encontrado = false;
        for (const auto& var : types_ide) {
            if (var.vars_ebp == variable) {
                encontrado = true;
                std::string msgcompleto = "Error: Variable ya declarada anteriormente " + variable;
                throw std::runtime_error(msgcompleto.c_str());\
                break;
            }
        }
        int posicion = 0;

        if(tipos == "anterior")
        {
            if (!encontrado) {
                

                types_ide.push_back({"siguiente", variable});
                
            }

        }else {
            if (!encontrado) {
                
                types_ide.push_back({tipos, variable});
                
            }
        }
            
    };

    Types_vars& getVector()
    {
        std::vector<int> posiciones;
        std::string tipoAn ;
        for (int i = 0; i < types_ide.size(); i++) {
            
            if(types_ide[i].type == "siguiente")
            {
                posiciones.push_back(i);
            }else
            {
                tipoAn = types_ide[i].type;
                for(int j = 0; j < posiciones.size(); j++)
                {
                    types_ide[posiciones[j]].type = tipoAn;
                }
                posiciones.clear();
                tipoAn = "";
            }
          
        }
        return types_ide;
    }

};

#endif