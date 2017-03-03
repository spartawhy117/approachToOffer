#pragma once
#include <mutex>
class Singleton1 final// final �ؼ���ʹ�ø��಻�ܱ��̳�
{
public:
	static Singleton1& getInstance()
	{
		//c++ 11 �̰߳�ȫ
		//c++11 ֮ǰ��Ҫ����
		mt.lock();
		static Singleton1 instance;
		mt.unlock();
		return  instance;
	}


private:
	Singleton1();
	Singleton1(Singleton1 const &);
	Singleton1& operator=(const Singleton1&);
	~Singleton1();
	static std::mutex mt;

};