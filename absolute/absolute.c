#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input[10];
    char start[10];
    int addr,i=0;
    int length;
    FILE *fp1,*fp2;
    fp1=fopen("input.txt","r");
    fp2=fopen("output.txt","w");

    fscanf(fp1,"%s",input);
    while(strcmp(input,"E")!=0){
        if(strcmp(input,"H")==0)
        {
            fscanf(fp1,"%s %d",start,&length);
        }else if(strcmp(input,"T")==0)
        {
            fscanf(fp1,"%d %s",&addr,input);
            for(i=0;i<3;i++)
            {
                fprintf(fp2,"%d\t%c%c\n",addr++,input[i*2],input[i*2+1]);
            }
        }else{
            for(i=0;i<3;i++)
            {
                fprintf(fp2,"%d\t%c%c\n",addr++,input[i*2],input[i*2+1]);
            }
        }
        fscanf(fp1,"%s",input);
    }
    fclose(fp1);
    fclose(fp2);
    return 0;
}