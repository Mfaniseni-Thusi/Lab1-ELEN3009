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
