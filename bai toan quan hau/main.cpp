#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
void solve(int);
void printsolution();
bool check(int,int);



/* Using j for row index
         i for column index
    The idea is to place queens one-by-one in different column, start at column 1 aka
    the leftmost one. When we place a piece in a column, we check if there is 
    no already placed queen. In the current column, we find a row for which there is no clash,
    mark it( both of column and row). If we cant find any row, we backtrack and return false.
    Basically, we need to ensure 4 things:
    1. there is no two queens share a column.
    2. there is no two queens share a row.
    3. there is no two queens share a top-right to left-bottom and top-left to bottom-right diagonal
*/

int pos[50], n;
int main()
{
    cout<<"please enter the size of board: ";
    cin>>n;
    if (n==2 || n==3)
    {
        cout<<"can't place any queens!!!";
        return 0;
    }
    solve(0);
    return 0;
}

void solve(int col) // col = i
{       
    int j;
    for(j = 0; j<n; j++)
        { 
        if(check(col,j) == true)
            {
            pos[col] = j;
            if(col == n)
                printsolution();
            else
                solve(col + 1);               
            }
        }
}  

void printsolution() 
{ 
    int i;
    for (i = 0; i < n; i++) 
        cout<<pos[i]<<" ";
    cout<<"\n";
} 

bool check(int x,int y)
// create a bool function checking the position of queen
{
    for(int i = 0; i<x; i++)
    {
    if (pos[x] == y)
        return false;
    if (abs(i-x) == abs(pos[i]-y))
        return false;
    }
    return true;        
}   
