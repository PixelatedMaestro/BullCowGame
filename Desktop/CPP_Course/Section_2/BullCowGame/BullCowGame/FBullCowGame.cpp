#include "FBullCowGame.h"

FBullCowGame::FBullCowGame()
{
	Reset();
}

void FBullCowGame::Reset()
{
	MyCurrentTry = 1;
	constexpr int MAX_TRIES = 6;
	MyMaxTries = MAX_TRIES;
	const FString HIDDEN_WORD = "planet";
	MyHiddenWord = HIDDEN_WORD;
	return;
}

Int32 FBullCowGame::GetMaxTries() const
{
	return MyMaxTries;
}

Int32 FBullCowGame::GetCurrentTry() const
{
	return MyCurrentTry;
}

Int32 FBullCowGame::GetHiddenWordLength() const
{
	return MyHiddenWord.length();
}

bool FBullCowGame::IsGameWon(FString Guess) const
{
	bool success = false;
	if (myCounts.Bulls == GetHiddenWordLength())
	{
		success = true;
	}
	return success;
}
//receives a valid guess, increments current try, returns count
BullCowCount FBullCowGame::SubmitGuess(FString Guess)
{
	//increment turn count
	MyCurrentTry++;
	//return BullCowCount Structure
	BullCowCount myBullCowCount;
	//loop through all letters of guess
	if (IsIsogram(Guess) && !IsUpperCase(Guess))
	{
		for (Int32 HWChar = 0; HWChar < MyHiddenWord.length(); HWChar++)
		{
			for (Int32 GChar = 0; GChar < MyHiddenWord.length(); GChar++)
			{
				if (MyHiddenWord[HWChar] == Guess[GChar])
				{
					if (HWChar == GChar)
					{
						myBullCowCount.Bulls++;
					}
					else
					{
						myBullCowCount.Cows++;
					}
				}

			}
		}

	}
		
	return myBullCowCount;
}

EWordStatus FBullCowGame::CheckGuessIsValid(FString Guess)
{
	EWordStatus Status = EWordStatus::OK;;
	if (Guess.length() < MyHiddenWord.length())
	{
		Status = EWordStatus::WORD_TOO_SHORT;
	}
	if (Guess.length() > MyHiddenWord.length())
	{
		Status = EWordStatus::WORD_TOO_LONG;
	}
	if (!IsIsogram(Guess))
	{
		Status = EWordStatus::NOT_ISOGRAM;
	}
	if (IsUpperCase(Guess))
	{
		Status = EWordStatus::NOT_LOWERCASE;
	}
	return Status;
}
bool FBullCowGame::IsIsogram(FString Guess)
{
	bool Success = true;
	for (int i = 0; i < Guess.length(); i++)
	{
		for (int j = 0; j < Guess.length(); j++)
		{
			int count = 0;
			if (Guess[i] == MyHiddenWord[j])
			{
				count++;
			}
			if (count == 1)
			{
				Success = false;
				break;
			}
		}
	}
	return Success;
}

bool FBullCowGame::IsUpperCase(FString Guess)
{
	bool Success = false;
	for (int i = 0; i < Guess.length(); i++)
	{
		if (Guess[i] == std::toupper(Guess[i]))
		{
			Success = true;
		}
	}
	return Success;
}

void FBullCowGame::SetMaxTries(Int32 tries)
{
	MyMaxTries = tries;
}

void FBullCowGame::SetCurrentTry(Int32 tri)
{
	MyCurrentTry = tri;
}
