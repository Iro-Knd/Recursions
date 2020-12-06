/* 
Konidari Iro
 HMMY
 thema 3o*/

#include <stdio.h>
#include <stdlib.h>

struct list{
  int elems;
  struct list *next;
        
};
void printList(struct list *l);  
void freeList(struct list *node);
struct list * ikonidari3(struct list *head,int elems,struct list *ptr); 
struct list * pythagoreio(struct list *ptr, int elems);
           
int main(){
   
       int size,elems,i,cur;
       struct list *head;     
       struct list *result; //pointer sthn lista mou gia na deixnei ton prwto komvo
       result=NULL; //gia na eimaste sigoyroi oti einai o swstos
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
    result =pythagoreio(head,size);
    if(result!=NULL){
     printf("\nResult= %d \n",result->elems);        
    }else {
     printf("\nDEN IPARXEIS!!! \n");
    }
   	freeList(head);
     system("PAUSE");
       return 0;
}
	void printList(struct list *l){
    if(l==NULL) return;
	printf("%d ", l->elems);
	printList(l->next);
}
//eisagogi stin arxi tis listas
struct list * ikonidari(struct list *head,int elems) { 
   struct list *node;
   node=(struct list *)malloc(sizeof(struct list));
   node->elems = elems;
   node->next = head;   
   return node;                 
     }            
     //anadromiki sinartisi eisagogis
struct list * ikonidari3(struct list *head,int elems,struct list *ptr) { 
   struct list *node;


   if(head == NULL){
   node=(struct list *)malloc(sizeof(struct list));
   node->elems = elems;
   node->next = NULL;              
   head = node;
   return head;        
   }
   if(ptr->next == NULL){
   node=(struct list *)malloc(sizeof(struct list));
   node->elems = elems;
   node->next = NULL;             
   ptr->next = node;
   return head;             
   }
   return ikonidari3(head,elems,ptr->next);
}  
// pythagoreio
  struct list * pythagoreio(struct list *ptr,int elems){
     int a, b, c;
     if(elems<3){
       printf("\nPythagoreio doesn't exist for less than three elements\n");
          return NULL;     
     }    
     if(((ptr->next)->next) ==NULL){
      printf("We reached the end");     //den yparxei triada        
      return NULL;  
      }      
      
   
     a=ptr->elems;
     b=(ptr->next)->elems;
     c=((ptr->next)->next)->elems;

     if(a*a==b*b+c*c){
     printf("Beautiful! The three numbers which have found are:\n %d %d %d\n",a,b,c);
     return ptr;
     }
     return pythagoreio(ptr->next,elems); //kalw 3ana thn pythagoreio anadromika gia na paei ston next node!
}
void freeList(struct list *node){ //eleu8erwnei thn lista!
	struct list *p;
	if(node == NULL){
		return;
	}
	p = node;
	node = node->next;
	free(p);
	freeList(node);
}
