// 7_완벽한전달1
//

int main()
{
  int n = 10;

  int* p1 = &n;
  int** p2 = &p1; // pointer의 pointer - ok

  int& r1 = n;
  int& & r2 =n; // 레퍼런스의 래퍼런스 - error.


}
