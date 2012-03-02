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

    void SetValue(size_t,size_t,int value);
    size_t GetSIze();
    int GetValue(size_t i, size_t j);
    void FillRandom(unsigned modul);
    void PrintMatr();

    int IsOK_IJ(size_t,size_t);
    TMatr& operator=(TMatr&);

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
    }
    catch(const char * exc)
    {
        cout << exc << endl;
    }
    catch(...)
    {
        cout << "\nCannot allocate memory for Matr";
    }

    SIZE = size;
    for(size_t i = 0; i < size; i++)
        for(size_t j = 0; j < size; j++)
            *(data + i * size + j) = 0;
}
TMatr::TMatr(const TMatr & m)
{
    SIZE = m.SIZE;
    try
    {
        data = new int[SIZE*SIZE];
    }
    catch(const char * exc)
    {
        cout << exc << endl;
    }
    catch(...)
    {
       cout << "\nCannot allocate memory for Matr";
    }
    for(size_t i= 0; i < SIZE; i++)
        for(size_t j = 0; j < SIZE; j++)
            *(data + i * SIZE + j) = *(m.data + i * SIZE + j) ;

}
TMatr::~TMatr()
{
    if(data)
    {
        delete[] data;
        data = NULL;
    }
}
size_t TMatr::GetSIze()
{
    return SIZE;
}
void TMatr::SetValue(size_t i, size_t j, int value)
{
    if(!IsOK_IJ(i,j))
    {
        cout << "\nSetValue -> Arguments must be in 0..SIZE";
    }
    else
    {
        *(data + i*SIZE + j) = value;
    }
}
int TMatr::GetValue(size_t i, size_t j)
{
    if(IsOK_IJ(i,j))
        return *(data + i*SIZE + j);
    else
        cout << "\nGetValue -> Arguments must be in 0..SIZE";
}
void TMatr::FillRandom(unsigned modul)
{
    if(data)
    {
        srand(time(NULL));
        if(modul <= 0)
        {
            cout << "\n Modul must be positive";
        }
        else
        {
            for(size_t i = 0; i < this->GetSIze(); i++)
            {
                for(size_t j = 0; j < this->GetSIze(); j++)
                {
                    this->SetValue(i,j,rand()%modul);
                }
            }
        }
    }
    else
    {
        cout << "\n data is NULL cannot fill random" << endl;
    }
}
void TMatr::PrintMatr()
{
    for(size_t i = 0; i < SIZE; i++)
    {
        for(size_t j = 0; j < SIZE; j++)
        {
            cout << GetValue(i,j) << "  ";
        }
        cout << endl;
    }
}
int TMatr::IsOK_IJ(size_t i,size_t j)
{
    if(i < 0 || j < 0 || i >= SIZE || j >= SIZE )
        return 0;
    return 1;
}
TMatr& TMatr::operator=(TMatr& RV)
{
    try
    {
        if(RV.SIZE != this->SIZE) throw "\n RVAL->SIZE not equal LVAL->SIZE";
        if(&RV == this) throw "\n Cannot use operator= to itself";
    }
    catch(const char * exc )
    {
        cout << exc <<endl;
    }
    for(size_t i = 0; i < SIZE; i++)
    {
        for(size_t j = 0; j < SIZE; j++)
        {
            this->SetValue(i,j, RV.GetValue(i,j));
        }
        cout << endl;
    }
    return *this;
}
//---------------------------------------------------------------------------
int GetScalar(int * first,int * second, size_t size)
{
    if(first && second && size >= 0)
    {
        int scalar = 0;

        for(int i = 0; i < size; i++)
        {
            scalar += first[i] * second[i];
        }
        return scalar;
    }
    else
        cout << "first \ second is null pointer of size is wrong";
}
//---------------------------------------------------------------------------

