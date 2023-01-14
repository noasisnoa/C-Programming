//문제 N개의 정수 수열을 연속된 네 부분으로 나누려고 한다. 
//단 각 부분은 최소 하나의 수를 포함한다. 
// 또 각 부분의 합은 모두 같아야 한다. 

//제약조건
//N>=4 && N <= 100000
//(i>=1 && i<=N)에 대해 Ai >=-1000 && Ai<=1000

//입력형식
//수열의 길이 N이 주어진다.
//두 번째 줄에 N개의 정수 A1, A2,,,,AN이 공배 하나씩 사이로 두고 주어진다. 

//출력형식
//첫번째 줄에 가능한 방법의 개수를 출력
//출력값이 매우 클 수 있으므로 C,C++언어에서는 long long형의 변수사용

#include <stdio.h>
#include <stdlib.h> //malloc(), free()

int main(){
	
	int N;  //수열의 길이 
	int i,j; //반복변수
	long long int Sum; //수열의 전체 합을 구하는 변수
	
	//N개의 수열을 4파트로 나눌 수 있도록 한다.
	//파트당 최소 1개의 수열이 있도록 한다.
	int Pn[4]={1, 0, 0, 0};
	
	//각각의 파트의 공통합을 구하기 위하여 최가값을 0으로 세팅한다.
	long long int Psum;
	
	scanf("%d", &N);
	if(N>=4 && N<=100000){
		
		//N개의 값을 입력받는다. 동적메모리 활용한다.
		int *M=(int *)malloc(sizeof(int)*N);
		for(i=0; i<N; i++){
			//1~N개의 수열 중 -1000~1000범위 값이 아니면 작업을 끝낸다.
			scanf("%d", &M[i]);
			if(M[i]<-1000 || M[i] >1000)
				return 0;
		}
		
		//수열의 전체 합을 구한다.
		Sum=0;
		for(i=0;i<N;i++){
			Sum += (long long int)M[i];
		}
		
		//각 구역의 합이 같은 값을 구한다.
		for(j=0;j<N;j++){
			Psum+=(long long int)M[j];
			for(i=3;i>=0;i--){
				if(Psum==Sum*i/4){
					Pn[i]+=Pn[i-1];
				}
			}
		}
		
		//결과 출력
		printf("%d", Pn[3]);
		
		//동적 메모리를 해제한다.
		free(M);
	}
	
	return 0;
}