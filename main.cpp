#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Book
{
public:
    std::string BTitle, BAuthor;
    int BYear;
    int BIndex = 0;
};

class Videogame
{
public:
    std::string VTitle, VStudio, VPlatform;
    int VYear, VIndex;
};

class Film
{
public:
    std::string FTitle, FDirector, FPlatform;
    int FYear, FIndex;
};

bool SelectFunction();
void EnterObject();
void BookDataCollection();
void FilmDataCollection();
void GameDataCollection();
void SearchMedium();
void FilmSearch();
void BookSearch();
void GameSearch();

void PrintIntroduction() // Function: Contextualize and Introduce the Calculator Program
{
    std::cout << "\nWelcome to the C++ Library Management System!\n";
    std::cout << "Use this Application for Efficient Analysis of Your Library of Books, Films, and Videogames.\n\n";
}

bool SelectFunction() // Function: Select a Function - Enter an Object In the Catalog or Search the Catalog
{
    PrintIntroduction();
    char ChooseFunction;
    std::cout << "To Choose Your Function, Type a Confirmation Letter (E - Enter an Object in the Catalog or S - Search the Catalog): "; // ADD: Search Function
    std::cin >> ChooseFunction;
    std::cout << "\n"; // Declaration and Input of the Reuse Confirmation Variable

    if (ChooseFunction == 'E') // Check Which Function the User Wants to Use
    {
        EnterObject();
    } else if (ChooseFunction == 'S')
    {
        SearchMedium();
    } else
    {
        std::cout << "\nThat is an Invalid Operator. Please Type Your Letter Again.";
    }

    return true;
}

void EnterObject() // Function: Enter an Object (Book, Film, or Videogame) And Its Details
{
    std::cout << "Enter the Medium of Your Object (Book, Film, or Videogame): ";
    std::string Medium;
    std::cin >> Medium; // Declaration and Input of Item's Medium (Book, Film, or Videogame)

    if (Medium == "Book" || Medium == "book") // Check the Medium of User's Object
    {
        BookDataCollection();
    } else if (Medium == "Film" || Medium == "film" || Medium == "movie" || Medium == "Movie")
    {
        FilmDataCollection();
    } else if (Medium == "Videogame" || Medium == "Game" || Medium == "videogame" || Medium == "game")
    {
        GameDataCollection();
    } else
    {
        std::cout << "\nThat is an Invalid Medium. Please Input Your Values Again.";
    }
}

bool DataConfirmation() // Function: Confirm the User's Submission
{
    char Confirm;
    std::cout << "\nAre These the Details You Want to Submit?\n";
    std::cout << "Enter Your Confirmation Letter (Y - Yes or N - No): ";
    std::cin >> Confirm; // Declaration and Input of the Statement Confirmation Variable

    if (Confirm == 'Y') // Check if Confirmation Condition is Met
    {
        std::cout << "\n\nYour Submission Has Been Successfully Entered."; // Successful Entry of the Object
        return true;
    }
    else
    {
        std::cout << "\n\nPlease Re-Enter the Object's Details.";
        std::cout << std::endl;
        return false;
    }
}

void BookDataCollection() // Function: Collect Data About a Book
{
    Book TestBook; // Declare a New Object of the Book Class

    std::cout << "Enter the Title of Your Book Here: ";
    std::cin >> TestBook.BTitle; // ADD: Enable Spaces in String Variable

    std::cout << "Enter the Author of Your Book Here: ";
    std::cin >> TestBook.BAuthor;

    std::cout << "Enter the Year in Which the Book Was Published: ";
    std::cin >> TestBook.BYear;

    bool bBookConfirmed = DataConfirmation();

    if(bBookConfirmed) // Check If Player Has Confirmed The Details of Their Film
    {
        std::ofstream outfile;
        outfile.open("BookLibrary.txt", std::ios_base::app);
        outfile << TestBook.BTitle << " (Author: " << TestBook.BAuthor << ", Year: " << TestBook.BYear << ")\n";
    } else
    {
        EnterObject();
    }
}

void FilmDataCollection() // Function: Collect Data About a Film
{
    Film Film; // Declare a New Object of the Film Class

    std::cout << "Enter the Title of Your Film Here: ";
    std::cin >> Film.FTitle; // ADD: Enable Spaces in String Variable

    std::cout << "Enter the Director of Your Film Here: ";
    std::cin >> Film.FDirector;

    std::cout << "Enter the Year in Which the Film Was Released: ";
    std::cin >> Film.FYear;

    std::cout << "Enter the Platform in Which the Film is Available in the Library: ";
    std::cin >> Film.FPlatform;

    bool bFilmConfirmed = DataConfirmation();

    if(bFilmConfirmed) // Check If Player Has Confirmed The Details of Their Film
    {
        std::ofstream outfile;
        outfile.open("FilmLibrary.txt", std::ios_base::app);
        outfile << Film.FTitle << " (Director: " << Film.FDirector << ", Year: " << Film.FYear << ", Platform: " << Film.FPlatform << ")\n";
    }
    else
    {
        EnterObject();
    }
}

void GameDataCollection() // Function: Collect Data About a Videogame
{
    Videogame Game; // Declare a New Object of the Book Class

    std::cout << "Enter the Title of Your Videogame Here: ";
    std::cin >> Game.VTitle; // ADD: Enable Spaces in String Variable

    std::cout << "Enter the Development Studio of Your Videogame Here: ";
    std::cin >> Game.VStudio;

    std::cout << "Enter the Year in Which the Videogame Was Released: ";
    std::cin >> Game.VYear;

    std::cout << "Enter the Platform in Which the Videogame is Available in the Library: ";
    std::cin >> Game.VPlatform;

    bool bGameConfirmed = DataConfirmation();

    if(bGameConfirmed) // Check If Player Has Confirmed The Details of Their Game
    {
        std::ofstream outfile;
        outfile.open("GameLibrary.txt", std::ios_base::app);
        outfile << Game.VTitle << " (Development Studio: " << Game.VStudio << ", Year: " << Game.VYear << ", Platform: " << Game.VPlatform << ")\n";
    } else
    {
        EnterObject();
    }
}

void SearchMedium()
{
    std::cout << "Enter the Medium of Your Object (Book, Film, or Videogame): ";
    std::string Medium;
    std::cin >> Medium; // Declaration and Input of Item's Medium (Book, Film, or Videogame)

    if (Medium == "Book" || Medium == "book")
    {
        BookSearch();
    }
    else if (Medium == "Film" || Medium == "film" || Medium == "movie" || Medium == "Movie")
    {
        FilmSearch();
    }
    else if (Medium == "Videogame" || Medium == "Game" || Medium == "videogame" || Medium == "game")
    {
        GameSearch();
    } else
    {
        std::cout << "\nThat is an Invalid Medium. Please Input Your Values Again.";
    }
}

void BookSearch() // Function: Check If Book Is In Library
{
    ifstream fin;
	fin.open("BookLibrary.txt");
	if(fin.fail())
	{
		cout << "Library File Opening Failed. Please Try Again.\n";
		exit(1);
	}
	string search;
	cout << "\nPlease Enter the Title of Your Book: ";
	cin  >> search;
	bool isFound=0;
	while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
		for(int i=0;i<search.size();i++)
		{
			if(temp[i]==search[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}

		if(isFound)
		{
			cout << "The Book You Have Searched for IS in the Catalog. The Details Are: ";
			for(int i = search.size()+1;i<temp.size();i++)
				cout << temp[i];

			break;
		}

	}

	if(fin.eof()&&(!isFound))
	{
		cout << "The Book You Have Searched for is NOT in the Catalog.\n";
	}

	fin.close();
}

void FilmSearch() // Function: Check If Film Is In Library
{
    ifstream fin;
	fin.open("FilmLibrary.txt");
	if(fin.fail())
	{
		cout << "Library File Opening Failed. Please Try Again.\n";
		exit(1);
	}
	string search;
	cout << "Please Enter the Title of Your Film: ";
	cin  >> search;
	bool isFound=0;
	while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
		for(int i=0;i<search.size();i++)
		{
			if(temp[i]==search[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}

		if(isFound)
		{
			cout << "\nThe Film You Have Searched for IS in the Catalog. The Details Are: ";
			for(int i = search.size()+1;i<temp.size();i++)
				cout << temp[i];

			break;
		}

	}

	if(fin.eof()&&(!isFound))
	{
		cout << "The Film You Have Searched for is NOT in the Catalog.\n";
	}

	fin.close();
}

void GameSearch() // Function: Check If Game Is In Library
{
    ifstream fin;
	fin.open("GameLibrary.txt");
	if(fin.fail())
	{
		cout << "Library File Opening Failed. Please Try Again.\n";
		exit(1);
	}
	string search;
	cout << "Please Enter the Title of Your Videogame: ";
	cin  >> search;
	bool isFound=0;
	while(!fin.eof())
	{
		string temp = "";
		getline(fin,temp);
		for(int i=0;i<search.size();i++)
		{
			if(temp[i]==search[i])
				isFound = 1;
			else
			{
				isFound =0;
				break;
			}
		}

		if(isFound)
		{
			cout << "The Videogame You Have Searched for IS in the Catalog. The Details Are: ";
			for(int i = search.size()+1;i<temp.size();i++)
				cout << temp[i];

			break;
		}

	}

	if(fin.eof()&&(!isFound))
	{
		cout << "The Videogame You Have Searched for is NOT in the Catalog.\n";
	}

	fin.close();
}

bool Replay() // Function: Reuse the Application
{
    char ReSubmit;
    std::cout << "To Reuse the Application, Enter Your Confirmation Letter (Y - Yes or N - No): ";
    std::cin >> ReSubmit;
    std::cout << "\n"; // Declaration and Input of the Reuse Confirmation Variable

    if (ReSubmit == 'Y') // Check if ReSubmit Confirmation Condition is Met
    {
        return true;
    } else if (ReSubmit == 'N')
    {
        exit(0);
        std::cout << "You have used the C++ Library Management System! Congratulations!" << std::endl;
    } else
    {
        std::cout << "\nThat is an Invalid Operator. Please Type Your Letter Again.";
    }
}

int main()
{
    bool Debug = true; // Boolean for the While Loop

    while (Debug) // Function: Loop the System Until Otherwise
    {
        bool bReuse = SelectFunction();
        std::cin.clear(); // Clears Errors
        std::cin.ignore(); // Discards the Buffer

        if (bReuse)
        {
            std::cout << "\n----------------------------------------------------\n";
            bool Debug = Replay(); // Intended to Replay the System
        }
    }
    return 0;
}
