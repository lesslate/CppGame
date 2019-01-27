#pragma once


#include <iostream>
#include <string>
#include "FBullCowGame.h"


//�𸮾� ����ȭ
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; //instantiate a new game

int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain=AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	
	std::cout << "Welcome to Bulls and Cows , a fun word game.\n";
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength();
	std::cout << " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;

}

void PlayGame()
{

	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	

	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries) 
	{
		FText Guess = GetValidGuess();

		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);

		// print bulls cows number
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << "\n\n";
	}
	PrintGameSummary();
	return;
}




FText GetValidGuess()
{
	
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do 
	{
		// get a guess from the player
		int32 CurrentTry = BCGame.GetCurrentTry();
		std::cout << "Try " << CurrentTry << ". Enter your guess: ";
		
		std::getline(std::cin, Guess);

		// check status and give feedback
		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status) 
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word.\n";
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word witout repeating letters.\n";
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters.\n";
			break;
		default:
			break;
		}
		std::cout << std::endl;
	} while (Status != EGuessStatus::OK); // keep looping until we get no errors
	return Guess;
}


bool AskToPlayAgain()
{
	std::cout << "Do you want to play again(Y/N)?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << "Well done - You Win ! \n";
	}
	else
	{
		std::cout << "Better luck next time!\n";
	}
}