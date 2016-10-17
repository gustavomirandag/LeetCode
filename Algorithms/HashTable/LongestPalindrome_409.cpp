#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
	int longestPalindrome(string s) {
		unordered_map<char, int> letters;

		for (int i = 0; i<s.size(); i++) {
			if (letters.find(s[i]) == letters.end())
				letters[s[i]] = 1;
			else
				letters[s[i]]++;
		}

		bool addedUniqueLetter = false;
		int count = 0;
		for (auto iter : letters) {
			if (iter.second % 2 == 0)
				count += iter.second;
			else {
				if (iter.second>1) {
					count += (iter.second / 2) * 2;
					if (!addedUniqueLetter) {
						addedUniqueLetter = true;
						count++;
					}
				}
				else {
					if (!addedUniqueLetter) {
						addedUniqueLetter = true;
						count++;
					}
				}

			}
		}

		return count;
	}
};