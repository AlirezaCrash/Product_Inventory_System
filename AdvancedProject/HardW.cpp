#include "HardW.h"
#include<iostream>
#include<string>
using namespace std;
HardW::HardW(int id,int numB,int Date,string Brand):PcEquip(id,numB)
{
SetRDate(Date);
SetBrand(Brand);
}
HardW::~HardW(void)
{
}
void HardW::SetRDate(int a)
{
RDate=a;
}
int HardW::GetRDate()
{
return RDate;
}
void HardW::SetBrand(string brand)
{
Brand = brand ;
}
string HardW::Getbrand()
{
return Brand; 
}
void HardW::Print()
{
PcEquip::Print();
cout << Getbrand() << "\t" << GetRDate() << "\t" ;
}
