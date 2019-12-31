#include <stdio.h>
#include <stdlib.h>

typedef struct Node{

	int data;
	struct Node *next;

}node;

void insert(int data, node* front){
	node* ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr = front;

	node* ins;
	ins = (node*)malloc(sizeof(node));
	ins->data = data;
	ins->next = NULL;
	
	if(front->data == -1){
		front->data = data;
		return;
	}
	else if(ins->data < front->data){
		//printf("========\n");
		
		ins->next =  ptr->next;
		ptr->next = ins;

		int t = ins->data;
		ins->data = ptr->data;
		ptr->data = t;

		return;
	}

	while(ptr!=NULL){
		if(ptr->data == data){
			return;
		}
		if(ptr->next==NULL){
			ptr->next = ins;
			return;
		}
		if(ptr->next->data > ins->data){
			ins->next = ptr->next;
			ptr->next = ins;
			return;
		}
		ptr = ptr->next;
	}		
	
} 

void delete(int data, node* front){
	node* ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr = front;

	node* ptr2;
	ptr2 = (node*)malloc(sizeof(node));
	
	if(front == NULL){
		return;
	}
		
	ptr2 = front;
	ptr = front->next;
	
	if(front->data == data){
		if(front->next == NULL){
			front->data = -1;
			return;
		}
		int t = ptr2->data;
		ptr2->data = ptr->data;
		ptr->data = t;
	}
	
	while(ptr!= NULL){
		if(ptr->data == data){
			ptr2->next = ptr->next;
			return;
		}
		ptr2 = ptr;
		ptr = ptr->next;
	}
	return;
}

void print(node* front){
	node* ptr;
	ptr = (node*)malloc(sizeof(node));
	ptr = front;
	
	int count = 0;
	if(front->data == -1){
		printf("0 :");
		printf("\n");
		return;
	}	

	while(ptr!= NULL){
		count = count + 1;
		ptr = ptr->next;
	}
	
	printf("%d : ", count);
	
	if(count > 0){

		ptr = front;
		while(ptr!= NULL){
			printf("%d", ptr->data);
			
			if(ptr->next != NULL){
				printf(" ");
			}
			ptr = ptr->next;
		}
	}
	printf("\n");
	return;
}

int main(){

	
	node* front = NULL;

	front = (node*)malloc(sizeof(node));	
	front->data = -1;

	int data;
	char c;
	int i = 0;
	while(1){

		if(scanf(" %c", &c) == '\0'){
			break;
		}

		if(c == 'i'){
			scanf(" %d", &data);
			if(data == -207){
				break;
			}
			insert(data, front);
		}
	
		else if(c == 'd'){
			scanf(" %d", &data);
			if(data == -207){
				break;
			}
			delete(data, front);	
		}
		else{
			return 0;
		}
		print(front);
		i++;
		data = -207;
	}
	return 0;
	
	
}
