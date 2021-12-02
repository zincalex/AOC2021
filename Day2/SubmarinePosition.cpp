#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
#define forward "forward"
#define up "up"
#define down "down"

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream inFile;
    inFile.open(".\\input.txt");
    if(!inFile) {
        cout << "Unable to open file input.txt";
        exit(1);
    }
    int depth = 0; 
    int horizontal_pos = 0;
    int aim = 0;
    string movement;
    int steps;
    while(inFile >> movement >> steps) {
        if(movement.compare(down) == 0) {
            aim += steps;
        }
        else if(movement.compare(up) == 0) {
            aim -= steps;
        }
        else {
            horizontal_pos += steps;
            depth += steps * aim;
        }
    }
    auto result = depth*horizontal_pos;
    cout << result;
    
    inFile.close();
    return 0;
}


/* prima parte

    int depth = 0; 
    int horizontal_pos = 0;
    string movement;
    int steps;
    while(inFile >> movement >> steps) {
        if(movement.compare(forward) == 0) {
            horizontal_pos += steps;
        }
        else if(movement.compare(up) == 0) {
            depth -= steps;
        }
        else depth += steps;
    }
    cout << (depth*horizontal_pos);
*/