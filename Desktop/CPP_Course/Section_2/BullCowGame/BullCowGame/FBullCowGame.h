#pragma once
#include <string>
using FString = std::string;
using Int32 = int;

enum EWordStatus
{
	OK,
	NOT_ISOGRAM,
	WORD_TOO_SHORT,
	WORD_TOO_LONG,
	EMPTY_GUESS,
	NOT_LOWERCASE
};

struct BullCowCount
{
	Int32 Bulls = 0;
	Int32 Cows = 0;
}myCounts;

class FBullCowGame {
public:
	FBullCowGame();
	void Reset(); //TOD) make a more rich return value
	Int32 GetMaxTries() const;
	Int32 GetCurrentTry() const;
	Int32 GetHiddenWordLength() const;
	bool IsGameWon(FString) const;
	EWordStatus CheckGuessIsValid(FString);
	void SetMaxTries(Int32);
	bool IsIsogram(FString);
	bool IsUpperCase(FString);
	void SetCurrentTry(Int32);
	BullCowCount SubmitGuess(FString);
private:
	Int32 MyCurrentTry;
	Int32 MyMaxTries;
	FString MyHiddenWord;
};