#pragma once
#include "UniversityStorage.h"
#include <functional>
class Console
{
public:
	void Init();
	Console() {
		_menuItems.push_back(MenuItems{ 1, "Read file", std::bind(&Console::ReadFile, this) });
		_menuItems.push_back(MenuItems{ 2, "Search universities by town", std::bind(&Console::SearchUniversitiesByTown, this) });
		_menuItems.push_back(MenuItems{ 3, "Search universities by name", std::bind(&Console::SearchUniversitiesByName, this) });
		_menuItems.push_back(MenuItems{ 4, "Search universities by code speciality", std::bind(&Console::SearchUniversitiesBySpeciality, this) });
		_menuItems.push_back(MenuItems{ 5, "Search universities by average score", std::bind(&Console::SearchUniversitiesByAverageScore, this) });
		_menuItems.push_back(MenuItems{ 6, "Add university", std::bind(&Console::AddUniversity, this) });
		_menuItems.push_back(MenuItems{ 7, "Remove university", std::bind(&Console::RemoveUniversity, this) });
		_menuItems.push_back(MenuItems{ 8, "Print all university", std::bind(&Console::PrintAllUniversity, this) });
	}

private:
	void Menu();
	void FileIsExist(std::ifstream& inputFile);
	void ReadFile();
	void SearchUniversitiesByTown();
	void SearchUniversitiesByName();
	void SearchUniversitiesBySpeciality();
	void SearchUniversitiesByAverageScore();
	void AddUniversity();
	void RemoveUniversity();
	void PrintAllUniversity();
	UniversityStorage universityStorage;

	struct MenuItems
	{
		int _number;
		std::string _message;
		std::function<void(void)>_function;
	};

	std::vector<MenuItems> _menuItems;

	string HelperAddUniversity();


};


