#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class TDate
{
private:
    int day;
    int mounth;
    int year;
public:
    TDate();
    TDate(int,int,int);
    TDate(TDate &date);

    void SetDate(int d,int m,int y) { day = d; mounth = m; year = y;}
    int GetDay() { return day;}
    int GetMounth() { return mounth;}
    int GetYear() { return year;}
    char * DateToStr();

    bool operator>(TDate);
    bool operator<(TDate);
    TDate * operator=(TDate);
};
TDate::TDate()
{
    day = 0;
    mounth = 0;
    year = 0;
}
TDate::TDate(int d, int m, int y)
{
    if( (d < 1 || d > 31) || (m < 1 || m > 12))
    {
        cout << "\n Bad initialize of date";
    }
    else
    {
        day = d;
        mounth = m;
        year = y;
    }
}
TDate::TDate(TDate &date)
{
    cout << "COPY CONSTRUCTOR" << endl;
    this->day = date.day;
    this->mounth = date.mounth;
    this->year = date.year;
}
char * TDate::DateToStr()
{
    char * p = new char[9];
    if(mounth < 10)
        sprintf(p,"%d-0%d-%d",year,mounth,day);
    else
        sprintf(p,"%d-%d-%d",year,mounth,day);
    return p;
}
 bool TDate::operator>(TDate date)
 {
    if( strcmp(this->DateToStr(),date.DateToStr()) > 0 )
        return true;
    else
        false;
 }
  bool TDate::operator<(TDate date)
 {
    if( strcmp(this->DateToStr(),date.DateToStr()) < 0 )
        return true;
    else
        false;
 }
 TDate * TDate::operator=(TDate date)
 {
     cout << "OPERATOR =" << endl;
     this->day = date.day;
     this->mounth = date.mounth;
     this->year = date.year;

     return this;
 }

#endif // MAIN_H_INCLUDED
