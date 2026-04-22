#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void print_set(int *set, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", set[i]);
    }
    printf("\n");
}

//Diese 7 parameter auswendig lernen!!
void powerset(int *set, int *subset, int set_size, int subset_size,
                int index, int target, int sum)
{
    if (index == set_size) //end check
    {
        if (sum == target) //success check
        {
            print_set(subset, subset_size);
        }
        return ;
    }
    //double recursion!!
    powerset(set, subset, set_size, subset_size, index+1, target, sum);
    //expand subset
    subset[subset_size] = set[index];
    powerset(set, subset, set_size, subset_size+1, index+1, target, sum + subset[subset_size]);
}

int main(int ac, char **av)
{
    int target = atoi(av[1]);
    int set_size = ac-2;
    int *set = malloc(4 * set_size);
    int *subset = malloc(4 * set_size);
    for (int i = 0; i < set_size; i++)
    {
        set[i] = atoi(av[i+2]);
    }
    powerset(set, subset, set_size, 0, 0, target,0);
}