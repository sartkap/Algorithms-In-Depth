#include<stdio.h>
#include<stdlib.h>

int N = 1e5 + 1;

typedef struct node{
	char *times;
	double priority;
	int id;
	node *next;
}node;


//function to create a new member of a linked list
node* createNode(char *times, double priority, int id){
	node *temp;
	temp = (node *)malloc(sizeof(node));
	temp->times = times;
	temp->id = id;
	temp->priority = priority;
	temp->next = NULL;

	return temp;
}

//function to merge to sorted linked lists
node* merge(node* a, node* b){
	node* result = NULL;

	//base cases 
	if(a==NULL){
		return b;
	}
	else if(b==NULL){
		return a;
	}

	//recursively call merge() to iterate the linked lists
	if(a->priority <= b->priority){
		result = a;
		result->next = merge(a->next,b);
	}
	else{
		result = b;
		result->next = merge(a,b->next);
	}

	return result;
}

//function to split an unsorted linked list into two equal (in case of odd length differing by 1 in length) parts  
void splitLinkedList(node* head, node** listBackPointer){

	//two pointers to help divide list into two parts
	node* ahead;
	node* behind;
	ahead = head->next;
	behind = head;

	//ahead moves two steps at a time while behind moves one
	//efectively when ahead points to null behind will point 
	//the middle of the list
	while(ahead != NULL){
		ahead = ahead->next;
		if(ahead != NULL){
			ahead = ahead->next;
			behind = behind->next;
		}
	}


	*listBackPointer = behind->next;

	//break the link between two parts of list
	behind->next = NULL;
}

//function to carry out the sort using divide and conquer
void mergeSort(node **headPointer){
	node *head = *headPointer;
	node *a = head;
	node *b;
	
	//base cases
	if(head == NULL || head->next == NULL){
		return;
	}
	

	//splitLinkedList() splits the linked list into two parts and stores a 
	//pointer the beginning of second part in the variable b 
	splitLinkedList(head, &b);

	//recursively call mergeSort to 
	//merge the two new linked lists
	//obtained after split
	mergeSort(&a);
	mergeSort(&b);

	//merge the two linked lists into one  
	*headPointer = merge(a,b);

}



int main(){
	node *head[N];
	
	//curr is a pointer to the back of the linked list maintained during scanning so that list may be scanned in O(n) time.
	node *curr[N];

	for(int i=0;i<N;i++){
		head[i] = NULL;
		curr[i] = NULL;
	}

	
	int maxSizeOfString = 15;
	int id;
	double priority;
	char *times;

	times = (char *)malloc(maxSizeOfString*sizeof(char));

	//head = (node *)malloc(sizeof(node));

	for(int i=0;i<N;i++){
		head[i] = (node *)malloc(sizeof(node));
	}
	
	//visited boolean array keeps count of which ids have been visited and which are empty
	bool visited[N]={false};

	//dealing with input
	while(1){
		if(scanf("%d",&id)!=1){
			break;
		}

		scanf("%s",times);
		scanf("%lf",&priority);
		
		//if id is not visited till now, change the corresponding head
		if(visited[id] == false){
			head[id]->id = id;
			head[id]->times = times;
			head[id]->priority = priority;
			curr[id] = head[id];
			visited[id]=true;
		}
		//else just expand the list
		else{
			node *temp = createNode(times, priority, id);
			curr[id]->next = temp;
			curr[id] = curr[id]->next;				
		}
		
	}

	for(int i=1;i<N;i++){

		//if id is not visited, no need to print anything.
		if(visited[i] == false){
			continue;
		}

		printf("\n");

		//sorting the ith linked list.
		mergeSort(&head[i]);


		node *p = head[i];
		printf("%d ",i);

		//printing the final sorted priorities.
		while(p != NULL){
			printf("%lf ",p->priority);
			p = p->next;
		}

		
	}
	
	return 0;
}
