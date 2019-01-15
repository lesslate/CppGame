#pragma once
#include <string>


class FBullCowGame {
public:
	
	int GetMaxTries() const;
	int GetCurrentTry() const;
	bool IsGameWon() const;

	bool CheckGuessValidity(std:: string);
	void Reset();


private:
	int MyCurrentTry=1;
	int MyMaxTries=5;
};