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

    

    //Gameplay: The player throws two random dice (two random numbers 1 - 6).
char startGame;
int dice1, dice2;
int sum;

//Welcome message
cout << "Welcome to my dice game. Enter 'y' to play or 'x' to cancel ";
cin >> startGame;

while ( startGame != 'y' && startGame != 'Y' &&  startGame != 'x' && startGame != 'X' ) {
    cout << "Welcome to my dice game. Enter 'y' to play or 'x' to cancel ";
    cin >> startGame;
}

while ( startGame == 'y' || startGame == 'Y' ) { //The Gameplay loop
        // Dice roll. Generate two random numbers between 1 and 6.
    dice1 = rand()%6 + 1;
    dice2 = rand()%6 + 1;
    sum = dice1 + dice2;

    //Display message "You rolled a # and a #. Your sum is: #"
    cout << "You rolled a " << dice1 << " and a " << dice2 << ". Your sum is: " << sum << endl;
        
        /*CASE 1: Sum of random numbers = 7 or 11. WIN
    Display: "You win! Hooray!"*/
    if (sum == 7 || sum == 11) 
        cout << "You win! Hooray!\n";

        /*CASE 2: Sum of random numbers = 2, 3 or 12. LOSE
    Display: "Oh no, you lose!" */
    else if (sum == 2 || sum == 3 || sum == 12)
        cout << "Oh no, you lose! \n";

        /*CASE 3: Sum becomes the player's point. (4,5,6,8,9,10)
        Store the sum in another variable.
    Display: "Roll again. Score a # to win."*/
    else {
        int point = sum;
        char roll;

       // With every roll: (1) Ask the user to enter 'y' to roll and (2) display the dice roll message.
        cout << "Roll again. Score a " << sum << " to win.\n";
        cout << "Enter 'y' ";
        cin >> roll;

            while (roll != 'y' && roll != 'Y' ) {//let user roll
            cout << "Enter 'y' ";
            cin >> roll;  
            }

        //To win in case 3, the player must roll until they score their point. (point == sum)
        dice1 = rand()%6 + 1;
        dice2 = rand()%6 + 1;
        sum = dice1 + dice2;

            while (sum != point && sum != 7) {
                
                cout << "You rolled a " << dice1 << " and a " << dice2 << ". Your sum is: " << sum << endl;
                cout << "Roll again. Score a " << point << " to win.\n";
                cout << "Enter 'y' ";
                cin >> roll;

                    while (roll != 'y' && roll != 'Y' ) {//let user roll
                        cout << "Enter 'y' ";
                        cin >> roll;  
                }

                dice1 = rand()%6 + 1;
                dice2 = rand()%6 + 1;
                sum = dice1 + dice2;

            }

        if (sum == point) {
                cout << "You rolled a " << dice1 << " and a " << dice2 << ". Your sum is: " << sum << endl;
                cout << "You win! Hooray!\n";
        
        }
            
            //OR if they roll a 7 they lose.
            else {
                cout << "You rolled a " << dice1 << " and a " << dice2 << ". Your sum is: " << sum << endl;
                cout << "Oh no you lost!\n";

            }


    }
    //GAME END: Ask the player to play again. If they press Y then restart the game.
    //Display "Would you like to play again? Enter 'Y' to restart the game or 'x' to cancel.

        cout << "Would you like to play again? Enter 'y' to restart the game or 'x' to cancel ";
    cin >> startGame;
}


}
