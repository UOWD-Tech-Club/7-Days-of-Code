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
		cout << "Checking " << arr[i] << endl;
		if (arr[i] == 2)
		{
			newArr.push_back(arr[i]);
			continue;
		}
		if (arr[i] % 2 == 0)
		{
			cout << arr[i] << '%' << 2 << "==0" << endl;
			continue;
		}
		if (arr[i] == 1)
		{
			cout << "1 is not a prime number" << endl;
			continue;
		}
		if (arr[i] <= 0)
		{
			cout << "Prime numbers can't be less or equal than zero "<<arr[i]<<"<=0" << endl;
			continue;
		}
		bool isPrime = true;
		for (long long int j = 3; j < arr[i]; j += 2)
		{
			if (arr[i] % j == 0)
			{
				cout << arr[i] << '%' << j <<"==0"<< endl;
				isPrime = false;
				break;
			}
		}
		if (isPrime)
		{
			newArr.push_back(arr[i]);
			cout << arr[i] << " is a prime number" << endl;
		}
	}
	return newArr;
}

int main()
{
	int timeStart = time(NULL);
	vector<long long int> arr = { 1,2,3,4,5,6,7,62345,80111,-4047932051,78957486898967,63812239,389095717,314001091,806107103 ,806107109 };
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