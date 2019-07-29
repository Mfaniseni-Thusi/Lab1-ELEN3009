#include <iostream>
#include <cmath>
#include <complex>
#include <cstdlib>

using namespace std;

void calcTheRoots();
char doYouWantToContinue();

int main()
{
    calcTheRoots();
    while(doYouWantToContinue() != 'q'){
        if(doYouWantToContinue() == 'c'){
            cout << endl;
            calcTheRoots();
        }
        else {
            cout << "Invalid input!" << endl;
        }
    }

    return 0;
}


void calcTheRoots(){
    double a=0;
    double b=0;
    double c=0;
    double roots[2]={0};

    cout << "Insert your coefficients:\n" << "a: ";
    while(!(cin >> a)){
          cin.clear();
          cin.ignore(INT_MAX,'\n');
          cout << "Invalid input, try again\na: ";
    }

    cout << "\nb: ";
    while(!(cin >> b)){
          cin.clear();
          cin.ignore(INT_MAX,'\n');
          cout << "Invalid input, try again\nb: ";
    }

    cout << "\nc: ";
    while(!(cin >> c)){
          cin.clear();
          cin.ignore(INT_MAX,'\n');
          cout << "Invalid input, try again\nc: ";
    }


    double underBrackets = pow(b,2) - 4*a*c;
   // if(underBrackets >= 0){
        roots[0] = (-b+sqrt(underBrackets))/2*a;
        roots[1] = (-b-sqrt(underBrackets))/2*a;
        cout << "First root = " << roots[0] << "\nSecond root = " << roots[1] << endl;
   // }
//    else{
//        cout << "The roots are Imaginary" << endl;
//    }
}

char doYouWantToContinue(){
    char answer = ' ';
    cout << "Enter \'c\' if you want to continue or \'q\' to quit!" << endl;
    cin >> answer;

    if(answer != 'c' && answer != 'q'){
        answer = tolower(answer);
    }

    return answer;
}
