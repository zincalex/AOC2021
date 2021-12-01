#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*Prima parte
int num, prev;
    int major = 0;
    inFile >> prev;
    while(inFile >> num) {
        if(num > prev) 
            major++;
        prev = num;
    }
    cout << major;
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream inFile;
    inFile.open(".\\input.txt");
    if(!inFile) {
        cout << "Unable to open file input.txt";
        exit(1);
    }
    int prev1, prev2, prev3;
    int num1, num2, num3;
    int major = 0;
    inFile >> prev1 >> prev2 >> prev3;
    int sumprev = prev1 + prev2 + prev3;
    num1 = prev2;
    num2 = prev3;
    while(inFile >> num3) {
        int sum = num1 + num2 + num3;
        if(sum > sumprev) 
            major++;
        sumprev = sum;
        num1 = num2;
        num2 = num3;
    }
    cout << major;
    inFile.close();
    return 0;
}