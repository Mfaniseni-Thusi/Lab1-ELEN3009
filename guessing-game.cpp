#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

bool randomNumberGenerator();

int main()
{
    srand(time(0));  //seed a number based on the current calender time
    randomNumberGenerator();

    while(true == randomNumberGenerator()){
        randomNumberGenerator();
    }

    return 0;
}

bool randomNumberGenerator(){
    const int RANDOM_NUMBER = rand()%100;
    int usersGuess=0;

    for(int counter=0; counter<5; counter++){
        cout << "Guess an integer less than 100: ";
        cin >> usersGuess;
        while(usersGuess > 100 || usersGuess < 0){
            cout << "\nInvalid Input! Guess an integer less than 100: ";
            cin >> usersGuess;
        }
        cout << endl;

        if(usersGuess < RANDOM_NUMBER && counter < 4){
            cout << "Guess Higher" << endl;
        }
        else if(usersGuess > RANDOM_NUMBER && counter < 4){
            cout << "Guess Lower" << endl;
        }
        else if(usersGuess == RANDOM_NUMBER && counter < 5){
            cout << "You Win! " << "The RANDOM NUMBER was " << RANDOM_NUMBER << "\n" << endl;
            return true;
        }
        else if(usersGuess != RANDOM_NUMBER && counter == 4){
            cout << "You Lose! " << "The RANDOM NUMBER was " << RANDOM_NUMBER << endl;
            return false;
        }

    }
}
