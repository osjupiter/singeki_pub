#include"Data.h"

#include <string>
#include <iostream>

#include "CsvReader.h"
using namespace std;

Data Data::ins;
void Data::Run(){

	auto tmp=CsvReader::parseTable("dat/test.txt",",");
	
	for(auto line:tmp){
		//���l�ɕϊ��ł��镶����łȂ��ƃG���[�͂���	
		dataTable[line[0].c_str()]=stoi(line[1]);

	}

 
    
}
Data* Data::getIns(){return &ins;}
