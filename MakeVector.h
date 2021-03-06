#pragma once

#include<vector>

//vector<Containts>を返す
//unique_ptrを引数にすることも可能
template <class Containts, class... Args>
std::vector<Containts> MakeVector(Args&&... args)
{
	using namespace std;
	Containts init[]{ forward<Args>(args)... };
	vector<Containts> ret{ make_move_iterator(begin(init)), make_move_iterator(end(init)) };

	return ret;
}