#include "FBullCowGame.h"
#include <iostream>

using FString = std::string;
using int32 = int;

constexpr int MAX_TRIES = 8;

int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::shouldPlayAgain() const
{
	bool bShouldPlay = (MyCurrentTry < MyMaxTries);
	return bShouldPlay;
}

FBullCowGame::FBullCowGame()
{
	MyWordLength = 5;
	MyHiddenWord = "extra";
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 0;
	MyMaxTries = MAX_TRIES;
	bIsGameWon = false;
	return;
}

bool FBullCowGame::IsGameWon() const
{
	return bIsGameWon;
}

bool FBullCowGame::checkSubmittedStringAgainstGameString(FString e)
{
	BullsCowsStore store = submitGuess(e);

	std::cout << "Bulls: " << store.Bulls << " Cows: " << store.Cows << std::endl;

	if (store.Bulls == MyWordLength) 
	{
		return true;
	}
	return false;
}

// *** Assumptions
// guess is valid (no repeating letters, MyWordLength long)
BullsCowsStore FBullCowGame::submitGuess(FString guess)
{
	BullsCowsStore store;
	for (int letterPosition = 0; letterPosition < MyWordLength; ++letterPosition)
	{
		// if guess or word has more characters than MaxWordLength, this will explode
		// best case explored first, then on fail, loop
		if (guess[letterPosition] == MyHiddenWord[letterPosition])
		{
			store.Bulls++;
		}
		else {
			for (int parsingCursorPosition = 0; parsingCursorPosition < MyWordLength; ++parsingCursorPosition)
			{
				
				// check current guess letter against cursor's position in parsed hidden word
				if (guess[letterPosition] == MyHiddenWord[parsingCursorPosition] && (letterPosition != parsingCursorPosition))
				{
					store.Cows++;
				}
			}
		}
	}
	return store;
}

bool FBullCowGame::isValidGuess(FString guess)
{
	// check if word has appropriate length and is an isogram
	return (isProperLength(guess) && isIsogram(guess));
}

void FBullCowGame::markGameWon()
{
	bIsGameWon = true;
}

void FBullCowGame::increaseCurrentTry()
{

	MyCurrentTry = MyCurrentTry++;
}

void FBullCowGame::displayCurrentTry() const
{
	std::cout << "Try " << (MyCurrentTry + 1) << " of " << MyMaxTries << std::endl;
	return;
}

void FBullCowGame::displayGameSummary() const
{
	if (IsGameWon())
	{
		// off-by-one correction needed
		std::cout << "Game won on try " << (MyCurrentTry + 1) << " of " << MyMaxTries << std::endl;

		if ((MyCurrentTry + 1) > MyMaxTries / 2)
		{
			std::cout << "You win, at last. The power of **LOSE** is still strong in you." << std::endl;
		}
		else
		{
			std::cout << "Win! You did not suck too much this time" << std::endl;
		}
	}
	else
	{
		// no off-by-one correction needed
		std::cout << "Game lost after " << MyCurrentTry << " attempts. Your Loser level increases by one." << std::endl;
	}
	return;
}

bool FBullCowGame::isIsogram(FString string)
{
	int32 strLength = string.length();
	for (int32 letterPosition = 0; letterPosition < strLength; letterPosition++)
	{
		for (int32 cursorPosition = 0; cursorPosition < strLength; cursorPosition++)
		{
			// ignore the letter itself
			if (cursorPosition == letterPosition) break;
			if (string[cursorPosition] == string[letterPosition])
			{
				std::cout << "Not an isogram, multiple " << string[letterPosition] << std::endl;
				return false;
			}
		}
	}
	// if we get there, we're good to go
	return true;
}

bool FBullCowGame::isProperLength(FString string)
{
	bool bIsWordLengthProper = (string.length() == MyWordLength);
	if (!bIsWordLengthProper) {
		std::cout << "Seems like some loser's not using the proper guess size." << std::endl;
	}
	return bIsWordLengthProper;
}
