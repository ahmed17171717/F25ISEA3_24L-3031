#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

// ===================== FUNCTION DECLARATIONS =====================
string getRandomWord(const string& filename);
void displayWord(const string& word, const bool guessed[]);
bool isWordComplete(const bool guessed[], int length);
bool processGuess(const string& word, bool guessed[], char letter);
void playGame(const string& word);

// ===================== MAIN FUNCTION =====================
int main()
{
    cout << "========================================\n";
    cout << "             HANGMAN GAME\n";
    cout << "========================================\n";
    cout << "Hint: FRUITS\n";
    cout << "========================================\n";

    string word = getRandomWord("words.txt");
    playGame(word);

    return 0;
}

// ===================== FUNCTION DEFINITIONS =====================

// --- Reads a random word from a file ---
string getRandomWord(const string& filename)
{
    ifstream file(filename);
    if (!file.is_open())
    {
        cout << "Error: Could not open file '" << filename << "'!" << endl;
        exit(1);
    }

    string words[100];
    int count = 0;

    while (getline(file, words[count]) && count < 100)
    {
        if (!words[count].empty())
        {
            count++;
        }
    }

    file.close();

    if (count == 0)
    {
        cout << "Error: No words found in file!" << endl;
        exit(1);
    }

    srand(static_cast<unsigned>(time(0)));
    int randomIndex = rand() % count;
    return words[randomIndex];
}

// --- Displays the current state of the word ---
void displayWord(const string& word, const bool guessed[])
{
    cout << "Word: ";
    for (int i = 0; i < word.length(); i++)
    {
        if (guessed[i])
        {
            cout << word[i] << " ";
        }
        else
        {
            cout << "_ ";
        }
    }
    cout << endl;
}

// --- Checks if the word is fully guessed ---
bool isWordComplete(const bool guessed[], int length)
{
    for (int i = 0; i < length; i++)
    {
        if (!guessed[i])
        {
            return false;
        }
    }
    return true;
}

// --- Converts uppercase to lowercase  ---
char toLowerChar(char ch)
{
    if (ch >= 'A' && ch <= 'Z')
        ch = ch + 32; 
    return ch;
}

// --- Checks if character is a letter manually ---
bool isAlphabet(char ch)
{
    return (ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z');
}

// --- Processes a player's guess ---
bool processGuess(const string& word, bool guessed[], char letter)
{
    bool found = false;
    letter = toLowerChar(letter);

    for (int i = 0; i < word.length(); i++)
    {
        char lowerWordChar = toLowerChar(word[i]);
        if (lowerWordChar == letter && !guessed[i])
        {
            guessed[i] = true;
            found = true;
        }
    }

    return found;
}

// --- Main gameplay function ---
void playGame(const string& word)
{
    bool guessed[100] = { false };
    int remainingMistakes = 7;
    char letter;

    while (remainingMistakes > 0)
    {
        displayWord(word, guessed);
        cout << "\nRemaining chances: " << remainingMistakes << endl;
        cout << "Enter a letter: ";
        cin >> letter;

        if (!isAlphabet(letter))
        {
            cout << "Invalid input! Please enter a letter.\n\n";
            continue;
        }

        bool found = processGuess(word, guessed, letter);

        if (found)
        {
            cout << "Correct!\n\n";

            if (isWordComplete(guessed, word.length()))
            {
                cout << "========================================\n";
                cout << "Congratulations! You guessed the word!\n";
                cout << "The word was: " << word << endl;
                cout << "========================================\n";
                return;
            }
        }
        else
        {
            remainingMistakes--;
            cout << "Wrong guess!\n\n";
        }
    }

    cout << "========================================\n";
    cout << "Game Over! You lost!\n";
    cout << "The word was: " << word << endl;
    cout << "========================================\n";
}


