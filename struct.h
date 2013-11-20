typedef struct {
	int sh;//種類
	double tx,ty;//座標
	int hp;
	double vx,vy;
	double ax,ay;
	int tcnt;
}ch_t;

typedef struct {
	int count;
	int sh;
	double x,y;//座標
	double vx,vy;
	double ax,ay;
	int tcnt;
}or_t;

typedef struct {
	int count;
	int sh;
	double x,y;//座標
}ef_t;

typedef struct {
	int count;
	int sh;
	double x,y;//座標
	double vx,vy;
}tm_t;

typedef struct {
	int count;
	int sh;
	double x,y;//座標
	double west,hight;
}at_t;
typedef struct {
	int sh;
	double x,y;//座標

}im_t;
