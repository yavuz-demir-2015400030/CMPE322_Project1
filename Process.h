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


    int number; //id of the process
    string name; // name of the process
    int priority; // priority of the process
    string codeFileName; // code file of the proces
    CodeFile codeFile;
    int pointer; // points the next instruction to execute
    int arriveTime; // arrive time of process
    int turnAroundTime; // total time of the process spend in the queue and execution
    int waitingTime; // time spend in the queue
    int queueEntry; // time when process return to the queue

    Process();//default constructor
    Process(string name, int priority, string codeFileName, int time, int number); // constructor
    Process(const Process& other); //copy constructor
    Process& operator=(const Process& other); //assignment operator
    // bool operators for comparison
    bool operator==(const Process& other) const;
    bool operator<(const Process& other) const;

};


#endif //CMPE322_PROJECT1_PROCESS_H
