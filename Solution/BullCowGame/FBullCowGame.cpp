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

	const FString HIDDEN_WORD = "ant";
	MyHideenWord = HIDDEN_WORD;

	MyCurrentTry = 1;
	return;
}

BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//incriment the turn number
	MyCurrentTry++;

	// setup a return variable
	FBullCowCount BullCowCount;
	// loop through all letters in the guess
		// coapre letters against the hidden word
	int32 HideenWordLength = MyHideenWord.length();
	for (int32 i = 0; i < HideenWordLength; i++)
	{
		for (int32 j = 0; j < HideenWordLength; j++)
		{
			if (Guess[i] == MyHideenWord[i])
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


bool FBullCowGame::CheckGuessValidity(FString)
{
	return false;
}
