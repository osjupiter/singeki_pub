#include "character.h"

character::character(int fx, int fy, int ln) : unit(fx, fy, ln){

}

UnitState character::getState(){
	return state;
}

PropertyType character::getProperty(){
	return property;
}

