#include <iostream>
#include "Hour.h"

using namespace std;

class ScheduledMovies
{
  private:
  int iScheduleId;
  int iNumMovie;
  Hour hour;
  int iTheatherRoom;

  public:
  //constructors
  ScheduledMovies();
  ScheduledMovies(int, int, Hour, int);
  //getters
  int getScheduleId();
  int getMovieNumber();
  Hour getHour();
  int getTheaterRoom();
  //setters
  void setScheduleId(int);
  void setMovieNumber(int);
  void setHour(Hour);
  void setTheaterRoom(int);
  //output
  void toString();
};

//constructors
ScheduledMovies::ScheduledMovies()
{
  iScheduleId = -1;
  iNumMovie = -1;
  iTheatherRoom = -1;
}

ScheduledMovies::ScheduledMovies(int iScheduleId, int iNumMovie, Hour hour, int iTheatherRoom)
{
  this -> iScheduleId = iScheduleId;
  this -> iNumMovie = iNumMovie;
  this -> hour = hour;
  this -> iTheatherRoom = iTheatherRoom;
}

//getters
int ScheduledMovies::getScheduleId()
{
  return iScheduleId;
}

int ScheduledMovies::getMovieNumber()
{
  return iNumMovie;
}

Hour ScheduledMovies::getHour()
{
  return hour;
}

int ScheduledMovies::getTheaterRoom()
{
  return iTheatherRoom;
}

//setters
void ScheduledMovies::setScheduleId(int iScheduleId)
{
  this -> iScheduleId = iScheduleId;
}

void ScheduledMovies::setMovieNumber(int iNumMovie)
{
  this -> iNumMovie = iNumMovie;
}

void ScheduledMovies::setHour(Hour hour)
{
  this -> hour = hour;
}

void ScheduledMovies::setTheaterRoom(int iTheatherRoom)
{
  this -> iTheatherRoom = iTheatherRoom;
}

//output
void ScheduledMovies::toString()
{
  cout << "Schedule iD: " << iScheduleId << endl;
  cout << "Movie iD: " << iNumMovie << endl;
  hour.toString();
  cout << "Theater room: " << iTheatherRoom << endl;
}
