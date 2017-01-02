#pragma once
#include <iostream>

template<typename PFUNC, template<typename> class Base> class ParamHolderImpl;

#define PH_FOR_EACH_0(f)
#define PH_FOR_EACH_1(f) f(1)
#define PH_FOR_EACH_2(f) PH_FOR_EACH_1(f) f(2)
#define PH_FOR_EACH_3(f) PH_FOR_EACH_2(f) f(3)
#define PH_FOR_EACH_4(f) PH_FOR_EACH_3(f) f(4)
#define PH_FOR_EACH_5(f) PH_FOR_EACH_4(f) f(5)
#define PH_FOR_EACH_6(f) PH_FOR_EACH_5(f) f(6)
#define PH_FOR_EACH_7(f) PH_FOR_EACH_6(f) f(7)
#define PH_FOR_EACH_8(f) PH_FOR_EACH_7(f) f(8)
#define PH_FOR_EACH_9(f) PH_FOR_EACH_8(f) f(9)
#define PH_FOR_EACH_10(f) PH_FOR_EACH_9(f) f(10)
#define PH_FOR_EACH_11(f) PH_FOR_EACH_10(f) f(11)
#define PH_FOR_EACH_12(f) PH_FOR_EACH_11(f) f(12)
#define PH_FOR_EACH_13(f) PH_FOR_EACH_12(f) f(13)
#define PH_FOR_EACH_14(f) PH_FOR_EACH_13(f) f(14)
#define PH_FOR_EACH_15(f) PH_FOR_EACH_14(f) f(15)
#define PH_FOR_EACH_16(f) PH_FOR_EACH_15(f) f(16)
#define PH_FOR_EACH_17(f) PH_FOR_EACH_16(f) f(17)
#define PH_FOR_EACH_18(f) PH_FOR_EACH_17(f) f(18)
#define PH_FOR_EACH_19(f) PH_FOR_EACH_18(f) f(19)
#define PH_FOR_EACH_20(f) PH_FOR_EACH_19(f) f(20)
#define PH_FOR_EACH_21(f) PH_FOR_EACH_20(f) f(21)
#define PH_FOR_EACH_22(f) PH_FOR_EACH_21(f) f(22)
#define PH_FOR_EACH_23(f) PH_FOR_EACH_22(f) f(23)
#define PH_FOR_EACH_24(f) PH_FOR_EACH_23(f) f(24)
#define PH_FOR_EACH_25(f) PH_FOR_EACH_24(f) f(25)
#define PH_FOR_EACH_26(f) PH_FOR_EACH_25(f) f(26)
#define PH_FOR_EACH_27(f) PH_FOR_EACH_26(f) f(27)
#define PH_FOR_EACH_28(f) PH_FOR_EACH_27(f) f(28)
#define PH_FOR_EACH_29(f) PH_FOR_EACH_28(f) f(29)
#define PH_FOR_EACH_30(f) PH_FOR_EACH_29(f) f(30)
#define PH_FOR_EACH_31(f) PH_FOR_EACH_30(f) f(31)
//#define PH_DEFINE_ALL(f, ...) f(0, __VA_ARGS__)
#define PH_DEFINE_ALL(f, ...) f(0, __VA_ARGS__) f(1, __VA_ARGS__) f(2, __VA_ARGS__) f(3, __VA_ARGS__) f(4, __VA_ARGS__) f(5, __VA_ARGS__)\
		f(6, __VA_ARGS__) f(7, __VA_ARGS__) f(8, __VA_ARGS__) f(9, __VA_ARGS__) f(10, __VA_ARGS__) f(11, __VA_ARGS__)\
		f(12, __VA_ARGS__) f(13, __VA_ARGS__) f(14, __VA_ARGS__) f(15, __VA_ARGS__) f(16, __VA_ARGS__) f(17, __VA_ARGS__)\
		f(18, __VA_ARGS__) f(19, __VA_ARGS__) f(20, __VA_ARGS__) f(21, __VA_ARGS__) f(22, __VA_ARGS__) f(23, __VA_ARGS__) f(24, __VA_ARGS__) \
		f(25, __VA_ARGS__) f(26, __VA_ARGS__) f(27, __VA_ARGS__) f(28, __VA_ARGS__) f(29, __VA_ARGS__) f(30, __VA_ARGS__) f(31, __VA_ARGS__)

#define PH_CONNECT_N_(f, n) f##n
#define PH_CONNECT_N(f, n) PH_CONNECT_N_(f, n)

#define PH_CALL_FUNCTION(f, ...)  f(__VA_ARGS__)
#define PH_CALL_F_N(f, n, ...) PH_CALL_FUNCTION(PH_CONNECT_N(f, n), __VA_ARGS__)
#define PH_FOR_EACH_N(f, n) PH_CALL_F_N(PH_FOR_EACH_, n, f)

#define PH_REMOVE_FIRST_PARAM_(x, ...)  __VA_ARGS__
#define PH_REMOVE_FIRST_PARAM(...) PH_REMOVE_FIRST_PARAM_(__VA_ARGS__)

#define PH_TYPE_NAME(i) Class_##i
#define PH_TYPE_NAME_(i) ,PH_TYPE_NAME(i)
#define PH_TYPE_NAME_N(n) PH_REMOVE_FIRST_PARAM(PH_FOR_EACH_N(PH_TYPE_NAME_, n))

#define PH_TEMPLATE_TYPE_NAME(i) ,typename PH_TYPE_NAME(i)
#define PH_TEMPLATE_TYPE_NAME_N(n) PH_FOR_EACH_N(PH_TEMPLATE_TYPE_NAME, n)

#define PH_PARAM_NAME(i) param_##i
#define PH_PARAM_NAME_(i) ,PH_PARAM_NAME(i)
#define PH_COMMA_PARAM_NAME_N(n) PH_FOR_EACH_N(PH_PARAM_NAME_, n)
#define PH_PARAM_NAME_N(n) PH_REMOVE_FIRST_PARAM(PH_COMMA_PARAM_NAME_N(n))

#define PH_FUNCTION_PARAM(i) , PH_TYPE_NAME(i) PH_PARAM_NAME(i)
#define PH_FUNCTION_PARAM_N(n)	PH_FOR_EACH_N(PH_FUNCTION_PARAM, n)

#define PH_CLASS_MEMBER_DEFINE(i) typename BASE_TYPE::template Trait<PH_TYPE_NAME(i)>::TYPE PH_PARAM_NAME(i);
#define PH_CLASS_MEMBER_DEFINE_N(n) PH_FOR_EACH_N(PH_CLASS_MEMBER_DEFINE, n)

//#define PH_GET_FIRST_PARAM_(x, ...) x
//#define PH_GET_FIRST_PARAM(...) PH_GET_FIRST_PARAM_(__VA_ARGS__)
//#define PH_GENERATE_COLON_N(n) :,
//#define PH_GENERATE_COLON(n) PH_GET_FIRST_PARAM(PH_FOR_EACH_N(PH_GENERATE_COLON_N, n))

#define PH_CONSTRUCT_INIT_PARAM(i) ,PH_PARAM_NAME(i)(PH_PARAM_NAME(i))
#define PH_CONSTRUCT_INIT_PARAM_N(n) PH_FOR_EACH_N(PH_CONSTRUCT_INIT_PARAM, n)

#define PH_TRUE(...) __VA_ARGS__
#define PH_FALSE(...)

#define PH_PARAM_HOLDER_N(n, isMember)\
template<isMember(typename C,) typename RET PH_TEMPLATE_TYPE_NAME_N(n), template<typename> class Base>\
class ParamHolderImpl< RET (isMember(C::)*) (PH_TYPE_NAME_N(n)), Base>: public Base<ParamHolderImpl< RET (isMember(C::)*) (PH_TYPE_NAME_N(n)), Base> >\
{\
	typedef RET (isMember(C::)*FUNCTION_TYPE) (PH_TYPE_NAME_N(n));\
	typedef RET RETURN_TYPE;\
	isMember(typedef C CLASS_TYPE;)\
	typedef Base<ParamHolderImpl<FUNCTION_TYPE, Base> > BASE_TYPE;\
public:\
	ParamHolderImpl(isMember(C* pInstance,) FUNCTION_TYPE pFunc PH_FUNCTION_PARAM_N(n)):\
	isMember(m_pInstance(pInstance),) m_pFunc(pFunc) PH_CONSTRUCT_INIT_PARAM_N(n) {}\
\
	RET invoke()\
	{\
		return (isMember(m_pInstance->*)m_pFunc)(PH_PARAM_NAME_N(n));\
	}\
\
private:\
	isMember(C* m_pInstance;)\
	FUNCTION_TYPE m_pFunc;\
	PH_CLASS_MEMBER_DEFINE_N(n)\
};

#define PH_CREATE_BIND(funcName, isPointer, isMember)\
template<isMember(typename C,) typename RET PH_TEMPLATE_TYPE_NAME_N(n)>\
ParamHolderImpl<PFUNC, Base> isPointer(*) funcName(isMember(C* pInstance,) FUNCTION_TYPE pFunc PH_FUNCTION_PARAM_N(n))\
{\
	return isPointer(new) ParamHolderImpl<PFUNC, Base>(isMember(pInstance,) pFunc PH_COMMA_PARAM_NAME_N(n));\
}\

template<template<typename> class Base >
class FunctionBindHelper{


};

PH_DEFINE_ALL(PH_PARAM_HOLDER_N, PH_TRUE)
PH_DEFINE_ALL(PH_PARAM_HOLDER_N, PH_FALSE)


template<typename Func>
class ParamHolder{
	template <typename T> class BaseValue;
	template <typename T> class BaseReference;

public:
	typedef ParamHolderImpl<Func, BaseValue> Value;
	typedef ParamHolderImpl<Func, BaseReference> Reference;

private:
	template <typename HolderImpl>
	class BaseValue{
	public:
		template <typename T>
		struct Trait
		{
			template <typename U>
			struct RemoveReference
			{
				typedef U TYPE;
			};

			template <typename U>
			struct RemoveReference<U&>
			{
				typedef U TYPE;
			};
			typedef typename RemoveReference<T>::TYPE TYPE;
		};
	};

	template <typename HolderImpl>
	class BaseReference{
	public:
		template <typename T>
		struct Trait
		{
			typedef T TYPE;
		};
	};

};
