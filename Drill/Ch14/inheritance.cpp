#include <iostream>
#include <string>

using namespace std;

struct B1 {
	virtual void vf() { cout <<"B1::vf\n"; }
	void f() {cout << "B1::f\n";}
	virtual void pvf()=0;
};

struct D1 : B1 {
	void vf() override { cout <<"D1::vf\n"; }
	void f() {cout << "D1::f\n";}
};

struct D2 : D1{

	void pvf() override {cout << "D2::pvf\n";}
};

struct B2
{
	virtual void pvf()=0;
};

struct D21 : B2 {
	string s="libling";
	void pvf() override {cout << s << endl;}
};

struct D22 : B2 {

	int i =17;
	void pvf() override {cout << i << endl;}

};

void f(B2& b)
{
	b.pvf();
}


int main()
{
	

	

	
	//B1 b1;
	/*cout << "B1 b1 object:" << endl;

	b1.vf();
	b1.f();


	D1 d1;
	cout << "D1 d1 object: " << endl;

	d1.vf();
	d1.f();

	cout << "B1& d1 object: " << endl;

	B1& b1ref=d1;
	b1ref.vf();
	b1ref.f();*/

	D2 d2;
	
	cout << "D2 d2 object" << endl;
	d2.vf();
	d2.f();
	d2.pvf();

	D21 d21;
	
	cout <<"D21 d21 object: " << endl;
	f(d21);

	D22 d22;
	
	cout <<"D22 d22 object: " << endl;
	f(d22); 
}