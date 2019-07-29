#include <iostream>
#include <ctime>
#include <locale>
#include "StopWatch.h"

using namespace std;

int main()
{
    StopWatch SWobj = StopWatch();
    cout << "\nTimer has run for: " << SWobj.getProcessTime() << "s" << endl;
    return 0;
}
