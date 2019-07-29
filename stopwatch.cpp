#include "StopWatch.h"
#include <ctime>
#include <iostream>
using namespace std;

// returns the amount of time in seconds that has passed since the process (i.e. your program) started executing

StopWatch::StopWatch(){}

double StopWatch::getProcessTime(){
    string Button = "";
    clock_t Time;

    cout << "Type START to start the timer" << endl;

    while(cin >> Button){
        if(Button == "START"){
            Time = clock();
            break;
        }
        else{
            cout << "\nInvalid! Type START to start the timer " << endl;
        }
    }

    cout << "The timer has started...\n\nType STOP to stop the timer ";

    while(cin >> Button){
        if(Button == "STOP"){
            break;
        }
        else{
            cout << "\nInvalid! Type STOP to stop the timer " << endl;
        }
    }

    return static_cast<double>(clock() - Time)/CLOCKS_PER_SEC;
}
