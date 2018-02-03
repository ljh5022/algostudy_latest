// 180202_CountLuck.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include <vector>
#include <string>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <algorithm>
using namespace std;
vector<string> markPoint(int posN, int posM, vector<string> matrix, int l);
int num;
string countLuck(vector <string> matrix, int k) {
	// Complete this function
	//출발위치 찾기
	int startN = 0;
	int startM = 0;
	for (int matrix_i = 0; matrix_i < matrix.size(); matrix_i++) {
		if (matrix[matrix_i].find("M") != string::npos)
		{
			startN = matrix_i;
			startM = matrix[matrix_i].find("M");
		}
	}

	vector<string> aa = markPoint(startN, startM, matrix, 0);
	cout << num << endl;
	//for (int matrix_i = 0; matrix_i < aa.size(); matrix_i++) {
	//	cout << aa[matrix_i] << endl;
	//}
	if(k==num) return "Impressed";
	else return "Oops!";

}

vector<string> markPoint(int posN, int posM, vector<string> matrix, int l)
{
	char count = matrix[posN].at(posM);
	if (count == '*')
	{
		if (num > l)
		{
			num = l;
			//cout << "!"<<num << endl;
		}
		return matrix;
	}
	/*if(matrix[posN][posM] !='M') */matrix[posN][posM]= 'X';
	int temp = 0;
	if (posN > 0)
	{
		if (matrix[posN - 1].at(posM) != 'X')
		{
			temp++;
		}
	}
	if (posM > 0)
	{
		if (matrix[posN].at(posM - 1) != 'X')
		{
			temp++;
		}
	}
	if (posN < matrix.size() - 1)
	{
		if (matrix[posN + 1].at(posM) != 'X')
		{
			temp++;
		}
	}
	if (posM < matrix[0].size() - 1)
	{
		if (matrix[posN].at(posM + 1) != 'X')
		{
			temp++;
		}
	}
	if (temp > 1)
	{
		l += 1;
		//cout << "@" << l << "@" << posN << posM << endl;
	}
	if (posN > 0)
	{
		if (matrix[posN - 1].at(posM) != 'X')
		{
			//matrix[posN - 1][posM] = count + 1;
			matrix = markPoint(posN - 1, posM, matrix,l);
		}
	}
	if (posM > 0)
	{
		if (matrix[posN].at(posM - 1) != 'X')
		{
			//matrix[posN][posM - 1] = count + 1;
			matrix =  markPoint(posN, posM - 1, matrix, l);
		}
	}
	if (posN < matrix.size() - 1)
	{
		if (matrix[posN + 1].at(posM) != 'X')
		{
			//matrix[posN + 1][posM] = count + 1;
			matrix = markPoint(posN + 1, posM, matrix,l);
		}
	}
	if (posM < matrix[0].size()-1)
	{
		if (matrix[posN].at(posM + 1) != 'X')
		{
			//matrix[posN][posM + 1] = count + 1;
			matrix = markPoint(posN, posM + 1, matrix,l);
		}
	}
	/*if (matrix[posN][posM] != 'M') */matrix[posN][posM] = '.';
	return matrix;
}

int main() {
	int t;
	cin >> t;
	for (int a0 = 0; a0 < t; a0++) {
		int n;
		int m;
		cin >> n >> m;
		num = n * m;
		vector<string> matrix(n);
		for (int matrix_i = 0; matrix_i < n; matrix_i++) {
			cin >> matrix[matrix_i];
		}
		int k;
		cin >> k;
		string result = countLuck(matrix,k);

		
		cout << result << endl;
	}
	return 0;
}
