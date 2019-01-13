#include <iostream>
#include <string>

using namespace std;

void PrintIntro();
void PlayGame();
string GetGuess();
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
	cout << "Welcome to Bulls and Cows , a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGTH
		<< " letter isogram I'm thinking of?" << endl;
	cout << endl;
	return;

}

void PlayGame()
{
	constexpr int NUMBER_OF_TURNS = 5;
	for (int count = 1; count <= NUMBER_OF_TURNS; count++)
	{
		string GUESS = GetGuess();
		cout << "Your guess was: " << GUESS << endl;
		cout << endl;
	}
}

string GetGuess()
{


	cout << "Enter your guess : ";
	string GUESS = "";
	getline(cin, GUESS);

	
	return GUESS;
}

bool AskToPlayAgain()
{
	cout << "Do you want to play again(Y/N)?";
	string Response = "";
	getline(cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');


}

