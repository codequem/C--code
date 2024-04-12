#include <iostream>
#include <algorithm>

using namespace std;

#define ios ios::sync_with_stdio(false),cin.tie(nullptr)

int main (void)
{
    int k;
    cin>>k;
    for(int i=0;i<k;i++)
    {
        int row,col;
        cin>>row>>col;
        bool array[row][col];
        char record;
        for(int j=0;j<row;j++)
        for(int s=0;s<col;s++)
        {
            cin>>record;
            if(record=='.')
            array[j][s]=false;
            else
            array[j][s]=true;
        }
        int row_lack=row,col_lack=col;
        for(int j=0;j<row;j++)
        for(int s=0;s<col;s++)
        {
            if(array[j][s])
            {
                
            }
        }
    }
}