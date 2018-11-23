//
// Created by Yavuz on 12/11/2018.
//

#ifndef CMPE322_PROJECT1_CODEFILE_H
#define CMPE322_PROJECT1_CODEFILE_H

#include <iostream>
#include <vector>

using namespace std;

class CodeFile {
public:

    string name;//Name of the code file
    vector<int> _instr; //vector for storing each instruction's execution time

    CodeFile(string fileName); // constructor
    CodeFile(); // default constructor


};


#endif //CMPE322_PROJECT1_CODEFILE_H
