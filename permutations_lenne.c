#include <stdio.h>

size_t length(char *str)
{
    size_t i = 0;
    while(str[i])
        i++;
    return i;
}

void swap(char *a, char *b)
{
    char tmp = *b;
    *b = *a;
    *a = tmp;
}

int is_ordered(char *str)
{
    size_t len = length(str) - 1;
    for (size_t i = 0; i < len; i++)
    {
        if (str[i] > str[i+1])
            return 0;
    }
    return 1;
}

void order(char *str)
{
    int ordered = 0;
    size_t len = length(str) - 1;
    while(!is_ordered(str))
    {
        for (size_t i = 0; i < len; i++)
        {
            if (str[i] > str[i+1])
                swap(&str[i], &str[i+1]);
        }
    }
}

void permute(char *str , int n) //pass n as arg which recursively decreases
{
    if (n == 1)
    {
        puts(str);
        return ;
    }
    for (size_t i = 0; i < n; i++)
    {
        permute(str, n-1); //recurse here
        if (n % 2 == 1) //Condition auswendig lernen!!
            swap(&str[0], &str[n-1]); //swap auswendig lernen!!!
        else
            swap(&str[i], &str[n-1]); //swap auswendig lernen!!!
        
    }
}

int main(int ac, char **av)
{
    //diese Logik merken!!
    order(av[1]);
    permute(av[1], length(av[1]));
    return 0;
}