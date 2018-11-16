#include <iostream>
#include <fstream>
#include <vector>
#include "Process.h"
#include "EventSimulator.h"
using namespace std;

int main(int argc, char* argv[]) {

    if (argc != 3) {
        cout << "Run the code with the following command: ./project1 [input_file] [output_file]" << endl;
        return 1;
    }

    cout << "input file: " << argv[1] << endl;
    cout << "output file: " << argv[2] << endl;

    ifstream input(argv[1]);

   vector<Process> procs;


    int i=0;
    while(input.peek()!=EOF){

        string a, c;
        int b;
        double d;
        input >> a >> b >> c >> d;

        Process p = Process(a, b, c, d, i);
        i++;
        procs.push_back(p);

    }

    EventSimulator scheduler = EventSimulator(procs, argv[2]);

    scheduler.Simulate();






//    cout << scheduler.schedule[1].codeFile._instr[2] << endl;



    return 0;
}