class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    string word; // Stores the word at the end node

    TrieNode() {
        word = "";
    }
};

// Trie Class
class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    // Insert a word into the Trie
    void insert(string word) {
        TrieNode* node = root;
        for (char ch : word) {
            if (node->children.find(ch) == node->children.end()) {
                node->children[ch] = new TrieNode();
            }
            node = node->children[ch];
        }
        node->word = word; // Mark the end of the word
    }
};

class Solution {
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        Trie trie;
        // Insert all words into the Trie
        for (string word : words) {
            trie.insert(word);
        }

        vector<string> result;
        int m = board.size();
        int n = board[0].size();

        // Perform DFS for each cell on the board
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, trie.root, result);
            }
        }

        return result;
    }

private:
    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node, vector<string>& result) {
        char ch = board[i][j];
        // Check if the current character exists in the Trie
        if (ch == '#' || node->children.find(ch) == node->children.end()) {
            return;
        }

        node = node->children[ch];
        // If a word is found, add it to the result
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word = ""; // Avoid adding the same word multiple times
        }

        // Mark the current cell as visited
        board[i][j] = '#';

        // Explore all 4 directions
        if (i > 0) dfs(board, i - 1, j, node, result); // Up
        if (j > 0) dfs(board, i, j - 1, node, result); // Left
        if (i < board.size() - 1) dfs(board, i + 1, j, node, result); // Down
        if (j < board[0].size() - 1) dfs(board, i, j + 1, node, result); // Right

        // Backtrack: unmark the current cell
        board[i][j] = ch;
    }
};