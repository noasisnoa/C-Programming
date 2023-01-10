#include <stdio.h>
//스트림을 구분하느 기준 1:Read or Write
//바인더리 데이터라는 것이 있데 재미있겠다..

//새로운 text를 만듬, text파일을 문자로 읽는 것이 아니라 숫자로도 읽을 수 있다. char을 사용하지 않겠다.

int main(void){
	
	FILE *fp;
	
	fp = fopen("data3.txt", "rt");
	
	int i;
	int data1 = 0;
	double data2 = 0.0;
	char ch;//문자를 넣을 것이기 때문에  char
	
	
	if(fp == NULL){
        //printf("File Writing Error!\n");
        puts("File Reading Error!\n");
		return -1 ;
    }
	else{
		printf("File Reading Success!\n");	
	}
	
	for(i =0; i<2; i++){  
		//문자가 아니기 때문에 fscanf를 사용해야 한다.

		fscanf(fp,"%d", &data1); 
		printf("%d \n", data1);
	}
	
	for(i =0; i<2; i++){   
		//문자가 아니기 때문에 fscanf를 사용해야 한다.

		fscanf(fp,"%lf", &data2); //double형이기 때문에 lf 사용
		printf("%lf \n", data2);
	}
	fclose(fp);

	return 1;
}


void example1(void){
	
    FILE *fp;
    fp = fopen("data2.txt", "wt");

    if(fp == NULL){
        //printf("File Writing Error!\n");
        puts("File Writing Error!\n");
		return;
    }
	else{
		printf("File Writing Success!\n");	
	}
	
	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp); 
	fputs("\nDEF\n", fp); //fputs 에서는 "" 해야 한다. 
						//대신해서 fprintf(fp,"A")사용할 수 있다.
						//교수님께서는 fprintf를 더 많이 사용하는게 이유는 타입을 걸어서 좀 더 많은 인자를 사용할 수 있기 때문이다.  
	printf("%d", fclose(fp));
	return; //void이기 때문에 return으로 바꾼다.

}

void example2(void){ //void형에서는 return 그래도 사용
		
	FILE *fp;
    fp = fopen("data2.txt", "rt"); //read text로 한다. 
	
	int i;
	char ch;//문자를 넣을 것이기 때문에  char
	
	
	if(fp == NULL){
        //printf("File Writing Error!\n");
        puts("File Reading Error!\n");
		return ;
    }
	else{
		printf("File Reading Success!\n");	
	}
	
	for(i =0; i<6; i++){   //두개가 더 나온 것에 대해서는 나중에 설명하겠다.
		//ch = fgetc(fp); //한 char씩 가지고 온다.
		fscanf(fp,"%c", &ch);
		printf("%c \n", ch);
	}
	fclose(fp);

	return ;
	
}

//빅데이터에 들어가는 문을 연 것이다. 