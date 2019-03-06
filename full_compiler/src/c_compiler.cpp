#include "../include/ast.hpp"



int main(int argc, char* argv[]){
    if(argc != 5){ 
        std::cerr << "invalid input format" << std::endl;
        return -1;
    }

    if(std::string(argv[1]) =="--translate"){
        //create AST
        Node* ast = parseAST(argv[2]); 
        ast->printTree(0);
        
        //create context and ostream
        pyContext context;
        std::ostream* os = &std::cout;
        std::ofstream stream;
        stream.open(argv[4]);
        os = &stream;

        //run print py
        ast->printPy(context, *os);
        stream.close();
        std::cout << "succesful python";
        return 0;
    }
    else if(std::string(argv[1]) == "-S"){
        //create AST
        Node* ast = parseAST(argv[2]);
        ast->printMips();
        return 0;
    }
    else std::cerr << "invalid input format" << std::endl;
    return -1;
}