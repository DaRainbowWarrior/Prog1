#include "std_lib_facilities.h"


struct Item 
{ 
	string name; 
 	int iid; 
 	double value; 
 	/* . . . */ 
};

template<typename C>
void write(C& c)
{
    for (auto p = c.begin();p != c.end(); ++p)
        cout << *p;
    cout << endl;
}

ostream& operator<<(ostream& os, Item& it)
{
    return os << it.name << " " << it.iid << " " << it.value << endl;
}

istream& operator>>(istream& is, Item& it)
{
    string ss;
    int ii;
    double dd;
    is >> ss >> ii >> dd;
    Item final_it {ss,ii,dd};
    it = final_it;
    return is;
}

int main()
{
	string item {"cucc.txt"};
    ifstream itemin {item};

	vector<Item> vi;
    for (Item it; itemin >> it; ) vi.push_back(it);


	string a,b;

    sort(vi.begin(), vi.end(),[](const Item& a, const Item& b){return a.name < b.name;}); //név szerint

    sort(vi.begin(), vi.end(),[](const Item& a, const Item& b){return a.iid < b.iid;}); //iid szerint

    sort(vi.begin(), vi.end(),[](const Item& a, const Item& b){return a.value > b.value;}); //value szerint, csökkenő sorrend


    Item horse {"horse shoe",99,12.34};
    Item canon {"Canon S400",9988,499.95};
    vi.insert(vi.end(),horse);
    vi.insert(vi.end(),canon);


    //erase by name
    vi.erase(find_if(vi.begin(),vi.end(),[](const Item& a){return a.name == "becsulet";}));
    vi.erase(find_if(vi.begin(),vi.end(),[](const Item& a){return a.name == "hotvilsz";}));

    //erase by iid
    vi.erase(find_if(vi.begin(),vi.end(),[](const Item& a){return a.iid == 2;}));
    vi.erase(find_if(vi.begin(),vi.end(),[](const Item& a){return a.iid == 444;}));

    write(vi);

    cout << endl;
    //part with list

    string iteml {"cucc.txt"};
    ifstream itemin2 {iteml};

	list<Item> li;
    for (Item it; itemin2 >> it; ) li.push_back(it);


	string a2,b2;

    li.sort([](const Item& a2, const Item& b2){return a2.name < b2.name;}); //név szerint

    li.sort([](const Item& a2, const Item& b2){return a2.iid < b2.iid;}); //iid szerint

    li.sort([](const Item& a2, const Item& b2){return a2.value > b2.value;}); //value szerint, csökkenő sorrend

    
    li.insert(li.end(),horse);
    li.insert(li.end(),canon);


    //erase by name
    list<Item>::iterator itr = find_if(li.begin(),li.end(),[](const Item& a2){return a2.name == "becsulet";});
    list<Item>::iterator itr2 = find_if(li.begin(),li.end(),[](const Item& a2){return a2.name == "hotvilsz";});

    li.erase(itr);
    li.erase(itr2);


    //erase by iid
    itr = find_if(li.begin(),li.end(),[](const Item& a2){return a2.iid == 2;});
    itr2 = find_if(li.begin(),li.end(),[](const Item& a2){return a2.iid == 444;});

    li.erase(itr);
    li.erase(itr2);
   
    write(li);
	return 0;
}