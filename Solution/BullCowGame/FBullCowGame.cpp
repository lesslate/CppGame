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

int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon() const
{
	return false;
}

void FBullCowGame::Reset()
{
	constexpr int32 MAX_TRIES = 8;
	const FString HIDDEN_WORD = "planet";

	MyMaxTries = MAX_TRIES;
	MyHiddenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
		// coapre letters against the hidden word
	int32 HiddenWordLength = MyHiddenWord.length();
	for (int32 i = 0; i < HiddenWordLength; i++)
	{
		for (int32 j = 0; j < HiddenWordLength; j++)
		{
			if (Guess[i] == MyHiddenWord[i])
			{
				if (i == j)
				{
					BullCowCount.Bulls++;
				}
				else
				{
					BullCowCount.Cows++;
				}
			}
		}
	}


	return BullCowCount;
}


EWordStatus FBullCowGame::CheckGuessValidity(FString) const
{
	return EWordStatus::OK;
}
