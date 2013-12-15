#include  "DxLib.h"
#include "unit.h"
#include <vector>
class castle : public unit{
	int stage;

	vector<int> musume_table;
	vector<int> enemy_table;
public:
	castle(int,int,int,int);
	void draw(int);
};