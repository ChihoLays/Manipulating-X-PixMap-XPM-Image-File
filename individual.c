#include <stdio.h>
#include <string.h>

int main(){

    char filelocation[100];
    char info[100];
    
    printf("Enter XPM file location: ");
    scanf("%s",filelocation);

    //file pointer variable
      FILE *original;
      FILE *manipulated;

      //point pointer variable to file
      original = fopen(filelocation,"r");
      manipulated = fopen("C:\\Users\\User\\Desktop\\results.xpm","w");

      while(!feof(original)){
          fscanf(original,"%[^\n] ",info);

          char* token = strtok(info, "#");

          while(token!=NULL)
          {
            
            if(strcmp(token,"FFFFFF")==0)
            {
              fprintf(manipulated,"#FF0000");
            }
            else if(strcmp(token,"000000")==0)
            {
              fprintf(manipulated,"#71c95b");
            }
            else{
              fprintf(manipulated,"%s",token);
            }

            token = strtok(NULL, "#");

        }

        fprintf(manipulated,"\n");

      }

      //close file
      fclose(original);
      fclose(manipulated);
      
      return 0;
}
