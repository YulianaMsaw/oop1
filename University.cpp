#include "University.h"

University::University(std::string nameTown, std::string  nameUniversity, list<Speciality*>listSpeciality) : _nameUniversity(nameUniversity), _listSpeciality(listSpeciality), _nameTown(nameTown)
{
	c++;
	_id = c;
}

const list<Speciality*>& University::GetSpeciality() const
{
	return _listSpeciality;
}

int University::GetIndex() const
{
	return _id;
}
const  std::string& University::GetTown() const
{
	return _nameTown;
}

void University::operator<<(std::ostream& os)
{
	os <<"ID "<< _id << endl;
	os <<"Name town "<<_nameTown << endl;
	os <<"Name "<<_nameUniversity << endl;
	for (auto it : _listSpeciality)
	{
		it->operator<<(cout);

	}



}

const std::string& University::GetName() const
{
 	return _nameUniversity;
}

void University::AddSpeciality(Speciality* speciality)
{


	for (auto it : _listSpeciality)
	{
		if (it->GetCodeSpeciality() == speciality->GetCodeSpeciality())
		{
			throw std::exception("Существует уже такая специальность");
		}
	}
	_listSpeciality.push_back(speciality);

}

void University::RemoveSpeciality(Speciality* speciality)
{


}
