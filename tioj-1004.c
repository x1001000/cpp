//1001000

#include <stdio.h>

int man[51];
int alive;

void next_array(int n)
{
    alive = n;
    for(int i=1; i<=alive/2; i++)
    {
        man[i] = man[i*2-1];
        //printf("%d\n", man[i]);
    }
    if(alive%2)
    {
        man[0] = man[alive];
        alive = alive/2 + 1;
        for(int i=alive; i>=1; i--)
        {
            man[i] = man[i-1];
            //printf("%d\n", man[i]);
        }
    }
    else
    {
        alive = alive/2;
    }
}

int main(void)
{
    scanf("%d", &alive);
    for(int i=1; i<=alive; i++)
    {
        man[i] = i;
        //printf("%d\n", man[i]);
    }
    while(alive>1)
    {
        next_array(alive);
    }
    printf("%d", man[1]);

    return 0;
}
