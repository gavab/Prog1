#include <iostream>

template<typename Elem>
struct Link{
	Link(const Elem& v=Elem(),Link* p=0,Link* s=0)
		:prev(p),succ(s),val(v) {}


	Link* prev; //previous link
	Link* succ; //successor (next) link
	Elem val; //the value

};

template<typename Elem>
class my_list{
	//represerarion and implementation details
public:
	Link<Elem>* first;
	Link<Elem>* last; //one beyond the last link

	my_list(): first(new Link<Elem>()), last(first) {}

	~my_list()
	{
		while(first !=0){
			auto p= first->succ;
			delete first;
			first=p;
		}
	}

	class iterator;		//member type: iterator

	iterator begin() {return iterator(first);}	//iterator first element
	iterator end()	{return iterator(last);}	//iterator last element

	iterator insert(iterator p,const Elem& v);	//insert v into list after p
	iterator erase(iterator p);					//remove p from the list

	void push_back(const Elem& v);		//insert v at end
	void push_front(const Elem& v);		//insert v at front
	void pop_front();		//remove first element
	void pop_back();		//remove last element

	Elem& front() {return *first;}			//the first element
	Elem& back() {return *last;}			//the last element

};

template<typename Elem> //requires Element<Elem>()
class my_list<Elem>::iterator{
	Link<Elem>* curr;		//current link
public:
	iterator(Link<Elem>* p):curr{p} {}

	iterator& operator++(){curr=curr->succ;return *this;} //forward
	iterator& operator--(){curr=curr->prev;return *this;} //backward
	Elem& operator*() {return curr->val;} //get value (dereference)

	bool operator==(const iterator& b) const {return curr==b.curr;}
	bool operator!=(const iterator& b) const {return curr!=b.curr;}
};

template<typename Elem>
void my_list<Elem>::push_front(const Elem& v)
{
	first = new Link<Elem>(v,0,first);
}

template<typename Iterator> //requires Input_iterator<Iter>()
Iterator high(Iterator first,Iterator last)
	//return an iterator to the element in[first,last] that has the highest value
{
	Iterator high=first;
	for(Iterator p = first; p!=last; ++p)
		if(*high<*p) high = p;
	return high;
}

void f()
{
	my_list<int> ml;for(int x;std::cin>>x;)ml.push_front(x);

	my_list<int>::iterator p=high(ml.begin(),ml.end());
	if(p==ml.end())	//did we reach the end?
		std::cout<<"The list is empty";
	else
		std::cout<<"The highest value is "<< *p <<'\n';
}


int main()
{

	f();

	return 0;
}