#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int key;

    Node **forward;
    Node(int key, int level)
    {
        this->key = key; // key of this element has the value key

        // allocate memory to forward
        forward = new Node *[level + 1];

        // fill forward array eith 0(NULL)
        memset(forward, 0, sizeof(Node *) * (level + 1));
    }
};

class SkipList
{
    // Max level for this skip list
    int MAXLVL;

    // P is the fraction of the nodes with level
    // i pointers also having level i+1 pointers
    float P;

    // current level of skip list
    int level;

    // pointer to the head node
    Node *header;

public:
    SkipList(int MAXLVL, float P)
    {
        this->MAXLVL = MAXLVL;
        this->P = P;
        level = 0;

        // create header node and initialize key to -1
        header = new Node(-1, MAXLVL);
    }

    int randomLevel()
    {
        float r = (float)rand()/RAND_MAX;
        int lvl = 0;
        while (r < p && lvl < MAXLVL)
        {
            lvl ++;
            r = (float)rand()/RAND_MAX;
        }
        return lvl;
    }

    Node* createNode(int key, int level)
    {
        Node *n = new Node(key, level);
        return n;
    }
}