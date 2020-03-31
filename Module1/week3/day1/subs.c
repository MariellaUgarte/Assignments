#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <ctype.h>
#include <stdlib.h>
 
 int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}

 int main(int argc, string argv []){
     /* Get Key*/
     string input;
     char arr[26];
     string plain_text;
     int i, k, j;
     input=(argv[1]);
     /*Validate Key*/
     if (argc !=2){
         printf("Usage: ./substitution key \n");
         return 1;
     }
     for(int i=0; i < 26 ; i++){
         arr[i]=tolower(input[i]);
         if (arr[i]<'a'|| arr[i]>'z'){
             printf("Key must contain alphabet characteres\n");
             return 1;
         }
         
     
     }
     qsort(arr, 26, sizeof(char), cmpfunc);
     for (int i=0; i < 25; i++){
         if (arr[i]==arr[i+1]){
          printf("Key must have different characters\n");
             return 1;
         }
     }


    
     plain_text=get_string("plaintext: ");
     
        

     string alphabet_uppercase="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

     string alphabet_lowercase="abcdefghijklmnopqrstuvwxyz";

     for ( j =0; j < strlen(plain_text); j++ ){
         for ( k=0; k < 26; k++){
             if (plain_text[j] == alphabet_uppercase[k]){
                  plain_text[j]= toupper(input[k]);
                  break;
                  
                 
             }
             else if (plain_text[j]== alphabet_lowercase[k]){
                 plain_text[j] = tolower(input[k]);
                 break;

             }
             
            
             
         }
     }
      printf("ciphertext: %s\n", plain_text);

   

    

    return 0;

 }
