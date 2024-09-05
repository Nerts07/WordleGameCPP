#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <ctime>
#include <string>

#pragma once

class Wordle 
{
public:
	void playGame();
	std::string hideWord(std::string& hiddenWord);
	std::string getWords(const char* filePath);

private:
	std::string wordie;
	std::string hw;
	std::string word;
	std::vector<std::string> words;
	char guess;
	int attempts;
	std::stringstream toString;
	int randomIndex;
	int choose;
	int level;
	bool choosed = false;
	bool guessed = false;
	int n;
};