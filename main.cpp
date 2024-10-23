#include <iostream>
#include <ctime>

using namespace std;

int tries = 0;
int attempts = 0;
int num = 0;

// to choose the difficulty and validations
void difficulty()
{
	int choice;

	cout << "Please select the difficulty level:" << "\n"
		 << "\n";
	cout << "1. Easy (10 chances)." << "\n";
	cout << "2. Normal (5 chances)." << "\n";
	cout << "3. Hard (3 chances)." << "\n";

	cout << "Level: ";
	cin >> choice;

	if (choice == 1)
	{
		tries = 10;
		cout << "Perfect, you selected the easy mode!" << "\n";
	}
	else if (choice == 2)
	{
		tries = 5;
		cout << "Perfect you selected normal mode!" << "\n";
	}
	else if (choice == 3)
	{
		tries = 3;
		cout << "Perfect you selected the hard mode!" << "\n";
	}
	else
	{
		cout << "Select a valid level." << "\n";
		difficulty();
	}
}

// for game logic and validations
void game()
{
	srand(time(NULL));

	num = (rand() % 100) + 1;

	while (true)
	{
		if (tries > 1)
		{
			cout << "You have " << tries << " chances." << "\n";
		}
		else
		{
			cout << "Last chance!" << "\n";
		}

		int guess;
		cin >> guess;

		attempts++;
		tries--;

		if (tries == 0 && guess != num)
		{
			cout << "You lost, you ran out of attempts." << "\n";
			cout << "The number I was thinking of was " << num << "\n";
			break;
		}

		if (guess < 0 || guess > 100)
		{
			cout << "Please say a number between 1 and 100." << "\n";
			tries++;
		}
		else if (guess > num)
		{
			cout << "Failed! Say a smaller number." << "\n";
		}
		else if (guess < num)
		{
			cout << "Failed! Say a bigger number." << "\n";
		}
		else
		{
			cout << "Congratulations! you won in " << attempts << " attempts." << "\n";
			break;
		}
	}
}

int main()
{

	cout << "Welcome to the number guessing game!" << "\n";
	cout << "Your job is to guess the number I'm thinking of, don't worry, it's between 1 and 100." << "\n";

	difficulty();

	game();

	return 0;
}
