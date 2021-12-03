#include <fstream>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ifstream inFile("input.txt");  
    if(!inFile) {
        cout << "Unable to open file input.txt";
        exit(1);
    }  

    vector<string> temp;
    vector<string> common;
    vector<string> leastCommon;
    vector<string> mirror;

    string s;
    int sus = 0;
    while(inFile >> s) {
        common.push_back(s);
        leastCommon.push_back(s);
    }
    for(int i = 0; i < 12; i++) {

        //OXY
        temp = common;
        common.clear();
        for(int j = 0; j < temp.size() && temp.size() > 1 ; j++) {
            if(temp[j][i] == '1') {
                sus++;
                common.push_back(temp[j]);
            }
            else {
                sus--;  
                mirror.push_back(temp[j]);
            }
        }
        if(sus < 0) { //ho più zeri che uni
            common.swap(mirror);
        }
        mirror.clear();
        sus = 0;

        //C02
        temp = leastCommon;
        leastCommon.clear();
        for(int j = 0; j < temp.size() && temp.size() > 1; j++) {
            if(temp[j][i] == '1') {
                sus++;
                mirror.push_back(temp[j]);
            }
            else {
                sus--;  
                leastCommon.push_back(temp[j]);
            }
        }
        if(sus < 0) { 
            leastCommon.swap(mirror);
        }
        mirror.clear();
        sus = 0;
    }
    cout << stoi(common[0], 0, 2) << endl;
    cout << stoi(leastCommon[0], 0, 2) << endl;
    cout << stoi(common[0], 0, 2) * stoi(leastCommon[0], 0, 2);
    return 0;
}

/*
string line = "";
    int unos[12] = {};
    while(inFile >> line) {
        for(int i = 0; i < line.size(); i++) {
            if(line[i] == '1') {
                (unos[i])++;
            }
            else (unos[i])--;
        }
    }
    inFile.close();
    int gamma = 0;
    int epsilon = 0;
    for(int i = 0; i < line.size(); i++) {
        if(unos[i] > 0) {
            gamma += pow(2, line.size() - i - 1);
        }
        else {
            epsilon += pow(2, line.size() - i - 1);
        }
    }
    cout << (epsilon*gamma);
*/