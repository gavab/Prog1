#include "std_lib_facilities.h"

template<typename T>
struct S { 
private:	
	T val;
public: 
	S() {}
	S(T hv): val(hv) {}

	S& operator=(const T&);

	T& get();
	const T& get() const;
	

};

template<typename T>
 T& S<T>::get()
{
	return val;
}

template<typename T> 
const T& S<T>::get() const
{
	return val;
}

template<typename T>
S<T>& S<T>::operator=(const T& s)
{
	val=s;
	return *this;
}

template<typename T> 
void read_val(T& v)
{
	cin >> v;	
}


int main()
{

	S<int> favnum;
	S<char> kar;
	S<double> tort; 
	S<string> szoveg {"dansz"};
	S<vector<int>> vi {vector<int>{12,13,14}};
	
	favnum=17;
	kar='!';
	tort=3.14;
	
	cout << favnum.get()<<endl;
	cout << kar.get()<<endl;
	cout << tort.get()<<endl;
	cout << szoveg.get()<<endl;

	
	for(int i=0;i<vi.get().size();++i)
		cout<<vi.get()[i]<<endl;


	cout << "Read variable(int): " <<endl;

	int rnum;
	read_val(rnum);
	S<int> rn {rnum};
	cout <<rn.get()<<endl;

	cout << "Read variable(char): " <<endl;

	char rkar;
	read_val(rkar);
	S<char> rk {rkar};
	cout <<rk.get()<<endl;

	cout << "Read variable(string): " <<endl;

	string rszov;
	read_val(rszov);
	S<string> rs {rszov};
	cout <<rs.get()<<endl;

	return 0;
}
