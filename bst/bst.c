#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	
	int data;
	struct Node* right;
	struct Node* left;

}node;

void addNode(node* front, int data){
	
	node* temp;
	temp = (node*)malloc(sizeof(node));
	temp->data = data;
	temp->left = NULL;
	temp->right = NULL;

	node* ptr;
	ptr = (node*)malloc(sizeof(node));
	
	ptr = front;
	
	
//======INSERTING NODE====================================	
	
	if(front->data == -1){
		front->data = data;
		printf("inserted\n");
		return;
	}
	
	while(1){
		if(data == ptr->data){
			printf("duplicate\n");
			return;
		}

		if(data > ptr->data){
			if(ptr->right == NULL){
				ptr->right = temp;
				printf("inserted\n");
				return;
			}
			ptr = ptr->right;
		}

		else if(data < ptr->data){
			if(ptr->left == NULL){
				ptr->left = temp;
				printf("inserted\n");
				return;
			}
			ptr = ptr->left;
		}
		
	}
	
}

int searchNode(node* front, int data){
	if(front == NULL){
		return 0;
	}

	node* ptr = (node*)malloc(sizeof(node));
	ptr = front;	
//======SEARCHING TREE==================================
	while(ptr != NULL){
		if(data == ptr->data){
			return 1;
		}
		if(data > ptr->data){
			ptr = ptr->right;
		}
		else if(data < ptr->data){
			ptr = ptr->left;
		}
	}
	return 0;
	
}


void printNodes(node* front){
	if(front->data == -1){
		return;
	}	
	node* ptr = front;
	printf("(");
	if(ptr->left == NULL && ptr->right == NULL){
		printf("%d)", ptr->data);
		return;
	}
	if(ptr->left != NULL){
		printNodes(ptr->left);
	}
	printf("%d", ptr->data);
	if(ptr->right != NULL){
		printNodes(ptr->right);
	}
	printf(")");
	return;
}

node* findNode(node* front, int data){
	node* ptr = front;
	node* prev = NULL;
	while(ptr != NULL){
		if(ptr->data == data){
			return prev;
		}
		prev = ptr;
		if(data > ptr->data){
			ptr = ptr->right;
		}
		else if(data < ptr->data){
			ptr = ptr->left;
		}
		
		
	}
	node* notFound = (node*)malloc(sizeof(node));
	notFound-> data = -1;
	notFound->right = NULL;
	notFound->left = NULL;
	
	return notFound;
}


void recDelete(node* p, node* prv){
	
	node* ptr = p;
	node* prev = prv;
	int temp;
	
	//case 1: no children
	if(ptr->right == NULL && ptr->left == NULL){
		if(prev->left == ptr){
			prev->left = NULL;
		}
		else{
			prev->right = NULL;
		}
		return;
	}
	
	//case 2: 1 child
	if(ptr->right!= NULL && ptr->left ==NULL){
		temp = ptr->data;
		ptr->data = ptr->right->data;
		ptr->right->data = temp;

		recDelete(ptr->right, ptr);
		return; 
	}
	else if(ptr->right == NULL && ptr->left != NULL){
		temp = ptr->data;
		ptr->data = ptr->left->data;
		ptr->left->data = temp;

		recDelete(ptr->left, ptr);
		return;
	}
	
	//case 3: 2 children
	else{
		node* ptr2 = ptr->left;
		prev = ptr;
		while(ptr2->right != NULL){
			prev = ptr2;
			ptr2 = ptr2->right;
		}
		temp = ptr->data;
		ptr->data = ptr2->data;
		ptr2->data =temp;
		recDelete(ptr2, prev);
		return;
	}
}

void deleteNode(node* front, int data){
	node* ptr;
	node* prev;
	prev = findNode(front, data);
	
	if(prev == NULL){
		
		ptr = front;
		
	}
	else if(prev->data == -1){
		printf("absent\n");
		return;
	}
	else if(data < prev->data){
		ptr = prev->left;
	}
	else{
		ptr = prev->right;
	}
	
	
	recDelete(ptr, prev);
	printf("deleted\n");			
	return;
}	


int main(){

	node* front = (node*)malloc(sizeof(node));
	front->data = -1;
	front->right = NULL;
	front->left = NULL;
	char c;
	int data;	
	while(1){
		scanf(" %c", &c);
		if(c == '#'){
			break;
		}
//==============INSERT NODE================================		
		if(c == 'i'){
			scanf(" %d", &data);
			addNode(front, data);
		}
	
//==============SEARCH NODE================================
		else if(c == 's'){
			scanf(" %d", &data);
			int found = searchNode(front, data);
			if(found == 0){
				printf("absent\n");
			}
			else if(found == 1){
				printf("present\n");
			}
		}

//==============PRINT NODE=================================
		else if(c == 'p'){
			printNodes(front);
			printf("\n");
		}

//==============DELETE NODE===============================
		else if(c== 'd'){
			scanf(" %d", &data);
			if(data == front->data){
				if(front->right == NULL && front->left == NULL){
					front->data = -1;
					printf("deleted\n");
				}
			
				else{
					deleteNode(front, data);
				}
			}
			else{
				deleteNode(front, data);
			}
		}
		
//==============EXIT PROGRAM==============================

		else{
			break;
		}
		c = '#';
	}


	return 0;


}
