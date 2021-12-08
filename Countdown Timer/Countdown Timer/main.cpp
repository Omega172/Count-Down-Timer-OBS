#include <Windows.h>
#include <iostream>
#include <string>
#include <fstream>

std::string outputPath = "countdown_timer.txt";

int main(int argc, char** argv, char** envp)
{
	std::cout << "Duration of timer in minutes: ";
	std::string input;
	std::getline(std::cin, input);

	int iSeconds, iHours, iMinutes;

	iSeconds = std::stoi(input) * 60;
	iSeconds++;

	std::cout << "Waiting for \"" << input << "\" minutes" << std::endl;
	
	std::ofstream file(outputPath);

	while (iSeconds >= 0)
	{
		system("cls");

		iMinutes = iSeconds / 60;
		iHours = iMinutes / 60;

		// Fix
		// 5:0 should be 5:00
		// 0:9 should be 0:09
		std::string sSeconds;
		if (int(iSeconds % 60) < 10)
		{
			sSeconds = "0" + std::to_string(int(iSeconds % 60));
		}
		else
		{
			sSeconds = std::to_string(int(iSeconds % 60));
		}
		
		std::cout << "Time remaining: " << int(iMinutes % 60) << ":" << sSeconds <<std::endl;


		std::string outputText = std::to_string(int(iMinutes % 60)) + ":" + sSeconds;

		file.seekp(0);
		file.write(outputText.c_str(), sizeof(outputText.c_str()));
		std::flush(file);
		

		iSeconds--;
		
		Sleep(1000);
	}

	file.close();
	std::cout << "Done!";

	return 0;
}