#include<iostream>
#include<time.h>
using namespace std;

void integer()
{
	int i, x, y, z;
	x = rand() % 99;    //���������xΪ��һλ��
	y = rand() % 99;   //���������yΪ�ڶ�λ��
	z = (x + y) % 4;      //z����ȷ������������������
	if (z == 0)                                                      //�������ʽ
		cout << x << "+" << y << "=" << endl;
	if (z == 1)
		cout << x << "-" << y << "=" << endl;
	while (x<y)
	{
		x = rand() % 99;
		y = rand() % 99;
	}  //�ų�����
	if (z == 2)
		cout << x << "*" << y << "=" << endl;
	if (z == 3)
		cout << x << "/" << y << "=" << endl;
}

//�������������
void fraction()
{
	int a, b, c, d, z;
	a = rand() % 99;
	b = rand() % 99;
	c = rand() % 99;
	d = rand() % 99;
	z = rand() % 4;
	while (a <= b || c <= d)
	{
		a = rand() % 99;
		b = rand() % 99;
		c = rand() % 99;
		d = rand() % 99;
	}
	if (z == 0)                                                      //�������ʽ
		cout << b << "/" << a << "+" << d << "/" << c << "=" << endl;
	if (z == 1)
		cout << b << "/" << a << "-" << d << "/" << c << "=" << endl;
	while ((b*c - a*d)<0)
	{
		a = rand() % 100 + 1;
		b = rand() % 100 + 1;
		c = rand() % 100 + 1;
		d = rand() % 100 + 1;
	}
	if (z == 2)
		cout << b << "/" << a << "*" << d << "/" << c << "=" << endl;
	if (z == 3)
		cout << b << "/" << a << "/" << d << "/" << c << "=" << endl;
}
void main()
{
	srand(time(0));
	int i, n, m;
	cout << "�������������" << endl;
	cout << "1.������������" << endl;
	cout << "2.������������" << endl;
	cin >> i;
	cout << "�����������Ŀ" << endl;
	cin >> n;
	for (m = 1; m <= n; m++)
	{
		if (i == 1)
			integer();
		else
			fraction();
	}
}