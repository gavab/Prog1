#include "std_lib_facilities.h"



void write_msi(map<string,int>& m)
{

	string s;
	int i;

	while(m.size()<10)
	{
		cin>>s>>i;
		
		m.insert(make_pair(s,i));

	}
}


int main()
{
	map<string,int> msi;

	msi["lecture"]=21;
	msi["Bob Ross"]=34;
	msi["Szecsei"]=99;
	msi["Barcelona"]=1;
	msi["Jump king"]=100;
	msi["PS5"]=10;
	msi["NBER"]=3;
	msi["Sió"]=40;
	msi["dansz"]=22;
	msi["Hé vakcina,Müller Cecila"]=11;

	for(const auto& e:msi)
		cout<<e.first<<": "<<e.second<<endl;


	msi.erase(msi.begin(),msi.end());

	write_msi(msi);

	for(const auto& e:msi)
		cout<<e.first<<": "<<e.second<<endl;

	int sum=0;

	for(const auto& e:msi)
	{
		sum+=e.second;
	}

	
	cout<<sum<<endl;

	map<int,string> mis;

	for(const auto& e:msi)
	{
		mis[e.second]=e.first;
	}

	for(const auto& e:mis)
		cout<<e.first<<": "<<e.second<<endl;


	return 0;
}

/*
bence 21 
nóri 20 
teto 3 
geza 15
ps5 30
barca 1
zsuzsi 4
glorious 10
dios 12
dafaq 23
*/