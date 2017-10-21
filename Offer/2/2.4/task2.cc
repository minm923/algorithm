void SortAge(int *age,int length)  
{  
    if(NULL==age || length<=0)  
    return;  
    const int oldestage=100;  
    int timesOfAge[oldestage];  //辅助空间；  
    for(int i=0;i<oldestage;i++)  
    {  
       timesOfAge[i]=0;  //初始化；  
    }  
    for(int i=0;i<oldestage;i++)  
    {  
       int age=age[i];  
       if(age<=0 || age>=100)  
       return ;  
       timeOfAge[age]++;  
    }  
    int index=0;  
    for(int i=0;i<oldest;i++)  
       for(int j=0;j<timesOfAge[i];j++)    
       {  
          age[index]=i;  
      index++;  
       }  
} 