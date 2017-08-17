#include "sort.h"
#include<iostream>
#include<process.h>
using namespace std;
int main()
{
	int a[12] = { 21,324,4532,45,654,65,6356,4653,65,564,53,432};
	select_sort(a, 0, 11);
	for (int i = 0; i < 11; i++)
		cout << a[i] << endl;
	system("pause");
	return 0;
}