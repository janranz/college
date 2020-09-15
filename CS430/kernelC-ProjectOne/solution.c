/* This one is for you to finish!  Have fun! */
#include <stdio.h>
#include <stdlib.h>
#include "tester.h"

int finder(void* ls, int calling, size_t len)
{
	int *goodList = (int*)ls;
	// printf("goodList: %p\n",goodList);
	// printf("goodList: %p\n",goodList[0]);
	static int needsWork = 1;
	if(needsWork)
	{
		needsWork = 0;
		return 1;
	}		
	return 7;
	

}
int comp(const void* m, const void* k)
{
	return(*(int*)m - *(int*)k);
}
int* sorter(int* arrInt, size_t len)
{
	int *copyarr = malloc(len * sizeof(int));

	for(int i = 0; i < len; i++)
	{
		copyarr[i] = arrInt[i];
	}
	qsort(copyarr,len,sizeof(int),comp);
	return copyarr;
}

// m = 636174 | 11000110110000101110100
// k = 656172 | 11001010110000101110010
//			  | 11001110110000101110
//			  | 11001110110000000000

//11001110110000101110
//11001110110000101100
//11001110110000100000
//11001110110000000000
//
//
//

int shifted(int m, int k)
{
	int _m = m;
	int _k = k;

	int outcome = _m | _k;
	outcome = outcome >> 3;
	for(int i = 0; i < 7; i++)
		outcome = outcome & ~(1 << i);	
	return outcome;
}
int main()
{
	struct bundle_struct bunds;
	bunds.sorted_copy = sorter;
	bunds.combine = shifted;
	bunds.find_best = finder;
	int testResult = test(&bunds);
	return 0;
}