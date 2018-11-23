//
// Created by Yavuz on 16/11/2018.
//

#ifndef CMPE322_PROJECT1_EVENTSIMULATOR_H
#define CMPE322_PROJECT1_EVENTSIMULATOR_H

#include <iostream>
#include <vector>
#include "Process.h"
using namespace std;

class EventSimulator {
public:

    vector<Process> schedule; // vector to store processes
    string outputFile; // name of the file output will be shown, taken as a command line argument

    EventSimulator();//default constructor
    EventSimulator(vector<Process> _sched, string outputFile); // constructor

    void Simulate(); // scheduler simulation performed here



};


#endif //CMPE322_PROJECT1_EVENTSIMULATOR_H
