#include <bits/stdc++.h>
#define input freopen("in.txt", "r", stdin)
#define output freopen("out.txt", "w", stdout)
using namespace std;

struct node
{
    map<char, node*> mapero;
    string caracter;
    bool isWord;                
} *trie;

void init()
{
    trie = new node();
    trie->isWord = false;
}
void insertWord(string word)
{
    node *currentNode = trie;  
    for (int i = 0; i < word.length(); i++)
    {
        if(currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            currentNode->mapero[word[i]] = new node();
        }
        currentNode = currentNode->mapero[word[i]];
    }
    currentNode->isWord=true;
}

bool search(string word)
{
	node *currentNode = trie;  
    for (int i = 0; i < word.length(); i++)
    {
        if(currentNode->mapero.find(word[i]) == currentNode->mapero.end())
        {
            return false;
        }
        currentNode = currentNode->mapero[word[i]];
    }
    return currentNode->isWord=true;
}
int main() {
    init(); 
    string word = "alto";
    insertWord(word);
    word = "auto";
    insertWord(word);
    word = "automovil";   
    insertWord(word);
    search("auto")? cout << "Existe\n" :
						cout << "No Existe\n";
    search("pluma")? cout << "Existe\n" :
						cout << "No Existe\n";
    return 0;
}
