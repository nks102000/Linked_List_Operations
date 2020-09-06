//1905622 - NITISH KUMAR SONTHALIA
//Linked list
#include<stdio.h>
#include <stdlib.h>

void creat_list(struct node ** ,int n);
void display_list(struct node ** );
void insert_at_position_n(struct node ** ,int n,int p);
void deleteNode(struct node **, int p);
void sort(struct node ** );
void rev(struct node **);

struct node
{
    int data;
    struct node *next;
};



int main(){
    struct node *start = NULL;
    int t;
    bool f=true;
    while(f){
    printf("\n MENU ");
    printf("\n 1. Enter An Element ");
    printf("\n 2. Display The List ");
    printf("\n 3. Insert At Position ");
    printf("\n 4. Deletion of Elements ");
    printf("\n 5. Sort the list ");
    printf("\n 6. Reverse the list ");
    printf("\n 7. EXIT ");
    scanf("%d",&t);
    switch (t)
    {
    case 1:
        int e;
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e);
        creat_list(&start,e);
        break;
    case 2:
        display_list(&start);
        break;
    case 3:
        int e1,p;
        printf("\n Enter The Element To Be Entered: ");
        scanf("%d",&e1);
        printf("\n Enter The Element position: ");
        scanf("%d",&p);
        insert_at_position_n(&start,e1,p);
        break;
    case 4:
        int p1;
        printf("\n Enter The Element position: ");
        scanf("%d",&p1);
        deleteNode(&start,p1);
        break;
    case 5:
        sort(&start);
        break;
    case 6:
        rev(&start);
        break;
    case 7:
        f=false;
        break;
    default:
        break;
    }
    }
}

void creat_list(struct node **st ,int n){
    struct node *temp;
    struct node *new1 = (struct node *)malloc(sizeof(struct node *));
    new1->data=n;
    new1->next=NULL;
    if(*st==NULL){
        *st=new1;
    }
    else{
        temp=*st;
        while(temp->next!=NULL){
            temp= temp->next;
        }
        temp->next = new1;
    }
}

void display_list(struct node **st){
    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }
    struct node*temp=*st;
        printf("Elements in LIST are:");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->next;
    }
}

void insert_at_position_n(struct node **st ,int n,int p){
    if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }
    struct node *ptr = (struct node*)malloc(sizeof(struct node));
    ptr->data=n;	
    int i;
    struct node *temp=*st;
    printf("\n Enter 1 for entering before the given position and 2 for entering after given position");
    int e;
    scanf("%d",&e);
    if(e==1){
    if(p==1)
    {
        ptr->next=*st;
        *st=ptr;
    }
    else{
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    }
    }
    if(e==2){
        p=p+1;
   	for(i=1;i<p-1;i++){
    	temp=temp->next;
    }
    ptr->next=temp->next;
    temp->next=ptr;
    }
    display_list(st);
}
void deleteNode(struct node **st, int p) 
{
   if (*st == NULL){ 
      printf("\n Empty List"); 
      return ;
    }
    printf("\n Enter 1 for deleting the given position and 2 for deletion before given position and 3 for deletion after given position");
    int e;
    scanf("%d",&e);
   struct node* temp = *st; 
    if(e=1){
    if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }
    }
    else if(e=2){
        p=p-1;
        if(p=0){
            return;
        }
     if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }   
    }
    else if(e=3){
        p=p+1;
     if (p == 1) 
    { 
        *st = temp->next;    
        free(temp);         
        return; 
    } 
    else{
    for (int i=1; temp!=NULL && i<p-1; i++) 
         temp = temp->next; 
   
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    struct node *next = temp->next->next; 
  
    free(temp->next); 
  
    temp->next = next; 
    }   
    }
    display_list(st);
}
void sort(struct node **st ){

    struct node *t1=*st;

    struct node *t2;

    int k;

    while (t1!=NULL)
    {
        for(t2=t1->next;t2!=NULL;t2=t2->next){
            if(t1->data>t2->data){
                k=t1->data;
                t1->data = t2->data;
                t2->data=k;
            }
        }
        t1=t1->next;
    }
    display_list(st); 
}
void rev(struct node **st){
    struct node *t2,*t1,*p;
    p=NULL;
    t1=*st;
    while(t1!=NULL){
        t2=t1->next;
        t1->next=p;
        p=t1;
        t1=t2;
    }
    *st=p;
    display_list(st);
}