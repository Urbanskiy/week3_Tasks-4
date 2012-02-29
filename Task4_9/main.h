#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

class TMatr
{
private:
    size_t SIZE;
    int * data;
public:
    TMatr();
    TMatr(size_t size);
    TMatr(const TMatr & m);
    ~TMatr();

    void SetValue(int,int,int value);
    size_t GetSIze();
    int GetValue(int i, int j);
    void FillRandom(unsigned modul);
    void PrintMatr();
    TMatr operator=(TMatr);

};
TMatr::TMatr()
{
    SIZE = 1;
    data = new int[SIZE];
    *data = 0;
    cout << "\n Created Matr 1x1" << endl;
}
TMatr::TMatr(size_t size)
{
    try
    {
        if( size <= 0) throw "\n Size must be bigger then zero";

        data = new int[size*size];
        if(data == NULL) throw "\nCannot allocate memory for Matr";

    }
    catch(const char * exc)
    {
        cout << exc << endl;
    }

    SIZE = size;
    for(int i = 0; i < size; i++)
        for(int j = 0; j < size; j++)
            *(data + i * size + j) = 0;
}
TMatr::TMatr(const TMatr & m)
{
    SIZE = m.SIZE;
    try
    {
        data = new int[SIZE*SIZE];
        if(data == NULL) throw "\nCannot allocate memory for Matr";
    }
    catch(const char * exc)
    {
        cout << exc << endl;
    }
    for(int i = 0; i < SIZE; i++)
        for(int j = 0; j < SIZE; j++)
            *(data + i * SIZE + j) = *(m.data + i * SIZE + j) ;

}
TMatr::~TMatr()
{
    delete[] data;
}
size_t TMatr::GetSIze()
{
    return SIZE;
}
void TMatr::SetValue(int i, int j, int value)
{
    if(i < 0 || j < 0 || i >= SIZE || j >= SIZE )
    {
        cout << "\nSetValue -> Arguments must be in 0..SIZE";
    }
    else
    {
        *(data + i*SIZE + j) = value;
    }
}
int TMatr::GetValue(int i, int j)
{
    try
    {
        if(i < 0 || j < 0 || i >= SIZE || j >= SIZE ) throw "\nGetValue -> Arguments must be in 0..SIZE";
    }
    catch(const char * exc)
    {
        cout << exc << endl;
    }

    return *(data + i*SIZE + j);
}
void TMatr::FillRandom(unsigned modul)
{
    srand(time(NULL));
    if(modul <= 0)
    {
        cout << "\n Modul must positive";
    }
    else
    {
        for(int i = 0; i < this->GetSIze(); i++)
        {
            for(int j = 0; j < this->GetSIze(); j++)
            {
                this->SetValue(i,j,rand()%modul);
            }
        }
    }

}
void TMatr::PrintMatr()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            cout << GetValue(i,j) << "  ";
        }
        cout << endl;
    }
}
TMatr TMatr::operator=(TMatr RV)
{
    try
    {
        if(RV.SIZE != this->SIZE) throw "\n RVAL->SIZE not equal LVAL->SIZE";
    }
    catch(const char * exc )
    {
        cout << exc <<endl;
    }
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            this->SetValue(i,j, RV.GetValue(i,j));
        }
        cout << endl;
    }
}
//---------------------------------------------------------------------------
int GetScalar(int * first,int * second, size_t size)
{
    int scalar = 0;

    for(int i = 0; i < size; i++)
    {
        scalar += first[i] * second[i];
    }
    return scalar;
}
//---------------------------------------------------------------------------
