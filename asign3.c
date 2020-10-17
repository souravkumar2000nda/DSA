#include<stdio.h>
#include<stdlib.h>

typedef  struct node{
    int data;
    struct node *next;
}nodetype;

nodetype *insert(nodetype *rear){
    int no;
    nodetype *p=NULL;
    p=(nodetype*)malloc(sizeof(nodetype));
    if(p!=NULL){
        printf("enter value\n");
        scanf("%d",&no);
        p->data=no;
        if(rear==NULL){
            rear=p;
        }
        else{
            rear->next=p;
            rear=p;

        }
        rear->next=NULL;
    }
return rear;
}

void display(nodetype *front){

if(front==NULL)
{   return ;
}
else {

    printf("%d ",front->data);
    display(front->next);

}
}


void delete(nodetype** lt,nodetype** rt,int k){

nodetype *temp=NULL,*prev=NULL;
temp=(*lt);
int loc=1;
while(temp->data!=k&&temp->next!=NULL){
    prev=temp;
    temp=temp->next;
    loc++;

}
if(temp->next==NULL&&temp->data!=k){

    printf("key is not found\n");
}
else{

    printf("key %d found at %d \n",k,loc);
    if(temp==(*lt)){
        (*lt)=(*lt)->next;
        free(temp);
        printf("node deleted \n");
    }
    else if(temp==(*rt)){

        (*rt)=prev;
        (*rt)->next=NULL;
        free(temp);
        printf("node deleted \n");
    }
    else{

        prev->next=temp->next;
        free(temp);
        printf("node deleted \n");
    }
}
}






int main(){
int n,key;
nodetype *front=NULL ,*rear=NULL;
do{

    printf("\n1 insert 2 display 3 exit 4 delete \n");
    scanf("%d",&n);
    if(n==1){
        rear=insert(rear);
        if(front==NULL){
            front=rear;
        }
    }
    else if(n==4)
  {
    printf("enter key\n");
    scanf("%d ",&key);
    delete(&front,&rear,key);
}

   else if(n==2){
        display(front);
    }
}while(n!=3);
return 0;

}
