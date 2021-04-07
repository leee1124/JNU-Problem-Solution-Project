#include<iostream>
#include<cstdio>
#pragma warning(disable:4996)
using namespace std;

void bubbleSort(int data[], int n) {//버블정렬을 수행하는 함수
	for (int i = 0; i < n; i++) {//데이터의 수만큼 반복
		int negativecount = 0;//오름차순을 부정하는 쌍이 몇 개 나오는지 세는 변수
		for (int j = 0; j < n-1; j++) {//data의 j번째 방과 j+1번째 방의 값을 비교하기 때문에 n-1번 반복함
			if (data[j] > data[j+1]) {//오름차순을 부정하는 쌍이 나오면 data[j]와 data[j+1]의 자리를 교환함
				int tmp = data[j];//교환 알고리즘은 tmp변수에 data[j]의값을 저장한 후 
				data[j] = data[j+1];//data[j]에 data[j+1]의 값으로 저장함
				data[j+1] = tmp;//그리고 data[j+1]에는 data[j]의 값이 들어있던 tmp 변수의 값을 저장함. 이렇게 교환 완료 
				negativecount++;//오름차순을 부정하는 쌍의 갯수를 증가함
			}
		}
		if (negativecount == 0)//배열은 오름차순으로 정렬된 상태라면
			break;//반복문을 빠져나가 함수를 종료함
	}
}
int main() {
	int n;//데이터의 수를 입력받을 변수
	int* data;//데이터가 들어갈 배열
	scanf("%d", &n);//데이터의 수를 입력받음
	data = new int[n];//데이터의 수만큼 data배열 동적할당
	
	for (int i = 0; i < n; i++) {//앞서 입력받은 데이터의 수만큼
		scanf("%d", &data[i]);//데이터를 입력받음
	}

	bubbleSort(data, n);//버블정렬 수행

	for (int i = 0; i < n; i++) {//데이터의 수만큼 반복
		if (i > 0) {//i가 0보다 크면 반복, 처음부터 공백이 나오면 안되기 때문에 i가 0일때는 수행하지 않음
			printf(" ");//출력값이 한 칸 떨어져서 나옴
		}
		printf("%d", data[i]);//오름차순으로 정렬된 배열의 값들 출력
	}

	delete[] data;//data배열의 동적할당 해제
	return 0;//프로그램 종료
}