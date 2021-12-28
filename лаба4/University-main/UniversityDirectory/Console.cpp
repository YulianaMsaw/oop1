
#pragma once
#include <fstream>
#include "Console.h"



void Console::Init()
{

	bool flag = true;
	while (flag)
	{
		Menu();
		int command;
		cout << "<<";
		std::cin >> command;
		if (command<0 || command>_menuItems.size())
		{
			throw std::logic_error("Input correct command");
		}

		if (command == 0)
		{
			flag = false;
		}
		else
		{
			try
			{
				_menuItems.at(command - 1)._function();
			}
			catch (const std::exception&ex)
			{
				cout << ex.what() << endl;
			}
		
		}
	}
}





void Console::Menu()
{
	for (auto& it : _menuItems)
	{
		std::cout << it._number << "-" << it._message << std::endl;
	}
	std::cout << "0-Exit" << endl;
	std::cout << endl;
}

void Console::FileIsExist(std::ifstream& inputFile)
{
	std::cout << "Input  name file: ";
	std::string nameFile;
	std::cin >> nameFile;
	inputFile.open(nameFile);

	if (!inputFile.is_open())
	{
		throw std::logic_error("File with name " + nameFile + " not exist");
	}
}

void Console::ReadFile()
{
	std::ifstream inputFile;

	try
	{
		FileIsExist(inputFile);
	}
	catch (const std::exception& ex)
	{
		std::cout << ex.what() << std::endl;
	}

	int count;
	inputFile >> count;


	for (int i = 0; i < count; i++)
	{
		
		list<Speciality*>listSpeciality;
		std::string nameTown;
		std::string name;
		int countSpeciality;
		inputFile >> nameTown >> name >> countSpeciality;
		for (int j = 0; j < countSpeciality; j++)
		{
			std::string codeSpeciality;
			getline(inputFile, codeSpeciality);
			getline(inputFile, codeSpeciality);
			int budgetPlaces;
			int countExams;
			inputFile >> budgetPlaces >> countExams;
			vector<pair<std::string, int>>listExams;

			for (int k = 0; k < countExams; k++)
			{
				std::string exams;
				int marke;
				inputFile >> exams >> marke;
				listExams.push_back(make_pair(exams, marke));
			}
			listSpeciality.push_back(new Speciality(codeSpeciality, listExams, budgetPlaces));
		}
		universityStorage.AddUniversity(new University(nameTown, name, listSpeciality));
		string str;
		getline(inputFile, str);
	}
}

void Console::SearchUniversitiesByTown()
{
	std::string nameTown;
	cout << "Input by town: ";
	cin >> nameTown;
	auto predicat=universityStorage.SearchByTown(nameTown);
	cout << endl;
	if (predicat.size() == 0)
	{
		cout << "not exist university in : " + nameTown << endl;
	}
	for (auto i : predicat)
	{
		i->operator<<(cout);
	}
}

void Console::SearchUniversitiesByName()
{
	std::string name;
	cout << "Input by name: ";
	cin >> name;
	auto predicat = universityStorage.SearchByName(name);
	cout << endl;
	if (predicat.size() == 0)
	{
		cout << "not exist university: " + name << endl;
	}
	for (auto i : predicat)
	{
		i->operator<<(cout);
	}
}

void Console::SearchUniversitiesBySpeciality()
{
	std::string codespeciality;
	cout << "Input code speciality ";
	cin >> codespeciality;
	vector<University*>predicat;
	predicat = universityStorage.SearchBySpeciality(codespeciality);
	cout << endl;
	if (predicat.size() == 0)
	{
		cout << "not exist university with: " + codespeciality << endl;
	}
	for (auto i : predicat)
	{
		i->operator<<(cout);
	}
	
}

void Console::SearchUniversitiesByAverageScore()
{
	int averageScore;
	cout << "Input average score ";
	cin >> averageScore;
	vector<University*>predicat;
	predicat= universityStorage.SearchByAverageScore(averageScore);
	cout << endl;
	if (predicat.size() == 0)
	{
		cout <<"not exist university with average lower then:" << averageScore << endl;
	}
	for (auto i : predicat)
	{
		i->operator<<(cout);
	}

}

void Console::AddUniversity()
{
	string nameTown;
	string name;
	int countSpeciality;
	list<Speciality*>listSpeciality;

	cout << "Input name town-";
	nameTown=HelperAddUniversity();
	cout << "Input name-";
	name=HelperAddUniversity();
	cout << "Input count speciality-";
	countSpeciality =std::stoi(HelperAddUniversity());
	for (int i = 0; i < countSpeciality; i++)
	{
		string codeSpeciality;
		int averageScore;
		int countBudgetPleces;
		cout << "Input code speciality-";
		codeSpeciality=HelperAddUniversity();
		cout << "Input average score-";
		averageScore=std::stoi(HelperAddUniversity());
		cout << "Input count budget places-";
		countBudgetPleces=std::stoi(HelperAddUniversity());
		cout << "Input count exams-";
		auto countExams=HelperAddUniversity();
		vector<pair<std::string, int>>listExams;
		for(int j=0;j<std::stoi(countExams);j++)
		{
			string nameExams;
			int marke;
			cout << "Input name exams-";
		    nameExams=HelperAddUniversity();
			cout << "Input marke on exams-";
			marke=std::stoi(HelperAddUniversity());
			listExams.push_back(make_pair(nameExams, marke));
		}
		listSpeciality.push_back(new Speciality(codeSpeciality, listExams, countBudgetPleces));
	}
    
	universityStorage.AddUniversity(new University(nameTown, name, listSpeciality));
}

void Console::RemoveUniversity()
{
	cout << "Input id university: ";
	int id;
	cin >> id;
	universityStorage.RemoveUniversity(id);
}

void Console::PrintAllUniversity()
{
	for (auto it : universityStorage.GetUniversities())
	{
		it.second->operator<<(cout);
	}
}



string  Console::HelperAddUniversity()
{
	std::string str;
	cin >> str;
	return str;
}






