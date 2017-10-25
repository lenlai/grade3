#include <iostream>
#include<math.h>
using namespace std;
void main()
{
	int i, j, num, N, M, S[100], S2[100], S3[100] = { 0 };
	double S1[100], ave, sum, G;
	double max, min;
	cout << "==============欢迎进入黄金点游戏!============" << endl;
	cout << "=============================================" << endl;
	cout << "=====================v指南v==================" << endl;
	cout << "===1.N个玩家(N通常大于10)进行游戏============" << endl;
	cout << "===2.每人写一个0~100之间的有理数 (除0和100)==" << endl;
	cout << "===3.G=N位玩家平均值*0.618===================" << endl;
	cout << "===4.最高分(N): 提交数字最接近G值的玩家======" << endl;
	cout << "===5.最低分(-2):提交数字距离G值最远的玩家====" << endl;
	cout << "===6.其他分(0): 其他所有玩家=================" << endl;
	cout << "Please input the number of your game!" << endl;
	cin >> N;
	cout << "The number of the person:" << endl;
	cin >> M;
	for (i = 1; i <= N; i++)
	{
		sum = 0;
		G = 0;
		cout << "Input the number between 1 to 100." << endl;
		for (j = 1; j <= M; j++)
		{
			cout << " Player " << j << " input your choose!" << endl;
			cin >> num;
			S[j] = num;
			sum = sum + S[j];
		}
		ave = sum / M;
		G = ave*0.618;
		cout << "黄金点是G=" << G << endl;
		for (j = 1; j <= M; j++)
		{
			S1[j] = abs(S[j] - G);
		}
		max = min = S1[1];
		for (j = 1; j <= M; j++)
		{
			if (S1[j] >= max)
				max = S1[j];
			else if (S1[j] < min)
				min = S1[j];
		}
		for (j = 1; j <= M; j++)
		{
			if (S1[j] == max)
				S2[j] = -2;
			else if (S1[j] == min)
				S2[j] = M;
			else S2[j] = 0;

		}
		for (j = 1; j <= M; j++)
		{
			cout << "本轮分数" << "S2[" << j << "]=" << S2[j] << endl;
			S3[j] = S3[j] + S2[j];
			cout << "总分数 " << "S3[" << j << "]=" << S3[j] << endl;
		}
	}
	system("pause");
}