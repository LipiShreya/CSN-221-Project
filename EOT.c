#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include<math.h>
///Number of test cases.
#define t 1000000
// 000000
///Total no of addresses in a test case
#define add 256
///Bits of an address
#define bit 8
int main()
{
    srand(time(0)); 
    ///Array to store addresses (tag). Each row will have 8 bits.
    int a[add][bit];
    ///Clock variables
    clock_t initial_time,final_time;
    ///To count total hits.
    int hit_eot=0,hit_fully_associative=0;  
    ///To count total  misses.
    int miss_eot=0,miss_fully_associative=0;
    double time_fully_associative=0,time_eot=0;

    

    int i,j,k,l=t,m;
    ///To check if it is a miss or a hit
    int flag;
    ///Boolean array for eot
    bool b[add];
    while(l--)
    {
        ///Address assignment.
        for(i=0;i<add;i++)
        {
            k=rand()%((int)pow(2,bit));
            // printf("%d\n",k);
            for(j=bit-1;j>=0;j--)
            {
                a[i][j]=k%2;
                k/=2;
                // printf("%d",a[i][j]);
            }
            // printf("\n");
            ///bool array assignment
            b[i]=true;
        }
        ///Address to be checked.
        m=rand()%((int)pow(2,bit));
        // printf("Checked add %d\n",m);
        ///Begin time calculation here as practically operation starts from here as assignment would have already been done.
        initial_time=clock();
        ///Fully associative
        for(i=0;i<add;i++)
        {
            ///hit case
            flag=1;
            k=m;
            for(j=bit-1;j>=0;j--)
            {
                if(a[i][j]!=k%2)
                {
                    ///miss
                    flag=0;
                    break;
                }
                k/=2;
            }
            if(flag==1)
            {
                ///hit
                hit_fully_associative++;
                // printf("i is %d eot\n",i);
                break;
            }

        }
        if(flag==0)
        {
            miss_fully_associative++;
        }
        final_time=clock();
        time_fully_associative+=((double)(final_time-initial_time))/CLOCKS_PER_SEC;
        initial_time=clock();
        
        ///EOT
        k=m;
        for(i=0;i<add;i++)
        {
            if(a[i][0]!=k>>bit-1)
            b[i]=false;
            
        }
        final_time=clock();
        
 initial_time=clock();
        for(i=0;i<add;i++)
        {
            ///hit
            flag=1;
            k=m;
            if(b[i])
           {
                for(j=bit-1;j>0;j--)
            {
                if(a[i][j]!=k%2)
                {
                    ///miss
                    flag=0;
                    break;
                }
                k/=2;
            }
            if(flag==1)
            {
                ///hit
                hit_eot++;
                //  printf("i is %d\n",i);
                break;
            }
           }

        }
        if(flag==0||((i==add)&&!b[i-1]))
        {
            miss_eot++;
        }
        final_time=clock();
        time_eot+=((double)(final_time-initial_time))/CLOCKS_PER_SEC;
    }

    printf("Total access time for all cases in fully associative technique is %lf\n",time_fully_associative);
    
    time_fully_associative/=t;
  
    printf("Average access time for fully associative technique is %lf\n",time_fully_associative);
    printf("Hits %d\nMisses %d\nTotal %d\n",hit_fully_associative,miss_fully_associative,hit_fully_associative+miss_fully_associative);
    printf("Total access time for all cases in EOT is %lf\n",time_eot);
       time_eot/=t;
    printf("Average access time for EOT is %lf\n",time_eot);
     printf("Hits %d\nMisses %d\nTotal %d",hit_eot,miss_eot,hit_eot+miss_eot);

   


}