#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision; //정도

int main() {
	//학생의 이름을 묻고 입력받음
	cout << "What's your name? >>> ";
	string name;
	cin >> name;
	cout << "Greetings, " << name << "!" << endl;


	// 중간시험과 기말시험 점수를 묻고 입력받음
	cout << "Enter your midterm and final grades: >>> ";
	double midterm, final;
	cin >> midterm >> final;

	// 과제 점수를 물음
	cout << "Enter assignment grades: >>> ",
		"then EOF: >>> "; 

	// 지금까지 입력된 과제 점수의 개수와 합
	int count = 0;
	double sum = 0;
	double x; // 입력을 위한 변수

	// 불변성: 지금까지 count가 점수를 입력받았으며
	// 입력받은 점수의 합은 sum
	while (cin >> x) {
		++count;
		sum += x; //sum은 0이고 x부터 카운트한다는 의미

	}

	//결과를 출력
	streamsize prec = cout.precision(); 
	cout << "Final grade: " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * sum / count
		<< setprecision(prec) << endl;

	return 0;
}
