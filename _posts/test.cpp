#include <iostream>

using namespace std;

struct IState
{
  virtual void run(){};
};

class NormalState : public IState
{
  virtual void run() override
  {
    cout << "run!" << endl;
  }
  
};

class PowerState : public IState
{

  virtual void run() override
  {
    cout << "boost!" << endl;
  }
};

class Character 
{
  IState* state;
public:
  void changeState(IState* s = new NormalState()) { this->state = s; }
  void run() { state->run(); }
};

int main()
{
  NormalState ns;
  PowerState ps;
  
  Character* c = new Character;
  
  //c->run();

  c->changeState(&ns);
  c->run();

  c->changeState(&ps);
  c->run();
}
