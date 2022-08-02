#include <iostream>
#include <fstream>
#include "Actor.h"
#include "Movie.h"
#include "ScheduledMovies.h"

using namespace std;

//Function that validates if the inputed movie id exists within the object array
bool MovieIdValidation(Movie M1[], int iD)
{
  for (int iR = 0; iR < 10;iR++)
  {
    if(M1[iR].getNumMovie() == iD)
    {
      return true;
    }
  }
  return false;
}

//Function that searches the name of the actors by iD
void ActorNames(Movie M1, Actor A1[])
{
  int iQuantity = M1.getQuantityOfActors();

  for(int iP = 0; iP < iQuantity; iP++)
  {
    cout << "Actor " << iP + 1 << " ";
    int iActorId = M1.getActor(iP);
    for (int iT = 0; iT < 20; iT++)
    {
      if (A1[iT].getActorId() == iActorId)
      {
        cout << A1[iT].getActorName() << endl;
      }
    }

  }
}

//function that validates if the hour object attributes already exist
bool ValidateHour(ScheduledMovies Smovies[], Hour H1, int iQSM)
{
  for(int iH = 0; iH < iQSM; iH++)
  {
    if(Smovies[iH].getHour() == H1)
    {
      return true;
    }
  }
  return false;
}

//function that validates if the given schedule iD exists within the scheduled movies
bool ValidateScheduleId(ScheduledMovies Smovies[], int iScheduleId, int iQSM)
{
  for (int iK = 0; iK < iQSM; iK++)
  {
    if (Smovies[iK].getScheduleId() == iScheduleId)
    {
      return true;
    }
  }
  return false;
}

//function that validates if the given actor iD exists within the actor array
bool ValidateActorId(Actor Actorlist[], int iActorId)
{
  for (int iX = 0; iX < 20; iX++)
  {
    if (Actorlist[iX].getActorId() == iActorId)
    {
      return true;
    }
  }
  return false;
}

int main() 
{
  int iNumMovie, iYear, iLength, iQuantityOfActors;
  string sTitle, sGenre;
  Actor Actorlist[20];
  ScheduledMovies SMovieslist[20];
  Movie Movielist[20];
  ifstream ifFile;
  Hour H1;

  //Creating multiple "Actor" objects within Actorlist
  int iC = 0;
  ifFile.open("Actors.txt");
  while (!ifFile.eof())
  {
    int iActorId;
    string sActorName;
    ifFile >> iActorId;
    ifFile.ignore();
    getline(ifFile, sActorName);

    Actorlist[iC].setActorId(iActorId);
    Actorlist[iC].setActorName(sActorName);
    iC++;
  }

  ifFile.close();

  ifFile.open("Movies.txt");
  iC = 0;

  //creating multiple "Movie" objects within Movielist
  while (!ifFile.eof())
  {
    int iNumMovie, iYear, iLength;
    string sGenre;
    int iNumOfActors, iActorId;
    string sTitle;

    ifFile >> iNumMovie >> iYear >> iLength >> sGenre >> iNumOfActors;
    Movielist[iC].setNumMovie(iNumMovie);
    Movielist[iC].setYear(iYear);
    Movielist[iC].setLength(iLength);
    Movielist[iC].setGenre(sGenre);
    //Multiple actor ids are added to an array of actors within "Movie" object
    for (int iQ = 0; iQ < iNumOfActors; iQ++)
    {
      ifFile >> iActorId;
      Movielist[iC].addActor(iActorId);
    }

    ifFile.ignore();
    getline(ifFile, sTitle);
    Movielist[iC].setTitle(sTitle);
    iC++;
  }
  ifFile.close();

  //printing out all movie objects iD and Title in a tablelike manner
  cout << "Available movies: " << endl;
  cout << "  iD  " << "   |   " << "         Title  " << endl;
  cout << "_________|_________________________________________" << endl;
  for (int iP = 0; iP < 10; iP++)
  {
    cout << "  " <<  Movielist[iP].getNumMovie() << "   " << " | ";
    cout << "  " << Movielist[iP].getTitle() << endl;
  }

  cout << endl;
  cout << "Create the movie screening schedule" << endl;

  int iScheduledMovies = 0;
  bool bContinue = true;
  while ((bContinue) and (iScheduledMovies < 20))
  {
    int iScheduleId, iScheduleMovieNum; //variables are organized in order of appearence
    int iHour, iMinutes;
    Hour hour;
    int iTheaterRoom;
    string sOption;
    cout << "Please type the schedule iD" << endl;
    cin >> iScheduleId;
    cout << "Please type the iD of the movie you want to schedule" << endl;
    cin >> iScheduleMovieNum;
    while (!MovieIdValidation(Movielist, iScheduleMovieNum))
    {
      cout << "Please type an existent movie iD" << endl;
      cin >> iScheduleMovieNum;
    }

    cout << "Please type screening hour in 24 hour format" << endl;
    cin >> iHour;
    while ((iHour > 24) or (iHour < -1))
    {
      cout << "Invalid input" << endl;
      cout << "Please type screening hour in 24 hour format" << endl;
      cin >> iHour;
    }

    cout << "Please type the screening minutes" << endl;
    cin >> iMinutes;
    while ((iMinutes > 60) or (iMinutes < -1))
    {
      cout << "Invalid input" << endl;
      cout << "Please type the screening minutes" << endl;
      cin >> iMinutes;
    }

    cout << "Please type the theater room at which the screening will be held" << endl;
    cin >> iTheaterRoom;

    //creating Hour object with the inputed parameters
    hour.setHour(iHour);
    hour.setMinutes(iMinutes);

    //creating ScheduledMovies object within SMovieslist
    SMovieslist[iScheduledMovies].setScheduleId(iScheduleId);
    SMovieslist[iScheduledMovies].setMovieNumber(iScheduleMovieNum);
    SMovieslist[iScheduledMovies].setHour(hour);
    SMovieslist[iScheduledMovies].setTheaterRoom(iTheaterRoom);

    iScheduledMovies++;

    cout << "Input 'Y' to schedule another movie" << endl;
    cin >> sOption;
    if (sOption == "Y" or sOption == "y")
    {
      bContinue = true;
    }
    else
    {
      bContinue = false;
    }
  }

  char cMenu;
  do
  {
    cout << "Option Menu" << endl;
    cout << "a. Show actors" << endl;
    cout << "b. Show all movies" << endl;
    cout << "c. Show all scheduled movies" << endl;
    cout << "d. Search scheduled movies by hour" << endl;
    cout << "e. Search scheduled movies by scheduleID" << endl;
    cout << "f. Search movies by actorID" << endl;
    cout << "g. Exit program" << endl;
    cin >> cMenu;

    switch(cMenu)
    {
      case 'a': cout << "  Actor iD   " << "|" << "         Actor Name" << endl;
                cout << "_____________|__________________________________" << endl;
                for(int iT = 0; iT < 20; iT++)
                {
                  Actorlist[iT].toString();
                }
                break;
      case 'b': for(int iT = 0; iT < 10; iT++)
                {
                sTitle = Movielist[iT].getTitle();
                iNumMovie = Movielist[iT].getNumMovie();
                iYear = Movielist[iT].getYear();
                sGenre = Movielist[iT].getGenre();
                iLength = Movielist[iT].getLength();
                iQuantityOfActors = Movielist[iT].getQuantityOfActors();

                cout << "Title: " << sTitle << endl;
                cout << "Movie iD number: " << iNumMovie << endl;
                cout << "Year: " << iYear << endl;
                cout << "Genre: " << sGenre << endl;
                cout << "Length: " << iLength << endl;
                cout << "Number of actors: " << iQuantityOfActors << endl;
                ActorNames(Movielist[iT], Actorlist);
                cout << endl;
                }
                break;
      case 'c': for(int iY = 0; iY < iScheduledMovies; iY++)
                {
                  for(int iG = 0; iG < 10; iG++)
                  {
                    if(Movielist[iG].getNumMovie() == SMovieslist[iY].getMovieNumber())
                    {
                      cout << endl;
                      cout << "Title: " << Movielist[iG].getTitle() << endl;
                      cout << "Year: " << Movielist[iG].getYear() << endl;
                      cout << "Genre: " << Movielist[iG].getGenre() << endl;
                      cout << "Length: " << Movielist[iG].getLength() << endl;
                      cout << "Number of actors: " << Movielist[iG].getQuantityOfActors() << endl;
                      ActorNames(Movielist[iG], Actorlist);
                    }
                  }
                  SMovieslist[iY].toString();
                  cout << endl << endl;
                }
                break;
      case 'd': int iHour, iMinutes;
                cout << endl << "Please type the hour of screening" << endl;
                cin >> iHour;
                while ((iHour > 24) or (iHour < -1))
                {
                  cout << "Invalid input" << endl;
                  cout << "Please type screening hour in 24 hour format" << endl;
                  cin >> iHour;
                }
                cout << "Please type the minutes of the screening" << endl;
                cin >> iMinutes;
                while ((iMinutes > 60) or (iMinutes < -1))
                {
                  cout << "Invalid input" << endl;
                  cout << "Please type the screening minutes" << endl;
                  cin >> iMinutes;
                }
                H1.setHour(iHour);
                H1.setMinutes(iMinutes);

                if (ValidateHour(SMovieslist, H1, iScheduledMovies))
                {
                  for (int iJ = 0; iJ < iScheduledMovies; iJ++)
                  {
                    if (SMovieslist[iJ].getHour() == H1)
                    {
                      for (int iK = 0; iK < 10; iK++)
                      {
                        if (Movielist[iK].getNumMovie() == SMovieslist[iJ].getMovieNumber())
                        {
                          cout << "Title: " << Movielist[iK].getTitle() << endl;
                          cout << "Year: " << Movielist[iK].getYear() << endl;
                          cout << "Genre: " << Movielist[iK].getGenre() << endl;
                          cout << "Length: " << Movielist[iK].getLength() << endl;
                          cout << "Number of actors: " << Movielist[iK].getQuantityOfActors() << endl;
                          ActorNames(Movielist[iK], Actorlist);
                        }
                      }
                      SMovieslist[iJ].toString();
                      cout << endl << endl;
                    }
                  }
                }
                else
                {
                  cout << "No movie scheduled at inputed time" << endl;
                }
                break;
      case 'e': int iScheduleId;
                cout << endl << "Please input the schedule iD to be searched" << endl;
                cin >> iScheduleId;
                if (ValidateScheduleId(SMovieslist, iScheduleId, iScheduledMovies))
                {
                  for (int iL = 0; iL < 10; iL++)
                  {
                    if (SMovieslist[iL].getScheduleId() == iScheduleId)
                    {
                      for(int iZ = 0; iZ < 10; iZ++)
                      {
                        if (SMovieslist[iL].getMovieNumber() == Movielist[iZ].getNumMovie())
                        {
                          cout << "Title: " << Movielist[iZ].getTitle() << endl;
                          cout << "Year: " << Movielist[iZ].getYear() << endl;
                          cout << "Genre: " << Movielist[iZ].getGenre() << endl;
                          cout << "Length: " << Movielist[iZ].getLength() << endl;
                          cout << "Number of actors: " << Movielist[iZ].getQuantityOfActors() << endl;
                          ActorNames(Movielist[iZ], Actorlist);
                        }
                      }
                      SMovieslist[iL].toString();
                      cout << endl << endl;
                    }
                  }
                }
                else
                {
                  cout << "Nonexistent schedule iD" << endl << endl;
                }
                break;
      case 'f': int iActorId;
                cout << "Please input the Actor iD to be searched" << endl;
                cin >> iActorId;
                if (ValidateActorId(Actorlist, iActorId))
                {
                  cout << endl << "Actor stars in: " << endl;
                  for (int iC = 0; iC < 10; iC++)
                  {
                    if(Movielist[iC].searchActor(iActorId))
                    {
                      cout << "Title: " << Movielist[iC].getTitle() << endl;
                      cout << "Year: " << Movielist[iC].getYear() << endl;
                      cout << "Genre: " << Movielist[iC].getGenre() << endl;
                      cout << "Length: " << Movielist[iC].getLength() << endl;
                      cout << "Number of actors: " << Movielist[iC].getQuantityOfActors() << endl;
                      ActorNames(Movielist[iC], Actorlist);
                      cout << endl;
                    }
                  }
                  cout << endl;
                }
                else
                {
                  cout << "Nonexistent actor iD" << endl << endl;
                }
                break;
    }
  }while(cMenu != 'g');


return 0;  
}
