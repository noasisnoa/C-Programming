#include <stdio.h>

int main(void){
    FILE *fp;
    fp = fopen("data2.txt", "wt");

    if(fp == NULL){
        printf("File Writing Error!\n");
        return -1;
    }
	else{
		printf("File Writing Success!\n");
		
	}

    fclose(fp);
	return 0;

}