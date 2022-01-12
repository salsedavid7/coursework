#include <stdio.h>
#include <cstdlib> 
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm> 

using namespace std;
    
int main (){
    //randomly generates the answer from a file
    vector<string> words;
    ifstream file("words.txt");
    string line;
    while (getline(file, line)) {
        words.push_back(line);
    }
    //stores answer
    string answer = words[arc4random_uniform(10)];
    //vector declaration for found char indexes
    vector<int> foundChar;
    //correct amt of guesses
    int count = 0;
    //user lives
    int lives = 6;
    
    //loops game
    while (count < (answer.size() - 1) && lives > 0) {
        cout << " \nYou have: " << lives << " guesses >:)" << endl;
        
        count = 0; //variable to keep track of correct user guesses

        for (int i = 0; i < answer.length(); i++) {
            if (find (foundChar.begin(), foundChar.end(), i) != foundChar.end()) {
                cout << answer[i] << " "; //letter found and prints it
                count++; //add to correct guess total
            }
            else {
                cout << "_ "; //incorrect guess
            }
        }
        cout << endl;

        char userGuess = ' ';
        bool found = false;
        cout << "Choose letter..." << endl;
        cin >> userGuess;
    
        //checks to see if the users answer choice is valid
        for (int i = 0; i < answer.length(); i++) {
            if (userGuess == answer[i]) {
                found = true;
                foundChar.push_back(i);
            }
        }
        
        //decrements lives if the guess is invalid
        if (found == false)
            lives--;
        
    }

    //win/lose output msgs
    if (lives != 0)
        cout << "\nYou guessed " << answer << " correct!" << endl;
    else
        cout << "\nYOU SUCK! The answer was: " << answer << endl;
    }   