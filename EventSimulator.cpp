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

void EventSimulator::Simulate() {

    ofstream out(outputFile);

    priority_queue<Process> scheduleQueue;
    priority_queue<Process> copyQueue;

    out<<"0:HEAD--TAIL" << endl;
    int i=0;
    int elapsedTime = schedule[i].arriveTime;
    Process current = schedule[i];




    while(true){
        bool changed = false;
        while(i != schedule.size()-1 && schedule[i+1].arriveTime <= elapsedTime){
            schedule[i+1].queueEntry = schedule[i+1].arriveTime;
            scheduleQueue.push(schedule[i+1]);
            changed = true;
            i++;
        }

        if(scheduleQueue.size() == 0){
            if(current.pointer == current.codeFile._instr.size()){
                if(i == schedule.size()-1){
                    break;
                }else{
                    current = schedule[i];
                    elapsedTime = current.arriveTime;
                    changed = true;
                }
            }else if(i == 0 && current.pointer == 0){
                changed = true;
            }


        }else if(scheduleQueue.top().priority < current.priority){
            current.queueEntry = elapsedTime;
            scheduleQueue.push(current);
            current = scheduleQueue.top();
            current.waitingTime += elapsedTime - current.queueEntry;
            scheduleQueue.pop();
            changed = true;

        }else{
            if(current.pointer == current.codeFile._instr.size()){

                current = scheduleQueue.top();
                scheduleQueue.pop();
                current.waitingTime += elapsedTime - current.queueEntry;
                changed = true;
            }
        }



        if(changed){
            out<< elapsedTime << ":HEAD-" << current.name << "[" << current.pointer+1 << "]-" ;
            copyQueue = scheduleQueue;
            while(copyQueue.size() != 0 ){
                out << copyQueue.top().name << "[" << copyQueue.top().pointer+1 << "]-" ;
                copyQueue.pop();
            }
            out<<"TAIL" << endl;

        }

        elapsedTime += current.codeFile._instr[current.pointer];
        current.pointer++;

        current.turnAroundTime = elapsedTime - current.arriveTime;
        schedule[current.number] = current;

    }

    out<<elapsedTime <<":HEAD--TAIL\n" << endl;

    for(int i=0; i<schedule.size(); i++){
        out<< "Turnaround time for " << schedule[i].name << " = " << schedule[i].turnAroundTime << " ms"<< endl;
        out<< "Waiting time for " << schedule[i].name << " = " << schedule[i].waitingTime << " ms"<< endl;
    }


}