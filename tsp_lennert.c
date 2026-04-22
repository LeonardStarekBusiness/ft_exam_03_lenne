#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

typedef struct s_city
{
	float x;
	float y;
}	t_city;


//pythagoras
float	distance(t_city a, t_city b)
{
	float x = a.x - b.x;
	float y = a.y - b.y;
	return sqrtf(x * x + y * y);
}
float	total_distance(t_city *cities, int *path, int n)
{
	float tdist = 0.0;
	for (int i = 0; i < n-1; i++)
	{
		tdist += distance(cities[i], cities[i+1]);
	}
	//nicht vergessen Weg zurück!!
	tdist += distance(cities[n-1], cities[0]);
	return tdist;
}

void swap(int *a, int *b)
{
	int tmp = *b;
	*b = *a;
	*a = tmp;
}

void	solve(t_city *cities, int *path, int n, int pos, float *min)
{
	//stop check
	if (pos == n)
	{
		float dist = total_distance(cities, path, n);
		if (dist < *min)
			*min = dist;
		return ;
	}
	//recusion
	for (int i = pos; i < n; i++)
	{
		//work on permutet path
		swap(&path[pos], &path[i]);
		solve(cities, path, n, pos+1, min);
		swap(&path[pos], &path[i]);
	}
}

int	main(void)
{
	t_city	cities[11];
	int		n = 0;
	while (n < 11 && fscanf(stdin, "%f, %f", &cities[n].x, &cities[n].y) == 2)
		n++;
	if (n < 2)
	{
		printf("0.00\n");
		return (0);
	}
	int path[11];
	for (int i = 0; i < n; i++)
		path[i] = i;
	float min = FLT_MAX;
	solve(cities, path, n, 1, &min);
	printf("%.2f\n", min);
	return (0);
}