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
		cout << "�������� ��������: 1 - �����, 0 - �����;" << endl;
		cin >> l;
		if (l != 1)
		{
			break;
		}
		system("cls");
		int n;
		double f, x, sam, last;
		cout << "���������� ������� ln((1-x)/(x-1))" << endl;
		cout << "������� �1:" << endl;
		do
		{
			cout << "������� ����� ���������: " << endl;
			cin >> n;
		} while (n < 0);
		do
		{
			cout << "������� x : " << endl;
			cin >> x;
		} while (fabs(x) < 1);
		f = log((1 + x) / (x - 1));
		sam = part1(x, n, last);
		cout << "������ ������� �������: " << f << endl;
		cout << "��������� �����: " << sam << endl;
		cout << "���������� �����������: " << fabs(f - sam) << endl;
		cout << "��������� ���������: " << last << endl;

		cout << "������� �2" << endl;
		cout << "������ ����������: " << endl;
		double E;
		cin >> E;
		f = log((1 + x) / (x - 1));
		sam = part2(x, E, n);
		cout << "������ �������� �������: " << f << endl;
		cout << "��������� ����� c ������������: " << sam << endl;
		sam = part2(x, E / 10, n);
		cout << "��������� ����� � ��������� ������� � 10 ���: " << sam << endl;
		
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