#include <iostream>
#include <string>
using namespace std;

template <typename T, size_t N>
inline size_t Count(  T ( & arr )[N] ) {
    return N;
}

struct course{
	string name;
	double GP;
	int score;
	double credit;
	int ismajor;
}allcourses[100] = {
	{"dxty1", 3.7, 87, 0.5, 0},
	{"cxsjjc", 3.7, 89, 3.5, 1},
	{"dxsxljk", 4, 92, 2.0, 1},
	{"jsll", 4, 91, 2.0, 0},
	{"jsxl", 3.7, 88, 2.0, 0},
	{"gdsx", 4.3, 95, 12.0, 1},
	{"xsyzc1", 3.7, 85, 0.25, 0},
	{"sx", 3.7, 86, 3.0, 0},
	{"dxyy1", 3.7, 88, 2.0, 0},
	{"cxsjkcsj", 2.0, 73, 1.0, 1},
	{"jjf", 3.3, 84, 1.5, 1},
	{"sjjgkcsj", 3.0, 84, 1.0, 1},
	{"dxyy2", 4.0, 93, 2.0, 0},
	{"xxds", 3.7, 85, 2.5, 1},
	{"sjjg", 4.3, 95, 4.5, 1},
	{"java", 3.7, 87, 2.0, 1},
	{"zgjdsgy", 4.3, 97, 3.0, 1},
	{"dxty2", 3.3, 84, 0.5, 0},
	{"xsyzc2", 4.3, 98, 0.25, 0},
	{"gcxlc", 3.3, 83, 2.0, 1},
	{"mglsywh", 3.9, 90, 1.5, 1},
	{"cxcy", 4.3, 97, 2.0, 1},
	{"dlydzjsjc", 2.0, 70, 3.0, 1},
	{"lssx", 3.7, 85, 4.0, 1},
	{"dxty3", 4.0, 91, 0.5, 0},
	{"dxwlc", 3.3, 82, 5.0, 1},
	{"gcll", 4.3, 100, 1.5, 1},
	{"cxsjysyff", 3.0, 80, 2.0, 1},
	{"dzsx", 4.0, 90, 1.0, 1},
	{"dxyw", 3.0, 80, 2.0, 1},
	{"dxwlsy1", 3.3, 82, 1.0, 1},
	{"rgznyxxsh", 4.3, 98, 1.5, 1},
	{"dxwlsy2", 3.3, 83, 1.0, 1},
	{"hyzhyynlsx", 4.3, 98, 1.0, 1},
	{"ozwmgl", 4.3, 100, 1.5, 1},
	{"xyjldd", 4.3, 95, 1.0, 1},
	{"jjyss", 4.3, 100, 1.5, 1},
	{"jsjtxx", 3.0, 80, 2.0, 1}, 
};

void hfut()
{
	double overallGPA;
	double overallcredit = 0.0;
	double overallscore = 0.0;
	int len = Count(allcourses);
	for(int i = 0; i < len; i++) overallcredit += allcourses[i].credit;
	for(int i = 0; i < len; i++) {
		overallGPA += allcourses[i].GP * allcourses[i].credit / overallcredit;
		overallscore += allcourses[i].score * allcourses[i].credit / overallcredit;
	}
	cout << "HFUT-GPA:   " << overallGPA << endl;
	cout << "HFUT-SCORE: " << overallscore << endl;
};

void wes()
{
	double overallGPA = 0.0;
	double overallcredit = 0.0;
	int len = Count(allcourses);
	for(int i = 0; i < len; i++) {
		if(allcourses[i].ismajor == 1) overallcredit += allcourses[i].credit;
		else { }
	}
	for(int i = 0; i < len; i++) {
		if(allcourses[i].ismajor == 1) {
			double tempGPA;
			if(allcourses[i].score >= 85) tempGPA = 4.0;
			else if(allcourses[i].score >= 75 && allcourses[i].score < 85) tempGPA = 3.0;
			else tempGPA = 2.0;
			overallGPA += tempGPA * allcourses[i].credit / overallcredit;
		} else { }
	}
	cout << "WES-GPA:    " << overallGPA << endl;
};

int main()
{
	hfut();
	wes();
	return 0;
}