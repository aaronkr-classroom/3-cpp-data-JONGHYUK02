#include <iostream>
#include <string>
#include <ios>
#include <iomanip>

using std::cin; using std::cout;
using std::endl;
using std::string;
using std::streamsize;
using std::setprecision; //����

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
		"then EOF: >>> "; 

	// ���ݱ��� �Էµ� ���� ������ ������ ��
	int count = 0;
	double sum = 0;
	double x; // �Է��� ���� ����

	// �Һ���: ���ݱ��� count�� ������ �Է¹޾�����
	// �Է¹��� ������ ���� sum
	while (cin >> x) {
		++count;
		sum += x; //sum�� 0�̰� x���� ī��Ʈ�Ѵٴ� �ǹ�

	}

	//����� ���
	streamsize prec = cout.precision(); 
	cout << "Final grade: " << setprecision(3)
		<< 0.2 * midterm + 0.4 * final + 0.4 * sum / count
		<< setprecision(prec) << endl;

	return 0;
}
