#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node{
        int data;
        struct node *ptr;
    };
    struct node *head=0,*newnode,*temp;
    int ch,m;
    printf("enter the choice");
    scanf("%d",&ch);
    while(ch!=0){
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("enter the element");
        scanf("%d",&newnode->data);
        newnode->ptr=0;
        if(head==0){
            temp=head=newnode;
        }
        else{
            
            temp->ptr=newnode;
            temp=newnode;
        }
        printf("enter the choice again");
        scanf("%d",&ch);
    }
    void insert_at_beg(int m){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=m;
        newnode->ptr=head;
        head=newnode;
        
    }
    printf("enter the element to be inserted at the begining");
    scanf("%d",&m);
    insert_at_beg(m);
    printf("displaying the elements");
    temp=head;
    while(temp!=0){
        printf("%d",temp->data);
        temp=temp->ptr;
    }
    return 0;
}