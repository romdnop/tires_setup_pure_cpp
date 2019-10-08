#include <iostream>
#include <windows.h>
#include <string>
#include <cstdio>
#include <math.h>


#define _GLIBCXX_USE_C99 1
#define CONSOLE_STANDART_COLOUR		7
#define CONSOLE_HIGHLIGHT_COLOUR	10
#define CONSOLE_ERROR_COLOUR		12

using namespace std;

bool Print_Help(void);
bool Check_Tires(void);
bool Enter_Tires(void);
bool Calibrate_Rev(void);

int main(int argc, char *argv[])
{
	while(Print_Help());
	 return 0;
}



bool Print_Help(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	std::string str;
	//char str[64] = {0};
	std::cout << "\nSelect current action (Type number than press ENTER):\n[1]: Check current rev\\km value\n[2]: Enter new tires height\n[3]: Callibrate exsited rev\\km ratio\n[0]: Exit\nSelect option: ";
    //QString value =  s->readLine();
	int choice = 0;
	std::cin >> choice;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
		cout<<"\nWrong value! Only numbers 0..3 are accepted.\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
		return true;
		//continue;
	}
	//int choice = stoi(str);
    switch(choice)
    {
    case 0:
		
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
		std::cout << "\nQuit\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
		return false;
    case 1:
        while(Check_Tires());
        break;
    case 2:
        while(Enter_Tires());
        break;
    case 3:
        while(Calibrate_Rev());
        break;
    default:
		//HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
        std::cout<< "\nUnknown option! Only [0..3] are acceptable\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
    }
    return true;
}



bool Check_Tires(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	string input;
    std::cout << "Enter current rev\\km (example: 320.4) [0 to return back]: ";
    //QString value = s->readLine();
	float revValue;
	std::cin >> revValue;
	
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
		cout<<"\nWrong value! Only numbers 0..3 are accepted.\n\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
		return true;
		//continue;
	}
	
	if(revValue == 0)
	{
		return false;
	}
	
    if(revValue >= 570 || revValue <= 0)
    {
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
        std::cout<< "\nError in number format [Example: XXX.X]\n" << std::endl;
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
        return true;
    }

    float tiresHeight = (100000/(3.14*revValue));
    tiresHeight = floor(tiresHeight/0.01 - 0.5)*0.01;
	SetConsoleTextAttribute(hConsole, CONSOLE_HIGHLIGHT_COLOUR);
    std::cout << "\nCurrent tires height is equal to: " << tiresHeight << "cm\n";
	SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
    return false;
}


bool Enter_Tires(void)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	float tiresHeight;
    std::cout << "Enter current tires height (in cm) (examples: 99.5, 99.0, 99): ";
    //QString value = s->readLine();
    //float tiresHeight = value.toFloat();
	std::cin >> tiresHeight;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
		cout<<"\nWrong value! Only numbers 0..3 are accepted.\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
		return true;
		//continue;
	}
    float revsPerKm = 100000/(3.14*tiresHeight);
	SetConsoleTextAttribute(hConsole, CONSOLE_HIGHLIGHT_COLOUR);
    std::cout << "\nRevs\\km: " << revsPerKm << " units\n";
	SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
    return false;
}



bool Calibrate_Rev(void)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    float distanceGPS = 0;
    float distanceTruck = 0;
    float currentRevs = 0;
    float deltaInPercents = 0;

    std::cout << "Enter distance by GPS in km: ";
    std::cin >> distanceGPS;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
		cout<<"\nWrong value! Only numbers 0..3 are accepted.\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
		return true;
		//continue;
	}

    std::cout << "Enter distance by odometer in km: ";
    std::cin >> distanceTruck; 
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
		cout<<"\nWrong value! Only numbers 0..3 are accepted.\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
		return true;
		//continue;
	}

    std::cout << "Enter current revs\\km (Example: 230.1): ";
    std::cin >> currentRevs;
	if(cin.fail())
	{
		cin.clear();
		cin.ignore(32767, '\n');
		SetConsoleTextAttribute(hConsole, CONSOLE_ERROR_COLOUR);
		cout<<"\nWrong value! Only numbers 0..3 are accepted.\n";
		SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
		return true;
		//continue;
	}

    std::cout << "Distance by GPS: " << distanceGPS << " Distance by truck: "<<distanceTruck<< "\n";
    deltaInPercents = static_cast <float>(((distanceTruck - distanceGPS)/((distanceGPS+distanceTruck)/2))*100);
	
	SetConsoleTextAttribute(hConsole, CONSOLE_HIGHLIGHT_COLOUR);
	std::cout << "\nDelta in percents: ";
	std::cout << deltaInPercents;
	//SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);
	std::cout << "%\n";
    currentRevs = currentRevs + ((currentRevs*deltaInPercents)/100);

	std::cout << "New value revs\\km: ";
	//SetConsoleTextAttribute(hConsole, CONSOLE_HIGHLIGHT_COLOUR);
	std::cout << currentRevs;
	
    std::cout << " units\n";
	SetConsoleTextAttribute(hConsole, CONSOLE_STANDART_COLOUR);

    return false;
}
