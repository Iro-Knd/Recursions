/* Konidari Iro A.M. 2012030049
 HMMY
 Project 1
 thema 1o*/

#include <stdio.h>
#include <stdlib.h>


struct list{
            int elements;
            struct list *next;
                
                };
void printList(struct list *l);               

void freeList(struct list *node);



struct list * ikonidari(struct list *head,int elems);
struct list * ikonidari2(struct list *head,int elems);
struct list * ikonidari3(struct list *head,int elems,struct list *ptr);
int perittoi(struct list *ptr,int cur);
            
              

int main(){
   
       int size,elems,i;
       int result=0;
       struct list *head;     
       head=NULL; 
 
       printf("Give the size of your list:");
       scanf("%d", &size);
       
       
  for(i=0;i<size;i++){        
       printf("Enter the elements of your list:\n");
       scanf("%d",&elems);
       //head=ikonidari(head,elems);
       //head=ikonidari2(head,elems);
       head=ikonidari3(head,elems,head);
       }
       
    printList(head);
     
    result = perittoi(head,0);
    printf("\n result = %d \n",result); 
    
    freeList(head); 
     
     system("PAUSE");
       return 0;
}


	void printList(struct list *l){
    if(l==NULL) return;
	printf("%d ", l->elements);
	printList(l->next);
}

//eisagogi stin arxi tis listasz
struct list * ikonidari(struct list *head,int elems) { 
   struct list *node;
   node=(struct list *)malloc(sizeof(struct list));
   node->elements = elems;
   node->next = head;   
   return node;                 
     }            


//mi anadromiki sinartisi eisagogis     
struct list * ikonidari2(struct list *head,int elems) { 
   struct list *node;
   struct list *ptr;
   ptr =head;
   node=(struct list *)malloc(sizeof(struct list));
   node->elements = elems;
   node->next = NULL;
   
   if(head == NULL){
   head = node;
   return head;        
   } 
   while(ptr->next !=NULL){
      //printf("hello \n");
      ptr = ptr->next;                  
   }
   ptr->next = node;
   return head;  
   //return node;                 
     }            
//anadromiki sinartisi eisagogis
struct list * ikonidari3(struct list *head,int elems,struct list *ptr) { 
   struct list *node;


   if(head == NULL){
   node=(struct list *)malloc(sizeof(struct list));
   node->elements = elems;
   node->next = NULL;              
   head = node;
   return head;        
   }
   if(ptr->next == NULL){
   node=(struct list *)malloc(sizeof(struct list));
   node->elements = elems;
   node->next = NULL;             
   ptr->next = node;
   return head;             
   }
   return ikonidari3(head,elems,ptr->next);
}            



int perittoi(struct list *ptr,int cur) { 
     if(ptr==NULL) {
     return cur;
     }
     if((ptr->elements)%2==1){
     printf("perittoi numbers:%d\n",ptr->elements);
     cur=cur+1;}
     return perittoi(ptr->next,cur);
     
}


void freeList(struct list *node){
	struct list *p;
	if(node == NULL){
		return;
	}
	p = node;
	node = node->next;
	free(p);
	freeList(node);
}
