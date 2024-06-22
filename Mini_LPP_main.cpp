#include <iostream>
#include <fstream>
#include "Mini_LPP_Lexer.hpp"
#include "Mini_LPP_Parser.hpp"
#include <unordered_map>




std::string runCmd(const std::string& cmd)
{
    FILE *stream = popen(cmd.c_str(), "r");
    if (stream == nullptr) {
        throw std::runtime_error("popen() failed!");
    }

    std::ostringstream ssdata;
    char buffer[256] = {0};

    while (fgets(buffer, sizeof(buffer) - 1, stream))
        ssdata << buffer;

    pclose(stream);
    return ssdata.str();
}



std::string runASM(std::string name_file ,std::string code)
{
        
        std::ofstream archivo;
        archivo.open(name_file, std::ios::out | std::ios::trunc);
        if (!archivo.is_open()) {
           throw std::runtime_error("Failed to open asm file for writing!");
        }
        archivo << code;
        archivo.close();

        std::string cmd = "../EasyASM-x86 --run "+ name_file + " 2>&1";

        
    std::cout<< "\n"<<runCmd(cmd);
        
};



int main(int argc, char *argv[]) 
{
    if (argc != 3) {
        std::cerr << "Not enough CLI arguments\n";
        return 1;
    }
    
    std::string fileLPP = argv[1];
    std::string fileASM = argv[2];


    
    std::ifstream in(fileLPP, std::ios::in);
    if (!in.is_open()) {
        std::cerr << "Cannot open input file\n";
        return 1;
    }

    Mini_LPP_Lexer lexer(in);
    Mini_LPP_Parser parser(lexer);
   
   try
   {
        parser.parse();

        std::string code = parser.getRoot()->GeneratorCode(parser.getVector());
        runASM(fileASM, code);
        return 0;
   }
   catch(const std::exception& e)
   {
        std::cerr << e.what() << '\n';
   }
   
}