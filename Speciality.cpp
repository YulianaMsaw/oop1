#include "Speciality.h"

Speciality::Speciality(std::string codeSpeciality, std::vector< std::pair<std::string, int> >listOfExams, int numberBudgetPlaces) :
	_codeSpeciality(codeSpeciality),
	_listOfExams(listOfExams), 
	_numberBudgetPlaces(numberBudgetPlaces)
{
	int sumOfExams = 0;
	for (auto it : _listOfExams)
	{
		sumOfExams += it.second;
	}
	_passingScore = sumOfExams;
}

void Speciality::operator<<(std::ostream&os1)
 {
	os1 <<"Code speciality "<< _codeSpeciality << std::endl;
	os1 << "Average score "<<_passingScore << std::endl;
	os1 <<"Count budget places "<<_numberBudgetPlaces << std::endl;
	os1 <<"Count exams "<<_listOfExams.size() << std::endl;
	for (auto it : _listOfExams)
	{
		os1 << it.first << " " << it.second << std::endl;
		
	}
	
	os1 << std::endl;
}

 const std::string&Speciality::GetCodeSpeciality()  const 
{
	 
	return _codeSpeciality;
}

 int Speciality::GetPassingScore() const
{
	return _passingScore;
}

 int Speciality::GetCountExams() const
 {
	 
	 return _listOfExams.size();
 }

 const std::vector<std::pair<std::string, int>>& Speciality::GetListOfExams() const
 {
	 return _listOfExams;
 }

 bool operator<(const Speciality& a, const Speciality& b)
 {
	if(a.GetCodeSpeciality()!=b.GetCodeSpeciality())
	{
		return false;
	}
	return true;
 }

 bool operator==(const Speciality& a, const Speciality& b)
 {
	 if (a.GetCodeSpeciality() == b.GetCodeSpeciality())
	 {
		 return  true;
	 }
	 return false;
 }
