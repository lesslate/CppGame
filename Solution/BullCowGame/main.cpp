#include <iostream>
#include <string>
#include "FBullCowGame.h"


using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();

FBullCowGame BCGame; //instantiate a new game

int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		AskToPlayAgain();
	} while (bPlayAgain);

	return 0;
}

void PrintIntro()
{
	constexpr int32 WORD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows , a fun word game.\n";
	std::cout << "Can you guess the " << WORD_LENGTH
		<< " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;

}

void PlayGame()
{

	BCGame.Reset();

	int32 MaxTries = BCGame.GetMaxTries();
	

	for (int32 count = 1; count <= MaxTries; count++)
	{
		FText GUESS = GetGuess();
		FBullCowCount BullCowCount = BCGame.SubmitGuess(GUESS);

		// print bulls cows number
		std::cout << "Bulls = " << BullCowCount.Bulls;
		std::cout << ". Cows = " << BullCowCount.Cows << std::endl;
		std::cout << std::endl;
	}
}

FText GetGuess()
{
	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Enter your guess : ";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	FText GUESS = "";
	std::getline(std::cin, GUESS);

	
	return GUESS;
}
// TODO summarise game
bool AskToPlayAgain()
{
	std::cout << "Do you want to play again(Y/N)?";
	FText Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

