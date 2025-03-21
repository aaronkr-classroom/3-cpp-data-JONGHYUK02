// grades_long.cpp
#include <iostream> // cin, cout, endl
#include <string> // string
#include <ios> // istream
#include <iomanip> // precision, setprecision
#include <vector> //�迭
#include <algorithm> // sort
#include <stdexcept> // domain_error()

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision; //����
using std::vector; using std::sort; //����
using std::domain_error; using std::istream;

// medina(vector<double>)
double median(vector<double> vec) {
	typedef vector<double>::size_type vec_sz;
	vec_sz size = vec.size();

	if (size == 0)
		throw domain_error("Median of empty vector!");

	// ������ ����
	sort(vec.begin(), vec.end()); // homework[0] ~ homework[size-1]

	// ���� ������ �߾Ӱ��� ����
	vec_sz mid = size / 2;
	return size % 2 == 0
		? (vec[mid] + vec[mid - 1]) / 2 // ¦���� ���
		: vec[mid]; // Ȧ���� ���


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
		// ���� ������ ����
		hw.clear();

		// ���� ������ ����

		double x; // �Է��� ���� ����

		// �Һ���: homework�� ���ݱ��� �Է¹��� ���� ������ ����
		while (in >> x) {
			hw.push_back(x);
		}

		// ���� �л��� ���� �Է� �۾��� ����� ��Ʈ���� ����
		in.clear();
	}
	return in;
}


int main() {
	//�л��� �̸��� ���� �Է¹���
	cout << "What's your name? >>> ";
	string name;
	cin >> name;
	cout << "Greetings, " << name << "!" << endl;


	// �߰������ �⸻���� ������ ���� �Է¹���
	cout << "Enter your midterm and final grades: >>> ";
	double midterm, final;
	cin >> midterm >> final;

	// ���� ������ ����
	cout << "Enter assignment grades: >>> ",
		"then EOF: >>> "; //CTRL + D

	vector<double> homework;
	
	// ���� ������ ����
	read_hw(cin, homework);

	// ���� ������ ����� ����
	try {
		double final_grade = grade(midterm, final, homework);
		//����� ���
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