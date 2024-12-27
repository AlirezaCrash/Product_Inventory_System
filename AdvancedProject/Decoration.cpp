#include "Decoration.h"
#include<iostream>
using namespace std;
#include<string>
Decoration::Decoration(int id,int num,string Name,string Mname):MobEquip(id,num,Name)
{
SetMName(Mname);
}
Decoration::Decoration():MobEquip()
{
SetMName(" ");
}
Decoration::~Decoration(void)
{
}
void Decoration::SetMName(string M)
{
Mobile_Name=M;
}
string Decoration::GetMName()
{
return Mobile_Name;
}
void Decoration::Print()
{
	MobEquip::Print();
cout << GetMName() << "\t \t "  ;
}