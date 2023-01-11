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
	char str[MAX_LEN];
	fgets(str, MAX_LEN, fs);
	printf("%s",str);
}