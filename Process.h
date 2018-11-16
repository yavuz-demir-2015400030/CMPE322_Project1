//
// Created by Yavuz on 12/11/2018.
//

#ifndef CMPE322_PROJECT1_PROCESS_H
#define CMPE322_PROJECT1_PROCESS_H

#include <iostream>
#include "CodeFile.h"
using namespace std;

class Process {
public:

    int number;
    string name;
    int priority;
    string codeFileName;
    CodeFile codeFile;
    int pointer;
    int arriveTime;
    int turnAroundTime;
    int waitingTime;
    int queueEntry;

    Process();
    Process(string name, int priority, string codeFileName, int time, int number);
    Process(const Process& other);
    Process& operator=(const Process& other);



    bool operator==(const Process& other) const;
    bool operator<(const Process& other) const;

};


#endif //CMPE322_PROJECT1_PROCESS_H
