#include "std_lib_facilities.h"

class Smaller_than{
	double v;

public:
	Smaller_than(double vv):v(vv){}
	bool operator()(double x) const {return x<v;}

};


int main()
{
	string iname="numbers.txt";

	ifstream ist {iname};

	if(!ist) error("Can't open file",iname);

	vector<double> vd;

	double num;

	while(ist>>num)
	{
		vd.push_back(num);

	}

	vector<int> vi(vd.size());

	copy(vd.begin(),vd.end(),vi.begin());

	for(int i=0;i<vd.size();++i)
	{
		cout<<vd[i]<<'\t'<<vi[i]<<endl;
	}

	double sum=0;

	for(int i=0;i<vd.size();++i)
	{
		sum+=vd[i];
	}

	cout <<sum<<endl;

	reverse(vd.begin(),vd.end());

	cout<<"Reverse vd: "<<endl;

	for(auto r:vd)
		cout<<r<<endl;

	double avg=sum/vd.size();

	cout <<"Mean value: "<<avg<<endl;

	vector<double> vd2(vd.size());

	/*for(int i=0;i<vd.size();++i)
	{
		if(vd[i]<avg)
		{
			vd2.push_back(vd[i]);
		}
	}*/

	auto diff= copy_if(vd.begin(),vd.end(),vd2.begin(),Smaller_than(avg));

	vd2.resize(distance(vd2.begin(),diff));

	cout<<"vd2 vector"<<endl;

	for(auto s:vd2)
		cout<<s<<endl;

	sort(vd.begin(),vd.end());
		
	cout<<"Sort vd:"<<endl;

	for(auto s:vd)
		cout<<s<<endl;


	return 0;
}