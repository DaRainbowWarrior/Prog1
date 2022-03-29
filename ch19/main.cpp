#include "std_lib_facilities.h"

template<typename T> 
struct S 
{ 
	S():val(T()){};
	S(T s):val(s){};

	T& get();
	const T& get() const;

	void set(const T& newv);

	T& operator = (const T&);

	void read_val(T& v);


private:
		T val; 
};

template<typename T> T& S<T>::get() { return val; };

template<typename T> const T& S<T>::get() const{ return val; }

template<typename T> void S<T>::set(const T& newv) { val = newv; };

template<typename T> void read_val(T& v) { cin >> v; };

int main()
{
	S<int> s1 {37};
	S<char> s2 {'b'};
	S<double> s3 {3.4845};
	S<string> s4 {"gislutyuly"};
	vector<int> vect {4,2};
	S<vector<int>> s5 {vect};

	/*cout << s1.val << endl;
	cout << s2.val << endl;
	cout << s3.val << endl;
	cout << s4.val << endl;
	for(int i=0;i<s5.val.size(); i++)
		cout << s5.val[i] << " ";
	cout << endl;*/

	/*cout << s1.get() << endl;
	cout << s2.get() << endl;
	cout << s3.get() << endl;
	cout << s4.get() << endl;
	for(int i=0;i<s5.get().size(); i++)
		cout << s5.get()[i] << " ";
	cout << endl;*/

	/*s2.set('x');
	cout << s2.get() << endl;*/

	int s1n;
	char s2n;
	double s3n;
	string s4n;

	read_val(s1n);
	s1.set(s1n);
	read_val(s2n);
	s2.set(s2n);
	read_val(s3n);
	s3.set(s3n);
	read_val(s4n);
	s4.set(s4n);

	cout << endl;

	cout << s1.get() << endl;
	cout << s2.get() << endl;
	cout << s3.get() << endl;
	cout << s4.get() << endl;



	return 0;
}