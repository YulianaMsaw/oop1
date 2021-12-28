#include "UniversityStorage.h"


const map<int, University*>& UniversityStorage::GetUniversities() const
{
	return _universities;
}

const map<int, set<int>>& UniversityStorage::GetUniversitiesByAverageScore() const
{
	return _universitiesByAverageScore;
}

const map<std::string, set<int>>& UniversityStorage::GetUniversitiesByTown() const
{
	return _universitiesByTown;
}


const map<std::string, set<int>>& UniversityStorage::GetUniversitieByName() const
{
	return  _universitiesByName;
}





vector<University*> UniversityStorage::SearchByTown(const std::string& nameTown)
{
	auto isChek = _universitiesByTown.find(nameTown);
	if (isChek == _universitiesByTown.end())
	{
		throw std::logic_error("not exist university with name " + nameTown);
	}
	vector<University*>universitiesByTown;
	set<int>id = isChek->second;
	for (auto it : id)
	{
		universitiesByTown.push_back(_universities[it]);
	}
	return universitiesByTown;
}

vector<University*> UniversityStorage::SearchByName(const std::string& name)
{
	auto isChek = _universitiesByName.find(name);
	if (isChek == _universitiesByName.end())
	{
		throw std::logic_error("not exist university with name " + name);
	}
	vector<University*>universitiesByName;
	set<int>id = isChek->second;
	for (auto it : id)
	{
		universitiesByName.push_back(_universities[it]);
	}
	return universitiesByName;
}

vector<University*> UniversityStorage::SearchBySpeciality(const std::string& speciality)
{
	auto isChek = _universitiesBySpeciality.find(speciality);
	if (isChek == _universitiesBySpeciality.end())
	{
		throw std::logic_error("not exist university with speciality"+speciality);
	}

	vector<University*>universitiesBySpeciality;
	set<int>id = isChek->second;
	for (auto it : id)
	{
		universitiesBySpeciality.push_back(_universities[it]);
	}
	return universitiesBySpeciality;

}

vector<University*> UniversityStorage::SearchByAverageScore(int averageScore)
{
	set<int>id;
	for(auto isChek :_universitiesByAverageScore)
	{

		if (isChek.first <= averageScore)
		{
	
			for (auto it : isChek.second)
			{
				id.insert(it);

			}

		}

    }
	vector<University*>universitiesByAverageScore;
	for (auto it : id)
	{
		universitiesByAverageScore.push_back(_universities[it]);
	}
	return universitiesByAverageScore;
}

void UniversityStorage::RemoveUniversity(int id)
{
	auto predicat = _universities.find(id);
	if (predicat == _universities.end())
	{
		throw std::logic_error("not exist by this id");
	}
	DeleteIndex(_universities[id]);
	_universities.erase(id);
}

void UniversityStorage::AddUniversity(University* university)
{
	if (_universities.find(university->GetIndex()) != _universities.end())
	{
		throw std::logic_error("this university is exist");
	}
	else
	{
		_universities.emplace(university->GetIndex(), university);
		CreateIndex(university);
	}

}

void UniversityStorage::DeleteIndex(University* university)
{
	auto predicatByTown = _universitiesByTown.find(university->GetTown());
	auto idPredicatByTown = predicatByTown->second.find(university->GetIndex());
	if (idPredicatByTown!=predicatByTown->second.end())
	{
		_universitiesByTown[university->GetTown()].erase(idPredicatByTown);

	}

	auto predicatByName = _universitiesByName.find(university->GetName());
	auto idPredicatBynName = predicatByName->second.find(university->GetIndex());
	if (idPredicatBynName != predicatByName->second.end())
	{
		_universitiesByName[university->GetName()].erase(idPredicatBynName);
	}

	for (auto& it : university->GetSpeciality())
	{
		auto predicatBySpeciality = _universitiesBySpeciality.find(it->GetCodeSpeciality());
		auto idpredicatBySpeciality = predicatBySpeciality->second.find(university->GetIndex());

		auto predicatByAverageScore = _universitiesByAverageScore.find(it->GetPassingScore());
		auto idpredicatByAverageScore = predicatByAverageScore->second.find(university->GetIndex());

		if (idpredicatBySpeciality != predicatBySpeciality->second.end())
		{
			_universitiesBySpeciality[it->GetCodeSpeciality()].erase(idpredicatBySpeciality);
		}
		if (idpredicatByAverageScore != predicatByAverageScore->second.end())
		{
			_universitiesByAverageScore[it->GetPassingScore()].erase(idpredicatByAverageScore);
		}
	}
}

void UniversityStorage::CreateIndex(University* university)
{
	_universitiesByTown[university->GetTown()].insert(university->GetIndex());
	_universitiesByName[university->GetName()].insert(university->GetIndex());

	for (auto it : university->GetSpeciality())
	{
		_universitiesByAverageScore[it->GetPassingScore()].insert(university->GetIndex());
	   	_universitiesBySpeciality[it->GetCodeSpeciality()].insert(university->GetIndex());
	}
}









