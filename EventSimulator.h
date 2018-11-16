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

    vector<Process> schedule;
    string outputFile;

    EventSimulator();
    EventSimulator(vector<Process> _sched, string outputFile);

    void Simulate();



};


#endif //CMPE322_PROJECT1_EVENTSIMULATOR_H
