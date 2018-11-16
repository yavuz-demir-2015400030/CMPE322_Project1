//
// Created by Yavuz on 12/11/2018.
//

#include "CodeFile.h"
#include <fstream>


CodeFile::CodeFile() {
    this->name = "";

}

CodeFile::CodeFile(string fileName) {



    ifstream file(fileName+".txt");

    while(file.peek()!=EOF){


        string a;
        int b;
        file >> a >> b;
        _instr.push_back(b);

    }


}