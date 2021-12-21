#include <stdio.h>
#include <string.h>
//  C:\Users\User\Desktop\test_1.xpm
int main()
{
    int userin;
    char filelocation[100];
    char info[100];

    printf("Enter XPM file location: ");
    scanf("%s",&filelocation);

    printf("1.Change color 2.Divide in half: Please select function");
    scanf("%d",&userin);

    while (userin>=3 || userin <=0)
        {
            printf("Enter 1 or 2: ");
            scanf("%d",&userin);
        }

    FILE *original;
    FILE *manipulated;
    
    original = fopen(filelocation,"r");
    manipulated = fopen("C:\\Users\\User\\Desktop\\results.xpm","w");

    if (userin ==1)
    {
        while(!feof(original))
            {
                fscanf(original,"%[^\n] ",info);

                char *token = strtok(info, "#");

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
                    // else if (strcmp(token,"00ffdd ")==0)
                    // {
                    // fprintf(manipulated,"#%s",token);
                    
                    else{
                    fprintf(manipulated,"%s",token);
                    }

                    token = strtok(NULL, "#");

                }
                fprintf(manipulated,"\n");
            }   
        
    }

    else if (userin ==2)
    {
        int holder = 0;
        char x;
        int data[4];

        int count=0;
        while((x = fgetc(original)) != EOF)
        {
        if (holder >= 4)
            {
                if(count<=24)
                {
                fprintf(manipulated,"%c",x);
                count++;
                }
                if (x == '\n')
                {
                    fprintf(manipulated,"%c",x);
                    count = 0;
                }
            }
        else 
            fprintf(manipulated,"%c",x);
        if (x == '\n' && holder == 0)
            {
                while(1)
                {
                    for (int i = 0; i < 4; i++)
                    {
                        fscanf(original, "%2d", &data[i]);
                    }
                    data[0] = data[0] - 24;

                    fprintf(manipulated,"%d ",data[0]);
                    fprintf(manipulated,"%d ", data[1]);
                    fprintf(manipulated,"%d ", data[2]);
                    fprintf(manipulated,"%d ", data[3]);
                    holder = 1;
                    break;
                }
            }
            else if ( x == '\n')
            {
                holder += 1;
                
            }
        }
        
    }

    fclose(original);
    fclose(manipulated);
      
    return 0;

}