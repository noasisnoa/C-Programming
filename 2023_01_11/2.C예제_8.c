//피자를 구워주는 오븐이 있다. 
//ADDH(60분 증가)
//ADDT(10분 증가)
//MINT(10분 감소)
//ADDO(1분 증가)
//MINO(1분 감소)

//내가 원하는 분으로 세팅할 때 가장 적은 횟수로 그 시간을 세팅해 하는 프로그램을 작서하여라

//입력방식
//프로그램의 한 번의 실행에 여러개의 세팅해야할 시간을 입력으로 받아 모두 처리해야 한다.
//하나의 입력 시간을 처리하고 다음 입력을 처리할 때 오븐의 시간은 다시 0분으로 초기화 된다. 
//즉 각각의 입력은 따로 처리하는 것이다. 

// 처리해야하는 경우들의 개수 T(T>=1 && T<=10,0000,000)

//출력형식
//각 경우마다 5개의 정수를 한 줄에 출력한다. 
//이 정수들은 차례로 세팅해야 할 시간을 만드는 버튼 ADDH, ADDT, MINT, ADDO, MINO 가 있다.
//버튼을 누르는 횟수를 ADDH, ADDT, MINT, ADDO, MINO 순서대로 한다.
//사전순이라 함은 동일한 시간을 세팅하고 작업 횟수가 동일한 방법이 여러가지가 있을 때, 
//ADDH를 누르는 횟수가 작은 것이 우선이고 ADDH를 누르는 횟수가 동일한 것이 여러개 있으면 
//다음으로 ADDT를 누르는 횟수가 작아지는 것을 우선으로 등등 선택한다.

//예시1]
//입력
//3
//4
//12
//27

//출력
//00050
//01020
//03003


#include <stdio.h>
#include<stdlib.h> //malloc(), free()

int main(){
	
	int T; //처리할 작업 수 변수
	int i; //반복 변수
	int ADDH; //+60분
	int ADDT; //10분
	int MINT; //-10분
	int ADDO; //+1분
	int MINO; //-1분
	
	scanf("%d", &T);
	
	if(T>=1 && T<=100){
		int *N = (int *)malloc(sizeof(int)*T);
		
		//작업수에 해당하는 실제 작업시간을 입력한다.
		for(i=0; i<T; i++){
			
			scanf("%d", &N[i]);
			
			//조건에 해당하는 작업시간이 아니면 작업을 끝낸다.
			if(N[i]<1 || N[i]>10000000)
				return 0;
		}
		
		//각 입력작업시간의 최소 버큰 횟수를 구한다.
		for(i=0; i<T; i++){
			
			ADDH = 0;
			ADDT = 0;
			MINT = 0;
			ADDO = 0;
			MINO = 0;
			
			ADDH += N[i]/60;
			N[i]%= 60;
			
			if(N[i]>35){
				ADDH++;
				MINT = 6-(N[i]+5)/10;
				N[i]%=10;
				
				if(N[i]>=5)
					MINO += 10 - N[i];
				else ADDO +=N[i];
			}
			else{
				
				ADDT = (N[i]+4)/10;
				N[i]%=10;
				 
				  if(N[i] >= 6)
					  MINO += 10-N[i];
				  else
					  ADDO += N[i];
			}
			
			//결과 출력
			printf("%d %d %d %d %d\n", ADDH, ADDT, MINT, ADDO, MINO);
		}
		
		
		//동적 메모리 해제
		free(N);
	}
	
	   return 0;
	
	
}
