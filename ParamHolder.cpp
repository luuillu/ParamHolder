#include "ParamHolder.h"

#define TDC_TO_STRING_(...) #__VA_ARGS__
#define TDC_TO_STRING(x) "expand [ "#x" ]is:[" TDC_TO_STRING_(x)"]"

class Test{
public:
	int f(const volatile  char c){
		std::cout<<"this is f, c="<<c<<std::endl;
		return 100;
	}


	void g(int *p){
		std::cout<<"this is g, p="<<p<<std::endl;
	}

	void static Sf(void* s){
		std::cout<<"this is s, s="<<s<<std::endl;
	}
};

template <typename U>
struct RemoveReference
{
	typedef U TYPE;
	enum {V=1};
};

template <typename U>
struct RemoveReference<U&>
{
	typedef U TYPE;
	enum {V=2};
};

template <typename U>
struct ISV{
	enum {V=1};
	typedef U TYPE;
};
template <typename U>
struct ISV<volatile U>
{
	typedef U TYPE;
	enum {V=2};
};

template <typename U>
struct ISV<U&>
{typedef U TYPE;
	enum {V=3};
};

template <typename U>
struct ISV<volatile U&>
{typedef U TYPE;
	enum {V=4};
};

template <typename U>
struct ISV<const volatile U&>
{typedef U TYPE;
	enum {V=5};
};

template <typename U>
struct ISV<const volatile U>
{typedef U TYPE;
	enum {V=6};
};

template<typename PFUNC> class ParamHolderImpl2;

template<typename C, typename RET,
		typename Class_1> class ParamHolderImpl2<RET (C::*)(volatile Class_1)> {
public:

	typedef RET (C::*FUNCTION_TYPE)(Class_1);
	typedef RET RETURN_TYPE;
	typedef C CLASS_TYPE;
	typedef volatile Class_1 TYPE;

};


template<typename T, template<typename> class Base>
class TA;

template<typename T, template<typename> class Base>
class TA<T*, Base>:Base<T*>{};

template<typename T>
	struct  A{
		enum{V=1};
	};
template<typename C>
struct A<void (C::*)()>{
	enum{V=2};
	};




//class C:public A<C> {
//public:
//public: C(){}
//
//};

void testDes()
{
	typedef void(*PF)();
	std::cout<<"testDes is V="<<A<PF>::V<<std::endl;
	//delete pB;
	//delete pB;
	//C *pC = new C();
	//delete pB;
}
int main(int argc, char **argv) {
	testDes();

#define RESULT TDC_TO_STRING(PH_PARAM_HOLDER_N(2, PH_IS_MEMBER_FUNCION))
//#define RESULT TDC_TO_STRING(TDC_GENERATE_COLON(0))
#pragma message(RESULT)
	const volatile char chv = 's';
	const volatile char& ch = chv;
	typedef int (Test::*PF)(const volatile  char c);
	typedef const volatile char PI;
	typedef ParamHolderImpl2<PF>::TYPE TYPE;
	//TYPE ch = chv;
	std::cout<<"this is f, V="<<ISV<TYPE>::V<<std::endl;


	ParamHolder<PF>::Reference pFHolder(ch);
	Test test;

	int ret = -1;
	//ret = pFHolder.invoke(&test, &Test::f);
	ret = test.f(ch);
	std::cout<<"this is f, ret="<<ret<<std::endl;

	ret = -1;

	typedef void (Test::*PG)(int *p);
	ParamHolder<PG>::Reference pGHolder(&ret);
	pGHolder.invoke(&test, &Test::g);

	typedef void (*PSF)(void *p);

	ParamHolder<PSF>::Value pSfHolder0(0);

	ParamHolder<PSF>::Value* pSfHolder = new ParamHolder<PSF>::Value(0);

	pSfHolder->invoke(&Test::Sf);

	//delete pSfHolder;
	//pSfHolder->free(pSfHolder);

	return 0;
}
