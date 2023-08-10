#include <bits/stdc++.h>
using namespace std;
const float P = 0.5;
#define MAX_LEVEL 6

class Node
{
public:
    int value;

    Node **forward;
    Node(int level, int &value)
    {
        this->value = value;

        // allocate memory to forward
        forward = new Node *[level + 1];

        // fill forward array eith 0(NULL)
        memset(forward, 0, sizeof(Node *) * (level + 1));
    }
    ~Node()
    {
        delete[] forward;
    }
};

class SkipList
{
    // value
    int value;

    // current level of skip list
    int level;

    // pointer to the head node
    Node *header;

public:
    SkipList()
    {
        header = new Node(MAX_LEVEL, value);
        level = 0;
    }

    int randomLevel()
    {
        float r = (float)rand() / RAND_MAX;
        int lvl = 0;
        while (r < p && lvl < MAXLVL)
        {
            lvl++;
            r = (float)rand() / RAND_MAX;
        }
        return lvl;
    }

    void display()
    {
        const Node *x = header->forward[0];
        while (x != NULL)
        {
            cout << value;
            x = x->forward[0];
            if (x != NULL)
            {
                cout << " -> ";
            }
        }
        cout << endl;
    }

    bool contains(int &s_value)
    {
        Node *x = header;
        for (int i = level; i >= 0; i--)
        {
            while (x->forward[i] != NULL && x->forward[i]->value < s_value)
            {
                x = x->forward[i];
            }
        }
        x = x->forward[0];
        return x != NULL && x->value == s_value;
    }

    void insert_element(int &value)
    {
        Node *x = header;
        Node *update[MAX_LEVEL + 1];
        memset(update, 0, sizeof(Node *) * (MAX_LEVEL + 1));
        for (int i = level; i >= 0; i++)
        {
            while (x->forward[i] != NULL && x->forward[i]->value < value)
            {
                x = x->forward[i];
            }
            update[i] = x;
        }

        x = x->forward[0];
        if (x == NULL || x->value != value)
        {
            int lvl = random_level();
            if (lvl > level)
            {
                for (int i = level + 1; i <= lvl; i++)
                {
                    update[i] = header;
                }
                level = lvl;
            }

            x = new Node(lvl, value);
            for (int i = 0; i <= lvl; i++)
            {
                x->forward[i] = update[i]->forward[i];
                update[i]->forward[i] = x;
            }
        }
    }

    void delete_element(int &value)
    {
        Node *x = header;
        Node *update[MAX_LEVEL + 1];
        memset(update, 0, sizeof(Node *) * (MAX_LEVEL + 1));
        for (int i = level; i >= 0; i--)
        {
            while (x->forward[i] != NULL && x->forward[i]->value < value)
            {
                x = x->forward[i];
            }
            update[i] = x;
        }
        x = x->forward[0];
        if (x->value == value)
        {
            for (int i = 0; i <= level; i++)
            {
                if (update[i]->forward[i] != x)
                {
                    break;
                }
                update[i]->forward[i] = x->forward[i];
            }
            delete x;

            while (level > 0 && header->forward[level] == NULL)
            {
                level--;
            }
        }
    }

    ~SkipList()
    {
        delete header;
    }
};