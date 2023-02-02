#include <stdio.h>

float x_avg_k_1=0;
float x_avg_k=0;
float data[3]={0,0,0}; //현재 평균 값을 저장해주는 변수
//총 폭이 1200 이고 반으로 나누면 600이다. 아두이노에서 최대 값이 2500이다. 
//3개를 사용하였다. 그러면 아무리 작은 값을 넣어줘도 {2500, 600, 600}/3 = 12333.333 쯤 된다. 

int K=1;


//재귀평균함수
void Average(float x_measure, int k)
	{
  	x_avg_k =  (x_avg_k_1*(k-1) + x_measure)/k;
	//k++;
	x_avg_k_1=x_avg_k;
	}

//재귀이동평균 함수
 void Moving_average (float x_measure){
	 
	 for(int i=0; i<4; i++){
		 data[i]=data[i+1];
	 }
	 
	 
	 data[2]=x_measure;
     x_avg_k = x_avg_k_1+(data[2]-data[0])/5; //현재평균 = 엣날평균 + (현재값 -과거값)/k
     x_avg_k_1 = x_avg_k ;
  }

int main(void){
	
	float n=0;

	
	for(int i=0; i<5; i++){
		
		printf("넣고 싶은 값을 넣으세요 : ");
		scanf("%f",&n);
		Average(n,K);
		K = K+1;
		printf("%f \n",x_avg_k);
		data[i] = n;
	}
	while(1){
		
		printf("넣고 싶은 값을 넣으세요 : ");
		scanf("%f",&n);
		Moving_average(n);
		printf("%f \n",x_avg_k);
	}
}