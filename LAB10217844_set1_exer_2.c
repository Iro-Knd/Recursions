/* Konidari Iro A.M. 2012030049
 HMMY
 Project 1
 thema 2o*/

#include <stdio.h>
#include <stdlib.h>

int synarthsh_katoptrikwn_zeugwn(int *A,int i,int j);

int main () {
    
    int size,k,nums,answer;
    int result=0;
    printf("Give the size of your board:\n");
    scanf("%d",&size);
      
    int *A;   //A=Pinakas
    A=(int*)malloc(size *sizeof(int));
    for(k=0;k<size;k++) {
      printf("Enter the numbers of your board:\n"); 
           
      do{
      scanf("%d",&nums);
      A[k]=nums; //apo8hkeuw ta stoixeia se pinaka
      if(nums<0){
         printf("Only Positive Numbers. Zero accepted. Try again!\n");          
       }
      }while(nums<0);
     }
     printf("********************\n"); 
     for(k=0;k<size;k++) {
      printf("%d \t",A[k]); 
     }     
     printf("\n********************\n"); 
       
     result = synarthsh_katoptrikwn_zeugwn(A,0,size-1);
     if(result == 1){
        printf("Definately Board is specular!!!\n");       
     }else{
        printf("Definately Board is not specular!!!\n");   
     } 
     free(A);
     
  system("PAUSE");   
  return 0;   
     }

 int synarthsh_katoptrikwn_zeugwn(int *A,int i,int j) {
     if(i>=j){
        printf("Board is specular!!!\n"); //specular=katoptrikos, tou lew na stamathsei 
       return 1;
        }
     if(i+1==j-1){
        printf("Board is specular!!!\n"); //elegxw thn periptwsh na einai perittos o pinakas
       return 1;
        }   
    
       
     if( A[i]+A[j]==A[i+1]+A[j-1]){
       return synarthsh_katoptrikwn_zeugwn(A,i+1,j-1); 
     }
     else {
      printf("Board is not specular!!!\n");    
      return -1;       
     }
}
