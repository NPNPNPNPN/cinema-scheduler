#include <iostream>

using namespace std;

class Movie
{
  private:
  int iNumMovie;
  string sTitle;
  int iYear;
  int iLength;
  string sGenre;
  int iQuantityOfActors;
  int iActorList[10];

  public:
  //constructor
  Movie();
  //getters
  int getNumMovie();  
  string getTitle();
  int getYear();
  int getLength();
  string getGenre();
  int getQuantityOfActors();
  int getActor(int);
  //setters
  void setNumMovie(int);
  void setTitle(string);
  void setYear(int);
  void setLength(int);
  void setGenre(string);
  void setQuantityOfActors(int);
  //methods
  bool addActor(int); 
  bool searchActor(int); 
};

//constructor
Movie::Movie()
{
  iNumMovie = -1;
  sTitle = "NN";
  iYear = -1;
  iLength = -1;
  sGenre = "NN";
  iQuantityOfActors = 0;
}

//getters
int Movie::getNumMovie()
{
  return iNumMovie;
}

string Movie::getTitle()
{
  return sTitle;
}

int Movie::getYear()
{
  return iYear;
}

int Movie::getLength()
{
  return iLength;
}

string Movie::getGenre()
{
  return sGenre;
}

int Movie::getQuantityOfActors()
{
  return iQuantityOfActors;
}

int Movie::getActor(int iD)
{
 return iActorList[iD];
}

//setters
void Movie::setNumMovie(int iNumMovie)
{
  this -> iNumMovie = iNumMovie;
}

void Movie::setTitle(string sTitle)
{
  this -> sTitle = sTitle;
}

void Movie::setYear(int iYear)
{
  this -> iYear = iYear;
}

void Movie::setLength(int iLength)
{
  this -> iLength = iLength;
}

void Movie::setGenre(string sGenre)
{
  this -> sGenre = sGenre;
}

void Movie::setQuantityOfActors(int iQuantityOfActors)
{
  this -> iQuantityOfActors = iQuantityOfActors;
}

//methods
bool Movie::addActor(int iD)
{
  if(iQuantityOfActors < 10)
  {
    iActorList[iQuantityOfActors] = iD;
    iQuantityOfActors++;
    return true;
  }
  else
  {
  return false;
  }
}

bool Movie::searchActor(int iD)
{
  for (int iV = 0; iV < iQuantityOfActors; iV++)
  {
    if (iActorList[iV] == iD)
    {
      return true;
    }
  }
  return false;
}