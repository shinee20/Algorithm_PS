#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>
using namespace std;
//Programmers 카카오 기출 가사검색 https://programmers.co.kr/learn/courses/30/lessons/60060
//unsolved
struct Trie
{
    // isEndOfWord is true if the node
    // represents end of a word
    bool isEndOfWord;

    /* nodes store a map to child node */
    unordered_map<char, Trie *> map;
};
/*function to make a new trie*/
Trie *getNewTrieNode()
{
    Trie *node = new Trie;
    node->isEndOfWord = false;
    return node;
}
/*function to insert in trie*/
void insert(Trie *&root, const string &str)
{
    if (root == nullptr)
        root = getNewTrieNode();

    Trie *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        char x = str[i];
        /* make a new node if there is no path */
        if (temp->map.find(x) == temp->map.end())
            temp->map[x] = getNewTrieNode();
        temp = temp->map[x];
    }
    temp->isEndOfWord = true;
}
/*function to search in trie*/
bool search(Trie *root, const string &str)
{
    /*return false if Trie is empty*/
    if (root == nullptr)
        return false;
    Trie *temp = root;
    for (int i = 0; i < str.length(); i++)
    {
        /* go to next node*/
        temp = temp->map[str[i]];

        if (temp == nullptr)
            return false;
    }
    return temp->isEndOfWord;
}

vector<int> solution(vector<string> words, vector<string> keyword)
{
    vector<int> answer;
    int n = words.size();

    Trie *root = nullptr;

    for (int i = 0; i < n; i++)
    {
        insert(root, words[i]);
    }

    int k = keyword.size();
    for (int j = 0; j < k; j++)
    {
    }

    return answer;
}