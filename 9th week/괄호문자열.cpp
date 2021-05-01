#include<iostream>
#include<stack>
#include<string>
#include<vector>
#pragma warning(disable:4996)

using namespace std;

class Parenthesis {
public:
	bool type;//열린 괄호면 true, 아니면 false
	int index;//해당 괄호의 인덱스

	Parenthesis(int index, bool type) {//클래스의 생성자, 두번째 매개변수가 bool형 변수이면 이 생성자를 실행
		this->index = index;//객체의 index에 int형 매개변수 index의 값 저장
		this->type = type;//객체의 type에 bool형 매개변수 type의 값 저장
	}
	Parenthesis(int index, char c) {//클래스의 생성자, 두번째 매개변수가 char형 변수이면 이 생성자를 실행
		this->index = index;//객체의 index에 int형 매개변수 index 저장
		if (c == '(') {//만약 char형 매개변수 c의 값이 ( 이면 객체의 타입에 true 저장
			this->type = true;
		}
		else {//만약 char형 매개변수 c의 값이 (이 아니면 객체의 타입에 false 저장
			this->type = false;
		}
	}
};
bool isValidParentheses(const vector<Parenthesis>& parentheses) {//
	//현재 짝을 찾지 못한 열린 괄호들만 저장
	//닫힌 괄호가 나오면 탑에 저장된 열린 괄호를 삭제해나감
	//탑 원소 삭제만 이루어짐 -> 스택변수로 선언
	stack<Parenthesis> myStack;
	
	for (int i = 0; i < parentheses.size(); i++) {//왼쪽부터 오른쪽의 괄호를 차례로 조회한다. 벡터변수이므로 모든 원소 접근
		Parenthesis p = parentheses[i];

		if (p.type == true)//열린 괄호이면 짝을 찾을 때 까지 스택에 보관
			myStack.push(p);
		else if (p.type == false) {//닫힌 괄호라면
			if (myStack.size() > 0) {//스택의 크기가 1 이상인 경우 마지막으로 열린 괄호와 짝을 맞출 수 있음
				myStack.pop();
			}
			else {//스택의 크기가 0이면
				return false;//짝을 맞출 수 있는 열린 괄호가 없으므로 올바르지 않은 괄호 문자열이므로 false를 반환한다.
			}
		}
	}
	if (myStack.size() != 0)//스택의 크기가 0보다 크면 짝을 못맞춘 괄호가 남아있는 것이므로
		return false;//false 반환
	return true;//모든 괄호가 짝을 맞췄으면 true를 반환한다.
}

void process(int caseIndex) {
	string str;//괄호 문자열을 입력받을 변수
	cin >> str;//괄호 문자열 입력

	vector<Parenthesis> parentheses;//Parenthesis 클래스의 인스턴스를 원소로 받을 배열 parentheses
	for (int i = 0; i < str.length(); ++i) {//str의 길이만큼 반복
		parentheses.push_back(Parenthesis(i, str[i]));//배열에 괄호 문자열을 넣음
	}

	bool isValid = isValidParentheses(parentheses);//isValidParentheses 함수가 반환한 값을 isValid 변수에 저장

	if (isValid) {//isValid 변수가 참이면 YES 출력
		cout << "YES" << endl;
	}//아니면 NO 출력
	else {
		cout << "NO" << endl;
	}
}

int main() {
	int caseSize;//테스트 케이스의 개수를 입력받을 변수
	cin >> caseSize;//테스트케이스 개수 입력

	for (int caseIndex = 1; caseIndex <= caseSize; caseIndex += 1) {
		process(caseIndex);//테스트 케이스 개수만큼 process 함수 실행
	}
}