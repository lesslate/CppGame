#include <iostream>
#include <string>
#include "FBullCowGame.h"


void PrintIntro();
void PlayGame();
std::string GetGuess();
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
	constexpr int WORLD_LENGTH = 5;
	std::cout << "Welcome to Bulls and Cows , a fun word game.\n";
	std::cout << "Can you guess the " << WORLD_LENGTH
		<< " letter isogram I'm thinking of?" << std::endl;
	std::cout << std::endl;
	return;

}

void PlayGame()
{

	

	int MaxTries = BCGame.GetMaxTries();
	

	for (int count = 1; count <= MaxTries; count++)
	{
		std::string GUESS = GetGuess();
		std::cout << "Your guess was: " << GUESS << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess()
{
	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Enter your guess : ";
	std::cout << "Try " << CurrentTry << ". Enter your guess: ";
	std::string GUESS = "";
	std::getline(std::cin, GUESS);

	
	return GUESS;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again(Y/N)?";
	std::string Response = "";
	std::getline(std::cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

