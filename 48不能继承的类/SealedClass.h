#pragma once
template <typename T> class MakeSealed
{
	friend T;
private:
	MakeSealed(){}
	~MakeSealed(){}
};
//虚继承 能够使得再次继承的类直接调用基类的构造函数
class SealedClass2:virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2(){}
	~SealedClass2(){}
};