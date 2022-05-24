cmake_minimum_required(VERSION 3.21)
project(program_language)

set(CMAKE_CXX_STANDARD 23)

add_executable(
        program_language

        main.cpp

        Lexer.cpp
        Lexer.h

        Token.cpp
        Token.h

        Parser.cpp
        Parser.h

        ParserException.cpp
        ParserException.h

        Expr.cpp
        Expr.h

        ExpAs.cpp
        ExpAs.h

        ExpID.cpp
        ExpID.h

        ExpSUM.cpp
        ExpSUM.h

        ExpSUB.cpp
        ExpSUB.h

        ExpDIV.cpp
        ExpDIV.h

        ExpMULT.cpp
        ExpMULT.h

        ExpINT.cpp
        ExpINT.h

        ExpDOUB.cpp
        ExpDOUB.h

        ExpLBR.cpp
        ExpLBR.h

        ExpLBRC.cpp
        ExpLBRC.h

        ExpRBR.cpp
        ExpRBR.h

        ExpRBRC.cpp
        ExpRBRC.h

        Node.cpp
        Node.h

        ExpIF.cpp
        ExpIF.h

        ExpWHILE.cpp
        ExpWHILE.h

        ExpCOMPARE.cpp
        ExpCOMPARE.h

        ExpSMALLER.cpp
        ExpSMALLER.h

        ExpMORE.cpp
        ExpMORE.h

        ExpSMALEQ.cpp
        ExpSMALEQ.h

        ExpMOREEQ.cpp
        ExpMOREEQ.h

        ExpLOGUM.cpp
        ExpLOGUM.h

        ExpLOGOR.cpp
        ExpLOGOR.h

        ExpNOTEQ.cpp
        ExpNOTEQ.h

        ExpNOT.cpp
        ExpNOT.h

        ExpSEM.cpp
        ExpSEM.h

        ExpBlock.cpp
        ExpBlock.h

        variables/Var.cpp
        variables/Var.h

        variables/VarBool.cpp
        variables/VarBool.h

        variables/VarInteger.cpp
        variables/VarInteger.h

        variables/VarDouble.cpp
        variables/VarDouble.h

        variables/VarList.cpp
        variables/VarList.h

        variables/VarMap.cpp
        variables/VarMap.h

        variables/VarString.cpp
        variables/VarString.h

        Interpreter.cpp
        Interpreter.h

        InterpreterArgs.cpp
        InterpreterArgs.h
        ExpPRINT.cpp ExpPRINT.h)
