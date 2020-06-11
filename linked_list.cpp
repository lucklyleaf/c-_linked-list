#include<iostream>
using namespace std;
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>

typedef struct STU {
	int data;
	struct STU* next;
}STU;

// Define the pointer of linked list 1 and 2
STU* pStu1 = NULL;
STU* pStu2 = NULL;

// Create the head nodes of linked list 1 and 2
void head(){
	pStu1 = (STU*)malloc(sizeof(STU));
	pStu2 = (STU*)malloc(sizeof(STU));
	
	pStu1->next = NULL;
	pStu2->next = NULL;
}


void AddNode(STU* p1, STU* p2){
	STU* pnew1 = NULL;
	STU* pnew2 = NULL;
	printf("Input 0 push out cycle\n");
	// input linked list 1
	while(true){
		pnew1 = (STU*)malloc(sizeof(STU));
		printf("please input linked1:");
		scanf("%d", &pnew1->data);
		if(pnew1->data == 0){
			break ;
		}
		pnew1->next = NULL;
		p1->next = pnew1;
		p1 = p1->next;
	}
	// input linked list 2
	while(true){		
		pnew2 = (STU*)malloc(sizeof(STU));			
		printf("please input linked2:");
		scanf("%d", &pnew2->data);	
		if(pnew2->data == 0){
			break ;
		}
		pnew2->next = NULL;
		p2->next = pnew2;
		p2 = p2->next;
	}

}

// print linked list 1 and 2
void Print()
{
	STU* P1 = pStu1->next;
	STU* P2 = pStu2->next;
	printf("linked1:");
	while(P1 != NULL)
	{
		printf("%d\t",P1->data);
		P1 = P1->next;
	}
	printf("\n");
	printf("linked2:");
	while(P2 != NULL)
	{
		printf("%d\t",P2->data);
		P2 = P2->next;
	}
	printf("\n");
}


void merge(STU* p1, STU* p2)
{
	// Let the pointer of linked list 1 stay at the last node
	while(p1->next != NULL)
	{
		p1 = p1->next;
	}
	/*
		Delete the head node of linked list 2, and then merge linked list 1 and linked list 2
    */
	STU* m = p2->next;
	free(p2);
	p1->next = m;
}


int len = 0;
void linked1_print(int k){
	//  Print combined linked list 1
	STU* L1 = pStu1->next;
	if(k == 1){
		cout<<"Linked list 1 and 2 before sorting:"<<endl;
	}else{
		cout<<"After sorting linked list 1 and 2:"<<endl;
	}
	
	while(L1 != NULL)
	{
		len++;
		printf("%d\t",L1->data);
		L1 = L1->next;
	}
	printf("\n");
}
    
//  Use bubble sort
void sort(STU*	p)
{	
	printf("%d\n", len);
	
	STU* n = p->next;
	int i,j,tmp;
	for(i = 0;i<len-1; i++)
	{
		p = n;	
		for(j = 0;j<len-i-1;j++){
			if(p->data > p->next->data)
			{
				tmp = p->data;
				p->data = p->next->data;
				p->next->data = tmp;
			}
			p = p->next;
		}
	}
}


int main(){

	head();
    
	AddNode(pStu1,pStu2);

	Print();

	merge(pStu1,pStu2);

	linked1_print(1);

	sort(pStu1);
	
	linked1_print(2);

	getchar();

	return 0;
}