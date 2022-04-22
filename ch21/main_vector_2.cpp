#include "std_lib_facilities.h"

using namespace std;

int main()
{
	string item {"cucc2.txt"};
    ifstream itemin {item};

	vector<double> vd;
    for (double it; itemin >> it; ) vd.push_back(it);


    vector<int> vi (vd.size());
	copy(vd.begin(),vd.end(),vi.begin());


	for (int i = 0; i <  vd.size(); ++i)
    	cout << "(" << vd[i] << " , " << vi[i] << ")" << endl;


    double sum1 = accumulate(vd.begin(),vd.end(),0.0);

    cout << "sum of vd: " << sum1 << endl;

    int sum2 = accumulate(vi.begin(),vi.end(),0);


    cout << "difference between vd and vi: " <<sum1-sum2 << endl;


    reverse(vd.begin(),vd.end());
    for(auto& n : vd)
    	cout << n << endl;


    double mean = sum1 / vd.size();
    cout << "mean value of vd values: " << mean << endl;


    vector<double> vd2;

    for(int i=0;i<vd.size();i++)
    	if(vd[i]<mean)
    		vd2.push_back(vd[i]);


    sort(vd.begin(),vd.end());
    for(auto& n : vd)
    	cout << n << endl;
    
	return 0;
}