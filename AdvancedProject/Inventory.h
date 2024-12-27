#include<iostream>
#pragma once
using namespace std;
class Inventory
{
public:
Inventory(int,int);
Inventory();
~Inventory(void);
void SetId(int a);
int GetId();
void SetNum(int a);
int GetNum();
virtual void Print();
private:
int Id , Num ;
};

