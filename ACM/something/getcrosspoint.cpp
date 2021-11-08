#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 20005
#define memset0(a) memset(a,0,sizeof(a))
#define EPS 1e-8

struct Pt//point 点的结构
{
	double x, y;
	Pt() {}
	Pt(double x, double y) :x(x), y(y) {}
}pois[MAXN];//points_of_intersection 双队中相邻两个半平面的交点
struct Ln//line 线（半平面边界）的结构
{
	Pt a, b;
	double angle;//线的极角
	Ln() {}
	Ln(double ax, double ay, double bx, double by) :a(Pt(ax, ay)), b(Pt(bx, by)) {}
}lns[MAXN];//lines 存放线的原始数据
int dq[MAXN], bot, top;//deque bottom top 模拟双队 存放的是在lns数组的下标 避免每次都要赋5个值
int N;//半平面总数
int signal(double a)//符号函数 用很多次了
{
	if (abs(a) < EPS)
		return 0;
	return a > 0 ? 1 : -1;
}
double xp(Pt a, Pt b, Pt c)//cross_product 向量积 由于改进之前的版本中有一个点是下面求交点函数得到的 因而不能传引用
{
	return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}
Pt point_of_intersection(Ln& a, Ln& b)//求交点 主体思想仍然是定比分点 不过参数换成两条线了而已 和以前都是一样的
{
	double Sabc = xp(b.a, a.a, a.b), Sabd = xp(b.b, a.a, a.b);//利用三角形的比例确定位置比例
	return Pt((Sabc * b.b.x - Sabd * b.a.x) / (Sabc - Sabd), (Sabc * b.b.y - Sabd * b.a.y) / (Sabc - Sabd));//利用构造函数直接返回无名变量 当然不能传引用
}
bool pred(const Ln& a, const Ln& b)//predicate sort的谓词
{
	return signal(a.angle - b.angle) ? signal(a.angle - b.angle) < 0 : signal(xp(b.a, a.a, a.b)) > 0;//极角不同时按极角升序 相同时被另一个半平面的可行域覆盖的排在前面
}
bool pred2(const Ln& a, const Ln& b)//unique的谓词 相当于重载等于
{
	return !signal(a.angle - b.angle);//极角相等时符号函数返回0 取非得1
}
double fun()
{
	lns[0] = Ln(0, 0, 10000, 0), lns[1] = Ln(10000, 0, 10000, 10000), lns[2] = Ln(10000, 10000, 0, 10000), lns[3] = Ln(0, 10000, 0, 0);//初始可行域的范围 需要注意每个的方向不能反
	N += 4;//计入总半平面数
	for (int p = 4; p < N; p++)
		scanf("%lf%lf%lf%lf", &lns[p].a.x, &lns[p].a.y, &lns[p].b.x, &lns[p].b.y);//input
	for (int p = 0; p < N; p++)
		lns[p].angle = atan2(lns[p].b.y - lns[p].a.y, lns[p].b.x - lns[p].a.x);//计算出半平面的极角
	sort(lns, lns + N, pred);
	N = unique(lns, lns + N, pred2) - lns;//由于已经排序过 极角相等的总是靠内的在前 懒得自己写 直接借用stl
	dq[bot = top = 0] = 0;//初始化双队的第一个元素
	for (int p = 1; p < N; p++) {//下面是半平面交主体算法
		while (bot < top && xp(lns[p].b, pois[top - 1], lns[p].a) > 0)//xp传值的顺序和以往不太相同 但表意相同 如果队头的两个半平面交点在当前考虑的半平面可行域外 交点都是事先求好的 不用每次都求 这也是主要的改进部分
			top--;//退掉队头的半平面
		while (bot < top && xp(lns[p].b, pois[bot], lns[p].a) > 0)//对队尾一样
			bot++;
		dq[top + 1] = p;//新的半平面入队 top还没变
		pois[top++] = point_of_intersection(lns[dq[top]], lns[dq[top + 1]]);//求出队头两个半平面的交点 方便下次使用 top会在所有计算完成后+1
	}
	while (bot < top && xp(lns[dq[bot]].b, pois[top - 1], lns[dq[bot]].a) > 0)//对队尾和队头进行类似与上面的处理 使其完成循环 也由于是循环 不必再额外对队尾进行相似的处理
		top--;
	pois[top++] = point_of_intersection(lns[dq[top]], lns[dq[bot]]);//同样也要类似的求出交点和递增
	double area = 0;//最后求出面积
	for (int p = bot + 1; p < top - 1; p++)
		area += xp(pois[p], pois[bot], pois[p + 1]);
	return area / 2;//除以2返回
}
int main(void)
{
	//freopen("vs_cin.txt", "r", stdin);
	//freopen("vs_cout.txt", "w", stdout);

	while (~scanf("%d", &N))//input
		printf("%.1f\n", fun());//output//最后用g++交的 不能用%lf
}
