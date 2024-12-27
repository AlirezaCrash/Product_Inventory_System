#include "Repair.h"
#include<string>
Repair::Repair(int a,int b,string Name,string OS):MobEquip(a,b,Name)
{
SetOSName(OS);
}
Repair::~Repair(void)
{
}
void Repair::SetOSName(string OS)
{
OSName=OS ;
}
string Repair::GetOSName()
{
return OSName;
}
void Repair::Print()
{
MobEquip::Print();
cout << GetOSName() << "\t" ;
}