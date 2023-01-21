#include <iostream>
#include <time.h>
using namespace std;
const int N = 10;
int random(int start, int end)
{
	return start + rand() % (end - start + 1);
}
void initarr(int arr[], int N, int start, int end)
{
	for (int i = 0; i < N; i++)
	{
		arr[i] = random(start, end);
	}
}
void printarr(int arr[], int N)
{
	for (int i = 0; i < N; i++)
	{
		cout << arr[i] << " ";
	}
}
void apartentrance(int apartN, int array[])
{
	cout << "Количество жильцов в квартире номер " << apartN;
	cout << ": " << array[(apartN - 1) % 10] << " чел.";
	if (apartN % 2 == 0)
	{
		apartN -= 1;
		cout << endl << "В соседней квартире номер " << apartN << " проживает: " << array[(apartN - 1) % 10];
	}
	else if (apartN % 2 == 1)
	{
		apartN += 1;
		cout << endl << "В соседней квартире номер " << apartN << " проживает: " << array[(apartN - 1) % 10];
	}
}
void sumofpeopleinentrance(int N, int arr[], int entranceN)
{
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		sum += arr[i];
	}
	cout << endl << "Количество человек в подъезде " << entranceN << ": " << sum;
}
void multipeoplesapart(int N, int array[], int x)
{
	for (int i = 0; i < N; i++)
		if (array[i] > 5)
		{
			cout << "Кв. " << i + x << " - " << array[i] << " чел." << "; ";
		}
	cout << endl;
}
int main()
{
	setlocale(0, "");
	//srand(time(NULL));
	int apartN{ 0 };
	int firstentrance[N]{};
	int secondentrance[N]{};
	int thirdentrance[N]{};
	int fourthentrance[N]{};
	initarr(firstentrance, N, 1, 7);
	initarr(secondentrance, N, 1, 7);
	initarr(thirdentrance, N, 1, 7);
	initarr(fourthentrance, N, 1, 7);
	cout << "В этом доме 40 квартир.\nВведите номер интересующей вас квартиры: ";
	cin >> apartN;
	if (apartN <= 40)
	{
		if (apartN <= 10)
			apartentrance(apartN, firstentrance);
		if (apartN >= 11 && apartN <= 20)
			apartentrance(apartN, secondentrance);
		if (apartN >= 21 && apartN <= 30)
			apartentrance(apartN, thirdentrance);
		if (apartN >= 31 && apartN <= 40)
			apartentrance(apartN, fourthentrance);
	}
	else
		cout << "Такой квартиры не существует";
	sumofpeopleinentrance(N, firstentrance, 1);
	sumofpeopleinentrance(N, secondentrance, 2);
	sumofpeopleinentrance(N, thirdentrance, 3);
	sumofpeopleinentrance(N, fourthentrance, 4);
	cout << endl << "Квартиры с многодетными семьями: " << endl;
	multipeoplesapart(N, firstentrance, 1);
	multipeoplesapart(N, secondentrance, 11);
	multipeoplesapart(N, thirdentrance, 21);
	multipeoplesapart(N, fourthentrance, 31);
	return 0;
}