#pragma once
template <typename T> class MakeSealed
{
	friend T;
private:
	MakeSealed(){}
	~MakeSealed(){}
};
//��̳� �ܹ�ʹ���ٴμ̳е���ֱ�ӵ��û���Ĺ��캯��
class SealedClass2:virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2(){}
	~SealedClass2(){}
};