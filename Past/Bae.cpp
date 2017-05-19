#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

int days(int,int,int,int,int);
int hours(int,int);
int minutes(int);
int seconds(int);
void display(int,int,int,int);

int main(){

  cout << "This program is a little something to maybe, make me feel happy...\n";
  cout << "So, future Wizard_, input the next meeting date...? :D\n:\n";
  //The prefix 'm' stands for meeting...

  int mday,mmonth,myear,mhours = 4;
  cin >> mday >> mmonth >> myear;

  time_t currentTime;

  int j = 1,i = 0;
  while(j){
    struct tm *localTime;

    time( &currentTime );                   // Get the current time
    localTime = localtime( &currentTime );  // Convert the current time to the local time

    int Day    = localTime->tm_mday;
    int Month  = localTime->tm_mon + 1;
    int Year   = localTime->tm_year + 1900;
    int Hour   = localTime->tm_hour;
    int Min    = localTime->tm_min;
    int Sec    = localTime->tm_sec;
 
    int noofdays = days(mmonth,Month,mday,Day,Year);
    int noofhours = hours(mhours,Hour);
    int noofminutes = minutes(Min);
    int noofseconds = seconds(Sec);

    int prevsec = 0;
	  if (j!=1){
		  if((Sec - prevsec) == 1){
        while(i<100){
          cout << endl;
            i++;
        }
        display(noofdays,noofhours,noofminutes,noofseconds);
        prevsec++;
		}
	}
	  else {
		  cout <<Hour <<endl;
      //Display...
      display(noofdays,noofhours,noofminutes,noofseconds);
      prevsec = Sec;
    }
	j++;
  if(j == 100){
    j = 2;
  }
}

}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int hours(int mhours,int Hours){
  int temp = 0;
  temp = 24 - Hours - 1;
  temp += mhours;
  // To account for the 59 effect...
  temp--;
  return temp;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int minutes(int min) {
  int temp = 0;
  temp = 59 - min;
  return temp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

int seconds(int sec){
  int temp = 0;
  temp = 59 - sec;
  return temp;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display(int days,int hours,int min,int sec){
  cout << sec << endl;
  cout <<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"
  <<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<
  "_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<< endl;
  cout << "|   Well, time still remains... (sigh)x100         |" << endl;
  cout << "|   Time to meet Bae...                            |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout << "|                                                  |" << endl;
  cout <<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"
  <<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<
  "_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<<"_"<< endl;

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////

int days(int mmonth, int Month, int mday, int Day, int Year){
  //counting number of days...
  int temp = 0; //Variable that stores #days...
  //Case - 1...
  if(mmonth > Month){
      for(int i=mmonth;i>Month;i--){
          //Months with 31 days...
          if(i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12){
            temp += 31;
          }
          //February
          else if(i == 2){
            //Leap year...
             if(Year % 4==0){
               temp += 29;
             }
             //Not a Leap year...
             else {
               temp += 28;
             }
          }
          //Months with 30 days...
          else {
            temp += 30;
          }
      }
  }
  //Case - 2...
  else if(mmonth < Month){
    for(int i=mmonth;i>0;i--){
        //Months with 31 days...
        if(i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12){
          temp += 31;
        }
        //February
        else if(i == 2){
          //Leap year...
           if(Year % 4==0){
             temp += 29;
           }
           //Not a Leap year...
           else {
             temp += 28;
           }
        }
        //Months with 30 days...
        else {
          temp += 30;
        }
    }
    for(int i=12;i>Month;i--){
        //Months with 31 days...
        if(i == 1 or i == 3 or i == 5 or i == 7 or i == 8 or i == 10 or i == 12){
          temp += 31;
        }
        //February
        else if(i == 2){
          //Leap year...
           if(Year % 4==0){
             temp += 29;
           }
           //Not a Leap year...
           else {
             temp += 28;
           }
        }
        //Months with 30 days...
        else {
          temp += 30;
        }
    }
  }
  else if(mmonth == Month){
    temp = mday - Day - 1;
  }

  //........................................................................................................
  //The number of days have been counted...

  --temp; // To count the number of hours...
  return temp;
}
