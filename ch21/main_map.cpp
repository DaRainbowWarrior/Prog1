#include "std_lib_facilities.h"

using namespace std;

template <typename T, typename C>
void write(const map<T, C>& map)
{
    for(const auto& p : map)
        cout << p.first << " " << p.second << endl;
    cout << endl;
}

void mapread(map<string, int>& map)
{
    string text;
    int number;
    cin >> text >> number;
    map.insert(pair<string, int>(text, number));
}

int main()
{
	map<string,int> msi;

	msi["lecture"] = 21;
    msi["cucc"] = 50;
    msi["masikcucc"] = 60;
    msi["macska"] = 23;
    msi["kutya"] = 77;
    msi["gorilla"] = 33;
    msi["adhd"] = 99;
    msi["mader"] = 32;
    msi["god"] = 42;
    msi["utolso"] = 01;

    write(msi);

    /*
    msi.erase(msi.begin(),msi.end());
    cout << "erased." << endl;

    for (int i = 0; i < 10; i++)
    {
    	mapread(msi);
    }
    cout << endl;

    write(msi);
    */

    int sum = accumulate(msi.begin(),msi.end(),0,[](auto prev_sum, auto &msi_entry){return prev_sum + msi_entry.second;});
    cout << sum << endl;

    map<int,string> mis;

    for(auto& mapentry: msi)
        mis[mapentry.second] = mapentry.first;

    write(mis);

	return 0;
}