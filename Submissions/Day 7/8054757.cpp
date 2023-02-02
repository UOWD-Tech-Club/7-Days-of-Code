// 27.01.2023 - 8054757 - Matvei Maslov
// Question 2
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string moveLetters(string str, vector<int> move)
{
	for (int i = 0; i < str.size(); ++i)
	{
		if (move[i] == 0) continue;
		if ((int)str[i]<91&&(int)str[i]+move[i] >= 65 && (int)str[i] + move[i]<= 90 || (int)str[i] > 91 && (int)str[i] + move[i]>= 97 && (int)str[i] + move[i]<= 122)
		{
			str[i] += move[i];
			continue;
		}
		if (move[i] <0)
		{
			if (int(str[i]) < 91) str[i] = 91 + (move[i] + abs((int)str[i] - 65)) % 26;
			else str[i] = 123 + (move[i] + abs((int)str[i] - 97)) % 26;
		}
		else
		{
			if (int(str[i]) < 91) str[i] = 64 + (move[i] - abs((int)str[i] - 90)) % 26;
			else str[i] = 96 + (move[i] - abs((int)str[i] - 122)) % 26;
		}
	}
	return str;
}

int main()
{
	cout << "apple with {0, 1, -1, 0, -1} to " << moveLetters("apple", { 0, 1, -1, 0, -1 }) << endl;
	cout <<"ApPlz with { -1, 1, -30, 0, 6} to "<< moveLetters("ApPlz", { -1, 1, -30, 0, 6}) << endl;
}