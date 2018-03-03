// 180303_hackerlandTransmitter.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
enum TRANSM
{
	INSTALLED,	//installed so radio possible
	POS,	//not installed but radio possible
	IMPOS	//not installed and radio impossible
};
int hackerlandRadioTransmitters(vector <int> x, int k) {
	// Complete this function
	vector<int> transmitter(x.size(),IMPOS);
	sort(x.begin(), x.end());
	int cur = 0;
	int idx = 0;
	int result = 0;
	while(idx<x.size())
	{
		cur = 0;
		while (x[idx + cur] - x[idx] <= k)
		{
			transmitter[idx + cur] = POS;
			cur++;
			if (idx + cur >= x.size()) break;
		}
		transmitter[idx + cur-1] = INSTALLED;
		result++;
		idx = idx + cur;
		int installed = idx - 1;
		while (1)
		{
			if (idx >= x.size()) break;
			if (x[idx] - x[installed] <= k)
			{
				transmitter[idx] = POS;
				idx++;
				if (idx >= x.size()) break;
			}
			else break;
		}
	}

	return result;
}

int main() {
	int n;
	int k;
	cin >> n >> k;
	vector<int> x(n);
	for (int x_i = 0; x_i < n; x_i++) {
		cin >> x[x_i];
	}
	int result = hackerlandRadioTransmitters(x, k);
	cout << result << endl;
	return 0;
}
