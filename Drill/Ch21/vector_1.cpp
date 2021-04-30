#include "std_lib_facilities.h"

struct Item
{
	string name;
	int iid;
	double value;
	/*  */
};


struct Compare_by_name{
	bool operator()(const Item& a, const Item& b) const
		{return a.name < b.name;}

};


struct Compare_by_iid{
	bool operator()(const Item& a, const Item& b) const
		{return a.iid < b.iid;}

};


struct Compare_by_value{
	bool operator()(const Item& a, const Item& b) const
		{return a.value > b.value;}

};

class Cheaper_than{
	double v;
public:
	Cheaper_than(double vv):v(vv) {}
	bool operator()(const Item& x) const {return x.value<v;}

};

class Nev_hasonltas{
	string n;
public:
	Nev_hasonltas(string nn):n(nn) {}
	bool operator()(const Item& nev) const {return nev.name==n;}

};


class Iid_hasonltas{
	int i;
public:
	Iid_hasonltas(int ii):i(ii) {}
	bool operator()(const Item& id) const {return id.iid==i;}

};



int main()
{
	string iname="items.txt";

	ifstream ist {iname};

	if(!ist) error("Can't open file",iname);

	vector<Item> vi;

	string name;
	int iid;
	double value;

	list<Item> li;

	while(ist >> name >> iid >> value)
	{
		Item test;
		test.name=name;
		test.iid=iid;
		test.value=value;

		vi.push_back(test);

		li.push_back(test);
	}

	
	// Vector

	Item cipo{"horse shoe",99,12.34};

	vi.push_back(cipo);

	Item kamera{"Canon S400",9988,499.99};

	vi.push_back(kamera);

	cout << "(Vector) Before sort:"<<endl;

	for(const auto& i : vi)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;

	cout<<endl; 

	cout << "After sort by name:"<<endl;

	sort(vi.begin(),vi.end(),Compare_by_name());

	for(const auto& i : vi)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;

	cout<<endl;

	cout << "After sort by iid:"<<endl;

	sort(vi.begin(),vi.end(),Compare_by_iid());

	for(const auto& i : vi)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;


	cout<<endl;

	cout << "After sort by value:"<<endl;

	sort(vi.begin(),vi.end(),Compare_by_value());

	for(const auto& i : vi)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;


	cout <<endl;

	cout << "After erase:"<<endl;

	vi.erase(find_if(vi.begin(),vi.end(),Nev_hasonltas("PS5")));
	vi.erase(find_if(vi.begin(),vi.end(),Nev_hasonltas("Tesla")));

	vi.erase(find_if(vi.begin(),vi.end(),Iid_hasonltas(78)));
	vi.erase(find_if(vi.begin(),vi.end(),Iid_hasonltas(55)));


	for(const auto& i : vi)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;


	//List

	cout << endl;

	li.push_back(cipo);

	li.push_back(kamera);


	cout << "(List) Before sort:" << endl;

	for(auto l:li)
		cout<<l.name<<' '<<l.iid<<' '<<l.value<<endl;

	cout<<endl; 

	cout << "After sort by name:"<<endl;

	li.sort([](const Item& a,const Item& b){return a.name<b.name;});

	for(const auto& i : li)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;

	cout<<endl;

	cout << "After sort by iid:"<<endl;

	li.sort([](const Item& a,const Item& b){return a.iid < b.iid;});

	for(const auto& i : li)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;


	cout<<endl;

	cout << "After sort by value:"<<endl;

	li.sort([](const Item& a,const Item& b){return a.value>b.value;});

	for(const auto& i : li)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;


	cout <<endl;

	cout << "After erase:"<<endl;

	li.erase(find_if(li.begin(),li.end(),Nev_hasonltas("PS5")));
	li.erase(find_if(li.begin(),li.end(),Nev_hasonltas("Tesla")));

	li.erase(find_if(li.begin(),li.end(),Iid_hasonltas(78)));
	li.erase(find_if(li.begin(),li.end(),Iid_hasonltas(55)));

	for(const auto& i : li)
		cout << i.name <<' '<< i.iid<<' '<< i.value << ' ' << endl;



	return 0;
}