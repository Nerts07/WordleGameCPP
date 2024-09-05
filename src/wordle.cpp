#include "worlde.h"

void Wordle::playGame()
{
	while (choosed == false)
	{
		std::cout << "\nChoose the difficult of game:\n" << std::endl;
		std::cout << "1: Easy" << std::endl;
		std::cout << "2: Medium" << std::endl;
		std::cout << "3: Hard\n" << std::endl;
		std::cin >> choose;

		if (choose < 1 || choose > 3) 
		{
			std::cout << "You have only 3 options! Please choose again." << std::endl;
		}
		else 
		{
			choosed = true;
			wordie = getWords(RESOURCES_PATH "words.txt");
			hw = hideWord(wordie);
		}
	}
	
	attempts = 6;
	guessed = false;

	if (choosed == true)
	{
		while (attempts > 0 && !guessed) 
		{
			std::cout << "word: " << hw << "\n";
			std::cout << "Attempts left: " << attempts << "\n";
			std::cout << "Enter a letter: ";
			std::cin >> guess;

			bool correctGuess = false;
			for (size_t i = 0; i < wordie.length(); i++)
			{
				if (wordie[i] == guess) 
				{
					hw[i] = guess;
					correctGuess = true;
				}
			}

			if (!correctGuess)
			{
				--attempts;
			}
			if (attempts == 0)
			{
				std::cout << "you loose, the word id: " << wordie << "\n";
				system("pause");
			}
			if (hw == wordie)
			{
				std::cout << "word: " << hw << "\n";
				guessed = true;
			}
			if (guessed)
			{
				std::cout << "CONGRATS!" << std::endl;
				system("pause");
			}
		}
	}
}

std::string Wordle::hideWord(std::string& hiddenWord) 
{
	return std::string(hiddenWord.length(), '_');
}

std::string Wordle::getWords(const char* filePath)
{
	std::srand(static_cast<unsigned int> (std::time(0)));
	
	std::fstream randomWord;
	randomWord.open(filePath, std::ios::in);

	if (!randomWord.is_open())
	{
		std::cout << "err";
	}

	while (randomWord >> word)
	{
		words.push_back(word);
	}
	randomWord.close();

	if (choose == 1)
	{
		randomIndex = std::rand() % std::min(7, static_cast<int>(words.size()));
	}	
	if (choose == 2)
	{
		randomIndex = 7 + std::rand() % std::min(7, static_cast<int>(words.size())-7);
	}	
	if (choose == 3)
	{
		randomIndex = 14 + std::rand() % std::min(6, static_cast<int>(words.size()) -14);
	}

	return words[randomIndex];
}