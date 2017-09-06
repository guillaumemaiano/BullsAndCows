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

	bool checkSubmittedStringAgainstGameString(FString) const;
	bool isValidGuess(FString) const;

	int32 GetHiddenWordLength() const;

	void increaseCurrentTry();

	void markGameWon();

private:
	int MyCurrentTry;
	int MyMaxTries;
	bool bIsGameWon;
	FString MyHiddenWord;
	bool isIsogram(FString string) const;
	bool isProperLength(FString string) const;
	FBullsCowsStore submitGuess(FString) const;
};