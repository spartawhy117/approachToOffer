#pragma once
#include <mutex>
class Singleton1 final// final 关键字使得该类不能被继承
{
public:
	static Singleton1& getInstance()
	{
		//c++ 11 线程安全
		//c++11 之前需要加锁
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