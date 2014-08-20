/*
 ID: dearxia1
 PROG: transform
 LANG: C++
 */

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

//Campare two squares
bool cmp(char a[][10], char b[][10], int num)
{
    for (int i = 0; i < num; i ++) {
        for (int j = 0; j < num; j ++) {
            if (a[i][j] != b[i][j])
                return false;
        }
    }
    return true;
}

//#1transform: 90 degree
void trans_one(char a[][10], char b[][10], int num)
{
    for (int i = 0; i < num; i ++) {
        for (int j = 0; j < num; j ++) {
            b[i][j] = a[num -1 - j][i];
        }
    }
}

//#2transform: 180 degree
void trans_two(char a[][10], char b[][10], int num)
{
    for (int i = 0; i < num; i ++) {
        for (int j = 0; j < num; j ++) {
            b[i][j] = a[num - 1 - i][num - 1 - j];
        }
    }
}

//#3transform: 270 degree
void trans_three(char a[][10], char b[][10], int num)
{
    for (int i = 0; i < num; i ++) {
        for (int j = 0; j < num; j ++) {
            b[i][j] = a[j][num - 1 -i];
        }
    }
}

//#4transform: Reflection
void trans_four(char a[][10], char b[][10], int num)
{
    for (int i = 0; i < num; i ++) {
        for (int j = 0; j < num; j ++) {
            b[i][j] = a[i][num - 1 - j];
        }
    }
}

int main()
{
    //    ofstream fout ("transform.out");
    //    ifstream fin ("transform.in");
    int n, trans = 7;
    
//Input
    cin >> n;
    char before[10][10], after[10][10], temp[10][10], temp2[10][10];
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> before[i][j];
        }
    }
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n; j ++) {
            cin >> after[i][j];
        }
    }

//#6: No change
    if (cmp(before, after, n))
        trans = 6;
    
//#5: Combination
    trans_four(before, temp, n);
    
//#5 => #1
    trans_one(temp, temp2, n);
    if (cmp(temp2, after, n))
        trans = 5;
    
//#5 => #2
    trans_two(temp, temp2, n);
    if (cmp(temp2, after, n))
        trans = 5;
    
//#5 => #3
    trans_three(temp, temp2, n);
    if (cmp(temp2, after, n))
        trans = 5;
    
//#4: Reflection
    if (cmp(temp, after, n))
        trans = 4;

//#3: 270
    trans_three(before, temp, n);
    if (cmp(temp, after, n))
        trans = 3;
    
//#2: 180
    trans_two(before, temp, n);
    if (cmp(temp, after, n))
        trans = 2;
    
//#1: 90
    trans_one(before, temp, n);
    if (cmp(temp, after, n))
        trans = 1;

//Output
    cout << trans << '\n';

    return 0;
}
