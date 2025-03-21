// grades_long.cpp
#include <iostream> // cin, cout, endl
#include <string> // string
#include <ios> // istream
#include <iomanip> // precision, setprecision
#include <vector> //배열
#include <algorithm> // sort
#include <stdexcept> // domain_error()

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision; //정도
using std::vector; using std::sort; //정렬
using std::domain_error; using std::istream;

// medina(vector<double>)
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)
		throw domain_error("Median of empty vector!");

	// 점수를 정렬
	sort(vec.begin(), vec.end()); // homework[0] ~ homework[size-1]

	// 과제 점수의 중앙값을 구함
	vec_sz mid = size / 2;
	return size % 2 == 0
		? (vec[mid] + vec[mid - 1]) / 2 // 짝수의 경우
		: vec[mid]; // 홀수의 경우


}

// grade(double, double, double)
double grade(double midterm, double final, double homework) {
	return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}


// grade(double, double, const vector<double>&)
double grade(double midterm, double final, const vector<double>& hw) {
	if (hw.size() == 0)
		throw domain_error("No homework entered!");

	return grade(midterm, final, median(hw));
}


// read_hw(istream&, vector<double>&)
istream& read_hw(istream& in, vector<double>& hw) {
	if (in) {
		// 이전 내용을 제거
		hw.clear();

		// 과제 점수를 읽음

		double x; // 입력을 위한 변수

		// 불변성: homework는 지금까지 입력받은 과제 점수가 있음
		while (in >> x) {
			hw.push_back(x);
		}

		// 다음 학생의 점수 입력 작업을 고려해 스트림을 지움
		in.clear();
	}
	return in;
}


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
	
	// 과제 점수를 읽음
	read_hw(cin, homework);

	// 종합 점수를 계산해 생성
	try {
		double final_grade = grade(midterm, final, homework);
		//결과를 출력
		streamsize prec = cout.precision();
		cout << "Final grade: " << setprecision(3)
			<< final_grade << setprecision(prec) << endl;
	}
	catch (domain_error) {
		cout << endl << "You must enter grades!"
			"Please try again." << endl;
		return 1;
	}
	return 0;
}