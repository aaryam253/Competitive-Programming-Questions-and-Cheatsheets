#include <iostream>
#include <stdio.h>
#include <vector>

using namespace std;

int main()
{
	int n, m;
	while (true)
	{
		int Jack[100000], Jill[100000];
		cin >> n >> m;

		if (!n && !m) break;

		for (int i = 0; i < n; i++)
		{
			int num;
			cin >> num;
			Jack.push_back(num);
		}
		for (int i = 0; i < m; i++)
		{
			int num;
			cin >> num;
			Jill.push_back(num);
		}

		int i = 0, d = 0, ans = 0;

		while (i != n && d != m)
		{
			if (Jack[i] == Jill[d]) {
				ans++;
				i++; d++;
			}
			else if (Jack[i] > Jill[d]) {
				d++;
			}
			else if (Jack[i] < Jill[d]) {
				i++;
			}
		}

		cout << ans << endl;
	}

    return 0;
}

