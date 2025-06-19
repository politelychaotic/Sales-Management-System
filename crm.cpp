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

}
