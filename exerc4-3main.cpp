// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Question 4.1" << endl;
	Screen myScreen = Screen{20,20};
	myScreen.clear();

    myScreen.move(1,1);
    //myScreen.set('*');
    myScreen.move(myScreen.UP);
    myScreen.set('*');
    myScreen.move(myScreen.FORWARD);
    myScreen.set('*');
    myScreen.move(myScreen.DOWN);
    myScreen.set('*');
	myScreen.display();
	myScreen.clear();

	return 0;
}

/* 1. Change the string::string-type and use string
   2. Instead of using auto we can explicitly declare the type of a variable - this helps improve the readability of the code.

    NOT CHANGING PUBLIC INTERFACE:
    - It helps keep improve the efficiency of the code without having the user to adapt to a new outlook
      of a program every time there is a change to be implemented.

    CHANGING IMPLEMENTATION:
    - It gives a developer the ability to maintain their program and have control over it.
      We are free to change it because it does not necessarily interfere with the user if approached rightly.
*/
