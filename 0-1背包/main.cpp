#include <iostream>
#include <vector>

int main() 
{
	const int n = 6;	//物体数量
	int weight[6] = { 1,2,1,3,4,2 };	//每个物体重量
	int value[6] = { 4,3,6,2,1,8 };	//每个物体价值
	const int max = 7;	//背包最多能承受的重量

	vector<int> res;

	int f[n + 1][max + 1] = { 0 };
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= max; j++)
		{
			if (weight[i] > j)
			{
				f[i][j] = f[i - 1][j];
			}
			else
			{
				int a = f[i - 1][j];
				int b = f[i - 1][j - weight[i-1]] + value[i-1];
				f[i][j] = a > b ? a : b;				
			}
		}
	}
	cout << f[n + 1][max + 1];

	system("pause");
	return 0;
}

