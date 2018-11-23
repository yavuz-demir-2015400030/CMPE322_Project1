
/*@Author Ahmet Yavuz Demir
 * Student ID : 2015400030
 * CMPE322 Operating Systems
 * Project-1
 */


#include <iostream>
#include <fstream>
#include <vector>
#include "Process.h"
#include "EventSimulator.h"
using namespace std;

int main(int argc, char* argv[]) {

    //If more or less arguments are given in the terminal exit
    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    //Open filereader for definition file
    ifstream input(argv[1]);

    //Create an vector for processes
    vector<Process> procs;


    int i=0; //ID of the process
    while(input.peek()!=EOF){ //cycles until there is no process left

        //Content of processes
        string Process_Name, Program_Code_File;
        int Priority;
        double Arrival_Time_ms;
        input >> Process_Name >> Priority >> Program_Code_File >> Arrival_Time_ms;

        Process p = Process(Process_Name, Priority, Program_Code_File, Arrival_Time_ms, i);
        i++;//updated in each cycle
        procs.push_back(p);//process is pushed to the vector

    }

    EventSimulator scheduler = EventSimulator(procs, argv[2]);//initialize EventSimulator

    scheduler.Simulate();//Simulate the events

    return 0;
}