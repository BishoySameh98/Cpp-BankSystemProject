// BankSystemProject.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include"Screens.h"

using namespace std;

int main()
{
    Client C;
    Client F;

    C.setId(11);
    C.setName("BishoySAAA");
    C.setBalance(1500.0);

    F.setId(22);
    F.setName("BeboSameeh");
    F.setBalance(2000.0);

    Screens::runApp();
   
}

