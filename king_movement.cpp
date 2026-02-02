#include <iostream>
#include <bits/stdc++.h>
using namespace std;    
string startingPosition{};
string endingPosition{};
int counter{};
vector<string> printarray;
void movement(string current, string target)
{
    if (current == target)
        return;
    if (current[0] < target[0] && current[1] < target[1])
    {
        printarray.push_back("RU");
        current[0]++;
        current[1]++;
    }
    else if (current[0] < target[0] && current[1] > target[1])
    {
        printarray.push_back("LU");
        current[0]++;
        current[1]--;
    }
    else if (current[0] > target[0] && current[1] < target[1])
    {
        printarray.push_back("RD");
        current[0]--;
        current[1]++;
    }
    else if (current[0] > target[0] && current[1] > target[1])
    {
        printarray.push_back("LD");
        current[0]--;
        current[1]--;
    }
    else if (current[0] < target[0])
    {
        printarray.push_back("U");
        current[0]++;
    }
    else if (current[0] > target[0])
    {
        printarray.push_back("D");
        current[0]--;
    }
    else if (current[1] < target[1])
    {
        printarray.push_back("R");
        current[1]++;
    }
    else if (current[1] > target[1])
    {
        printarray.push_back("L");
        current[1]--;
    }
    
    movement(current, target);  
    
}
int main(){
    cin >> startingPosition;
    cin >> endingPosition;
    movement(endingPosition, startingPosition);
    cout << printarray.size() << endl;
    for (const string &move : printarray)   
    {
        cout << move << endl;
    }
    return 0;



}