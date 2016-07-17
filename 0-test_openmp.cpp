#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
void Test (int n) {
	for(int i = 0; i < 10000; ++i) {
	//do nothing, just waste time
	}
	Sleep(100-n);
	printf("%d, ", n);
}
int main(int argc,char* argv[]) 
{
	#pragma omp parallel for
	for(int i = 0; i < 100; ++i)
		Test( i );
	system("pause");
}