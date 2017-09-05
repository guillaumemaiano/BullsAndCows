#pragma once
#include <string>

using int32 = int;
using FString = std::string;

struct FBullsCowsStore {

	int32 Bulls = 0;
	int32 Cows = 0;
};

class FBullCowGame {

public:

	FBullCowGame();

	void Reset(); // TODO improve return value, pass values etc
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;
	bool shouldPlayAgain() const;

	void displayCurrentTry() const;
	void displayGameSummary() const;

	void increaseCurrentTry();
	bool checkSubmittedStringAgainstGameString(FString);
	bool isValidGuess(FString);
	void markGameWon();

private:
	int MyCurrentTry;
	int MyMaxTries;
	bool bIsGameWon;
	int MyWordLength;
	FString MyHiddenWord;
	bool isIsogram(FString string);
	bool isProperLength(FString string);
	FBullsCowsStore submitGuess(FString);
};