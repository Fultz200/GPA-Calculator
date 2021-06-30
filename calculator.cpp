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
	int ismajor; //for wes, some corses are ignored, like Military Theory.
}allcourses[100] = {
	/*Your courses scores*/
	/*For example: {"Robot technology", 4.0, 91, 2.0, 1}*/
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
