#define _CRT_SECURE_NO_DEPRECATE
#include "utilities.h"
#include <iostream>
#include <cstring>
using namespace std;

const char WORDFILENAME[] = "/Users/shreya/Documents/College/1/1/CS31/Project5/words.txt";
const int MAXINPUT = 100;
const int MAXWORDS = 9000;

int runOneRound(const char words[][7], int nWords, int wordnum);

int main() {    
    char wordList[MAXWORDS][MAXWORDLEN + 1];
    int nWords = getWords(wordList, MAXWORDS, WORDFILENAME);
    if (nWords < 1) {
        cout << "No words were loaded, so I can't play the game." << endl;
        return -1;
    }
    if (nWords > MAXWORDS) {
        return 0;
    }
    
    int rounds = 0;
    cout << "How many rounds do you want to play? ";
    cin >> rounds;
    if (rounds <= 0) {             // terminates program if number of rounds is not positive
        cout << "The number of rounds must be positive." << endl;
        return -1;
    }
    cin.ignore(10000, '\n');
    cout << endl;
    
    int min = 10000000;
    int max = 0;
    double grand = 0;
    double gameCount = 0;       // number of games
    for (int i = 0; i < rounds; i++) {
        cout << "Round " << i + 1 << endl;
        int wordnum = randInt(0, nWords - 1);
        cout << "The secret word is " << strlen(wordList[wordnum]) << " letters long." << endl;
        int total = runOneRound(wordList, nWords, wordnum);     // sets total to the score
        if (total == 1){
            cout << "You got it in 1 try." << endl;
        } else {
            cout << "You got it in " << total << " tries." << endl;
        }
        gameCount++;
        grand += total;
        if (total <= min) {     // checks if the total scores is less than the min
            min = total;
        }
        if (total >= max) {     // checks if the total score is greater than the max
            max = total;
        }
        cout.setf(ios::fixed);
        cout.precision(2);      // sets average to have 2 decimal places
        cout << "Average: " << (grand/gameCount) << ", minimum: " << min << ", maximum: " << max << endl;
        cout << endl;
    }
    return 0;
}

int runOneRound(const char words[][7], int nWords, int wordnum) {
    if (nWords < 0 || wordnum < 0 || wordnum >= nWords)     // checks for bad input
        return -1;
    char probe[MAXINPUT];                   // temp probe word
    char probefinal[MAXWORDLEN + 1];        // final probe word
    
    int stars = 0;
    int planets = 0;
    int score = 0;
    
    char secret[MAXWORDLEN + 1];            // temp secret word
    char finalsecret[MAXWORDLEN + 1];       // final secret word
    
    strcpy(secret, words[wordnum]);         // set secret to random word in wordlist
    strcpy(finalsecret, words[wordnum]);    // set finalsecret to random word in wordlist
    
    for (int i = 0; strcmp(probe, secret) != 0; i++) {
        int test = 0;
        cout << "Probe word: ";
        
        cin.getline(probe, MAXINPUT + 1);
        cin.clear();
        cin.sync();
        
        if (strcmp(probe, secret) == 0)     // if probe is the secret word, break out of the loop
            break;
        if (strlen(probe) < MINWORDLEN || strlen(probe) > MAXWORDLEN) {     // checks if probe is between 4 and 6 letters
            cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
            continue;
        }
        for (int j = 0; probe[j] != '\0'; j++) {
            if (isupper(probe[j]) || ! isalpha(probe[j])) {     // chekcs if the characters in the probe word and lowercase
                cout << "Your probe word must be a word of 4 to 6 lower case letters." << endl;
                test = 1;
            }
            if (test == 1)
                break;
        }
        if (test == 1)
            continue;
        for (int k = 0; k < nWords; k++) {             // checks if word is in wordlist
            if (strcmp(words[k], probe) == 0)
                break;
            if (k == nWords - 1) {
                cout << "I don't know that word." << endl;
                test = 1;
            }
        }
        if (test == 1){
            continue;
        }
        stars = 0;
        planets = 0;
        // replaces stars and planets with 1s and 0s to check for overlaps
        for (int x = 0; x < 2; x++) {
            for (int y = 0; secret[y] != '\0'; y++) {
                for (int z = 0; probe[z] != '\0'; z++) {
                    if (probe[z] == secret[y] && y == z && x == 0) {
                        probe[z] = '0';
                        secret[y] = '1';
                        stars++;
                        if(secret[y + 1] != '\0' || probe[y + 1] != '\0')
                            y++;
                    }
                    else if (probe[z] == secret[y] && x == 1) {
                        probe[z] = '0';
                        secret[y] = '1';
                        planets++;
                    }
                }
            }
        }
        strcpy(probe, probefinal);      // resets the probe word to original
        strcpy(secret, finalsecret);    // resets the secret word to original
        cout << "Stars: " << stars << ", Planets: " << planets << endl;
        score++;
    }
    return score + 1;
}
