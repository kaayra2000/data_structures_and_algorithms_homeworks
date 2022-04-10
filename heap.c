#include <stdio.h>
#include <stdlib.h>
int * maxHeap(int * a, int i, int n){
	int l,r,largest;
	l=2*i+1;
	r=2*i+2;
	if(l<n && a[l]>a[i]){
		largest=l;	
	}
	else
		largest=i;
	if(r<n && a[r]>a[largest])
		largest=r;
	if(largest!=i){
		a[i]=a[largest]+a[i];
		a[largest]=a[i]-a[largest];
		a[i]=a[i]-a[largest];
		a=maxHeap(a,largest,n);
	}
	return a;
}
int * updateElement(int * a,int n,int i, int key){
	int parent;
	if(i>=0 && a[i]!=key){
		a[i]=key;
		if(a[i]>key)
			a=maxHeap(a,i,n);
		else{
			parent=(i-1)/2;
			while(i>=0 && a[i]>a[parent]){
				a[i]+=a[parent];
				a[parent]=a[i]-a[parent];
				a[i]=a[i]-a[parent];
				i=parent;
				parent=(i-1)/2;
			}
	}
}
	printf("Succesful!!!\n");
	return a;
}
int * addElement(int * a, int * n){
	(*n)++;
	int key,i;
	printf("Please enter number for add\n");
	scanf("%d",&key);
	a[(*n)-1]=key-1;
	return updateElement(a,*n,(*n)-1,key);
}
int * enterElements(int * n){
	int * a,i;
	printf("Please enter n\n");
	scanf("%d",n);
	a=(int *)malloc(sizeof(int)*(*n));
	for(i=0;i<(*n);i++){
		printf("Please enter a %d. element\n",i+1);
		scanf("%d",&a[i]);
	}	
	return a;
}
int menu(){
	int n;
	printf("What do you want?\nFor enter elements ->1\nFor deletion ->2\nFor construct or reconstruct ->3\nFor print array ->4\nFor update element ->5\nFor add element -> 6\nFor exit ->7\n");
	scanf("%d",&n);
	return n;
}
void printArray(int * a,int n){
	int i;
	for(i=0;i<n;i++){
		printf("%d -> %d \n",i,a[i]);	
	}
}
int * deleteElement(int * a,int * n){
	a[0]=a[(*n)-1];
	(*n)--;
	a=maxHeap(a,0,*n);
}

int main (){
	int n=0,*a,i,choice,index,key;
	a=NULL;
	do{
		choice=menu();
		switch(choice){
			case 1:
				a=enterElements(&n);
				break;
			case 2:
				if(n>0){
				printf("Deleted number -> %d\n",a[0]);
				a=deleteElement(a,&n);}
				else
					printf("No entries yet\n");
				break;
			case 3:
				if(n>0){
					for(i=n/2-1;i>=0;i--){
					a=maxHeap(a,i,n);
				}}
				else
					printf("No entries yet\n");
				break;
			case 4:
				if(n>0){
					printArray(a,n);}
				else
					printf("No entries yet\n");
				break;
			case 5:
				if(n>0){
						printf("Please enter a uptade index\n");
						scanf("%d",&index);
						printf("It is -> %d\n",a[index]);
						printf("Please enter number to update\n");
						scanf("%d",&key);
						a=updateElement(a,n,index,key);
				}
					
					
				else
					printf("No entries yet\n");
				break;
			case 6:
				if(n<=0)
					n=0;
				if(a==NULL){
					a=(int*)malloc(sizeof(int));
				}
				else
					a=realloc(a,n+1);
				a=addElement(a,&n);
				break;
			case 7:
				printf("Exiting\n");
				break;
			default:
				printf("Please enter normal number !!!!\n");			
		}
		
	}while(choice!=7);
	return 0;
}