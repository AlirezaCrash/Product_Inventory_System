#include "SoftW.h"
#include<iostream>
#include<string>
using namespace std;
SoftW::SoftW(int id , int numB,string N ):PcEquip(id,numB)
{
SetName(N);
}
SoftW::~SoftW(void)
{
}
void SoftW::SetName(string N)
{
Name = N ; 
}
string SoftW::GetName()
{
return Name ;
}
void SoftW::Print()
{
PcEquip::Print();
cout << GetName() << "\t" ;
}
