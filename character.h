#pragma once
#include "unit.h"
#include "difine.h"

class character : public unit{
protected:
	UnitState state;
	PropertyType property;
public:
	character(int, int, int);
	virtual UnitState getState();
	PropertyType getProperty();
	
};

