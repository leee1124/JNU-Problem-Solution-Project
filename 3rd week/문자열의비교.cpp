#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
#pragma warning(disable: 4996)
using namespace std;

const int MAX_LENGTH = 100000;

class MyString {
private:
	char* characters;//MyString Ŭ������ �ִ� charters �迭, ���ڿ��� �� ����
	int length;//MyString Ŭ������ ���̰� �� ����

public:
	MyString(const char* str) {//MyString�� ������, �Ű������� char �迭�� ����
		this->length = strnlen(str, MAX_LENGTH);//strnlen�Լ��� ����Ͽ� �ִ���̸� MAX_LENGTH���� �����ϰ�, str�� ���̸� length ������ ����
		this->characters = new char[this->length];//length������ŭ �迭�� ���� �Ҵ�
		for (int i = 0; i < this->length; i++) {//�� ��ü�� length�� ����ŭ �ݺ�
			this->characters[i] = str[i];//characters�迭�� str���ڿ� ����
		}
	}

	MyString(const string& original) {//MyString�� ������, �Ű������� ���ڿ� �������� ������
		this->length = original.length();//�� Ŭ������ ��ü�� length�� ���� ���ڿ��� ũ��� �ʱ�ȭ
		this->characters = new char[this->length];//length������ ����ŭ charters�迭 ���� �Ҵ�
		for (int i = 0; i < this->length; i++) {//�� ��ü�� length�� ����ŭ �ݺ�
			this->characters[i] = original[i];//characters�迭�� ���� ���ڿ� ����
		}
	}
	~MyString() {//�Ҹ���
		delete[] characters;//ĳ���ͽ� �迭�� ���� �Ҵ� ����
	}

	/*
	@param o ���� ���ڿ�(������ ��)
	@return true this�� o���� ���������� �ռ��ٸ� true
	@return false �׷��� �ʴٸ� false
	*/

	bool operator < (const MyString& o)const {//�񱳿����� �����ε�
		int n = min(this->length, o.length);//n�� ���� ���ڿ��� ���� ���ڿ��� ũ���� ���� ������ �ʱ�ȭ
		for (int i = 0; i < n; i++) {//ũ�Ⱑ ���� ���ڿ��� ũ�⸸ŭ �ݺ�
			if (this->characters[i] < o.characters[i])//this�� ���� ���ڿ����� ���������� �ռ��ٸ�
				return true;//true ��ȯ
			else if (this->characters[i] > o.characters[i]) {//this�� ���� ���ڿ����� ���������� �ڶ��
				return false;//false ��ȯ
			}
		}
		if (this->length < o.length) {//���� ���ڿ��� this�� �����ϰ� ������
			return true;//true ��ȯ(ex. algo, algorithm�̸� algo�� ���������� �ռ��ٴ� ��)
		}
		else {//�׷��� �ʴٸ�
			return false;//false ��ȯ(ex. algorithm, algo�̸� algorithm�� ���������� �ڶ�� ��)
		}
	}
	/*
@param o ���� ���ڿ�(������ ��)
@return true o�� this���� ���������� �ռ��ٸ� true
@return false �׷��� �ʴٸ� false
*/
	bool operator > (const MyString& o)const {//�񱳿����� �����ε�
		int n = min(this->length, o.length);//n�� ���� ���ڿ��� ���� ���ڿ��� ũ���� ���� ������ �ʱ�ȭ
		for (int i = 0; i < n; i++) {//ũ�Ⱑ ���� ���ڿ��� ũ�⸸ŭ �ݺ�
			if (this->characters[i] < o.characters[i])//this�� ���� ���ڿ����� ���������� �ռ��ٸ�
				return false;//false ��ȯ
			else if (this->characters[i] > o.characters[i]) {//this�� ���� ���ڿ����� ���������� �ڶ��
				return true;//true ��ȯ
			}
		}
		if (this->length > o.length) {//���� ���ڿ��� this�� ���ԵǾ� ������
			return true;//true ��ȯ
		}
		else {//�׷��� �ʴٸ�
			return false;//false ��ȯ
		}
	}
	/*
@param o ���� ���ڿ�(������ ��)
@return true �� ���ڿ��� ���ٸ� true
@return false �׷��� �ʴٸ� false
*/
	bool operator == (const MyString& o)const {//�񱳿����� �����ε�
		if (this->length != o.length)//this�� ���� ���ڿ��� ���̰� �ٸ��ٸ�
			return false;//false ��ȯ
		
		for (int i = 0; i < this->length; i++) {//���̰� ������ ���ڿ��� ���̸�ŭ �ݺ�
			if (this->characters[i] != o.characters[i])//���� �ѱ��ڶ� �ٸ���
				return false;//false ��ȯ
		}
		return true;//��� ������ true ��ȯ
	}
};

int main() {
	string s1;//�Է¹ޱ� ���� s1 ���ڿ���
	string s2;//s2 ���ڿ�
	cin >> s1 >> s2;//scanf��� cin�� ���⿬���� >>�� ����� ���ڿ� 2�� �Է�

	MyString mys1(s1);//�Է¹��� ���ڿ� s1�� �̿��� MyString ���� mys1 ����
	MyString mys2(s2);//�Է¹��� ���ڿ� s2�� �̿��� MyString ���� mys1 ����

	if (mys1 < mys2) {//ó�� �Է¹��� ���ڿ��� �ι�°�� �Է¹��� ���ڿ����� ���������� �ռ��ٸ�
		printf("-1");//-1 ���
	}
	else if (mys1 > mys2) {//ó�� �Է¹��� ���ڿ��� �ι�°�� �Է¹��� ���ڿ����� ���������� ���� �ƴ϶��
		printf("1");//1 ���
	}
	else {//ó�� �Է¹��� ���ڿ��� �ι�°�� �Է¹��� ���ڿ��� �����ϴٸ�
		printf("0");//0���
	}
}