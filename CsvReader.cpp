#include "CsvReader.h"
#include <fstream>
vector<string> CsvReader::split(const string &str, const string &delim){
    vector<string> tokens;
    size_t cp, fp; // current position, found position
    const size_t dsize = delim.size();
    for(cp = 0; (fp = str.find(delim, cp)) != string::npos; cp = fp + dsize){
        tokens.emplace_back(string(str, cp, fp - cp));
    }
    tokens.emplace_back(string(str, cp, str.size() - cp));
    return tokens;
}

vector<vector<string>> CsvReader::parseTable(string name, const string &delim){
	auto stream=std::ifstream(name.c_str());
    vector<vector<string>> table;
    string str;
    while(getline(stream, str)){
        table.emplace_back(split(str, delim));
    }
    return table;
}
 

void CsvReader::saveCsv(string filename,map<string,string> hash){
	ofstream ofs(filename);
 
	
	for(auto part: hash ) 
	{
		ofs << part.first << "," << part.second << endl;
	}
	return;

}

boolean CsvReader::existCsv(string filename){
	ifstream *ifs = new ifstream(filename.c_str(), ios::in);
	if (!*ifs) {
		return false;
	}
	return true;
}

vector<vector<string>> CsvReader::parseTableDX(string name, const string &delim){
	auto fp=FileRead_open(name.c_str());
	 char String[2048] ;
    vector<vector<string>> table;
    string str;
    while( FileRead_gets( String, 2048, fp ) ){
		str=(String);
		auto res = str.find("//", 0);
		if (res == 0)continue;
		table.emplace_back(split(str, delim));
		if (FileRead_eof(fp))break;
    }
    return table;
}