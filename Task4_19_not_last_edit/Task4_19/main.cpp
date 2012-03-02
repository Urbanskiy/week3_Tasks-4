
#include "main.h" // TDate class nothing main =)
#include "TApForm.h"

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

class GR
{
private:
    size_t SIZE;
    TApForm * data;
public:
    GR();
    GR(size_t size);
    GR(GR&gr);
    ~GR();

    TApForm * GetData(int i);
    void PushTApForm(size_t pos,TApForm * Taf);

};
GR::GR()
{
    SIZE = 1;
    data = new TApForm();
}
GR::GR(size_t size)
{
    SIZE = size;
    data = new TApForm[size];
}
GR::GR(GR&gr)
{
    SIZE = gr.SIZE;
    data = new TApForm[SIZE];
    for(int i = 0 ; i < SIZE; i++)
        data[i] = gr.data[i];
}
GR::~GR()
{
    cout << "\nGR DESTRUSTOR";
    delete[] data;
}
TApForm * GR::GetData(int i)
{
    return (data+i);
}
void GR::PushTApForm(size_t pos,TApForm * Taf)
{
    *(data+pos) = *Taf;
}

int main()
{
    GR * a = new GR(3);
    TApForm * Taf = new TApForm("urb",1,new TDate(10,1,2001));
    a->PushTApForm(1,Taf);
    for(int i = 0 ; i < 3 ; i++)
    {
        a->PushTApForm(i,new TApForm("urb",MALE,new TDate(i+1,10,2010)));
        a->GetData(i)->PrintAF();
    }
    delete Taf;
    delete a;
    return 0;
}




