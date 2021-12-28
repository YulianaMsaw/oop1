#pragma once
#include "IUniversity.h"
class University : public IUniversity {
public:
	University() = default;
	University(std::string nameTown, std::string _nameUniversity, list<Speciality*>listSpeciality);

	University(const University& other) = delete;

	const list<Speciality*>& GetSpeciality()const override;

	const std::string& GetTown() const override;
	const std::string& GetName()const override;

	int GetIndex()const override;


	void  operator << (std::ostream& os);

	void AddSpeciality(Speciality* speciality)override;
	void RemoveSpeciality(Speciality* speciality)override;

private:
	std::string _nameUniversity;
	std::string _nameTown;
	list<Speciality*>_listSpeciality;
	int _id = 0;

};

static int c;
