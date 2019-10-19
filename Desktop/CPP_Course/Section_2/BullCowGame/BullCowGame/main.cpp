#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using Int32 = int;
void PrintIntro();
void PlayGame();
FText GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame;
// the entry point for our application
int main()
{
	//introduce the game
	PrintIntro();
	do
	{
		PlayGame();
	} while (AskToPlayAgain());
	return 0;
}

void PlayGame()
{
	BCGame.Reset();
	//loop the number of turns the player has to guess the word
	const Int32 MAX_TRIES = BCGame.GetMaxTries();
	for (Int32 i = 0; i < MAX_TRIES; i++)
	{
		BCGame.SetCurrentTry(i);
		FText Guess = GetGuess();
		BullCowCount BCCount = BCGame.SubmitGuess(Guess);
		std::cout << "Bulls = " << BCCount.Bulls << " ";
		std::cout << "Cows = " << BCCount.Cows << " ";
		std::cout << std::endl;
		if (BCGame.IsGameWon(Guess))
		{
			break;
		}
	}
}

void PrintIntro()
{
	//introduce the game
	std::cout << "Welcome to my Bulls and Cows game!\n";
	std::cout << "Can you guess my " << BCGame.GetHiddenWordLength();
	std::cout << " word in 10 guesses or less?\n";
	std::cout << std::endl;
	return;
}

FText GetGuess()
{
	//get an input from the player
	FText Guess = "";
	std::cout << "Try " << BCGame.GetCurrentTry() << ": Enter your guess: ";
	std::getline(std::cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again? (Y/N)\n";
	FText PlayAgain;
	std::getline(std::cin, PlayAgain);

	if (PlayAgain == "Y" || PlayAgain == "y")
	{
		return true;
	}
	
	else {
		return false;
	}
}