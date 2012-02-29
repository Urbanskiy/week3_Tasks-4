#ifndef TAPFORM_H_INCLUDED
#define TAPFORM_H_INCLUDED
#include "main.h" // TDate class nothing main =)

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define MALE 1
#define FEMALE 0
class TApForm
{
private:
    char * surname;
    int sex;
    TDate * bday;

public:
    TApForm();
    TApForm(char*,int,TDate*);
    TApForm(TApForm & Taf);
    ~TApForm();

    char * GetSurname();
    int GetSex();
    TDate * GetBirth();
    void PrintAF();


};
TApForm::TApForm()
{
    surname = new char[15];
    strcpy(surname,"Anonimous");

    sex = MALE;

    bday = new TDate(1,1,2001);
}
TApForm::TApForm(char * sur, int SEX, TDate * date )
{
    surname = new char[strlen(sur)+1];
    strcpy(surname,sur);

    sex = SEX;

    bday = new TDate(*date);
}
TApForm::TApForm(TApForm & Taf)
{
    cout << "TAF COPY CONST";
    surname = new char[strlen(Taf.GetSurname())+1];
    strcpy(surname,Taf.surname);
    sex = Taf.sex;
    bday = new TDate(*Taf.bday);
}
TApForm::~TApForm()
{

   printf("\nTAPFORM DESTRUCTOR");
   delete[] surname;
   delete bday;

}
char * TApForm::GetSurname()
{
    return this->surname;
}
int TApForm::GetSex()
{
    return this->sex;
}
TDate * TApForm::GetBirth()
{
    return this->bday;
}
void TApForm::PrintAF()
{

    cout << "\n*********************" << endl;
    cout << "Surname  : " << this->GetSurname() << endl;
    cout << "Sex      : ";
    if (this->sex)
        {cout <<"Male\n";}
    else
        {cout <<"Female\n";};
    cout << "BirthDay : " << this->bday->DateToStr() << endl;
    cout << "*********************" << endl;
}




#endif // TAPFORM_H_INCLUDED
