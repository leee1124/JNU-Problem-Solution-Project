#include<iostream>
#include<stack>
#include<string>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

class Parenthesis {
public:
	bool type;//���� ��ȣ�� true, �ƴϸ� false
	int index;//�ش� ��ȣ�� �ε���

	Parenthesis(int index, bool type) {//Ŭ������ ������, �ι�° �Ű������� bool�� �����̸� �� �����ڸ� ����
		this->index = index;//��ü�� index�� int�� �Ű����� index�� �� ����
		this->type = type;//��ü�� type�� bool�� �Ű����� type�� �� ����
	}
	Parenthesis(int index, char c) {//Ŭ������ ������, �ι�° �Ű������� char�� �����̸� �� �����ڸ� ����
		this->index = index;//��ü�� index�� int�� �Ű����� index ����
		if (c == '(') {//���� char�� �Ű����� c�� ���� ( �̸� ��ü�� Ÿ�Կ� true ����
			this->type = true;
		}
		else {//���� char�� �Ű����� c�� ���� (�� �ƴϸ� ��ü�� Ÿ�Կ� false ����
			this->type = false;
		}
	}
};
bool isValidParentheses(const vector<Parenthesis>& parentheses) {//
	//���� ¦�� ã�� ���� ���� ��ȣ�鸸 ����
	//���� ��ȣ�� ������ ž�� ����� ���� ��ȣ�� �����س���
	//ž ���� ������ �̷���� -> ���ú����� ����
	stack<Parenthesis> myStack;
	
	for (int i = 0; i < parentheses.size(); i++) {//���ʺ��� �������� ��ȣ�� ���ʷ� ��ȸ�Ѵ�. ���ͺ����̹Ƿ� ��� ���� ����
		Parenthesis p = parentheses[i];

		if (p.type == true)//���� ��ȣ�̸� ¦�� ã�� �� ���� ���ÿ� ����
			myStack.push(p);
		else if (p.type == false) {//���� ��ȣ���
			if (myStack.size() > 0) {//������ ũ�Ⱑ 1 �̻��� ��� ���������� ���� ��ȣ�� ¦�� ���� �� ����
				myStack.pop();
			}
			else {//������ ũ�Ⱑ 0�̸�
				return false;//¦�� ���� �� �ִ� ���� ��ȣ�� �����Ƿ� �ùٸ��� ���� ��ȣ ���ڿ��̹Ƿ� false�� ��ȯ�Ѵ�.
			}
		}
	}
	if (myStack.size() != 0)//������ ũ�Ⱑ 0���� ũ�� ¦�� ������ ��ȣ�� �����ִ� ���̹Ƿ�
		return false;//false ��ȯ
	return true;//��� ��ȣ�� ¦�� �������� true�� ��ȯ�Ѵ�.
}

void process(int caseIndex) {
	string str;//��ȣ ���ڿ��� �Է¹��� ����
	cin >> str;//��ȣ ���ڿ� �Է�

	vector<Parenthesis> parentheses;//Parenthesis Ŭ������ �ν��Ͻ��� ���ҷ� ���� �迭 parentheses
	for (int i = 0; i < str.length(); ++i) {//str�� ���̸�ŭ �ݺ�
		parentheses.push_back(Parenthesis(i, str[i]));//�迭�� ��ȣ ���ڿ��� ����
	}

	bool isValid = isValidParentheses(parentheses);//isValidParentheses �Լ��� ��ȯ�� ���� isValid ������ ����

	if (isValid) {//isValid ������ ���̸� YES ���
		cout << "YES" << endl;
	}//�ƴϸ� NO ���
	else {
		cout << "NO" << endl;
	}
}

int main() {
	int caseSize;//�׽�Ʈ ���̽��� ������ �Է¹��� ����
	cin >> caseSize;//�׽�Ʈ���̽� ���� �Է�

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);//�׽�Ʈ ���̽� ������ŭ process �Լ� ����
	}
}