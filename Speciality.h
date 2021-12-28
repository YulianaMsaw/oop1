#pragma once
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include<string>
class Speciality {
public:
	Speciality() = default;
	Speciality(std::string codeSpeciality, std::vector< std::pair<std::string, int> >listOfExams, int numberBudgetPlaces);
	void operator << (std::ostream& os1);
	const std::string& GetCodeSpeciality() const;
	int GetPassingScore() const;
	int GetCountExams()const;
	const std::vector< std::pair<std::string, int>>& GetListOfExams()const;
private:
	std::string _codeSpeciality;
	int _passingScore;
	std::vector< std::pair<std::string, int>>_listOfExams;
	int _numberBudgetPlaces;
};

bool operator<(const Speciality& a, const  Speciality& b);
bool operator ==(const Speciality& a, const Speciality& b);