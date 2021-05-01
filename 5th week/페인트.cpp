#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

const int MAX_TABLE_LENGTH = 10000;//0000~ 9999까지 이므로 전화번호 뒷자리의 수는 10000개

void fillFrequnecyTable(int data[], int n, int table[]) {//data[0] ~ data[n-1]에 등장한 번호들에 대한 빈도수 테이블을 채우는 함수
	int frequent_number = 0;//data배열에 들어있는 전화번호 뒷자리를 저장할 배열
	for (int i = 0; i < n; i++) {//전화번호 개수만큼 반복
		frequent_number = data[i];//data배열에 들어있는 전화번호 뒷자리를 저장
		table[frequent_number]++;//전화번호에 해당하는 빈도수 테이블의 수를 증가
	}//frequent_table을 사용하지 않아도, table[data[i]]++;으로 사용 가능
}

int getFrequentNumber(int data[], int n) {
	int frequent_number = 0;//가장 많이 나온 전화번호 뒷자리를 입력받을 변수
	int table[MAX_TABLE_LENGTH] = { 0 };//전화번호의 최대 수만큼 빈도수 테이블을 0으로 초기화함

	fillFrequnecyTable(data, n, table);

	for (int i = 0; i < 10000; i++) {//0000~9999까지 반복
		if (table[i] > table[frequent_number])//i가 작은 수부터 시작하기 때문에 횟수가 같은 번호가 2개인 경우, 작은 숫자가 먼저 나옴
			frequent_number = i;//만약 최대 빈도수보다 더 많이 나온 숫자가 있으면 최대 빈도수로 나온 전화번호 업데이트
	}

	return frequent_number;//최대 빈도수를 가진 전화번호 뒷자리 반환
}

int main() {
	int n;//전화번호의 개수를 입력받을 변수
	
	scanf("%d", &n);//전화번호 개수 입력
	int* data = new int[n];//data배열을 전화번호 개수만큼 동적 할당

	for (int i = 0; i < n; ++i) {
		scanf("%d", &data[i]);//n개의 전화번호 입력
	}
	int answer = getFrequentNumber(data, n);//0000~9999중 가장 많이 나온 전화번호를 answer에 저장

	printf("%04d", answer);//%04d를 이용해 4자리 숫자가 나옴

	delete[] data;//data배열 동적할당 해제
	return 0;//프로그램 종료
}