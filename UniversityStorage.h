#pragma once

#include "University.h"
class UniversityStorage

{
public:

	virtual ~UniversityStorage() = default;

	const map<int, University*>& GetUniversities()const;
	const map<int, set<int>>&GetUniversitiesByAverageScore()const;
	const map<std::string, set< int>>& GetUniversitiesByTown()const;
	const map<std::string, set< int>>& GetUniversitieByName()const;


	vector<University*>SearchByTown(const std::string& nameTown);
	vector<University*>SearchByName(const std::string& name);
	vector<University*>SearchBySpeciality(const std::string& speciality);
	vector<University*>SearchByAverageScore(int averageScore);


	void RemoveUniversity(int id);


	void AddUniversity(University* university);

private:

	void DeleteIndex(University* university);
	void CreateIndex(University* university);

	map<int, University*>_universities;
	map<int, set<int>>_universitiesByAverageScore;
	map<std::string, set< int>>_universitiesByTown;
	map<std::string, set<int>>_universitiesBySpeciality;
	map<std::string, set<int>>_universitiesByName;

};