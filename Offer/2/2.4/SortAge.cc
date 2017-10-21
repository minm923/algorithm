#include <stdio.h>
#include <string.h>

void SortAge(int *ages,int length)  
{  
    if(NULL==ages || length<=0)  
        return;  

    const int oldestage = 99;  
    int timesOfAge[oldestage+1];  //辅助空间；  

    memset(timesOfAge, 0, sizeof timesOfAge);

    for(int i=0;i<length;i++)  
    {  
       int age=ages[i];  
       if(age<=0 || age>=100)  
        return ;  
       timesOfAge[age]++;  
    }  

    int index=0;  
    for(int i=0; i<=oldestage; ++i)  
    {
       for(int j=0;j<timesOfAge[i];++j)    
       {  
          ages[index]=i;
          index++;  
       }  

        for(int k=0;k<30;k++)
        {
            printf("%d ",ages[k]);
        }
        printf("\n");
    }
} 

int main(int argc, char * argv[])
{
    int ages[] = {33,34,45,24,36,23,21,22,19,26,45,34,21,34,34,33,52,22,32,25,27,43,22,21,20,33,26,27,15,29};
    int len = 30;
    SortAge(ages,len);
    for(int i=0;i<len;i++)
    {
        printf("%d ",ages[i]);
    }
    printf("\n");

    return 0;
}
