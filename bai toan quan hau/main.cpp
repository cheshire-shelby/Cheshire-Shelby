#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;
void solve(int);
void printsolution();
bool check(int,int);
void __init__();



/* Using j for row index
         i for column index
    The idea is to place queens one-by-one in different column, start at column 1 aka
    the leftmost one. When we place a piece in a column, we check if there is 
    no already placed queen. In the current column, we find a row for which there is no clash,
    mark it( both of column and row). If we cant find any row, we backtrack.
    Basically, we need to ensure 4 things:
    1. there is no two queens share a column.
    2. there is no two queens share a row.
    3. there is no two queens share a diagonal
*/

int pos[50], n, save[50];
int main()
{    
    __init__();
    cout<<"please enter the size of board: ";
    cin>>n;

    if (n==2 || n==3)
    {
        cout<<"can't place any queens!!!";
        return 0;
    }

    solve(1);
    return 0;
}
void __init__()
{
    int i;
    for (i = 1; i<= 50; i++)
        save[i] = 0;
}
void solve(int col) //solve the puzzle
{       
    int j;
    if(col > n)
        printsolution();
    else
        for(j = 1; j<=n; j++) // check n rows
            if( save[j] == 0)
            { 
                if(check(col,j) == true)
                {
                    pos[col] = j; //saving the satisfying pos
                    save[j] = 1; // mark this pos used
                    solve(col + 1);
                    save[j] = 0;//backtrack
                }
            }
}  

void printsolution() 
{ 
    static int count = 1;
    int i;
    cout<<"case:"<<count++<<endl;
    cout<<"-- -- -- -- -- -- -- --"<<endl;
    for (i = 1; i <= n; i++) 
        cout<<"|"<<pos[i]<<"|";
    cout<<"\n\n";
} 

bool check(int x,int y)
// create a bool function checking the position of queen
{
    for(int i = 1; i<x; i++)
    {
    if (pos[i] == y)
        return false;
    if (abs(i-x) == abs(pos[i]-y))
        return false;
    }
    return true;        
}   
