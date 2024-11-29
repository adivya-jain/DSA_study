#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <cmath>

using namespace std;

unordered_map<int, vector<char>> charMap = {
    {92229, {'A', 'D'}}, {93339, {'B'}}, {92222, {'C', 'F'}}, {93333, {'E'}}, {92336, {'G'}}, 
    {91119, {'H', 'N', 'U'}}, {22322, {'I'}}, {62229, {'J'}}, {92226, {'K'}}, {91111, {'L'}}, 
    {91519, {'M', 'W'}}, {72227, {'O'}}, {92225, {'P'}}, {92339, {'Q'}}, {93336, {'R'}}, 
    {63336, {'S'}}, {11911, {'T'}}, {71117, {'V'}}, {22122, {'X'}}, {62226, {'Y'}}, {23332, {'Z'}}
};


int calcuColumnValue(int startIdx, const vector<string>& Grid) {
    string valueStr = "";
    for (int row = 0; row < 5; row++) {
        int colSum = 0;
        for (int col = 0; col < 9; col++) {
            colSum += Grid[col][startIdx + row] - '0';  
        }
        valueStr += to_string(colSum);
    }
    return stoi(valueStr);  
}

char getCharacterFromValue(int startIdx, const vector<string>& ledGrid) {
    int columnValue = calcuColumnValue(startIdx, ledGrid);
    if (columnValue == 91519) {
        return (ledGrid[8].substr(startIdx, 5) == "11111") ? 'W' : 'M';
    } else if (columnValue == 91119) {
        if (ledGrid[1].substr(startIdx, 5) == "11001") return 'N';
        if (ledGrid[8].substr(startIdx, 5) == "11111") return 'U';      
        return 'H';
    } else if (columnValue == 92222) {
        return (ledGrid[8].substr(startIdx, 5) == "11111") ? 'C' : 'F';
    } else if (columnValue == 92229) {
        return (ledGrid[8].substr(startIdx, 5) == "10001") ? 'A' : 'D';
    } else {
        return charMap[columnValue][0]; 
    }
}

string mergeGridRows(const vector<string>& ledGrid) {
    int totalCols = ledGrid[0].size();
    string merged = ledGrid[0];
    for (int i = 1; i < 9; i++) {
        for (int j = 0; j < totalCols; j++) {
            merged[j] = (merged[j] - '0' | ledGrid[i][j] - '0') + '0';
        }
    }
    return merged;
}

string decodeLedGrid(const vector<string>& ledGrid) {
    string mergedGrid = mergeGridRows(ledGrid);
    string decodedResult = "";
    int idx = 0;

    while (idx < mergedGrid.size()) {
        if (mergedGrid[idx] == '1') {
            decodedResult += getCharacterFromValue(idx, ledGrid);
            idx += 5; 
        } else {
            idx++; 
        }
    }
    return decodedResult;
}


int main() {
    int numRows = 9;
    vector<string> segmentGrid(numRows);
    for (int i = 0; i < numRows; i++) {
        cin >> segmentGrid[i];
    }

    cout << decodeLedGrid(segmentGrid) << endl;
    return 0;
}
