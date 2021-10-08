#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list{
    int data;
    struct linked_list *nxt;
}QUEUE;

void initialisation(QUEUE **aatop){
    *aatop = NULL;
}

int is_empty(QUEUE *aa_top)
{
    return (aa_top==NULL); 
} 

void insert(QUEUE **aatop,int val){
    QUEUE *new =(QUEUE *)malloc(sizeof(QUEUE));
    new->data = val;
    new->nxt = NULL;
    QUEUE *temp = *aatop;
    if(*aatop==NULL){
        *aatop=new;
        return;
    }
    while(temp->nxt!=NULL)
        temp=temp->nxt;
    temp->nxt=new;
    return;
}

int del(QUEUE **aatop)
{
    int n;
    QUEUE *temp;
    if(is_empty(*aatop))
        printf("\nEmpty Queue\n");
    else{
        temp=*aatop;
        n=temp->data;
        *aatop=temp->nxt;
        free(temp);
        printf("\nThe deleted no. is %d\n",n);
        return(n);
    }
}

int display(QUEUE **aatop){
    int n;
    printf("\nThe elements of the queues are:\n");
    QUEUE *temp = *aatop;
    while(temp!=NULL){
        n=temp->data;
        printf(" %d ",n);
        temp=temp->nxt;
    }
    printf("\n");
}

void main(){
    QUEUE *q=NULL;
    int n=1,p;
    initialisation (&q);
    while(1)
    {
        printf("\nPress the number: \n1 for inserting,\n2 for deleting,\n3 for displaying,\n0 for exit:  ");
        scanf("%d",&n);
        if(n==0){
            printf("\nThank You");
            exit(1);
        }

        if (n==1){
            printf("\nEnter the no. to be inserted: ");
            scanf("%d",&p);
            insert(&q,p);
            printf("Inserted Succesfully\n");
        }
        else if (n==2)
            del(&q);
        else if (n==3)
            display(&q);
        else
            printf("\nERROR: Wrong Input\n");
    }
}