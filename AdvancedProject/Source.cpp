#include<iostream>
#include<string>
#include"Inventory.h"
#include"MobEquip.h"
#include"PcEquip.h"
#include"SoftW.h"
#include"HardW.h"
#include"Repair.h"
#include"Decoration.h"
#include<vector>
#include<fstream>
#include <windows.h>
#include<conio.h>
#include <fstream>
ofstream Sf_out("Software.txt", ios::app);
ifstream Sf_in("Software.txt", ios::in);
ofstream Hf_out("Hardware.txt", ios::app);
ifstream Hf_in("Hardware.txt", ios::in);
ofstream Rf_out("Repair.txt",ios::app);
ifstream Rf_in("Repair.txt", ios::in);
ofstream Df_out("Decor.txt", ios::app);
ifstream Df_in("Decor.txt", ios::in);
using namespace std ;
int idnumber=1015;
bool menu=true;
void LoadFile(vector <Decoration> &Dec,vector <Repair> &Rep,vector <HardW> &Hard,vector <SoftW> &Soft)
{
int id , numb ,Date ;
string Name, OName ;
for(int i=0;i<Sf_in.eof();i++)
{
Sf_in >> id >> Name >> numb ;
SoftW b(id,numb,Name);
Soft.push_back(b);
}
for(int i=0;i<Hf_out.eof();i++)
{
Hf_in >> id >> Name >> numb >> Date ;
HardW b(id,numb,Date,Name);
Hard.push_back(b);
}
for(int i=0;i<Rf_in.eof();i++)
{
Rf_in >> id >> Name >> numb >> OName ; 
Repair b(id,numb,Name,OName);
Rep.push_back(b);
}
for(int i=0;i<Df_in.eof();i++)
{
Df_in >> id >> Name >> numb >> OName ;
Decoration b(id,numb,Name,OName);
Dec.push_back(b);
}
}
void gotoxy(int x, int y)
{
    COORD c = { static_cast<SHORT>(x), static_cast<SHORT>(y) };  
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
COORD getScreenCenter()
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    COORD center;
    if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi))
    {
        int width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        int height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        center.X = static_cast<SHORT>(width / 2);
        center.Y = static_cast<SHORT>(height / 2);
    }
    else
    {
        center.X = 40;
        center.Y = 12;
    }
    return center;
}
void AddProd(vector <Decoration> &Dec,vector <Repair> &Rep,vector <HardW> &Hard,vector <SoftW> &Soft)
{

	int Number =0 ,Pyear=0,Add1,Add2,Add3,Add4;
	string Productname;
	string MobileName;
	string OSName;
	char ch = 5;
    system("cls");
    COORD center = getScreenCenter();
    int x = center.X, y = center.Y;
    
    gotoxy(center.X - 15, center.Y - 2);
    cout << "Which category do you want to add?";
    
    gotoxy(center.X, center.Y);
    Sleep(300);
    cout << "Hardware";
    
    gotoxy(center.X, center.Y + 2);
    Sleep(300);
    cout << "Software";
    
    gotoxy(center.X, center.Y + 4);
    Sleep(300);
    cout << "Decoration";
    
    gotoxy(center.X, center.Y + 6);
    Sleep(300);
    cout << "Repairing";

    int startY = center.Y;
    int endY = center.Y + 6;

    while (ch != 27)
    {
        gotoxy(x - 5, y);
        cout << "===>";
        ch = _getch();
        if (ch == 13) // Enter key
        {
            string Productname, MobileName, OSName;
            int Number, Pyear;

            if (y == center.Y)
            {
                system("cls");
                cout << "Please enter the name of product" << endl;
                cin.ignore();
                getline(cin, Productname);
                cout << "How many " << Productname << "s do you want to add?" << endl;
                cin >> Number;
                cout << "What's the Date of manufacture?" << endl;
                cin >> Pyear;
                HardW a(idnumber, Number, Pyear, Productname);
                Hard.push_back(a);
                idnumber++;
                Hf_out << idnumber << " " << Productname << " " << Number << " " << Pyear << endl;
            }
            else if (y == center.Y + 2)
            {
                system("cls");
                cout << "Please enter the name of product" << endl;
                cin.ignore();
                getline(cin, Productname);
                cout << "How many " << Productname << "s do you want to add?" << endl;
                cin >> Number;
                SoftW a(idnumber, Number, Productname);
                Soft.push_back(a);
                idnumber++;
                Sf_out << idnumber << " " << Productname << " " << Number << endl;
            }
            else if (y == center.Y + 4)
            {
                system("cls");
                cout << "Please enter the name of product" << endl;
                cin.ignore();
                getline(cin, Productname);
                cout << "How many " << Productname << "s do you want to add?" << endl;
                cin >> Number;
                cout << "Please enter the name of Mobile?" << endl;
                cin.ignore();
                getline(cin, MobileName);
                Decoration a(idnumber, Number, Productname, MobileName);
                Dec.push_back(a);
                idnumber++;
                Df_out << idnumber << " " << Productname << " " << Number << " " << MobileName << endl;
            }
            else if (y == center.Y + 6)
            {
                system("cls");
                cout << "Please enter the name of product" << endl;
                cin.ignore();
                getline(cin, Productname);
                cout << "How many " << Productname << "s do you want to add?" << endl;
                cin >> Number;
                cout << "What is the mobile OS?" << endl;
                cin.ignore();
                getline(cin, OSName);
                Repair a(idnumber, Number, Productname, OSName);
                Rep.push_back(a);
                idnumber++;
                Rf_out << idnumber << " " << Productname << " " << Number << " " << OSName << endl;
            }
            system("cls");
            break;
        }
        gotoxy(x - 5, y);
        cout << "    ";
        switch (ch)
        {
        case 72: // Up arrow
            y = (y > startY) ? y - 2 : y;
            break;
        case 80: // Down arrow
            y = (y < endY) ? y + 2 : y;
            break;
        }
    }
    gotoxy(1, 30);
}


void Menu(vector<Decoration>& Dec, vector<Repair>& Rep, vector<HardW>& Hard, vector<SoftW>& Soft)
{
    system("cls");
    COORD center = getScreenCenter();
    int x = center.X - 5, y = center.Y - 5;
    int IDNumB, NumB, sw = 0;
    string Ed1, Ed2;
    char ch = 5;

    gotoxy(center.X, center.Y - 5);
    Sleep(300);
    cout << "Add a new Product";
    gotoxy(center.X, center.Y - 3);
    Sleep(300);
    cout << "Overall Listing";
    gotoxy(center.X, center.Y - 1);
    Sleep(300);
    cout << "Specific Product Listing";
    gotoxy(center.X, center.Y + 1);
    Sleep(300);
    cout << "Remove Product";
    gotoxy(center.X, center.Y + 3);
    Sleep(300);
    cout << "Edit Product";
    gotoxy(center.X, center.Y + 5);
    Sleep(300);
    cout << "Exit";

    while (ch != 27)
    {
        gotoxy(x, y);
        cout << "===>";
        ch = _getch();
        if (ch == 13) // Enter key
        {
            if (y == center.Y - 5)
            {
                AddProd(Dec, Rep, Hard, Soft);
                break;
            }
            else if (y == center.Y - 3)
            {
                system("cls");
                cout << "ID" << "\t" << "Q" << "\t" << "Name" << "\t" << "Date/Model/OS" << endl;
                for (int i = 0; i < Hard.size(); i++)
                {
                    Hard[i].Print();
                    cout << endl;
                }
                for (int i = 0; i < Soft.size(); i++)
                {
                    Soft[i].Print();
                    cout << endl;
                }
                for (int i = 0; i < Dec.size(); i++)
                {
                    Dec[i].Print();
                    cout << endl;
                }
                for (int i = 0; i < Rep.size(); i++)
                {
                    Rep[i].Print();
                    cout << endl;
                }
                system("pause>0");
                break;
            }
            else if (y == center.Y - 1)
            {
                system("cls");
                cout << "Which ID number do you want to check?" << endl;
                cin >> IDNumB;
                for (int i = 0; i < Hard.size(); i++)
                    if (Hard[i].GetId() == IDNumB) {
                        Hard[i].Print();
                    }
                for (int i = 0; i < Soft.size(); i++)
                    if (Soft[i].GetId() == IDNumB) {
                        Soft[i].Print();
                    }
                for (int i = 0; i < Dec.size(); i++)
                    if (Dec[i].GetId() == IDNumB) {
                        Dec[i].Print();
                    }
                for (int i = 0; i < Rep.size(); i++)
                    if (Rep[i].GetId() == IDNumB) {
                        Rep[i].Print();
                    }
                system("pause");
                break;
            }
            else if (y == center.Y + 1)
            {
                system("cls");
                cout << "Which ID number do you want to remove?" << endl;
                cin >> IDNumB;
                for (int i = 0; i < Hard.size(); i++)
                    if (Hard[i].GetId() == IDNumB) {
                        Hard.erase(Hard.begin() + i);
                        sw = 1;
                    }
                for (int i = 0; i < Soft.size(); i++)
                    if (Soft[i].GetId() == IDNumB) {
                        Soft.erase(Soft.begin() + i);
                        sw = 1;
                    }
                for (int i = 0; i < Dec.size(); i++)
                    if (Dec[i].GetId() == IDNumB) {
                        Dec.erase(Dec.begin() + i);
                        sw = 1;
                    }
                for (int i = 0; i < Rep.size(); i++)
                    if (Rep[i].GetId() == IDNumB) {
                        Rep.erase(Rep.begin() + i);
                        sw = 1;
                    }
                if (sw == 1)
                    cout << "ID=" << IDNumB << " Has been deleted successfully " << endl;
                else if (sw == 0)
                    cout << "ID=" << IDNumB << " Was not found, please try again " << endl;
                system("pause");
                break;
            }
            else if (y == center.Y + 3)
            {
                sw = 0;
                system("cls");
                cout << "Which ID number do you want to Edit?" << endl;
                cin >> IDNumB;
                cin.ignore();
                for (int i = 0; i < Hard.size(); i++)
                    if (Hard[i].GetId() == IDNumB) {
                        cout << "The ID you entered was this product:";
                        cout << endl;
                        Hard[i].Print();
                        cout << endl;
                        cout << "Name?" << endl;
                        getline(cin, Ed1);
                        Hard[i].SetBrand(Ed1);
                        cout << "Quantity?" << endl;
                        cin >> NumB;
                        Hard[i].SetNum(NumB);
                        sw = 1;
                        break;
                    }
                for (int i = 0; i < Soft.size(); i++)
                    if (Soft[i].GetId() == IDNumB)
                    {
                        cout << "The ID you entered was this product:";
                        cout << endl;
                        Soft[i].Print();
                        cout << endl;
                        cout << "Name?" << endl;
                        getline(cin, Ed1);
                        Soft[i].SetName(Ed1);
                        cout << "Quantity?" << endl;
                        cin >> NumB;
                        Soft[i].SetNum(NumB);
                        sw = 1;
                        break;
                    }
                for (int i = 0; i < Dec.size(); i++)
                    if (Dec[i].GetId() == IDNumB)
                    {
                        cout << "The ID you entered was this product:";
                        cout << endl;
                        Dec[i].Print();
                        cout << endl;
                        cout << "Mobile Name?" << endl;
                        getline(cin, Ed1);
                        Dec[i].SetMName(Ed1);
                        cin.ignore();
                        cout << "Name?" << endl;
                        getline(cin, Ed2);
                        Dec[i].SetPName(Ed2);
                        cout << "Quantity?" << endl;
                        cin >> NumB;
                        Dec[i].SetNum(NumB);
                        sw = 1;
                        break;
                    }
                for (int i = 0; i < Rep.size(); i++)
                    if (Rep[i].GetId() == IDNumB)
                    {
                        cout << "The ID you entered was this product:";
                        cout << endl;
                        Rep[i].Print();
                        cout << endl;
                        cout << "OSName?" << endl;
                        getline(cin, Ed1);
                        Rep[i].SetOSName(Ed1);
                        cin.ignore();
                        cout << "Name?" << endl;
                        getline(cin, Ed2);
                        Rep[i].SetPName(Ed2);
                        cout << "Quantity?" << endl;
                        cin >> NumB;
                        Rep[i].SetNum(NumB);
                        sw = 1;
                        break;
                    }
                if (sw == 0)
                {
                    cout << "ID=" << IDNumB << " Was not Found please try again :)" << endl;
                    system("pause");
                }
                break;
            }
            else if (y == center.Y + 5)
            {
                menu = false;
                gotoxy(1, 30);
                return;
            }
        }
        gotoxy(x, y);
        cout << "    ";
        switch (ch)
        {
        case 72: // Up arrow
            y = y > center.Y - 5 ? y - 2 : y;
            break;
        case 80: // Down arrow
            y = y < center.Y + 5 ? y + 2 : y;
            break;
        }
    }

    gotoxy(1, 30);
}
void initialiseProducts()
{
SoftW W10(1001,0,"Windows10");
SoftW VS(1002,0,"Visual Studio");
HardW Dell(1005,0,2018,"Dell");
HardW Ucom(1006,0,2018,"U Com");
HardW sony(1007,0,2018,"Sony");
HardW Ram(1003,0,2018,"Asus6GB");
HardW Cpu(1004,0,2018,"Core i5");
Repair Lcd(1008,0,"LCD","Android");
Repair LcD(1009,0,"LCD","iOS");
Repair touch(1010,0,"Touch","Android");
Repair Touch(1011,0,"Touch","iOS");
Decoration Guard(1000,0,"Guard","S8");
Decoration GlassA(1012,0,"Glass","Honor 7");
Decoration GlassB(1013,0,"Glass","Iphone 7");
Decoration GlassC(1014,0,"Glass","J510");
vector <Decoration> Dec;
vector <Repair> Rep;
vector <HardW> Hard;
vector <SoftW> Soft;
Dec.push_back(Guard);
Dec.push_back(GlassA);
Dec.push_back(GlassB);
Dec.push_back(GlassC);
Rep.push_back(Lcd);
Rep.push_back(LcD);
Rep.push_back(touch);
Rep.push_back(Touch);
Hard.push_back(Dell);
Hard.push_back(Ucom);
Hard.push_back(sony);
Hard.push_back(Ram);
Hard.push_back(Cpu);
Soft.push_back(VS);
Soft.push_back(W10);
LoadFile(Dec,Rep,Hard,Soft);
while(menu==true)
Menu(Dec,Rep,Hard,Soft);
}

int main()
{
 initialiseProducts();
}

