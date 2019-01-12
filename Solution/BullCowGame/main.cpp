#include <iostream>
#include <string>

using namespace std;

void PrintIntro()
{
	constexpr int WORLD_LENGTH = 5;
	cout << "Welcome to Bulls and Cows , a fun word game.\n";
	cout << "Can you guess the " << WORLD_LENGTH
		<< " letter isogram I'm thinking of?" << endl;
	cout << endl;
	return;

}

string GetGuessAndPrintBack()
{


	cout << "Enter your guess : ";
	string GUESS = "";
	getline(cin, GUESS);

	cout << "Your guess was: " << GUESS << endl;
	return GUESS;
}

int main()
{
	PrintIntro();
	GetGuessAndPrintBack();
	GetGuessAndPrintBack();


	return 0;
}