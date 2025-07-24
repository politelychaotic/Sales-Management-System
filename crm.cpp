#include <iostream.h>
#include <fstream.h>
#include <process.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <conio.h>
#include <dos.h>

// class Menu
// Controls over functions

class menu 
{
public:
    void main_menu(void);
private:
    void edit_menu(void);
};

class product
{
public:
    void add_item(void);
    void delete_item(void);
    void modify_item(void);
    void list_of_items(void);
    void purchase(void);
private:
    int last_code(void);
    void delete_record(int);
    void modify_record(int);
    void display_record(int);
    int item_found(int);
    int recordno(int);
    void sort(void);

    int itemcode;
    char itemname[30];
    float itemcost, itemprice;
};

class account
{
public:
    void bill_list(void);
    void prepare_bill(void);
    int last_billno(void);
    void add_bill(int, int t_itemcode, char*t_itemname, float t_qty, float t_cost, float t_price);
private:
    int code, billno, length;
    int dd, mm, yy;
    float cost, price, quantity;
    char name[30];
};


//This function creates main menu and calls other funcs
void menu::main_menu(void)
{
    clrscr();
    char ch;
    while(1)
    {
        clrscr();
        gotoxy(10,3);
        cout << "*******************************************************";
        gotoxy(10,23);
        cout << "*******************************************************";
        gotoxy(28,6);
        cout << " SALES MANAGEMENT";
        gotoxy(28,7);
        cout << "---------------------------";
        gotoxy(30,9);
        cout << "1: Purchase Products";
        gotoxy(30,11);
        cout << "2: List of Products";
        gotoxy(30,13);
        cout << "3: Edit Products File";
        gotoxy(30,15);
        cout << "4: Bills Report";
        gotoxy(30,17);
        cout << "0: Quit";
        gotoxy(30,20);
        cout << "Enter Option:";
        ch = getche();
        if(ch=='1') 
        {
            product p;
            p.purchase();
        }
        else if(ch=='2')
        {
            product p;
            p.list_of_items();
        }
        else if(ch=='3')
        {
            edit_menu();
        }
        else if(ch=='4')
        {
            account a;
            a.bill_list();
        }
        else if(ch=='0')
        {
            break;
        }
    }
}


// EDIT MENU

void menu::edit_menu(void)
{
    char ch;
    while(1)
    {
        clrsrc();
        gotoxy(10,3);
        cout << "**************************************************";
        gotoxy(10,23);
        cout << "**************************************************";
        gotoxy(32,6);
        cout << "Edit Menu";
        gotoxy(32,7);
        cout << "---------------------";
        gotoxy(32,10);
        cout << "1: Add Products";
        gotoxy(32,12);
        cout << "2: Modify Products";
        gotoxy(32,14);
        cout << "3: Delete Products";
        gotoxy(32,16);
        cout << "0: Exit";
        gotoxy(32,19);
        cout << "Enter Option:";
        ch=getche();
        if(ch=='1')
        {
            product p;
            p.add_item();
            break;
        }
        else if(ch=='2')
        {
            product p;
            p.modify_item();
            break;
        }
        else if(ch=='3')
        {
            product p;
            p.delete_item();
            break;
        }
        else if(ch=='0')
        {
            break;
        }
    }
}


// Returns code of last record in the product file (product.dat)

int product::last_code(void)
{
    fstream file;
file.open("product.dat", ios::in);
file.seekg(0,ios::beg);
int t=0;
while(file.read((char*)this,sizeof(product)))
    t = itemcode;
fileclose();
return t;
}

// Displays the list of items

void product::list_of_items(void)
{
    clrscr();
    fstream file;
    file.open("product.dat", ios::in);
    file.seekg(0);
    int row = 6, found = 0;
    gotoxy(30,2);
    cout << "List of Items:";
    gotoxy(3,4);
    cout << "Item Code | Item Name | Item Cost | Item Price";
    gotoxy(2,5);
    cout << "********************************************************";
    while(file.read((char*)this, sizeof(product)))
    {
        delay(10);
        found = 1;
        gotoxy(5,row);
        cout << itemcode;
        gotoxy(14,row);
        cout << itemname;
        gotoxy(37,row);
        cout << itemcost;
        cout << itemprice;
        if(row == 22)
        {
            row = 5;
            gotoxy(1,25);
            cout << "Press any key to continue...";
            getche();
            clrsrc();
            gotoxy(30,2);
            cout << "List of Items";
            gotoxy(3,4);
            cout << "Item Code | Item Name | Item Cost | Item Price";
            gotxy(2,5);
            cout << "********************************************************";   
        }
        else
            row++;
    }
    if(!found)
    {
        gotoxy(5,10);
        cout << "\nRecords Not Found.";
    }
    gotoxy(1,25);
    cout << "Press any key to continue...";
    getche();
    file.close();
}


//Function adds products to (product.dat)

void product::add_item(void)
{
    
}
