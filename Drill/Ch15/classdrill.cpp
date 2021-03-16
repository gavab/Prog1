#include "std_lib_facilities.h"

struct Person
{
	Person() {};
	Person(string fn,string ln, int a):first_name(fn),last_name(ln),age(a)
	{
		if(!valid_age()) error("Invalid age!");

		if(!valid_name()) error("Invalid name!");
	}
	
	bool valid_age();
	bool valid_name();
	bool end_cin();

	string get_fname() const {return first_name;}
	string get_lname() const {return last_name;}
	int get_age() const {return age;}

private:
	string first_name;
	string last_name;
	int age;
};


bool Person::valid_age()
{
	if(0>age || 150<age)
		return false;

	return true;
}

bool Person::valid_name()
{
	string wholename=first_name+last_name;
	for(char c: wholename)
	{
		if(!isalpha(c))
			return false;
	}
	return true;
}


ostream& operator<<(ostream& os,Person& p)
{
	return os <<p.get_fname()<<' '<<p.get_lname()<<' '<<p.get_age();
}

istream& operator>>(istream& is,Person& p)
{
	string f;
	string l;
	int a;

	is >> f >> l >> a;

	if(!is) return is;

	p=Person{f,l,a};
	return is;
}

int main()
{
	Person test{"Goofy","Tetya",63};

	cout<<"Person: "<<test.get_fname()<<' '<<test.get_lname()<<' '<<test.get_age()<<endl;


	vector<Person> person_v;

	cout <<"Enter names and ages. To stop enter quit!"<< endl;

	Person p;
	
	while(cin>>p)
	{
		person_v.push_back(p);
	}

	cout << "Person vector: " <<endl;

	for(Person p : person_v)
		cout << p << '\n';

	return 0;
}