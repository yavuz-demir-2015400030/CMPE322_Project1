//
// Created by Yavuz on 16/11/2018.
//

#include "EventSimulator.h"
#include <fstream>
#include <queue>


EventSimulator::EventSimulator() {
    this->schedule;
    this->outputFile = "";
}


EventSimulator::EventSimulator(vector<Process> _sched, string outputFile) {
    this->schedule = _sched;
    this->outputFile = outputFile;
}

void EventSimulator::Simulate() { //All smilation performs in here

    ofstream out(outputFile);//intializing output file

    priority_queue<Process> scheduleQueue; //queue for processes
    priority_queue<Process> copyQueue; // copy of the process queue for printing the queue


    int i=0; //number of processes
    int elapsedTime = schedule[i].arriveTime; //elapsed time
    if(elapsedTime != 0){
        out<<"0:HEAD--TAIL" << endl;
    }
    Process current = schedule[i]; // process in the execution

    while(true){

        bool changed = false; //shows whether a queue is changed or not

        while(i != schedule.size()-1 && schedule[i+1].arriveTime <= elapsedTime){ // check if the next process has arrived
            schedule[i+1].queueEntry = schedule[i+1].arriveTime; // update new process's queue entry time
            scheduleQueue.push(schedule[i+1]); // add new process to the queue
            changed = true; // queue is changed because of the new process/es
            i++; // increment the number of processes
        }

        if(scheduleQueue.size() == 0){ // if there is no process in the queue
            if(current.pointer == current.codeFile._instr.size()){ // chech if the current process finished it's instructions
                if(i == schedule.size()-1){ // check whether it is the last process of not
                    break;
                }else{ // if it is not the last process fetch the next process
                    current = schedule[i];
                    elapsedTime = current.arriveTime;
                    changed = true;
                }
            }else if(i == 0 && current.pointer == 0){
                changed = true; // fetch the first process
            }

        }else if(scheduleQueue.top().priority < current.priority){ //if there is a prior process in the queue fetch the prior process
            current.queueEntry = elapsedTime;
            scheduleQueue.push(current); // add current process to the queue
            current = scheduleQueue.top();
            current.waitingTime += elapsedTime - current.queueEntry; //update the prior process's waiting time
            scheduleQueue.pop();
            changed = true;
        }else{
            if(current.pointer == current.codeFile._instr.size()){ // if current process finished fetch the next one in the queue

                current = scheduleQueue.top();
                scheduleQueue.pop();
                current.waitingTime += elapsedTime - current.queueEntry;
                changed = true;
            }
        }

        if(changed){ //if queue is changed print the state of the queue
            out<< elapsedTime << ":HEAD-" << current.name << "[" << current.pointer+1 << "]-" ;
            copyQueue = scheduleQueue; //create a copy queue for iterate
            while(copyQueue.size() != 0){
                out << copyQueue.top().name << "[" << copyQueue.top().pointer+1 << "]-" ;
                copyQueue.pop();
            }

            out<<"TAIL" << endl;

        }

        elapsedTime += current.codeFile._instr[current.pointer]; //update elapsed time
        current.pointer++; // update instruction pointer

        current.turnAroundTime = elapsedTime - current.arriveTime; //update turn out time
        schedule[current.number] = current; // update process in the array;

    }

    out<<elapsedTime <<":HEAD--TAIL\n" << endl;

    for(int i=0; i<schedule.size(); i++){
        out<< "Turnaround time for " << schedule[i].name << " = " << schedule[i].turnAroundTime << " ms"<< endl;
        out<< "Waiting time for " << schedule[i].name << " = " << schedule[i].waitingTime << " ms"<< endl;
    }

}