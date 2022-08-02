#include <iostream>

using namespace std;

class Hour
{
  private:
  int iHH;
  int iMM;

  public:
  //constructors
  Hour();
  Hour(int, int);
  //getters
  int getHour();
  int getMinutes();
  //setters
  void setHour(int);
  void setMinutes(int);
  //output
  void toString();
  //operator override
  friend bool operator == (Hour, Hour);
};

//constructors
Hour::Hour()
{
  int iHH = -1;
  int iMM = -1;
}

Hour::Hour(int iHH, int iMM)
{
  this -> iHH = iHH;
  this -> iMM = iMM;
}

//getters
int Hour::getHour()
{
  return iHH;
}

int Hour::getMinutes()
{
  return iMM;
}

//setters
void Hour::setHour(int iHH)
{
  this -> iHH = iHH;
}

void Hour::setMinutes(int iMM)
{
  this -> iMM = iMM;
}

//output
void Hour::toString()
{
  cout << "screening time: " << iHH << ":" << iMM << endl;
}

//operator override
bool operator == (Hour H1, Hour H2)
{
  if ((H1.getHour() == H2.getHour()) and (H1.getMinutes() == H2.getMinutes()))
  {
    return true;
  }
  else
  return false;
}