 ///
 /// trie.h
 /// Created by stabey(stabeyzhou@gmail.com).
 /// 2018-07-10 15:53:48
 /// @Brief: 
 ///
 
#ifndef __TRIE_H__
#define __TRIE_H__ 
#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#define MAX 26
using namespace std;

typedef struct node{
    struct node *next[MAX];
    int num;
}Node;

class Trie{
public:
    Trie()
    : root(new Node)
    {
        for(int i = 0; i < MAX; ++i)
            root->next[i] = NULL;
        root->num = 0;
    }
    void read(const string &filename);
    void list(const string &filename);
        


private:
    Node *root;
};

#endif
