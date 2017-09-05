#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

FText getGuess();
bool compareGuess(FText s);
bool askForMore();
void PlayGame();

FBullCowGame game;

constexpr int32 WORD_LENGTH = 5;

int32 main(int argc, char** argv) {

	std::cout << "Welcome to Bulls and Cows\n";
	
	do {
		PlayGame();
		game.Reset();
	} while (askForMore());
	return 0;
}

FText getGuess() {

	FText Guess = "";
	std::getline(std::cin, Guess);
	std::cout << " You guessed: " << Guess << std::endl;
	return Guess;
}

bool compareGuess(FText s) {

	return game.checkSubmittedStringAgainstGameString(s);
}

bool askForMore() {

	FText shouldPlayAgainString = "";
	std::cout << "Play again?" << std::endl;
	std::getline(std::cin, shouldPlayAgainString);
	return shouldPlayAgainString[0] == 'y';
}

void PlayGame() {
	
	do {
		game.displayCurrentTry();
		std::cout << "Guess the word. Length: " << WORD_LENGTH << std::endl;
		std::cout << "Your guess:" << std::endl;

		FString Guess = getGuess();
		if (game.isValidGuess(Guess))
		{
			bool bFoundWord = compareGuess(Guess);
			if (bFoundWord)
			{
				game.markGameWon();
				break;
			}
			if (game.shouldPlayAgain()) {
				game.increaseCurrentTry();
			}
		}
		
	} while (game.shouldPlayAgain());

	game.displayGameSummary();
}