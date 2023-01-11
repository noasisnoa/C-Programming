#include <stdio.h>
#define NO_MAX_WAYPOINTS 50


//result 값이 EOF(End of File)이 올때 까지 읽고 데이터 lline의 갯수를 출력 할것


float   X[NO_MAX_WAYPOINTS] = {0,};
float   Y[NO_MAX_WAYPOINTS] = {0,};
float YAW[NO_MAX_WAYPOINTS] = {0,};

int read_waypoints_data(void)

{

    FILE *fp;
	int result;
    int no_line = 0;
    float x,y,yaw; 
	
    fp= fopen("waypoints.dat","r");
	
    do  
    {

      result = fscanf(fp,"%f %f %f", &x,&y,&yaw);
      X[no_line] = x;
      Y[no_line] = y;
	  YAW[no_line] = yaw;
	  printf(" %f, %f, %f \n", x, y, yaw);

      no_line++;

    } while(result !=EOF);
	//printf("no of line %d\n", no_line);
    return no_line;
}

int main(){
	int num;
	num = read_waypoints_data();
	printf("END OF LINE :%d", num);
	for(int i=0; i<num; i++){
		printf(" %d %f %f %f \n",i+1, X[i], Y[i], YAW[i]);
	}
	return 0;
	
}