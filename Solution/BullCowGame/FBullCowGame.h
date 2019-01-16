#pragma once
#include <string>


class FBullCowGame {
public:
	FBullCowGame(); //constructor

	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std:: string);
	void Reset();


private:
	int MyCurrentTry;
	int MyMaxTries;
};