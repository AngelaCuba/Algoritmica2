#include <bits/stdc++.h>
#include <iostream>
using namespace std;

struct node {
    char currentCharacter;       
    bool isWord;       
    struct node *children[27];
}*trie; 


void init() {
    trie = new node();
    trie->isWord = false;
    trie->currentCharacter = ' ';
}


void insert(string word)
{
	node *currentNode = trie;

	for (int i = 0; i < word.length(); i++)
	{
		int character = (int)word[i] - (int)'a';
		if (currentNode->children[character]==NULL)
        	{
            		currentNode->children[character]= new node();
        	}
		currentNode = currentNode->children[character];
		currentNode->currentCharacter=word[i];
        
	}

	currentNode->isWord=true;
}



bool search(string word)
{
	node *currentNode = trie;

	for (int i = 0; i < word.length(); i++)
	{
		int character = (int)word[i] - (int)'a';
		if (currentNode->children[character]==NULL)
        	{
            		return false;
        	}
        	currentNode = currentNode->children[character];
	}
	return currentNode->isWord;
}


int main()
{
	init();  
    	string word = "auto";
    	insert(word);
	search("auto")? cout << "Yes\n" : cout << "No\n";
	search("automovil")? cout << "Yes\n" : cout << "No\n";
	return 0;
}
