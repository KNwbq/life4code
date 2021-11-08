#include<stdio.h>
#include<cstring>
using namespace std;

class Student
{ private:
	long code; char name[20]; char gender; int e, c, m;
	static int tote, totc, totm, cnt;
  public:
  	Student(long num = 0, const char* n = "no name", const char gen = 'n', int eng = 0, int chi = 0, int mat = 0)
	{
	  	code = num;
	  	strcpy(name, n);
	  	gender = gen;
	  	e = eng; c = chi; m = mat;
	  	tote += e; totc += c; totm += m;
	  	++cnt;
	}	
	Student(Student& pp)
	{
		code = pp.code; strcpy(name, pp.name); gender = pp.gender; e = pp.e; c = pp.c; m = pp.m;
		tote += e; totc += c; totm += m;
	  	++cnt;
	}
	static double avg_eng();
	static double avg_chi();
	static double avg_mat();
};

int Student::tote = 0, Student::totc = 0, Student::totm = 0, Student::cnt = 0;
double Student::avg_eng(){ return (double)tote / cnt; }
double Student::avg_chi(){ return (double)totc / cnt; }
double Student::avg_mat(){ return (double)totm / cnt; }

int main()
{
	Student std_1(1001,"Li Hua",'F',91,71,81);
 	Student std_2(1002,"HeXiao",'M',92,72,82);
 	Student std_3 = std_1, std_4;
 	printf("英语的平均分是：%.1lf\n", Student::avg_eng());
 	printf("语文的平均分是：%.1lf\n", Student::avg_chi());
 	printf("数学的平均分是：%.1lf\n", Student::avg_mat());
	return 0;
}
