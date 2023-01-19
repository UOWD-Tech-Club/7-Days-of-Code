// 19.01.2023 - 8054757 - Matvei Maslov
// Question 1
#include <iostream>
#include <vector>
using namespace std;

vector<long long int> findPrimeNums(const vector<long long int>& arr)
{
	vector<long long int> newArr;
	for (int i = 0; i < arr.size(); ++i)
	{
		if (arr[i] == 2)
		{
			newArr.push_back(arr[i]);
			continue;
		}
		if (arr[i] % 2 == 0 || arr[i] == 1) continue;
		bool isPrime = true;
		for (long long int j = 3; j < arr[i]; j += 2)
		{
			if (arr[i] % j == 0)
			{
				//cout << arr[i] << '%' << j <<"==0"<< endl;
				isPrime = false;
				break;
			}
		}
		if (isPrime) newArr.push_back(arr[i]);
	}
	return newArr;
}

int main()
{
	int timeStart = time(NULL);
	vector<long long int> arr = { 1,2,3,4,5,6,7,62345,4047932051,78957486898967,9857502407 };
	cout << "Input elements: ";
	if (arr.size() == 0) return 0;
	cout << arr[0];
	for (int i = 1; i < arr.size(); ++i) cout << ", " << arr[i];
	cout << endl;
	vector<long long int> newArr=findPrimeNums(arr);
	cout << "Prime elements: ";
	if (newArr.size() == 0) return 0;
	cout << newArr[0];
	for (int i = 1; i < newArr.size(); ++i) cout <<", "<< newArr[i];
	cout << endl;
	cout << "Time spent: " << time(NULL) - timeStart << "sec" << endl;
	return 0;
}