#include <iostream>

using namespace std;

template <int i>
class D {
public:
   D(void*);
};

template <int A>
class factorial {
public:
	enum{ value = factorial<A-1>::value * A };
	enum{ debug = factorial<A>::value };
	void f(){
		D<factorial<A>::value> d = value ? 1 : 0;
	}
};

template <>
class factorial<0> {
public:
	enum { value = 1 };
	void f(){
		D<factorial<0>::value> d = value ? 1 : 0;
	}
};

template <int start, int end, int inc, bool keepgoing = true>
class FOR
{
public:
	static void f(){
		factorial<start> a;
		a.f();
		FOR<start+inc, end, inc,(start+inc < end) >::f();
		//b.f();
	}
};


template <int start, int end, int inc>
class FOR<start, end, inc, false>
{
	enum{go = 0};
	void f(){ }
};


int main()
{
	FOR<0, 10, 1> a;
	a.f();
  return 0;
}

