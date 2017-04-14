// Builder.cpp : コンソール アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include"Builder.h"
#include<iostream>
#include<vector>
#include<conio.h>
#include<initializer_list>
#include<utility>

#include"VUInitialize.h"
using namespace std;



int main()
{
	class Base
	{
	public:
		Base() :x(0), y(1) {}
		int x, y;
		virtual void Disp() 
		{
			cout << "b" << endl;
		};
	};

	class X :public Base
	{
		void Disp() { cout << x << endl; }
	};

	class Y:public Base
	{
		void Disp() { cout << y << endl; }
	};

	auto MyClass = VUInitialize<pair<int,unique_ptr<Base>>>
		(
			make_pair(1,make_unique<X>()),
			make_pair(1,make_unique<Y>())
			);
	//move(begin(temp), end(temp), back_inserter(MyClass));
	for (auto &i : MyClass)
	{
		i.second->Disp();
	}

	_getch();

    return 0;
}

