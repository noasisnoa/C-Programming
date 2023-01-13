#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define NO_MAX_WAYPOINTS 50

float  SONAR_DATA[NO_MAX_WAYPOINTS] = {0,};
int no_line = -1;

int read_waypoints_data(){
	
    FILE *fp;
    fp = fopen("sonar.text", "r");

	int result = 0;
	float x;

	
	if(fp == NULL){
		printf("File Qriting Error!\n");
		return -1;
	}else{
		printf("waypoints.data open\n");
		
		do{
			result = result = fscanf(fp, "%f", &x);
			
			SONAR_DATA[++no_line] = x;		
			//no_line++;
			
		}while(result != EOF);
	}
	fclose(fp); //데이터를 가지고 왔으니 파일을 닫아준다.
	printf("End of line = %d\n", no_line);
	
	for(int i=0; i<no_line; i++){
		printf("%d %lf\n", i +1, SONAR_DATA[i]);
	}

}

////////////////////////////////////////////////////////////////////////////

int sonar_avg(){
	
	double sum = 0;
	double avg = 0;
	
	for(int i=0; i<no_line; i++){
		sum += SONAR_DATA[i];	
	}

	avg = sum/ no_line;
	printf("평균 : %f\n", avg);
	
}


int sonar_a(){
	
	double sum = 0;
	double v = 0;
	double avg = 0;
	double a = 0;

	for(int i=0; i<no_line; i++){
		sum += (SONAR_DATA[i]-avg) * (SONAR_DATA[i]-avg);	
	}
	
	v = sum/ no_line;
	a = sqrt(v);
	
	printf("표준편차 : %f", a);
	
}


int main(void){
	
	read_waypoints_data();
	sonar_avg();
	sonar_a();
	
	return 0;
	
}