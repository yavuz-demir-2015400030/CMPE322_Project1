//
// Created by Yavuz on 12/11/2018.
//

#include "CodeFile.h"
#include <fstream>


CodeFile::CodeFile() {
    this->name = "";
}

CodeFile::CodeFile(string fileName) {



    ifstream file(fileName+".txt"); //Code file name has to exist in the same place with the source code with .txt extension

    bool exit = false;
    while(file.peek()!=EOF && !exit){ //Loop until there is no instruction left

        //Content of code files
        string INSTRUCTION_NAME;
        int INSTRUCTION_EXECUTION_TIME;
        file >> INSTRUCTION_NAME >> INSTRUCTION_EXECUTION_TIME;
        _instr.push_back(INSTRUCTION_EXECUTION_TIME);
        exit = "exit" == INSTRUCTION_NAME;

    }


}