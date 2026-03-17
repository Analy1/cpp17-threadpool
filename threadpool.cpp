// 线程池项目-终版.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<thread>
#include <future>
#include<functional>
#include<chrono>
#include"threadpool.h"
using namespace std;


/*
如何能让线程池提交任务更方便
1.pool.submitTask(num1,10,20);
  pool.submitTask(num2,1,2,3);
  submitTask:可变参模板编程

2.我自己写了一个Result以及相关的类型，导致代码很多
  packaged_task(function函数对象)
*/


int sum1(int a, int b)
{
	this_thread::sleep_for(chrono::seconds(2));
	return a + b;
}

int sum2(int a, int b, int c)
{
	return a + b + c;
}

int main()
{
	ThreadPool pool;
	pool.setMode(PoolMode::MODE_CACHED);
	pool.start(2);
	future<int> r1 = pool.submitTask(sum1, 1, 2);
	future<int> r2 = pool.submitTask(sum2, 1, 2, 3);
	future<int> r3 = pool.submitTask(sum1, 1, 2);
	future<int> r4 = pool.submitTask(sum1, 1, 2);
	future<int> r5 = pool.submitTask(sum1, 2, 3);
	future<int> r6 = pool.submitTask(sum1, 4, 2);


	cout << r1.get() << endl;
	cout << r2.get() << endl;
	cout << r3.get() << endl;
	cout << r4.get() << endl;


	return 0;
}

