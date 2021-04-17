#include<stdio.h>
#include<stdlib.h>
int main(){
    struct node{
        int data;
        struct node *ptr;
    };
    struct node *head=0,*newnode,*temp;
    int ch,m,n,pos,key,choice;
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
            temp=temp->ptr;
        }
        prevnode->ptr=0;
        free(temp);
    }
    void deletion_at_pos(int pos){
        int i=1;
        struct node *nextnode;
        if(pos==0){
            delete_at_beg();
        }
        else{
            while(i<pos-1){
                temp=temp->ptr;
            }
            nextnode=temp->ptr;
            temp->ptr=nextnode->ptr;
            free(nextnode);
        }
    }
    while(1){
        printf("1 :insertion");
        printf("2 :deletion");
        printf("3 :display");
        scanf("%d",&choice);
        break;
    }
    switch(choice){
        case 1 :printf("1 :insertion at begining");
                printf("2 :insertion at the end");
                printf("3 :insertion at position");
                scanf("%d",&choice);
                switch(choice){
                    case 1  :printf("enter the element to be inserted at the begining");
                            scanf("%d",&m);
                            insert_at_beg(m);
                            break;
                    case 2 :printf("enter the element you wish to insert at the end");
                            scanf("%d",&n);
                            insert_at_end(n);
                            break;
                    case 3 :printf("enter the pos of element to be inserted");
                            scanf("%d",&pos);
                            printf("enter the key to be inserted at the given position");
                            scanf("%d",&key);
                            insert_at_pos(pos,key);
                            break;
                }
                break;
        case 2 :printf("1 :deletion at begining");
                printf("2 :deleion at end");
                printf("3 :deletion at a peculiar position");
                scanf("%d",&choice);
                switch(choice){
                    case 1 :delete_at_beg();
                            break;
                    case 2 :delete_at_end();
                            break;
                    case 3 :deletion_at_pos(2);
                            break;
                }
                break;
        case 3 :printf("displaying the elements");
                temp=head;
                while(temp!=0){
                printf("%d",temp->data);
                temp=temp->ptr;
                }  
                break;    
    }
    
    
   

  
    
   
    return 0;
}