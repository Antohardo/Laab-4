#define _CRT_SECURE_NO_DEPRECATE
#include<locale.h>
#include<stdio.h>
#include<cstdlib>
#include<iostream>
#include<cmath>
double part1(double, int, double&);
double part2(double, double, int&);
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");
	while (1)
	{
		int l = 0;
		cout << "Выберите действие: 1 - старт, 0 - выход;" << endl;
		cin >> l;
		if (l != 1)
		{
			break;
		}
		system("cls");
		int n;
		double f, x, sam, last;
		cout << "Вычисление функции ln((1-x)/(x-1))" << endl;
		cout << "Задание №1:" << endl;
		do
		{
			cout << "Введите число слагаемых: " << endl;
			cin >> n;
		} while (n < 0);
		do
		{
			cout << "Введите x : " << endl;
			cin >> x;
		} while (fabs(x) < 1);
		f = log((1 + x) / (x - 1));
		sam = part1(x, n, last);
		cout << "Точное значние функции: " << f << endl;
		cout << "Частичная сумма: " << sam << endl;
		cout << "Абсолютная погрешность: " << fabs(f - sam) << endl;
		cout << "Последнее слагаемое: " << last << endl;

		cout << "Задание №2" << endl;
		cout << "Задате погрешнсть: " << endl;
		double E;
		cin >> E;
		f = log((1 + x) / (x - 1));
		sam = part2(x, E, n);
		cout << "Точное значение функции: " << f << endl;
		cout << "Частичная сумма c погрешностью: " << sam << endl;
		sam = part2(x, E / 10, n);
		cout << "частичная сумма с точностью большей в 10 раз: " << sam << endl;
		
	}
	
	return 0;
}

double part1(double x, int n, double& last)
{
	last = 1 / x;                            
	double sum = last;
	for (int i = 1; i <= n; i++)
	{
		last *= 1 / ((2 * n + 1) * pow(x, 2 * n + 1));
		sum += last;
	}
	sum *= 2;
	return sum;
}

double part2(double x, double E, int& n)
{
	double last = 1 / x;
	double sum = last;
	for (n = 1; fabs(last) > E; n++)
	{
		last *= 1 / ((2 * n + 1) * pow(x, 2 * n + 1));
		sum += last;
	}
	return sum;
}