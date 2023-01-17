//원소 삽입하기

#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


typedef struct Node
{
	int number;
	int name;
	int korean;
	int math;
	int english;
	
	struct Node *next;
	
}student;

int insertNode(Node **ptrHead)
{
	
	int tem_number;
	int tem_name;
	int tem_korean;
	int tem_math;
	int tem_english;
	//scanf로 입력받기

	Node tempNode = (Node *)malloc(sizeof(Node));
	if(!tempNode)
	{
		return -1;
		
	}
	
	tempNode -> number = tem_number;
	tempNode -> name = tem_name;
	tempNode -> korean = tem_korean;
	tempNode -> math = tem_math;
	tempNode -> english = tem_english;
	tempNode -> next = ptrHead;
	*ptrHead = tempNode ;
		

	return 1;
}

void printList(Node *head)
{
	
	printf("리스트 출력\n");///*head
	while(1)
	{
		printf("학번 : %d", head -> number );
		printf("이름 : %d", head -> name );
		printf("수학 : %d", head -> math );
		printf("국어 : %d", head -> korean );
		printf("영어 : %d", head -> english );
	}
	printf("\n");
}

int main()
{
	
	insertNode(&head);
	printf("리스트 출력\n");
	printList(&head)
		
	insertNode(&head);
	printf("리스트 출력\n");
	
	return 1;
	
	
}