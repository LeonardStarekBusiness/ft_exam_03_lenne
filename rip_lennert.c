#include <stdio.h>

int length(char *str)
{
    int i = 0;
    while (str[i])
        i++;
    return i;
}

int is_balanced(char *str)
{
    int i = 0;
    int balance = 0;
    while (i < length(str))
    {
        if (str[i] == '(')
            balance++;
        if (str[i] == ')')
            balance--;
        if (balance < 0)
            return 0;
        i++;
    }
    return (balance == 0);
}

//two functions with similar structure
void print_sol(char *str, int min, int index, int removals)
{
    if (removals > min)
        return ;
    if (is_balanced(str) && removals == min)
    {
        printf("%s\n", str);
        return ;
    }
    //i = index!! 
    for (int i = index; i < length(str); i++)
    {
        if (str[i] == '(' || str[i] == ')')
        {
            char truc = str[i];
            str[i] = ' ';
            print_sol(str, min, i, removals+1);
            str[i] = truc;
        }
    }
}

//try all possible combinations
void get_min_len(char *str, int *min, int index, int removals)
{
    //stop check
    if (removals > *min)
        return ;
    //found any valid solution
    if (is_balanced(str) )//|| index >= length(str)-1)
    {
        //update minimum if better solution
        if (removals <= *min)
        {
            *min = removals;
        }
        return ;
    }
    // i = index!!
    for (int i = index; i < length(str); i++)
    {
        //work with truncated string, gets reset at end.
        char truc = str[i];
        str[i] = ' ';
        get_min_len(str, min, i+1, removals+1);
        str[i] = truc;
    }
}

int main(int ac, char **av)
{
    //memorise this structure!!
    int min = length(av[1]);
    get_min_len(av[1], &min, 0, 0);
    print_sol(av[1], min, 0, 0);
}