#include"Data.h"

#include <string>
#include <iostream>

#include "CsvReader.h"
using namespace std;

Data Data::ins;
void Data::Read(){
	if(!CsvReader::existCsv("save.dat")){
		dataTable["stage"]=1;
		dataTable["1"]=0;
		dataTable["2"]=0;
		dataTable["3"]=0;
		dataTable["4"]=0;
		dataTable["5"]=0;
		dataTable["6"]=0;
		Write();
	}

	auto tmp=CsvReader::parseTable("save.dat",",");
	
	for(auto line:tmp){
		//”’l‚É•ÏŠ·‚Å‚«‚é•¶š—ñ‚Å‚È‚¢‚ÆƒGƒ‰[‚Í‚­‚æ	
		dataTable[line[0].c_str()]=stoi(line[1]);
	}

 
    
}
Data* Data::getIns(){return &ins;}

void Data::Write(){
	map<string,string> write;
	for(auto hoge:dataTable){
		string tmp=""+std::to_string( hoge.second);
		write[hoge.first]=tmp;
	}
	CsvReader::saveCsv("save.dat",write);
}

int Data::get(string key){
	return dataTable[key];
}
void Data::set(string key,int val){
	dataTable[key]=val;
}