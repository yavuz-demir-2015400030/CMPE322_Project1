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

    string name;


    vector<int> _instr;

    CodeFile(string fileName);
    CodeFile();


};


#endif //CMPE322_PROJECT1_CODEFILE_H
