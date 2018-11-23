//
// Created by Yavuz on 12/11/2018.
//

#include "Process.h"

Process::Process() {
    number = -1;
    name = "";
    priority = -1;
    codeFileName = "";
    this->arriveTime = -1;
    this->pointer = -1;
    codeFile = CodeFile();
    this->turnAroundTime = -1;
    this->waitingTime = -1;
    this->queueEntry = -1;
}


Process::Process(string name, int priority, string codeFileName, int time, int number) {
    this->number = number;
    this->queueEntry = 0;
    this->name = name;
    this->priority = priority;
    this->codeFileName = codeFileName;
    this->arriveTime = time;
    this->pointer = 0;
    this->turnAroundTime = 0;
    this->waitingTime = 0;
    codeFile = CodeFile(codeFileName);
}

Process::Process(const Process &other) {
    this->waitingTime = other.waitingTime;
    this->turnAroundTime = other.turnAroundTime;
    this->name = other.name;
    this->arriveTime= other.arriveTime;
    this->pointer = other.pointer;
    this->codeFile = other.codeFile;
    this->priority = other.priority;
    this->codeFileName = other.codeFileName;
    this->number = other.number;
    this->queueEntry = other.queueEntry;
}


Process& Process::operator = (const Process &other){
    this->waitingTime = other.waitingTime;
    this->turnAroundTime = other.turnAroundTime;
    this->name = other.name;
    this->arriveTime= other.arriveTime;
    this->pointer = other.pointer;
    this->codeFile = other.codeFile;
    this->priority = other.priority;
    this->codeFileName = other.codeFileName;
    this->number = other.number;
    this->queueEntry = other.queueEntry;
    return *this;
}


bool Process::operator==(const Process &other) const {

    return this->priority == other.priority;

}

bool Process::operator<(const Process &other) const {
    return this->priority > other.priority || (this->priority==other.priority && this->arriveTime>other.arriveTime) ||
            ((this->priority==other.priority && this->arriveTime==other.arriveTime && this->number > other.number));
}

