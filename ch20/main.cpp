#include "std_lib_facilities.h"

template<typename Iter1, typename Iter2>
	// requires Input_iterator<Iter1>() && Output_iterator<Iter2>()
Iter2 mycopy(Iter1 f1, Iter1 e1, Iter2 f2)
{
	for (; f1 != e1; f1 ++) 
	{
        *f2 = *f1;
        f2++;
    }
    	return f2;
}

int main()
{
	int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	vector<int> v1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	list <int> ls1 = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

	int array2[10];
	for(int i=0; i<10;i++)
	{
		array[i] = array2[i];
		//cout << array2[i] << " ";
	}
	vector<int> v2 = v1;
	list <int> ls2 = ls1;

	for(int i=0; i<10;i++)
	{
		array[i]=array[i]+2;
		v1[i]=v1[i]+3;
		ls1.push_back(i+5);
	}

	mycopy(array, array+10, v1.begin());
	mycopy(ls1.begin(),ls1.end(),array);

	if(find(v1.begin(),v1.end(), 3) != v1.end())
	{
		for(int i=0;i<10;i++)
			if(v1[i] == 3)
				cout << i << endl;
	}
	else
		cout << "3 not found" << endl;

	if(find(ls1.begin(),ls1.end(), 27) != ls1.end())
	{
		int szam = 0;
		for(int i:ls1)
			{
				if(i == 27)
					cout << szam << endl;
				szam++;
			}

	}
	else
		cout << "27 not found" << endl;
	return 0;
}