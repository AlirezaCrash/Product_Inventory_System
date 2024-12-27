#include "Inventory.h"
#include<iostream> 
using namespace std ;
Inventory::Inventory(int a,int Numb)
{
SetId(a);
SetNum(Numb);
}
Inventory::Inventory(){SetId(0);SetNum(0);}
Inventory::~Inventory(void)
{
}
void Inventory::SetId(int a)
{
Id= a ; 
}
int Inventory::GetId() 
{
return Id ;
}
void Inventory::SetNum(int a)
{
Num = a ;
}
int Inventory::GetNum()
{
return Num ; 
}
void Inventory::Print()
{
cout << GetId() << "\t" << GetNum() << "\t" ;
}
