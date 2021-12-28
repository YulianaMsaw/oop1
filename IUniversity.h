#pragma once
#include <list>
#include "Speciality.h"
using namespace std;
class IUniversity {
public:
	virtual ~IUniversity() = default;

	virtual const list<Speciality*>& GetSpeciality()const = 0;

	virtual int GetIndex()const = 0;
	virtual const std::string& GetName()const = 0;
	virtual const std::string& GetTown()const = 0;

	virtual void AddSpeciality(Speciality* speciality) = 0;
	virtual void RemoveSpeciality(Speciality* speciality) = 0;
};