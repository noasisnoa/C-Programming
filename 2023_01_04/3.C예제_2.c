//임이의 정수 N, M을 입력하여 N, M까지 출력하는 프로그램

//0 <= N, M <100000의 두 개의 정수가 있다 
//조건에 맞지 않는 수가 뜨면 에러메세지를 띄우고 다시 입력하도록 한다 

#include <stdio.h>

int main(){

    int x = 0;
    int y = 0;
	int temp = 0;

    while(1){
        printf("정수2개를 입력하세요 : ");
        scanf("%d %d", &x, &y);
        if((x>=0 && x<100000) && (y>=0 && y<100000))
		break;
        printf("입력된 변수가 0=<x,y<100000의 조건을 벗어났습니다. 다시 입력하세요 : \n");
    }
	
	
	if(x>y){
		temp = x;
		x = y;
		y = temp;
	}
	
	//x~y까지 출력
	printf("%d~%d까지의 출력결과\n", x, y);
	for(int i=x; i<=y; i++){
		printf("%d\n", i);
	}

	return 0;
}
