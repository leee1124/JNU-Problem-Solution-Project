#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<ctime>
#include<set>
using namespace std;

#define MUL 65536// ���� ��

map<string, int> fir;//ó�� �Է¹��� ���ڿ��� ���� map ����
map<string, int> sec;//�ι�°�� �Է¹��� ���ڿ��� ���� map ����
set<string> substrings;//���꽺Ʈ������ ���� set����

void init(string first, string second) {//�ʰ� ���� �ʱ�ȭ�ϴ� �Լ�
	string ss;//���ڿ����� 2���ڸ� ���� ���꽺Ʈ��

	for (int i = 0; i < max(first.length(), second.length()) - 1; i++) {//first�� second�� �� �� ���ڿ���ŭ �ݺ�
		if (i < first.length()-1) {//���� ù��° ���ڿ���ŭ �� �ȵ�������
			ss = first.substr(i, 2);//ù��° ���ڿ��� ���꽺Ʈ��
			if ('a' <= ss[0] && ss[0] <= 'z')	ss[0] = ss[0] - 32;//ss�� �ҹ����̸�
			if ('a' <= ss[1] && ss[1] <= 'z')	ss[1] = ss[1] - 32;//�빮�ڷ� �ٲ�

			bool cond_1 = 'A' <= ss[0] && ss[0] <= 'Z';//ss[0]�� ���ĺ����� Ȯ���ϱ� ���� ����
			bool cond_2 = 'A' <= ss[1] && ss[1] <= 'Z';//ss[1]�� ���ĺ����� Ȯ���ϱ� ���� ����

			if (fir.find(ss) != fir.end()) {//fir �ʿ��� first ���ڿ��� ���꽺Ʈ���� �ִ��� ã�ƺ�
				fir[ss]++;//������ value�� ����
			}
			else {//������
				if (cond_1 && cond_2) {//ss�� ���ĺ����θ� �̷�������� Ȯ��
					fir[ss] = 1;//���ĺ����θ� �̷�������� value�� 1�� �ʱ�ȭ
					substrings.insert(ss);//substrings ��Ʈ�� ss ���� ���꽺Ʈ�� �߰�
				}
			}

		}

		if (i < second.length()-1) {//���� �ι�° ���ڿ���ŭ �� �ȵ�������
			ss = second.substr(i, 2);//�ι�° ���ڿ��� ���꽺Ʈ��
			if ('a'<= ss[0] && ss[0] <= 'z')	ss[0] = ss[0] - 32;//ss�� �ҹ����̸�
			if ('a' <= ss[1] && ss[1] <= 'z')	ss[1] = ss[1] - 32;//�빮�ڷ� �ٲ�
			bool cond_1 = 'A' <= ss[0] && ss[0] <= 'Z';//ss[0]�� ���ĺ����� Ȯ���ϱ� ���� ����
			bool cond_2 = 'A' <= ss[1] && ss[1] <= 'Z';//ss[1]�� ���ĺ����� Ȯ���ϱ� ���� ����

			if (sec.find(ss) != sec.end()) {//sec �ʿ��� second ���ڿ��� ���꽺Ʈ���� �ִ��� ã�ƺ�
				sec[ss]++;//������ value�� ����
			}
			else {
				if (cond_1 && cond_2) {//ss�� ���ĺ����θ� �̷�������� Ȯ��
					sec[ss] = 1;//���ĺ����θ� �̷���� ������ value���� 1�� �ʱ�ȭ
					substrings.insert(ss);//substrings ��Ʈ�� ss ���� ���꽺Ʈ�� �߰�
				}
			}
		}
	}
}

int solution(string first, string second) {
	init(first, second);//�ʰ� �º������� �ʱ�ȭ

	int uni=0;//������
	int inter=0;//������
	
	for (auto iter : substrings) {//substrings�� iterator�� �̿��ؼ� �ݺ�
		inter += min(fir[iter], sec[iter]);//���� �� ������ �������� ������
		uni += max(fir[iter], sec[iter]);//���� �� ū ���� �������� ������
	}
	
	if (inter == 0 && uni == 0) return MUL;//�������̸� ��ī�� ���絵�� 1�ε�, MUL��ŭ ���ؼ� ����ؾ� �ϹǷ� MUL ��ȯ
	return MUL * inter / uni;//��ī�� ���絵�� ������ / ������
}


int main() {
	time_t start, end;// �ð� ������ ���� ����
	string first, second;// �� ���ڿ��� �Է¹��� ����
	
	getline(cin, first);// ù ��° ���ڿ� �Է�
	getline(cin, second);// �� ��° ���ڿ� �Է�
	start = clock();// �ð� ���� ����

	int res = solution(first, second);//�ַ�� �Լ��� ���� ���� ����� res�� ����
	
	cout << res << endl;//��� ���
	end = clock();//�ð� ���� ����
	double result = (double)(end - start) / CLOCKS_PER_SEC;//�����ð� �ʴ�����
	cout << "����ð�: " << result << "��" << endl;//����ð� ���

	return 0;//���α׷� ����
}