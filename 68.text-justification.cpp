//Given an array of strings words and a width maxWidth, format the text such 
//that each line has exactly maxWidth characters and is fully (left and right) 
//justified. 
//
// You should pack your words in a greedy approach; that is, pack as many words 
//as you can in each line. Pad extra spaces ' ' when necessary so that each line 
//has exactly maxWidth characters. 
//
// Extra spaces between words should be distributed as evenly as possible. If 
//the number of spaces on a line does not divide evenly between words, the empty 
//slots on the left will be assigned more spaces than the slots on the right. 
//
// For the last line of text, it should be left-justified and no extra space is 
//inserted between words. 
//
// Note: 
//
// 
// A word is defined as a character sequence consisting of non-space characters 
//only. 
// Each word's length is guaranteed to be greater than 0 and not exceed 
//maxWidth. 
// The input array words contains at least one word. 
// 
//
// 
// Example 1: 
//
// 
//Input: words = ["This", "is", "an", "example", "of", "text", "justification."]
//, maxWidth = 16
//Output:
//[
//   "This    is    an",
//   "example  of text",
//   "justification.  "
//] 
//
// Example 2: 
//
// 
//Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 
//16
//Output:
//[
//  "What   must   be",
//  "acknowledgment  ",
//  "shall be        "
//]
//Explanation: Note that the last line is "shall be    " instead of "shall     
//be", because the last line must be left-justified instead of fully-justified.
//Note that the second line is also left-justified becase it contains only one 
//word. 
//
// Example 3: 
//
// 
//Input: words = ["Science","is","what","we","understand","well","enough","to",
//"explain","to","a","computer.","Art","is","everything","else","we","do"], 
//maxWidth = 20
//Output:
//[
//  "Science  is  what we",
//  "understand      well",
//  "enough to explain to",
//  "a  computer.  Art is",
//  "everything  else  we",
//  "do                  "
//] 
//
// 
// Constraints: 
//
// 
// 1 <= words.length <= 300 
// 1 <= words[i].length <= 20 
// words[i] consists of only English letters and symbols. 
// 1 <= maxWidth <= 100 
// words[i].length <= maxWidth 
// 
// Related Topics Array String Simulation 👍 1415 👎 2470


//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
  vector<int> getSpaces(int spaces, int cnt, int w, int len, bool lastRow) {
    vector<int> cols;
    if (cnt == 0) {
      cols.push_back(w - len);
      return cols;
    }
    if (lastRow) {
      for (int j = 0; j < cnt; j++) {
        cols.push_back(1);
      }
    } else if (spaces % cnt == 0) {
      for (int j = 0; j < cnt; j++) {
        cols.push_back(spaces/cnt);
      }
    } else {
      int left = spaces % cnt;
      int pos = spaces / cnt;
      for (int j = 0; j < cnt; j++) {
        int t = pos;
        if (left > 0) {
          left--;
          t++;
        }
        cols.push_back(t);
      }
    }
    return cols;
  }

  vector<string> fullJustify(vector<string>& a, int w) {
    vector<string> res;
    if (a.size() == 0) {
      return vector<string>();
    }
    vector<vector<string>> lines;
    vector<int> lens;
    vector<string> cur;
    int width = 0;
    for (string word : a) {
      int newWidth = width + word.size();
      if (cur.size() > 0) {
        newWidth += cur.size();
      }
      if (newWidth > w) {
        lines.push_back(cur);
        lens.push_back(width);
        cur.clear();
        width = 0;
      }
      width += word.size();
      cur.push_back(word);
    }
    if (cur.size() > 0) {
      lines.push_back(cur);
      lens.push_back(width);
    }
    for (int i = 0; i < lines.size(); i++) {
      int spaces = w - lens[i];
      int cnt = lines[i].size() - 1;
      vector<int> cols = getSpaces(spaces, cnt, w, lens[i], i + 1 == lines.size());

      string cur;
      for (int j = 0; j < lines[i].size(); j++) {
        string word = lines[i][j];
        cur += word;
        for (int k = 0; j < cols.size() && k < cols[j]; k++) {
          cur += " ";
        }
      }
      while (cur.size() < w) {
        cur += " ";
      }
      res.push_back(cur);
    }
    return res;
  }
};
//leetcode submit region end(Prohibit modification and deletion)
