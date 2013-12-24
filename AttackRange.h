

class AttackRange{
	int l_edge;
	int r_edge;
	int damage;
	int atk_type;

public:
	AttackRange(int l_e, int r_e, int d, int a_t){
		l_edge = l_e;
		r_edge = r_e;
		damage = d;
		atk_type = a_t;
	}

	bool judge(int x,int w,int u_type);
	int getDamage();
	int getAtkType();

};