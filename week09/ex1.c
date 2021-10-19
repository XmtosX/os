#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct page{
    int cnt;
    int id;
};

int main(int argc, char *argv[])
{
    if(argc<=1)
    {
        printf("pass the number of pages as an argument.\n");
        exit(1);
    }
    const int page_num = atoi(argv[1]);
    struct page mem[page_num];
    for(int i=0;i<page_num;i++)
    {
        mem[i].cnt = -1;
        mem[i].id = -1;
    }
    FILE *file;
    file = fopen("input.txt", "r");
    int cur;
    int hit=0;
    int mis=0;
    fscanf (file, "%d", &cur);
    while(!feof(file))
    {
        int minn = 0;
        bool found = false;
        for(int i=0;i<page_num;i++)
        {
            if(mem[minn].cnt>mem[i].cnt)
            {
                minn = i;
            }
            mem[i].cnt = mem[i].cnt>>1;
            if(mem[i].id == cur)
            {
                hit++;
                found = 1;
                mem[i].cnt += (1<<7);
            }
        }
        if(!found)
        {
            mis++;
            mem[minn].id = cur;
            mem[minn].cnt = (1<<7);
        }
        fscanf (file, "%d", &cur);
    }
    printf("Hits: %d\nMisses: %d\n",hit,mis);
    printf("The ratio of Hit/Miss is %f\n",(float)hit/mis);
}
