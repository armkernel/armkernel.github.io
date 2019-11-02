#include <iostream>
#include <string>

using namespace std;

class Edit
{
  string data;
public:
  string getData()
  {  
    cin >> data;
    return data;
  }
};

int main()
{
  Edit edit;

  while(1)
  {
    string str = edit.getData();
    cout << str << endl;
  }
}
