#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

//SlidingWindow technique
int LengthOfLongestSubstring(const string& str) {
    unordered_map<char, int> charIndexMap;
    int longest = 0;
    int left = 0;

    for (int right = 0; right < str.length(); right++) {
        char currentChar = str[right];

        if (charIndexMap.find(currentChar) != charIndexMap.end() && charIndexMap[currentChar] >= left) {
            left = charIndexMap[currentChar] + 1;
        }

        charIndexMap[currentChar] = right;

        int windowLength = right - left + 1;
        if (windowLength > longest) {
            longest = windowLength;
        }
    }

    return longest;
}

int main() {
    string input = "abcabcbb";
    cout << LengthOfLongestSubstring(input) << endl;
    return 0;
}
