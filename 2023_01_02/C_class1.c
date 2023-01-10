#include <stdio.h>

//출력 스트림의 생성
int main(void){
    FILE *fp;
    fp = fopen("data2.txt", "wt");

    if(fp == NULL){
        //printf("File Writing Error!\n");
        puts("File Writing Error!\n");
		return -1;
    }
	else{
		printf("File Writing Success!\n");
		
	}
	fputc('A', fp);
	fputc('B', fp);
	fputc('C', fp);
	fputs("\nDEF", fp); //fputs 에서는 "" 해야 한다. 

	 
    fclose(fp);
	return 0;

}