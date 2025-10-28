

#include<stdio.h>
#include<stdbool.h>

#define N 10
int i;
int call_history[N];
int top = -1;
bool isEmpty(){
	if(top == -1){
		return true;
	}
	else{
		return false;
	}
}
bool isFull(){
	if(top >= (N-1)){
		return true;
	}
	else{
		return false;
	}
}
void deleteHalf(){
	int half = (top+1)/2;
	
	printf("\nCall history full - deleting oldest %d entries...\n", half);
	
	for(i = 0; i<=top-half;i++){
		
		call_history[i] = call_history[i+half];
	}
	top = top + half;
}
void push(int n){
	if(!isFull()){
		deleteHalf();
	}
	call_history[++top] =  n;
}
int pop(){
	if(!isEmpty()){
		return call_history[top--];
	}
	else{
		printf("Call history is empty!\n");
		return -1;
	}
}
int main(){
	int calls[] = {2312,1232144,5667,4354,8,89,777,899,57756,54644,334345,24};
	int n = sizeof(calls) / sizeof(calls[0]);
	
	for(i=0; i<n; i++){
		push(calls[i]);
	}
	printf("\nCurrent Call History: \n");
	for(i = 0; i<=top; i++){
		printf("%d\t", call_history[i]);
	}
	getchar();
}
