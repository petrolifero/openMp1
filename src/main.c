#include <stdio.h>
#include <stdint.h>
#include <omp.h>

int fact(int number)
{
	int ret=1;
	#pragma omp parallel
	{
		int omp_priv=1;
		#pragma omp for nowait schedule(dynamic, 4)
		for(int n=2; n<=number; n++)
		{
			omp_priv*=n;
		}
		#pragma omp atomic
		ret *= omp_priv;
	}
	return ret;
}


int main(int argc, char* argv[])
{
	int n=12;
	printf("fatorial de %d e %d\n", n, fact(n));
	return 0;
}
