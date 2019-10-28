#include <iostream>
#include <algorithm>
#include <functional> // less<>, greater<> �� ���⿡ �ֽ��ϴ�.
using namespace std;

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	// sort() �Լ��� ��� ���ڰ� ���ø� �Դϴ�.
	// 1. ����å���� �Ϲ� �Լ��� ����Ҷ�

	// ���� : ����å�� ��ü�ص� sort() ���� �ڵ�� �Ѱ��̴�.
	//		  �ڵ� �޸� ���� ����
	// ���� : ����å�� �ζ��� ġȯ�ɼ� ����. ������.

	sort(x, x + 10, cmp1); // sort(int*, int*, bool(*)(int,int)) �� �Լ� ����
	sort(x, x + 10, cmp2); // sort(int*, int*, bool(*)(int,int)) �� �Լ� ����


	// 2. ����å���� �Լ���ü�� ����Ҷ�

	// ���� : ��å�� ��ü�� Ƚ�� ��ŭ sort ���� �ڵ� ����
	//		�ڵ�޸� ����

	// ���� : ��å �Լ��� ������ �ζ��� ġȯ�ȴ�. ������.!!

	less<int> f1;    // STL �ȿ� �� �Լ���ü�� �ֽ��ϴ�.
	greater<int> f2;

	sort(x, x + 10, f1); // sort(int*, int*, less<int> ) �� �Լ� ����
	sort(x, x + 10, f2); // sort(int*, int*, greater<int>) �� �Լ� ����
}




