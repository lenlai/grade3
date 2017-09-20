#include<iostream>
#include<time.h>
using namespace std;

void integer()
{
	int i, x, y, z;
	x = rand() % 99;    //产生随机数x为第一位数
	y = rand() % 99;   //产生随机数y为第二位数
	z = (x + y) % 4;      //z用来确定随机产生的运算符号
	if (z == 0)                                                      //输出算术式
		cout << x << "+" << y << "=" << endl;
	if (z == 1)
		cout << x << "-" << y << "=" << endl;
	while (x<y)
	{
		x = rand() % 99;
		y = rand() % 99;
	}  //排除负数
	if (z == 2)
		cout << x << "*" << y << "=" << endl;
	if (z == 3)
		cout << x << "/" << y << "=" << endl;
}

//增加真分数运算
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
	if (z == 0)                                                      //输出算术式
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
	cout << "请输入出题类型" << endl;
	cout << "1.整数四则运算" << endl;
	cout << "2.分数四则运算" << endl;
	cin >> i;
	cout << "请输入出题数目" << endl;
	cin >> n;
	for (m = 1; m <= n; m++)
	{
		if (i == 1)
			integer();
		else
			fraction();
	}
}