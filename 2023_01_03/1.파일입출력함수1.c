#include <stdio.h>
#pragma warning(disable : 4996)
#define MAX_LEN 100

//fgets와 fput만 사용한다. 
//우선 fopen함수는 scanf함수처럼 안정성 문제로 비활성화 되어있다.
//맨위에 #pragma warning(disable:4996)코드를 추가해주세요

//FILE *형 변수 fs에 test.txt파일이 읽기모드로 열려서 들어가게 된다.

//fgets(버퍼,읽을 길이,파일);

int main(void){
	FILE* fs;
	fs = fopen("test.txt", "r");
	while (feof(fs) == 0){
	char str[MAX_LEN];
	fgets(str, MAX_LEN, fs);
	printf("%s",str);	
	}
	fclose(fs);
}

// scanf는 입력의 끝은 enter이다.gets함수도 엔터를 만나면 입력을 끝으로 알고 엔터까지 출력하고 함수를 종료한다.

//여기서 부터 매우 중요!!
//파일은 파일포인터 라는것으로 이뤄집니다. 파일을 처음 열면 파일포인터는 파일의 시작지점을가리키고 있다.
//fgets은 연속해서 쓰면 계속 이어서 읽을 수 있다 

//하지만 파일 포인터를 처음 위치로 변경학 싶다면.. rewind함수를 쓰면 파일포인터의 위치를 맨앞으로 보낼수 있지만
//여기서는 fseek라는 함수를 사용하겠다.

//fseek 함수의 사용법, fseek(파일, 이동할 거리, 이동을 시작할 위치);

//feof 함수는 파일을 모두 읽었을때는 파일포인터가 SEEK_END위치에 있는지 검사해준다.


