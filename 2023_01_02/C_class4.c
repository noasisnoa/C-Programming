#include <stdio.h>

//파일로부터 데이터를 읽어본다. 
//fgetc를 사용하는 대신에 다른 것을 사용해보자.


int main(void){
	
	FILE *fp;
    fp = fopen("data2.txt", "rt"); //read text로 한다. 
	
	int i;
	char ch;//문자를 넣을 것이기 때문에  char
	
	
	if(fp == NULL){
        //printf("File Writing Error!\n");
        puts("File Reading Error!\n");
		return -1 ;
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
	printf("%d", fclose(fp));
	return; //void이기 때문에 return으로 바꾼다.

}