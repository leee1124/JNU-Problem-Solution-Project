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
	char* characters;//MyString 클래스에 있는 charters 배열, 문자열이 들어갈 변수
	int length;//MyString 클래스의 길이가 들어갈 변수

public:
	MyString(const char* str) {//MyString의 생성자, 매개변수를 char 배열로 받음
		this->length = strnlen(str, MAX_LENGTH);//strnlen함수를 사용하여 최대길이를 MAX_LENGTH까지 제한하고, str의 길이를 length 변수에 대입
		this->characters = new char[this->length];//length변수만큼 배열의 동적 할당
		for (int i = 0; i < this->length; i++) {//이 객체의 length의 값만큼 반복
			this->characters[i] = str[i];//characters배열에 str문자열 대입
		}
	}

	MyString(const string& original) {//MyString의 생성자, 매개변수를 문자열 원본으로 가져옴
		this->length = original.length();//이 클래스의 객체의 length를 원본 문자열의 크기로 초기화
		this->characters = new char[this->length];//length변수의 값만큼 charters배열 동적 할당
		for (int i = 0; i < this->length; i++) {//이 객체의 length의 값만큼 반복
			this->characters[i] = original[i];//characters배열에 원본 문자열 대입
		}
	}
	~MyString() {//소멸자
		delete[] characters;//캐릭터스 배열의 동적 할당 해제
	}

	/*
	@param o 비교할 문자열(오른쪽 항)
	@return true this가 o보다 사전순으로 앞선다면 true
	@return false 그렇지 않다면 false
	*/

	bool operator < (const MyString& o)const {//비교연산자 오버로딩
		int n = min(this->length, o.length);//n을 원래 문자열과 비교할 문자열의 크기중 작은 값으로 초기화
		for (int i = 0; i < n; i++) {//크기가 작은 문자열의 크기만큼 반복
			if (this->characters[i] < o.characters[i])//this가 비교할 문자열보다 사전순으로 앞선다면
				return true;//true 반환
			else if (this->characters[i] > o.characters[i]) {//this가 비교할 문자열보다 사전순으로 뒤라면
				return false;//false 반환
			}
		}
		if (this->length < o.length) {//비교할 문자열이 this를 포함하고 있으면
			return true;//true 반환(ex. algo, algorithm이면 algo가 사전순으로 앞선다는 것)
		}
		else {//그렇지 않다면
			return false;//false 반환(ex. algorithm, algo이면 algorithm이 사전순으로 뒤라는 것)
		}
	}
	/*
@param o 비교할 문자열(오른쪽 항)
@return true o가 this보다 사전순으로 앞선다면 true
@return false 그렇지 않다면 false
*/
	bool operator > (const MyString& o)const {//비교연산자 오버로딩
		int n = min(this->length, o.length);//n을 원래 문자열과 비교할 문자열의 크기중 작은 값으로 초기화
		for (int i = 0; i < n; i++) {//크기가 작은 문자열의 크기만큼 반복
			if (this->characters[i] < o.characters[i])//this가 비교할 문자열보다 사전순으로 앞선다면
				return false;//false 반환
			else if (this->characters[i] > o.characters[i]) {//this가 비교할 문자열보다 사전순으로 뒤라면
				return true;//true 반환
			}
		}
		if (this->length > o.length) {//비교할 문자열이 this에 포함되어 있으면
			return true;//true 반환
		}
		else {//그렇지 않다면
			return false;//false 반환
		}
	}
	/*
@param o 비교할 문자열(오른쪽 항)
@return true 두 문자열이 같다면 true
@return false 그렇지 않다면 false
*/
	bool operator == (const MyString& o)const {//비교연산자 오버로딩
		if (this->length != o.length)//this와 비교할 문자열의 길이가 다르다면
			return false;//false 반환
		
		for (int i = 0; i < this->length; i++) {//길이가 같으면 문자열의 길이만큼 반복
			if (this->characters[i] != o.characters[i])//만약 한글자라도 다르면
				return false;//false 반환
		}
		return true;//모두 같으면 true 반환
	}
};

int main() {
	string s1;//입력받기 위한 s1 문자열과
	string s2;//s2 문자열
	cin >> s1 >> s2;//scanf대신 cin과 추출연산자 >>을 사용해 문자열 2개 입력

	MyString mys1(s1);//입력받은 문자열 s1을 이용해 MyString 변수 mys1 생성
	MyString mys2(s2);//입력받은 문자열 s2을 이용해 MyString 변수 mys1 생성

	if (mys1 < mys2) {//처음 입력받은 문자열이 두번째로 입력받은 문자열보다 사전순으로 앞선다면
		printf("-1");//-1 출력
	}
	else if (mys1 > mys2) {//처음 입력받은 문자열이 두번째로 입력받은 문자열보다 사전순으로 앞이 아니라면
		printf("1");//1 출력
	}
	else {//처음 입력받은 문자열과 두번째로 입력받은 문자열이 동일하다면
		printf("0");//0출력
	}
}