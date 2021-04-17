#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node{
        int data;
        struct node *ptr;
    };
    struct node *head=0,*newnode,*temp;
    int ch,m,n,pos,key;
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
    void insert_at_end(int n){
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=n;
        newnode->ptr=0;
        temp=head;
        while(temp->ptr!=0){
            temp=temp->ptr;
        }
        temp->ptr=newnode;
    }
    void insert_at_pos(int pos,int key){
        newnode=(struct node*)malloc(sizeof(struct node));
        temp=head;
        int i=1;
        if(pos==1){
            insert_at_beg(key);
        }
        else{
            newnode->data=key;
            while(i<pos-1){
                temp=temp->ptr;
            }
            newnode->ptr=temp->ptr;
            temp->ptr=newnode;
        }
    }
    void delete_at_beg(){
        temp=head;
        head=head->ptr;
        free(temp);
    }
    void delete_at_end(){
        struct node *prevnode;
        while(temp->ptr!=0){
            prevnode=temp;
            temp=temo->ptr;
        }
        prevnode->ptr=0;
        free(temp);
    }

    printf("enter the element to be inserted at the begining");
    scanf("%d",&m);
    insert_at_beg(m);
    printf("enter the element you wish to insert at the end");
    scanf("%d",&n);
    insert_at_end(n);
    printf("enter the pos of element to be inserted");
    scanf("%d",&pos);
    printf("enter the key to be inserted at the given position");
    scanf("%d",&key);
    insert_at_pos(pos,key);
    delete_at_beg();
    delete_at_end();
    printf("displaying the elements");
    temp=head;
    while(temp!=0){
        printf("%d",temp->data);
        temp=temp->ptr;
    }
    return 0;
}