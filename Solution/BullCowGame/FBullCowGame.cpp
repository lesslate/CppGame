#include "FBullCowGame.h"




FBullCowGame::FBullCowGame()
{
	Reset();
}


int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";
	MyHideenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

BullCowCount FBullCowGame::SubmitGuess(FString)
{
	//incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	BullCowCount BullCowCount;
	// loop through all letters in the guess
		// coapre letters against the hidden word



	return BullCowCount;
}


bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
