#include<iostream>
#include<vector>
#include<algorithm>

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int index = 0;
        
        while (index < words.size()) {
            int totalChars = words[index].length();
            int last = index + 1;

            // Greedily add as many words as fit
            while (last < words.size()) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length(); // 1 for the space
                last++;
            }

            int gaps = last - index - 1;
            string line;

            
            if (last == words.size() || gaps == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                
                line += string(maxWidth - line.length(), ' ');
            } else {
                // Full justification
                int totalSpaces = maxWidth - totalChars + gaps;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int i = index; i < last - 1; i++) {
                    line += words[i];
                    line += string(spacePerGap + (i - index < extraSpaces ? 1 : 0), ' ');
                }
                line += words[last - 1]; 
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};