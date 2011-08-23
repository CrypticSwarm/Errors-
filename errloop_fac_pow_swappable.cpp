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

template <int base>
class POW2 {
public:
	enum { value = 1 };
	void f(){
		D<base*base> d = value ? 1:0; 
	}
};

/*
 * start
 * end
 * increment
 * loopiteration class
 * keepgoing -- used internally
 */
template <int S, int E, int I, template <int> class LI = factorial, bool K = true>
class FOR
{
public:
	FOR<S+I, E, I, LI, (S+I < E) > a;
	LI<S> b;
	void f(){
		a.f();
		b.f();
	}
};


template <int S, int E, int I, template <int> class LI>
class FOR<S,E,I,LI,false>
{
	enum{go = 0};
	void f(){ }
};



int main()
{
	FOR<0, 10, 1, POW2> a;
	a.f();

  return 0;
}

