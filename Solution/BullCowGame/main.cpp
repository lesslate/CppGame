#include <iostream>
#include <string>



void PrintIntro();
void PlayGame();
std::string GetGuess();
bool AskToPlayAgain();


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
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		std::string GUESS = GetGuess();
		std::cout << "Your guess was: " << GUESS << std::endl;
		std::cout << std::endl;
	}
}

std::string GetGuess()
{


	std::cout << "Enter your guess : ";
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

