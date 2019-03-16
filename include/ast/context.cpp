#include "context.hpp"

//---------------------------------------------//
//--------------Lexer_Context------------------//
//---------------------------------------------//


void lexContext::incScope(){
        type_defs.push_back(type_defs[scopeLevel]);
        scopeLevel++;
    }

void lexContext::decScope(){
        type_defs.pop_back();
        scopeLevel--;
    }

//---------------------------------------------//
//--------------Python_Context-----------------//
//---------------------------------------------//

void pyContext::incScope(){
        scopeLevel++;
    }

void pyContext::decScope(){
        scopeLevel--;
    }

//---------------------------------------------//
//----------------tempDecl_Struct--------------//
//---------------------------------------------//

void DeclaratorContext::purge(){
    id.clear();
    initliased = false;
    int size = 0;
}

void DeclaratorContext::nextElement(){
    id.clear();
    initliased = false;
}

int DeclaratorContext::totSize(){
    return size * elements;
}

//---------------------------------------------//
//----------------Vardata_Struct---------------//
//---------------------------------------------//



//---------------------------------------------//
//----------------Scope_Struct-----------------//
//---------------------------------------------//

scope::scope(std::map<std::string, varData>& _bindings): bindings(_bindings){}

//---------------------------------------------//
//----------------funcScope_Struct-------------//
//---------------------------------------------//

void funcScope::incScope(){
    scopes.push_back(scope(scopes[scopeLevel].bindings)); //when you enter a new scope, take the old scope bindings and put them into the new one
    scopeLevel++;
}

//---------------------------------------------//
//----------------Compiler_Context-------------//
//---------------------------------------------//

void compilerContext::newFunc(){
    functions.push_back(funcScope());
}

std::map<std::string, varData>* compilerContext::currentBindings(){
    return &functions.back().scopes.back().bindings;
}

void compilerContext::addToStack(int size, std::ostream& os){
    os << "addiu $sp, $sp, " << -size << std::endl;
}