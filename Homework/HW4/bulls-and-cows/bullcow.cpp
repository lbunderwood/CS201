/*
Luke Underwood
10/14/19
bullcow.cpp
Guessing game where the user tries to guess a four digit number. With each
guess, they are told how many "cows," or correct numbers in the wrong place
that they have, as well as how many bulls, or correct numbers in the correct
place that they have. Game starts over when they get four bulls.
*/

#include<iostream>
#include<vector>
#include<string>
#include<time.h>

int main()
{
	//initialize some variables
	std::vector<int> number(4);
	std::vector<int> guess(4);
	std::string guessStr;
	int cows = 0;
	int bulls = 0;
	int score = 0;
	int highscore = 0;

	//Print out some instructions for the user
	std::cout << "Welcome to Bulls and Cows! A Guessing game where you "
			<< "will try to guess a four digit number. With each guess, you "
			<< "will be told how many \"cows,\" or correct numbers in the "
			<< "wrong place you have, as well as how many \"bulls,\" or "
			<< "correct numbers in the correct place that you have. The game "
			<< "starts over when you get four bulls. Your score is the number "
			<< "of turns you took, so try to get the lowest score possible!" 
			<< std::endl;

	while(true)
	{
		//Sets our number to be four unique random integers 0 to 9
		for (int i = 0; i < 4; i++)
		{
			srand(time(NULL));
			int num = rand() % 10;
			for (int j = 0; j < i; j++)
			{
				while (number[j] == num)
				{
					num = rand() % 10;
				}
			}
			number[i] = num;
		}

		//loops until game is concluded
		while (bulls < 4)
		{
			//reset variables
			bulls = 0;
			cows = 0;

			//collects guess
			std::cout << "Please input your guess: ";
			std::cin >> guessStr;

			//converts guess to vector
			for (int i = 0; i < 4; i++)
			{
				guess[i] = guessStr[i] - 48;
			}

			//Checks for cows
			for (int numcount = 0; numcount < 4; numcount++)
			{
				for (int guesscount = 0; guesscount < 4; guesscount++)
				{
					if (guess[guesscount] == number[numcount] && guesscount != numcount)
					{
						cows++;
					}
				}
			}

			//Checks for bulls
			for (int numcount = 0; numcount < 4; numcount++)
			{
				if (guess[numcount] == number[numcount])
				{
					bulls++;
				}
			}

			//gives feedback on guess
			std::cout << "You have " << bulls;
			if (bulls == 1)
				std::cout << " bull and " << cows;
			else
				std::cout << " bulls and " << cows;
			if (cows == 1)
				std::cout << " cow." << std::endl;
			else
				std::cout << " cows." << std::endl;

			score++;
		}

		if (score < highscore || highscore == 0)
			highscore = score;

		//Victory message
		std::cout << "Congratulations! You Win!\n" 
			<< "Your score: " << score << ", High score: " 
			<< highscore << std::endl;

		//resets variables
		bulls = 0;
		cows = 0;
		score = 0;
	}
}