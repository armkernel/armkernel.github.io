// 5_EBCO1.cpp - 73page
#include <iostream>
using namespace std;

class Empty {};

class PAIR
{
	Empty e;
	int n;	
};

// EBCO : Empty Base Class Optimization
//        Empty Ŭ������ ��� Ŭ������ ����ϸ� ũ�Ⱑ 0���� ���ȴ�.
class PAIR2 : public Empty
{
	int n;
};

int main()
{
	cout << sizeof(Empty) << endl; // 1
	cout << sizeof(PAIR)  << endl; // 8
	cout << sizeof(PAIR2) << endl; // 4
}



