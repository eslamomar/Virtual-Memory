#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


int main (int argc,char *argv[])

{
int temp;
int pages[40];    // pages numbers  from input file
int mod;          // type of algorithm 0 for FIFO   1 FOR LRU
int frames;       // number of memory frames
char *file_name;    // input file name
int i=0,j=0;     // counters
int page_num=0;    // pages number
int Flag=0;
// passing arg to variables
mod=atoi(argv[1]);
frames=atoi(argv[2]);
file_name=argv[3];

// geting pages from input file
FILE *fp;

fp=fopen(file_name,"r");

while( fscanf(fp, "%d ",&temp) > 0 )
{
pages[i]=temp;
//printf("\npages[%d]= %d\n",i,pages[i]);
i++;
page_num++;
}
fclose(fp);


int m,min,t=0,head=0,a[50],count=0,page_fault=0,k[50];

for (i=0;i<40;i++)
{
a[i]=-1;
k[i]=-1;
}


fp=fopen("output.txt","a");

if (mod==0){
fprintf(fp, "FIFO  Number of pages=%d   from input file: %s \n\n",page_num,file_name);
for(j=0;j<page_num;j++)
{
// serch for page in frames
        for (i=0;i<frames;i++)
    {
                if(a[i]==pages[j])
                {
                Flag=1;
                // continue;
                }
    }


    if(Flag==0)
    {       page_fault++;
            a[head]=pages[j];
            head++;

                if(head==frames)
                    head=0;
//print output
        for (i=0;i<frames;i++)
            {
            fprintf(fp, "%d   ",a[i]);

            }
    }
else
{
//print output
        for (i=0;i<frames;i++)
        {
        fprintf(fp, "%d   ",a[i]);

        }

}

fprintf(fp, "\n ");
Flag=0;
}

fprintf(fp, "\n Number of Page Fault= %d \n",page_fault);
fprintf(fp, "\n Number of Page Fault ratio = %f \n",(float)((float)page_fault/(float)page_num));

}
else
{
        fprintf(fp, "LRU  Number of pages=%d   from input file: %s \n\n",page_num,file_name);

for(j=0;j<page_num;j++)
{
// serch for page in frames
        for (i=0;i<frames;i++)
    {
                if(a[i]==pages[j])
                {
                Flag=1;
                // continue;
                }
    }


    if(Flag==0)
    {
            k[pages[j]]=count;
            for (m=0;m<40;m++)
            {
            if (k[m]==t)
            {
            min=m;
            t++;
            }
            }
a[min]=pages[j];
page_fault++;
count++;


//print output
        for (i=0;i<frames;i++)
            {
            fprintf(fp, "%d   ",a[i]);

            }
}
else
{
//print output
k[pages[j]]=count;
count++;

        for (i=0;i<frames;i++)
        {
        fprintf(fp, "%d   ",a[i]);

        }

}

fprintf(fp, "\n ");
Flag=0;
}

fprintf(fp, "\n Number of Page Fault= %d \n",page_fault);
}
fclose(fp);


}

