struct point{
	double x, y;
}; 

struct vec{
	double x, y;
};

double dot(point a, point b)
{
	return a.x*b.x+a.y*b.y;
}

double cross(point a, point b)
{
	return a.x*b.y-a.y*b.x;
}

const int pai = acos(-1.0); 

const dcmp(const double v){
	if(v > esp)return 1;
	if(v < esp)return -1;
	return 0;
}
