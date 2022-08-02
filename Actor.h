#include <iostream>

using namespace std;

class Actor
{
  private:
  int iActorId;
  string sName;

  public:
  //constructors
  Actor();
  Actor(int, string);
  //getters
  int getActorId();
  string getActorName();
  //setters
  void setActorId(int);
  void setActorName(string);
  //output
  void toString();
};

//constructors
Actor::Actor()
{
  iActorId = -1;
  sName = "NN";
}

Actor::Actor(int iActorId, string sName)
{
  this -> iActorId = iActorId;
  this -> sName = sName;
}

//getters
int Actor::getActorId()
{
  return iActorId;
}

string Actor::getActorName()
{
  return sName;
}

//setters
void Actor::setActorId(int iActorId)
{
  this -> iActorId = iActorId;
}

void Actor::setActorName(string sName)
{
  this -> sName = sName;
}

//output
void Actor::toString()
{
  cout << "     " << iActorId << "      |        " << sName << "     " << endl;
}