#include<bits/stdc++.h>
using namespace std;

#define ARR_SIZE 100
int data[ARR_SIZE][ARR_SIZE], singleArray[ARR_SIZE*ARR_SIZE+1];

//merge sort begin
void bubble_sort(int data[], int len)
{
    for(int i=0;i<len;i++){
        for(int j=0;j<len-i;j++){
            if(data[j] > data[j+1]){
                swap(data[j], data[j+1]);
            }
        }
    }
    return;
}
//Bubble sort end


void takeValue(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cin>>data[i][j];
        }
    }
}

void display2D(int n)
{
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<data[i][j]<<" ";
        }
        cout<<endl;
    }
}

void sort2D(int n)
{
    int l = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            singleArray[l] = data[i][j];
            l++;
        }
    }
    sort(singleArray, singleArray+(n*n)); // here you can make own sorting system.i used built-in sort for simplicity.
    // for(int i=0;i<n*n;i++){
    //     cout<<singleArray[i]<<" ";
    // }
    // cout<<endl;
    l=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            data[i][j] = singleArray[l];
            l++;
        }
    }
    display2D(n);
}

int main()
{
    int n;
    cout<<"Enter row/col number for square matrix 2D array: "<<endl;
    cin>>n;
    cout<<"Enter the values: \n"; 
    takeValue(n);
    cout<<"Your entered values are: "<<endl;
    display2D(n);
    cout<<"Sort 2D:"<<endl;
    sort2D(n);
    return 0;   
}
