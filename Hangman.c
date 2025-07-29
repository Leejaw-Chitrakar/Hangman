// C program to implement hangman game
#include <ctype.h>
#include <conio.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 6

// Struct to hold a word and its hint
struct WordWithHint {
    char word[MAX_WORD_LENGTH];
    char hint[MAX_WORD_LENGTH];
};

// Function to display the current state of the word
void displayWord(const char word[], const bool guessed[]);

// Function to draw the hangman
void drawHangman(int tries);

// driver code
int main()
{
    // Seed the random number generator with the current
    // time
    srand(time(NULL));
    // Array of words with hints
    struct WordWithHint wordList[] = {
    { "computer", "A machine that processes data" },
    { "programming", "Writing instructions for a computer" },
    { "hardware", "The physical parts of a computer system" },
    { "protocol", "A set of rules governing the format and transmission of data" },
    { "malware", "Malicious software designed to harm computer systems" },
    { "internet", "A global network of interconnected computer networks" },
    { "database", "A collection of organized data, often stored and accessed electronically" },
    { "debugging", "The process of finding and fixing errors in software" },
    { "interface", "A visual interface element that allows users to interact with software" },
    { "encryption", "Securely transferring information over a network by scrambling it" },
    { "developer", "A professional who designs, develops, and maintains software applications" },
    { "computing", "Cloud-based services providing computing resources over the internet" },
    { "algorithm", "A step-by-step procedure for solving a problem" },
    { "software", "A set of instructions, data, or programs used to operate computers" },
    { "network", "A group of interconnected devices that can communicate with each other" },
    { "security", "Measures taken to protect computer systems and data" },
    { "website", "A collection of related web pages hosted on a web server" },
    { "browser", "A software application for accessing information on the World Wide Web" }
};

    // Select a random word from the list
    int wordIndex = rand() % 4;

    const char* secretWord = wordList[wordIndex].word;
    const char* hint = wordList[wordIndex].hint;

    int wordLength = strlen(secretWord);
    char guessedWord[MAX_WORD_LENGTH] = { 0 };
    bool guessedLetters[26] = { false };

    printf("Welcome to Hangman!\n");
    printf("Info\n");
    printf("The computer has secretly chosen a word.\nYour goal is to guess this word, letter by letter, before you run out of tries.\n");
    printf("You will be given a hint to help you figure out the word.\n");
    printf("For each turn, you will be prompted to enter a single letter.\n");
    printf("If the letter you guess is in the secret word, all occurrences of that letter will be revealed.\n");
    printf("If the letter you guess is not in the word, a part of the hangman figure will be drawn, and you will lose one try.\n");
    printf("You have a maximum of 6 tries.\n");
    printf("Try to guess the word before the hangman is fully drawn!\n");
    printf("Good luck!\n");

    printf("\nHint: %s\n", hint);
    int tries = 0;

    while (tries < MAX_TRIES) {
        printf("\n");
        displayWord(guessedWord, guessedLetters);
        drawHangman(tries);

        char guess;
        printf("Enter a letter: ");
        scanf(" %c", &guess);
        guess = tolower(guess);

        if (guessedLetters[guess - 'a']) {
            printf("You've already guessed that letter. "
                   "Try again.\n");
            continue;
        }

        guessedLetters[guess - 'a'] = true;

        bool found = false;
        for (int i = 0; i < wordLength; i++) {
            if (secretWord[i] == guess) {
                found = true;
                guessedWord[i] = guess;
            }
        }

        if (found) {
            printf("Good guess!\n");
        }
        else {
            printf("Sorry, the letter '%c' is not in the "
                   "word.\n",
                   guess);
            tries++;
        }

        if (strcmp(secretWord, guessedWord) == 0) {
            printf("\nCongratulations! You've guessed the "
                   "word: %s\n",
                   secretWord);
            break;
        }
    }

    if (tries >= MAX_TRIES) {
        printf("\nSorry, you've run out of tries. The word "
               "was: %s\n",
               secretWord);
    }
    getch();
    return 0;
}

void displayWord(const char word[], const bool guessed[])
{
    printf("Word: ");
    for (int i = 0; word[i] != '\0'; i++) {
        if (guessed[word[i] - 'a']) {
            printf("%c ", word[i]);
        }
        else {
            printf("_ ");
        }
    }
    printf("\n");
}

void drawHangman(int tries)
{
    const char* hangmanParts[]
        = { "     _________",    "    |         |",
            "    |         O",   "    |        /|\\",
            "    |        / \\", "    |" };

    printf("\n");
    for (int i = 0; i <= tries; i++) {
        printf("%s\n", hangmanParts[i]);
    }
}
