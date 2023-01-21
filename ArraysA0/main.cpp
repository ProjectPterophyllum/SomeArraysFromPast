#include <iostream>
using namespace std;
const int N = 10;
const int N1 = 20;
void printarr(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void arrayfill(int arr[], int N)
{
	for (int i = 0; i < N; i++)
		arr[i] = i + 1;
}
void arrayXcombineFollow(int N, int N1, int arr1[], int arr2[], int arr3[])
{
	for (int i = 0; i < N; i++)
		arr3[i] = arr1[i];
	for (int i = N; i < N1; i++)
		arr3[i] = arr2[i - N];
}
void arrayXcombineAlternation(int N, int arr1[], int arr2[], int arr3[])
{
	int x = 0;
	for (int i = 0; i < N; i++)
	{
		arr3[x] = arr1[i];
		x++;
		arr3[x] = arr2[i];
		x++;
	}

}
int main()
{
	int A[N]{};
	int B[N]{};
	int X[N1]{};
	arrayfill(A, N);
	arrayfill(B, N);
	arrayXcombineAlternation(N, A, B, X);
	cout << "Alternation Mode: ";
	printarr(X, N1);
	arrayXcombineFollow(N, N1, A, B, X);
	cout << "Follow Mode: ";
	printarr(X, N1);
	return 0;
}