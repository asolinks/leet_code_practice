#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> result;
        int index = 0;
        
        while (index < words.size()) {
            int totalChars = words[index].length();
            int last = index + 1;

            
            while (last < words.size()) {
                if (totalChars + 1 + words[last].length() > maxWidth) break;
                totalChars += 1 + words[last].length(); // 1 for the space
                last++;
            }

            int gaps = last - index - 1;
            std::string line;

            
            if (last == words.size() || gaps == 0) {
                for (int i = index; i < last; i++) {
                    line += words[i];
                    if (i < last - 1) line += " ";
                }
                
                line += std::string(maxWidth - line.length(), ' ');
            } else {
                
                int totalSpaces = maxWidth - totalChars + gaps;
                int spacePerGap = totalSpaces / gaps;
                int extraSpaces = totalSpaces % gaps;

                for (int i = index; i < last - 1; i++) {
                    line += words[i];
                    line += std::string(spacePerGap + (i - index < extraSpaces ? 1 : 0), ' ');
                }
                line += words[last - 1]; 
            }

            result.push_back(line);
            index = last;
        }

        return result;
    }
};

int main() {
    Solution sol;
    std::vector<std::string> words = {"This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;

    std::vector<std::string> justified = sol.fullJustify(words, maxWidth);

    std::cout << "Justified Text:\n";
    for (const std::string& line : justified) {
        std::cout << "\"" << line << "\"" << std::endl;
    }

    return 0;
}