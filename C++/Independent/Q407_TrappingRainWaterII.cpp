#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cctype>
#include <algorithm>
using namespace std;

// Function to parse a string into a 2D vector
std::vector<std::vector<int>> parse2DVector(const std::string& input) {
    std::vector<std::vector<int>> result;
    std::string temp = input;

    // Remove the outer brackets
    if (temp.front() == '[' && temp.back() == ']') {
        temp = temp.substr(1, temp.size() - 2);
    }

    std::stringstream ss(temp);
    std::string row;

    // Parse each row
    while (std::getline(ss, row, ']')) {
        if (row.front() == ',') {
            row = row.substr(1); // Remove leading comma for subsequent rows
        }
        if (!row.empty() && row.front() == '[') {
            row = row.substr(1); // Remove leading '['
        }

        std::stringstream rowStream(row);
        std::string number;
        std::vector<int> currentRow;

        // Parse numbers in the row
        while (std::getline(rowStream, number, ',')) {
            // Trim spaces and check if the number is valid
            number.erase(std::remove_if(number.begin(), number.end(), ::isspace), number.end());
            if (!number.empty() && std::all_of(number.begin(), number.end(), ::isdigit)) {
                currentRow.push_back(std::stoi(number));
            } else if (!number.empty()) {
                throw std::invalid_argument("Invalid number in input: " + number);
            }
        }

        if (!currentRow.empty()) {
            result.push_back(currentRow);
        }
    }

    return result;
}

void print2DVector(vector<vector<int>>& vec) {
    cout << endl;
    for(int i = 0; i < vec.size(); i++) {
        for(int j = 0; j < vec[i].size(); j++) {
            cout << vec[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int m = heightMap.size();
        int n = heightMap[0].size();

        vector<vector<int>> grid(m, vector<int>(n, 0));


        return height;
    }
};

int main(int argc, char* argv[]) {

    if(argc < 2) {
        std::cerr << "Error: Please provide a string input in the format [[...],[...]] as a command-line argument.\n";
        return 1;
    }
    
    string input = argv[1];
    vector<vector<int>> map = parse2DVector(input);
    cout << "input map: ";
    print2DVector(map);

    Solution s;
    int ans = s.trapRainWater(map);
    cout << "ans: " << ans << endl;

    return 0;
}