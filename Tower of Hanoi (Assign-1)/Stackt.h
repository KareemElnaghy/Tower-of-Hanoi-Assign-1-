//
//  Header.h
//  Tower of Hanoi (Assign-1)
//
//  Created by Kareem Elnaghy on 9/12/23.
//

#ifndef Header_h
#define Header_h

#include <string>
#include <iostream>
using namespace std;

template <class T>      //template class prototype
class Stackt{
    T *arr;
    string pegName;
    int top;
    int maxSize;
    
public:
    Stackt(int, string);
    Stackt();
    void push(int);
    int pop();
    bool isEmpty();
    bool isFull();
    static int counter; //to counter the number of moves
    string getName();
    int getTop();   //returns top element
    void printStack();

};

template <class T>
void printTowers();

template <class T>
int Stackt<T>::counter = 0;     //initialising static variable

template <class T>
void moveDisk(Stackt<T> &Source, Stackt<T> &Target);    //prototype for move Disk function

template <class T>
void Towers(int N, Stackt<T> &Source, Stackt<T> &Target, Stackt<T>& Aux); //prototype for move Tower of Hanoi recursive function

template <class T>
Stackt<T>::Stackt(){        //default constructor
    top = -1;
    maxSize = 0;
    pegName = " ";
    arr = new T [maxSize];
}

template <class T>
Stackt<T>::Stackt(int N, string name){      //Argumentative constructor which takes the number of disks and the name of the peg
    maxSize = N;
    pegName = name;
    top = -1;
    arr = new T [maxSize];
    
    int i;
    if(name == "Start")     //finds the start peg and initilises the stack with the disk numbers 1,2,3
    {
       
        int j = 0;
        for(i = N; i>=1; i--)
        {
            arr[j] = i;
            j++;
        }
        top = maxSize-1;
    }
    else
    {
        for(i = 0; i<maxSize; i++)
            arr[i] = 0;
            }
    
}




template <class T>
void Stackt<T>::push(int x)     //adds value to the stack
{
    if(isFull())
    {
        //cout<<"The Stack is Full"<<endl;
        return;
    }
    else
    {
        if(top < maxSize - 1)
        {
            top++;
            arr[top]= x;
        }
    }
}

template <class T>
int Stackt<T>::pop()        //removes value from the stack
{
    int value = 0;
    if(isEmpty())
    {
        //cout<<"The Stack is Empty"<<endl;
        return -1;
    }
    else{
        if(top > -1)
        {
            value = arr[top];
            top--;
        }
    }
    return value;
    
}

template <class T>
bool Stackt<T>::isEmpty()       //determines whether a stack is empty
{
    if(top == -1)
        return true;
    else
        return false;
}

template <class T>
bool Stackt<T>::isFull()        //determines whether a stack is full
{
    if(top == maxSize-1)
        return true;
    else
        return false;
    
}

template <class T>
int Stackt<T>::getTop()     //returns the top element
{
    return arr[top];
}

template <class T>
string Stackt<T>::getName()    //returns the name of the peg
{
    return pegName;
}

template <class T>
void Towers(int N, Stackt<T> &Source, Stackt<T> &Target, Stackt<T>& Aux)        //tower of hanoi function
{
    if(N==1)        //base case if there is one disk
    {
        int disk = Source.getTop();         //sets the disk as the top element of the starting peg
        Source.pop();
        Target.push(disk);      //add element to the target peg
        cout<<"Move disk "<<disk<<" from " << Source.getName() << " to "<< Target.getName()<<endl;
        printTowers(Source, Target, Aux);
        Stackt<T>::counter ++;
    }
    else        //recursive case
    {
        Towers(N-1, Source, Aux, Target);
        int disk = Source.getTop();
        Source.pop();
        Target.push(disk);
        
        cout<<"Move disk "<<disk<<" from " << Source.getName() << " to "<< Target.getName()<<endl;
        printTowers(Source, Target, Aux);
        Stackt<T>::counter ++;
        Towers(N-1, Aux, Target, Source);
    }
}

template <class T>
void Stackt<T>:: printStack()       //print function that displays the peg in the correct format
{
    if(this->isEmpty())
    {
        cout<<"Empty";
        return;
    }
    
    int i;
    for(i = 0; i<=top; i++)
        cout<<arr[i]<<" ";
    
}

template <class T>
void printTowers(Stackt<T>&A, Stackt<T>&B, Stackt<T>&C )
{
    Stackt<T>* temp[3] = {&A,&B,&C};    //create a temp array of pointers to contain the three pegs
    
    //loops and conditions to rearrange the output into the correct order e.g. Start then Aux then End
    for(int i = 0; i<3; i++)
    {
        if(temp[i]->getName() == "Start"){
            cout<<"Start: ";temp[i]->printStack();cout<<endl;}
  
    }
 
    for(int i = 0; i<3; i++)
    {
        if(temp[i]->getName() == "Aux"){
            cout<<"Aux: ";temp[i]->printStack();cout<<endl;}
    }
    
    for(int i = 0; i<3; i++)
    {
        if(temp[i]->getName() == "End"){
            cout<<"End: ";temp[i]->printStack();cout<<endl;}
    }
   
    cout<<endl;
    
}

#endif /* Header_h */



