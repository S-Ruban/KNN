#include <stdio.h>
#include <math.h>
typedef struct
{
	double x, y ;
}point ;
double dist(point p1, point p2);
void swap(double* x, double* y);
int main()
{
	int a, b, k, i ;
	printf("Enter the number of A points : ");
	scanf("%d", &a);
	printf("Enter the number of B points : ");
	scanf("%d", &b);
	printf("\n");
	point A[a];
	point B[b];
	printf("Enter the A points : \n");
	for(i = 0; i < a; i++)
		scanf("%lf %lf", &A[i].x, &A[i].y);
	printf("\n");
	printf("Enter the B points : \n");
	for(i = 0; i < b; i++)
		scanf("%lf %lf", &B[i].x, &B[i].y);
	printf("\n");
	printf("Enter the value of k : ");
	scanf("%d", &k);
	printf("\n");
	printf("Enter the co-ordinates of the point P : \n");
	point P ;
	scanf("%lf %lf", &P.x, &P.y);
	printf("\n");
	double d[a+b][2];
	for(i = 0; i < a; i++)
	{
		d[i][0] = dist(A[i], P);
		d[i][1] = 0.0 ;
	}
	for(i = a; i < a+b; i++)
	{
		d[i][0] = dist(B[i-a], P);
		d[i][1] = 1.0 ;
	}
	int m, n ;
	for(m = 0; m < a+b-1; m++)
	{
		for(n = m+1; n < a+b; n++)
		{
			if(d[n][0] < d[m][0])
			{
				swap(&d[m][0], &d[n][0]);
				swap(&d[m][1], &d[n][1]);
			}
		}
	}
	double c = 0.0 ;
	for(i = 0; i < k; i++)
		c += d[i][1];
	if(2*c <= (double)k)
		printf("Point P belongs to class A.");
	else
		printf("Point P belongs to class B.");
}
double dist(point p1, point p2)
{
	return (pow(p1.x-p2.x, 2)+pow(p1.y-p2.y, 2));
}
void swap(double* x, double* y)
{
	double t = *x ;
	*x = *y ;
	*y = t ;
}
