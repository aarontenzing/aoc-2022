//Day 1 Advent Of Code -- Counting calories till we reach an empty line, then take max value from array.
//Calculate also top 3 most calories and give the sum.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 10
#define MAX 500

char calories[MAX_LINE_LENGTH];
int sum[MAX],results[MAX];
int max=0,i=0,output;

int main()
{
    FILE* ptr = fopen("input.txt","r");
    
    while (fgets(calories, MAX_LINE_LENGTH, ptr))
    {
        sum[i] += atoi(calories);
        if(calories[0] == '\n')
        {
            i++;
        }
    }
    fclose(ptr);

    int z=0,tmp=0,j=0;
    while(z < 3)
    {
        for(j=0;j<i;j++)
        {
            if(max < sum[j])
            {
                max = sum[j];
                tmp = j;
                results[z] = max;
               
            }
        }
        sum[tmp] = 0;
        max=0;
        z++;
    }
    printf("solution 1=%d, solution 2=%d",results[0],results[0]+results[1]+results[2]);   
}