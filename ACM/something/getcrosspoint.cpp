#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
#define INF 0x3f3f3f3f
#define MAXN 20005
#define memset0(a) memset(a,0,sizeof(a))
#define EPS 1e-8

struct Pt//point ��Ľṹ
{
	double x, y;
	Pt() {}
	Pt(double x, double y) :x(x), y(y) {}
}pois[MAXN];//points_of_intersection ˫��������������ƽ��Ľ���
struct Ln//line �ߣ���ƽ��߽磩�Ľṹ
{
	Pt a, b;
	double angle;//�ߵļ���
	Ln() {}
	Ln(double ax, double ay, double bx, double by) :a(Pt(ax, ay)), b(Pt(bx, by)) {}
}lns[MAXN];//lines ����ߵ�ԭʼ����
int dq[MAXN], bot, top;//deque bottom top ģ��˫�� ��ŵ�����lns������±� ����ÿ�ζ�Ҫ��5��ֵ
int N;//��ƽ������
int signal(double a)//���ź��� �úܶ����
{
	if (abs(a) < EPS)
		return 0;
	return a > 0 ? 1 : -1;
}
double xp(Pt a, Pt b, Pt c)//cross_product ������ ���ڸĽ�֮ǰ�İ汾����һ�����������󽻵㺯���õ��� ������ܴ�����
{
	return (a.x - b.x) * (c.y - b.y) - (a.y - b.y) * (c.x - b.x);
}
Pt point_of_intersection(Ln& a, Ln& b)//�󽻵� ����˼����Ȼ�Ƕ��ȷֵ� �������������������˶��� ����ǰ����һ����
{
	double Sabc = xp(b.a, a.a, a.b), Sabd = xp(b.b, a.a, a.b);//���������εı���ȷ��λ�ñ���
	return Pt((Sabc * b.b.x - Sabd * b.a.x) / (Sabc - Sabd), (Sabc * b.b.y - Sabd * b.a.y) / (Sabc - Sabd));//���ù��캯��ֱ�ӷ����������� ��Ȼ���ܴ�����
}
bool pred(const Ln& a, const Ln& b)//predicate sort��ν��
{
	return signal(a.angle - b.angle) ? signal(a.angle - b.angle) < 0 : signal(xp(b.a, a.a, a.b)) > 0;//���ǲ�ͬʱ���������� ��ͬʱ����һ����ƽ��Ŀ����򸲸ǵ�����ǰ��
}
bool pred2(const Ln& a, const Ln& b)//unique��ν�� �൱�����ص���
{
	return !signal(a.angle - b.angle);//�������ʱ���ź�������0 ȡ�ǵ�1
}
double fun()
{
	lns[0] = Ln(0, 0, 10000, 0), lns[1] = Ln(10000, 0, 10000, 10000), lns[2] = Ln(10000, 10000, 0, 10000), lns[3] = Ln(0, 10000, 0, 0);//��ʼ������ķ�Χ ��Ҫע��ÿ���ķ����ܷ�
	N += 4;//�����ܰ�ƽ����
	for (int p = 4; p < N; p++)
		scanf("%lf%lf%lf%lf", &lns[p].a.x, &lns[p].a.y, &lns[p].b.x, &lns[p].b.y);//input
	for (int p = 0; p < N; p++)
		lns[p].angle = atan2(lns[p].b.y - lns[p].a.y, lns[p].b.x - lns[p].a.x);//�������ƽ��ļ���
	sort(lns, lns + N, pred);
	N = unique(lns, lns + N, pred2) - lns;//�����Ѿ������ ������ȵ����ǿ��ڵ���ǰ �����Լ�д ֱ�ӽ���stl
	dq[bot = top = 0] = 0;//��ʼ��˫�ӵĵ�һ��Ԫ��
	for (int p = 1; p < N; p++) {//�����ǰ�ƽ�潻�����㷨
		while (bot < top && xp(lns[p].b, pois[top - 1], lns[p].a) > 0)//xp��ֵ��˳���������̫��ͬ ��������ͬ �����ͷ��������ƽ�潻���ڵ�ǰ���ǵİ�ƽ��������� ���㶼��������õ� ����ÿ�ζ��� ��Ҳ����Ҫ�ĸĽ�����
			top--;//�˵���ͷ�İ�ƽ��
		while (bot < top && xp(lns[p].b, pois[bot], lns[p].a) > 0)//�Զ�βһ��
			bot++;
		dq[top + 1] = p;//�µİ�ƽ����� top��û��
		pois[top++] = point_of_intersection(lns[dq[top]], lns[dq[top + 1]]);//�����ͷ������ƽ��Ľ��� �����´�ʹ�� top�������м�����ɺ�+1
	}
	while (bot < top && xp(lns[dq[bot]].b, pois[top - 1], lns[dq[bot]].a) > 0)//�Զ�β�Ͷ�ͷ��������������Ĵ��� ʹ�����ѭ�� Ҳ������ѭ�� �����ٶ���Զ�β�������ƵĴ���
		top--;
	pois[top++] = point_of_intersection(lns[dq[top]], lns[dq[bot]]);//ͬ��ҲҪ���Ƶ��������͵���
	double area = 0;//���������
	for (int p = bot + 1; p < top - 1; p++)
		area += xp(pois[p], pois[bot], pois[p + 1]);
	return area / 2;//����2����
}
int main(void)
{
	//freopen("vs_cin.txt", "r", stdin);
	//freopen("vs_cout.txt", "w", stdout);

	while (~scanf("%d", &N))//input
		printf("%.1f\n", fun());//output//�����g++���� ������%lf
}
