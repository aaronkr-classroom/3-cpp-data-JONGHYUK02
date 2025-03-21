// grades_vector.cpp
#include <iostream>
#include <string>
#include <ios>
#include <iomanip>
#include <vector> //�迭
#include <algorithm>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision; //����
using std::vector; using std::sort; //����

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
	double x; // �Է��� ���� ����

	// �Һ���: homework�� ���ݱ��� �Է¹��� ���� ������ ����
	while (cin >> x) {
		homework.push_back(x);
	}

	// ���� ������ �Է� ������ Ȯ��
	typedef vector<double>::size_type vec_sz;
	vec_sz size = homework.size();
	if (0 == size) {
		cout << endl << "NO grades entered! "
			<< "Please try again!" << endl;
		return 1;
	}

	// ������ ����
	sort(homework.begin(), homework.end()); // homework[]0 ~ homework[size-1]

	// ���� ������ �߾Ӱ��� ����
	vec_sz mid = size / 2;
	double median = size % 2 == 0
		? (homework[mid] + homework[mid - 1]) / 2 // ¦���� ���
		: homework[mid]; // Ȧ���� ���

	//����� ���
	streamsize prec = cout.precision();
	cout << "Final grade: " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * median
		<< setprecision(prec) << endl;

	return 0;
}
