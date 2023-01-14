//길이 8m의 막대를 3명이서 1m단위로 자르려고할 때 
//몇 번 이면 1m가 될 수 있는지 알려주는 프로그램을 짜시오

//8-> 4,4-> 2,2,2,2-> 1, 1, 1, 1, 1, 1, 1, 1
//총 4번을 자르면 8m 막대기를 1m 막대기로 자를 수 있다.


#include <stdio.h>

#include <stdio.h>

//x: 최종 막대기 총 수
//y: 막대기를 자를 인원수
//count: 현재 자를 막대기 개수

int Jarki_DFS(int x, int y, int count){
	
	static int cnt = 0;
	if(count >= x)
		return cnt;
	
	cnt++;
	
	if(count < y)
		return Jarki_DFS(x, y, count*2);
	else
		return Jarki_DFS(x, y, count+y);
	
}

int main(void){
	
	int a, b;
	
	scanf("%d %d", &a, &b);
	printf("%d\n", Jarki_DFS(a,b,1));
	
	return 0;
}