#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
using namespace std;



//�õݹ�ķ�ʽ���
int fuc(int m, int n)
{
	if (m != 0 && n == 0)
		return 1;
	else if (m < n)
		return 0;
	else
		return fuc(m - 1, n) + fuc(m, n - 1);
}

//�õ��Ƶķ������

int fuct(int m, int n)
{
	if (m < n)
		return 0;
	vector<vector<int>> h(m+1,vector<int>(m+1,0));

	for (int i = 1; i <= m; ++i)//��ʼ��
	{
		h[i][0] = 1;
	}
	for (int i = 1; i <= m; ++i)//����
	{
		for (int j = 1; j <= i; j++)
		{
			h[i][j] = h[i - 1][j] + h[i][j - 1];
		}
	}
	return h[m][n];
}


int main(void)
{
	cout << fuc(3, 2);
	cout << fuct(3, 2);


	return 0;
} 