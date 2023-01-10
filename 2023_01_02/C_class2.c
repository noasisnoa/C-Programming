#include <stdio.h>

//스트림의 소멸을 요정하는 fclose 함수
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
	printf("%d\n", fclose(fp));

	 
    fclose(fp);
	return 0;

}