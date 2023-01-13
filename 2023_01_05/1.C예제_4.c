#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void){
	
	int T; // 몇개의 문자열을 만들것인지
	char str[255]; //임의의 문자열을 입력할 문자열 배열 변수
	int r,c;//행 열 변수
	int c1, c2; //열변수
	int chk1, chk2, chk3; //회문, 유사회문 비회문 변수
	int i; //반복변수
	int N; //체크할 문자열의 길이
	
	//몇개의 문자열의 개수를 입력받을 것인가
	printf("몇개의 문자열을 만들것인가요: ");
	scanf("%d%*c",&T);
	
	//1<=T <=30 조건에 맞으면 작업을 계속한다.
	if(T>=1 && T<=30){
		//입력된 개수 만큼의 문자열을 입력할 동적 메모리를 설정한다. 
		char **M=(char**)malloc(sizeof(char*)*T);
		for(r=0;r<T;r++)
		{
			scanf("%s%*c",str);
			if(strlen(str)>=3 && strlen(str)<100000)
			{
				M[r]=(char*)malloc(sizeof(char)*(strlen(str)+1));
				strcpy(M[r],str);
			}
			else
				return 0;
		}
		//입력된 문자열이 회문, 유사회문, 둘 다 아닌지 체크한다.
		
		for(r=0;r<T;r++)
		{	//문자열 중 틀린 글자가 나오면 회문이 아님
			//틀린 문자의 위치를 회문체크변수에 지장
			//회문이면 출력
			chk1=-1; // 회문체크변수
			N=strlen(M[r]);
			for(c=0;c<N/2;c++)
				if(M[r][c] != M[r][N-1-c]){
					chk1=c;
					break;
				}
				if(chk1==-1){
					printf("0\n");
				}
				else{
					//유사회문 또는 비회문인지 체크한다.
					c1=c2=0;
					chk2=0;
					chk3=0;
					char *chkStr1=(char*)malloc(sizeof(char)*(strlen(M[r])+1));
					char *chkStr2=(char*)malloc(sizeof(char)*(strlen(M[r])+1));//비교할 문자열 변수
					
					//틀린 위치의 문자를 뺀 문자들을 각각의 변수에 저장한다.
					for(i=0;i<N;i++)
					{
						if(i!=chk1)
							chkStr1[c1++]=M[r][i];
						if(i!=N-1-chk1)
							chkStr2[c2++]=M[r][i];
					}
					
		//각각의 문자들을 비교하여 유사회문, 비회문을 체크한다.			
		for(i=0;i<N-1;i++)
			{
				if(chkStr1[i] != chkStr1[N-2-i])
					chk2=1;
				if(chkStr2[i] != chkStr2[N-2-i])
					chk3=1;
			}
			if(chk2==1&&chk3==1)
				printf("2\n");
			else
				printf("1\n");
			free(chkStr1);
			free(chkStr1);
			}
		}
		
	for(r=0;r<T;r++)
			free(M[r]);
		free(M);
    }
	
	return 0;
}
