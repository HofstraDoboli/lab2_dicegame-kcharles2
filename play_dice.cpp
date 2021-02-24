/* Kaihil Charles */
    
#include <iostream>
#include <cstdlib>  // contains the rand() and srand() function 
#include <ctime>    // time() function
using namespace std;


int main()
{
    srand(time(0)); // initialize random seed generator to current time: 
					// needed to generate a different sequence of random numbers
					// each time you run your program

char startGame;//stores a character the user enters to start the game loop
int dice1, dice2;
int sum;


//Welcome message
cout << "Welcome to my dice game. Enter 'y' to play ";
cin >> startGame;

while ( startGame == 'y' || startGame == 'Y' ) { //The Gameplay loop
    
    // Dice roll. Generates two random numbers between 1 and 6.
    dice1 = rand()%6 + 1;
    dice2 = rand()%6 + 1;
    sum = dice1 + dice2;

    bool winFirstRoll = (sum == 7 || sum == 11); //CASE 1: Sum of random numbers = 7 or 11. WIN
    bool loseFirstRoll = (sum == 2 || sum == 3 || sum == 12); //CASE 2: Sum of random numbers = 2, 3 or 12. LOSE

    //Display message "You rolled a # and a #. Your sum is: #"
    cout << "You rolled a " << dice1 << " and a " << dice2 << ". Your sum is: " << sum << endl;
        
    if (winFirstRoll) //CASE 1
        cout << "You win! Hooray!\n";

    else if (loseFirstRoll) //CASE 2
        cout << "Oh no, you lose! \n";
    
    else { //CASE 3
        int point = sum; //Stores the sum in another variable
        char roll;

       
       do {// Rolls until the player scores 7 or their point.
       //Display: "Roll again. Score a # to win."
        cout << "Roll again. Score a " << point << " to win.\n";
        cout << "Enter any key ";
        cin >> roll;

        dice1 = rand()%6 + 1;
        dice2 = rand()%6 + 1;
        sum = dice1 + dice2;

                
        cout << "You rolled a " << dice1 << " and a " << dice2 << ". Your sum is: " << sum << endl;
                
        } while (sum != point && sum != 7);
       
       //To win in case 3, the player must roll until they score their point. (point == sum)
        if (sum == point) 
                cout << "You win! Hooray!\n";
            
            //OR if they roll a 7 they lose.
            else 
                cout << "Oh no you lost!\n";


    }
    //GAME END: Ask the player to play again. If they press Y then restart the game.

        cout << "Would you like to play again? Enter 'y' to restart the game or another key to exit ";
    cin >> startGame;
}


}
