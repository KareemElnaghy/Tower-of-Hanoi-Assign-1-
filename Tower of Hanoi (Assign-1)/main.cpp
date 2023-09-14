//
//  main.cpp
//  Tower of Hanoi (Assign-1)
//
//  Created by Kareem Elnaghy on 9/12/23.
//

#include "Stackt.h"
#include <iostream>
using namespace std;

int main()
{
    int N = 0;
    
    cout<<"Enter the number of disks: ";
    cin>> N;        //input the number of disks
    cout<<endl;
    
    Stackt<int> pegA(N, "Start");   //declaring the three pegs as objects to the stack
    Stackt<int> pegB(N, "Aux");
    Stackt<int> pegC(N, "End");
    
    cout<<"Stacks before Tower of Hanoi: "<<endl;
    
    printTowers(pegA, pegB, pegC);
    
    cout<<endl;
    
    Towers(N, pegA, pegC, pegB);
    
    cout<<endl;
    
    cout<<"Number of Moves: "<<Stackt<int>:: counter<<endl; //displays the number of moves made
    
    
}

