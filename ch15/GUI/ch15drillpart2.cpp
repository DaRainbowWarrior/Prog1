#include "std_lib_facilities.h"

struct Person
{
	Person(){};
	Person(string fname, string lname, int n) : fname(fname), lname(lname), age{n} 
	{
		if((age < 0)||(age > 150))
			error("Invalid age");
		for(auto i : fname)
			if(!isalpha(i))
				error("Character not allowed");
		for(auto i : lname)
			if(!isalpha(i))
				error("Character not allowed");
	}

	string get_fname() const {return fname;}
	string get_lname() const {return lname;}
	int get_age() const {return age;}

private:
	string fname; string lname;
	int age;
};

istream& operator>>(istream& is, Person& p)
{
	string fname; string lname;
	int age;

	is >> fname >> lname >> age;
	p = Person(fname,lname,age);
	return is;
}

ostream& operator<<(ostream& os, Person& p)
{
	return os << p.get_fname() << " " << p.get_lname() << " " << p.get_age() << endl;
}

vector<Person> pepol;

int main()
{
	/*Person p ("Goofy","", 63);
	cout << p;*/

	cout << "Add people by typing a first and last name, and an age separated by spaces, then press enter.\n";
	cout << "To exit, type exit followed by a random string and number, also separated by spaces and press enter.\n";

	for(Person p; cin >> p;)
	{
		if(p.get_fname()=="exit")
			break;
		pepol.push_back(p);
	}

	cout << "\nData entry complete\nEntered data:\n";

	for(auto i : pepol)
	{ cout << i; }

	/*cin >> p;
	cout << p;*/

	return 0;
}