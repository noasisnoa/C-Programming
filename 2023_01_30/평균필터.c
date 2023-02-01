#include <stdio.h>
#include <stdlib.h>

int k=1;
float x_avg_k_1=0;
float x_avg_k=0;

void Average(float x_measure)
	{
  	x_avg_k =  (x_avg_k_1*(k-1) + x_measure)/k;
	k++;
	x_avg_k_1=x_avg_k;
	}



int main(void){
	k=1;
	float n;
	int i; //반복 변수
	while(1){
		printf("넣고 싶은 수를 넣으세요 : ");
		scanf("%f",&n);
		
		Average(n);
		printf("%f \n",x_avg_k);		
	}

	return 0;
} 
