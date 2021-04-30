#include "std_lib_facilities.h"

template<typename In,typename Out>
	//requires Input_iterator<In> && Output_iterator<Out> ()
Out my_copy(In first,In last,Out res)
{
	while(first!=last)
	{	
		*res=*first; //copy element

		++res;
		++first;
	}
	return res;
}

int main()
{
 	const int size=10;

	array<int,size> tomb={0,1,2,3,4,5,6,7,8,9};

	vector<int> vi(size);
	vi={0,1,2,3,4,5,6,7,8,9};

	list<int> li(size);
	li={0,1,2,3,4,5,6,7,8,9};

	array<int,size> tomb2=tomb;


	for(int i=0;i<size;++i)
	{
		tomb2[i]=tomb2[i]+2;
	}

	
	vector<int> vi2=vi;

	for(int i=0;i<vi2.size();++i)
	{
		vi2[i]=vi2[i]+3;
	}


	list<int> li2=li;

	for(auto& l:li2)
		l+=5;


	vector<int> vi3(size);
	my_copy(tomb2.begin(),tomb2.end(),vi3.begin());

	array<int,size> tomb3;
	my_copy(li2.begin(),li2.end(),tomb3.begin());


	auto pv=find(vi2.begin(),vi2.end(),3);

	if(pv!=vi2.end())
		cout<<"vi2 contain 3 at:"<<distance(vi2.begin(),pv)<<endl;
	else
		cout<<"vi2 does not contain 3"<<endl;
	
	

	auto pl=find(li2.begin(),li2.end(),27);

	if(pl!=li2.end())
		cout<<"li2 contain 27 at: "<<distance(li2.begin(),pl)<<endl;
	else
		cout<<"li2 does not contain 27"<<endl;
	

	return 0;
}