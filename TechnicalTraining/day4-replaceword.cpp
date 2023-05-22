#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void findAndReplace(string& str, const string& findStr, const string& replaceStr) {
    size_t pos = 0;
    while ((pos = str.find(findStr, pos)) != string::npos) {
        str.replace(pos, findStr.length(), replaceStr);
        pos += replaceStr.length();
    }
}

int main() {
    // Open the input file
    ifstream inFile("input.txt");
    if (!inFile) {
        cerr << "Error: Could not open input file." << endl;
        return 1;
    }
    
    // Read the input file into a string
    string text((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());
    inFile.close();
    
    // Modify the text using the findAndReplace function
    string findStr = "falling";
    string replaceStr = "hiking";
    findAndReplace(text, findStr, replaceStr);
    
    // Open the output file
    ofstream outFile("output.txt");
    if (!outFile) {
        cerr << "Error: Could not open output file." << endl;
        return 1;
    }


    
    // Write the modified text to the output file
    outFile << text;
    outFile.close();
    
    return 0;
}
