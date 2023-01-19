#define _CRT_SECURE_NO_WARNINGS
#include <stdlib.h>
#include <stdio.h>
#include <string.h>



//원형 연결 리스트
//ListNode == student
typedef struct Node
{
	int number;
	char name[20];
	int korean;
	int math;
	int english;
	
	struct Node *next;
	
}student;

int insertNode(student **ptrHead)
{
	
	int tem_number;
	char tem_name[20];
	int tem_korean;
	int tem_math;
	int tem_english;
	//scanf로 입력받기

	student *tempNode = (student *)malloc(sizeof(student));
	
	if( !tempNode )
	{
		return -1;
		
	}
	
	printf("학번 : ");
	scanf("%d", &tem_number);
	printf("이름 : ");
	scanf("%s", &tem_name);
	printf("수학 : ");
	scanf("%d", &tem_math);
	printf("국어 : ");
	scanf("%d", &tem_korean);
	printf("영어 : ");
	scanf("%d", &tem_english);
	printf("\n");
	
	
	tempNode -> number = tem_number;
	tempNode -> name == tem_name;                      /////배열에서는 == 해주어야 한다.
	tempNode -> korean = tem_korean;
	tempNode -> math = tem_math;
	tempNode -> english = tem_english;
	tempNode -> next = *ptrHead;
	*ptrHead = tempNode ;
		

	return 1;
}

int printlist(student *head)
{
	while(head)
	{
		printf("학번 : %d ", head -> number);
		printf("이름 : %s ", head -> name);
		printf("수학 : %d ", head -> math);
		printf("국어 : %d ", head -> korean);
		printf("영어 : %d ", head -> english);
		printf("\n");
		head = head -> next;
	}
	
}


//단일 연결 리스트에서 특정 값의 노드 삭제하기
void deletNode(student **ptrHead, int direction, int tem_delValue)
{
	printf("\n노드 삭제\n");
	student *currNode = *ptrHead;  // 만약 첫번째 리스트가 비어있지 않는다면 머리노드를 임시변수 currNode에 넣어준다.
	student *nextNode;  //두번째 변수
	
	
	switch(direction){
		case 1:
			currNode -> number; break;
			if(currNode && currNode -> number == tem_delValue)
			{
				*ptrHead = currNode -> next;  
				free(currNode);    
				return;             
			}
	
			
			while(currNode != NULL)  
			{
				nextNode = currNode -> next;  
				if(nextNode && nextNode -> number == tem_delValue)  
				{
					currNode -> next = nextNode -> next;  
					free(nextNode);  
					return;          
				}
				else
				{
					currNode = nextNode;  //계속해서 탐색
				}
			}
			break;
				
		case 2:
			currNode -> name; 
			if(currNode && currNode -> name == tem_delValue)
			{
				*ptrHead = currNode -> next;  
				free(currNode);    
				return;             
			}
	
			
			while(currNode != NULL)  
			{
				nextNode = currNode -> next;  
				if(nextNode && nextNode -> name == tem_delValue)  
				{
					currNode -> next = nextNode -> next;  
					free(nextNode);  
					return;          
				}
				else
				{
					currNode = nextNode;  //계속해서 탐색
				}
			}
			break;	
		
		case 3:
			currNode -> math; 
			if(currNode && currNode -> math == tem_delValue)
			{
				*ptrHead = currNode -> next;  
				free(currNode);    
				return;             
			}
	
			
			while(currNode != NULL)  
			{
				nextNode = currNode -> next;  
				if(nextNode && nextNode -> math == tem_delValue)  
				{
					currNode -> next = nextNode -> next;  
					free(nextNode);  
					return;          
				}
				else
				{
					currNode = nextNode;  //계속해서 탐색
				}
			}
				break;
				
		case 4:
			currNode -> korean; 
			if(currNode && currNode -> korean == tem_delValue)
			{
				*ptrHead = currNode -> next;  
				free(currNode);    
				return;             
			}
	
			
			while(currNode != NULL)  
			{
				nextNode = currNode -> next;  
				if(nextNode && nextNode -> korean == tem_delValue)  
				{
					currNode -> next = nextNode -> next;  
					free(nextNode);  
					return;          
				}
				else
				{
					currNode = nextNode;  //계속해서 탐색
				}
			}
			
			break;
				
		case 5:
			currNode -> english; 
			if(currNode && currNode -> english == tem_delValue)
			{
				*ptrHead = currNode -> next;  
				free(currNode);    
				return;             
			}
	
			
			while(currNode != NULL)  
			{
				nextNode = currNode -> next;  
				if(nextNode && nextNode -> english == tem_delValue)  
				{
					currNode -> next = nextNode -> next;  
					free(nextNode);  
				return;          
				}
				else
				{
					currNode = nextNode;  //계속해서 탐색
				}
			}
			break;

	}
}
	

int main(void)
{
	student *head = NULL;
	insertNode(&head);
	//printlist(head);  //이름이 왜 안뜨는지 모르겠어..
	insertNode(&head);
	insertNode(&head);
	printlist(head);
	
	deletNode(&head, 3, 5);
	printlist(head);
	
	return 0;
}
