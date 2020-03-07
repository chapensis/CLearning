#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <string>

using namespace std;

int max(int i, int j)
{
	if (i >= j)
		return i;
	else
		return j;
}

int min(int i, int j)
{
	if (i <= j)
		return i;
	else
		return j;
}

int main()
{
	int N;
	cin >> N;
	string aa[N];
	for (int i = 0; i < N; i++)
	{
		cin >> aa[i];
	}

	int rows = N;
	int cols = aa[0].size();
	int dp[cols + 1];
	int max1 = 0;
	int pre = 0;
	cout << "row " << rows << " cols " << cols << endl;

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
			cout << aa[i][j];
		cout << endl;
	}
	for (int i = 1; i <= rows; i++)
	{
		for (int j = 1; j <= cols; j++)
		{
			int tmp = dp[j];
			if (aa[i - 1][j - 1] == '1')
			{
				dp[j] = min(min(dp[j - 1], pre), dp[j]) + 1;
				max1 = max(max1, dp[j]);
			}
			else
			{
				dp[j] = 0;
			}
			pre = tmp;
		}
	}
	cout << "max:" << max1 << endl;
	cout << max1 * max1 << endl;
	return 0;
}