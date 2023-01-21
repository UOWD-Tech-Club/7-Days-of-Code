// 21.01.2023 - 8054757 - Matvei Maslov
// Question 1
#include <iostream>
#include <vector>
using namespace std;
/*
* Not the best sort method, but it stable. 
* Also it is quite complicated, so it is fun to write.
*/

class SplitedVector
{
public:
	vector<int>* arr;
	vector<int>* toCompareWith;
	SplitedVector* prev;
	SplitedVector()
	{
		arr = NULL;
		toCompareWith = NULL;
		prev = NULL;
	}
	SplitedVector(vector<int>* input, vector<int>* tocomparewith=NULL,SplitedVector* pre=NULL)
	{
		arr = input;
		toCompareWith = tocomparewith;
		prev = pre;
	}
	~SplitedVector()
	{
		arr = NULL;
		toCompareWith = NULL;
		prev = NULL;
	}
};

SplitedVector* splitArr(SplitedVector* array)
{
	if (array->arr->size() > 1)
	{
		int m = array->arr->size() / 2;
		vector<int>* arr1=new vector<int>, *arr2=new vector<int>;
		for (int i = 0; i <array->arr->size(); ++i)
		{
			if (i < m) arr1->push_back(array->arr->data()[i]);
			else arr2->push_back(array->arr->data()[i]);
		}
		splitArr(new SplitedVector(arr1,NULL,array));
		splitArr(new SplitedVector(arr2,arr1,array));
	}
	if (!array->prev) return array;
	if (array->toCompareWith)
	{
		int i = 0;
		int j = 0;
		int currPrevPos = 0;
		vector<int>* prev = array->prev->arr;
		vector<int>* arr1 = array->arr;
		vector<int>* arr2 = array->toCompareWith;
		while (j != arr2->size() && i != arr1->size())
		{
			if (arr1->data()[i] > arr2->data()[j]) prev->data()[currPrevPos++] = arr2->data()[j++];
			else prev->data()[currPrevPos++] = arr1->data()[i++];
		}
		while (i != arr1->size()) prev->data()[currPrevPos++] = arr1->data()[i++];
		while (j !=arr2->size()) prev->data()[currPrevPos++] = arr2->data()[j++];
	}
}

vector<int>* mergeSort(vector<int>* arr)
{
	return splitArr(new SplitedVector(arr))->arr;
}

int main()
{
	srand(time(NULL));
	int size = 1000000;//set amount of randoms
	vector<int> arr;
	arr.push_back(rand());
	cout << " Input: " << arr[0];
	bool printValues = true;
	for (int i = 1; i < size-1; ++i)
	{
		arr.push_back(rand());
		if (printValues) cout << ", " << arr[i];
		if (i == 199)
		{
			cout << "...";
			printValues = false;
		}
	}
	cout << endl;
	size_t timeStart = time(NULL);
	mergeSort(&arr);
	size_t timeEnd = time(NULL) - timeStart;
	cout << "Output: " << arr[0];
	printValues = true;
	for (int i = 1; i < arr.size(); ++i)
	{
		if (printValues) cout << ", " << arr[i];
		if (i == 199)
		{
			cout << "...";
			printValues = false;
		}
		if (arr[i - 1] > arr[i])
		{
			cout <<' '<<arr[i - 1] << '>' << arr[i] << " FAIL!" << endl;
			break;
		}
	}
	cout << endl<<"Time spent: "<<timeEnd<<"sec"<<endl;
	return 0;
}