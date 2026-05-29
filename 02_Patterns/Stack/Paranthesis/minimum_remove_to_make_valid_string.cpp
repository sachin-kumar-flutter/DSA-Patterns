/*
-------------------------------------
🧩 Problem: Minimum Remove to Make Valid Parentheses
📂 Category: Stack / Parentheses
🧠 Concept:
- Parentheses matching
- Index tracking

⚡ Approach:
- Store indices of unmatched '('
- Mark invalid ')' immediately
- Mark remaining unmatched '('
- Build final valid string

⏱️ Time Complexity: O(n)
💾 Space Complexity: O(n)

🎯 Key Idea:
- Track invalid positions instead of
  modifying the string repeatedly

-------------------------------------
*/

class Solution {
public:

    string minRemoveToMakeValid(string s) {

        stack<int> openBracketIndices;
        vector<bool> shouldRemove(s.size(),false);
      
        for(int i = 0; i < s.size(); i++) {
          
            if(s[i] == '(') openBracketIndices.push(i);
          
            else if(s[i] == ')') {
                if(!openBracketIndices.empty()) openBracketIndices.pop();
                else shouldRemove[i] = true;
            }
        }

        // Remaining unmatched '('
        while(!openBracketIndices.empty()) {
            shouldRemove[openBracketIndices.top()] = true;
            openBracketIndices.pop();
        }

        string validString = "";

        for(int i = 0; i < s.size(); i++) if(!shouldRemove[i]) validString += s[i];

        return validString;
    }
};
