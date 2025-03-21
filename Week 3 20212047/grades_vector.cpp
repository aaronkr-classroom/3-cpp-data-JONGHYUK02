// grades_vector.cpp
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector> //배열
#include <algorithm>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision; //정도
using std::vector; using std::sort; //정렬

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
		"then EOF: >>> "; //CTRL + D

	vector<double> homework;
	double x; // 입력을 위한 변수

	// 불변성: homework는 지금까지 입력받은 과제 점수가 있음
	while (cin >> x) {
		homework.push_back(x);
	}

	// 과제 점수의 입력 유무를 확인
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (0 == size) {
		cout << endl << "NO grades entered! "
			<< "Please try again!" << endl;
		return 1;
	}

	// 점수를 정렬
	sort(homework.begin(), homework.end()); // homework[]0 ~ homework[size-1]

	// 과제 점수의 중앙값을 구함
	vec_sz mid = size / 2;
	double median = size % 2 == 0
		? (homework[mid] + homework[mid - 1]) / 2 // 짝수의 경우
		: homework[mid]; // 홀수의 경우

	//결과를 출력
	streamsize prec = cout.precision();
	cout << "Final grade: " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
}
