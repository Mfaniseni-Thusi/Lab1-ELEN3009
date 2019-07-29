// Exercising the Screen class
#include "screen.h"
#include <iostream>

using namespace std;

int main()
{
    cout << "Question 4.1" << endl;
                                             //    enum Direction;
	Screen myScreen = Screen{20,20};
	myScreen.clear();

        myScreen.move(1,1);
        myScreen.set('*');
        myScreen.move(myScreen.FORWARD);
        myScreen.set('*');
	myScreen.display();
	cout << endl;
	myScreen.clear();

/*	myScreen.reSize(16,16);
	myScreen.display();
	cout << endl;
	//myScreen.clear(' ');
	myScreen.clear(); */
	return 0;
}
