// make sure you're aware of the possiblity of negative integers
#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> set1);

int intersection(vector<int> set1, vector<int> set2, vector<int> *change) // done in O(n), change the code for sets, rather than vector inputs
{
    int i = 0, j = 0;
    vector<int> res = {};
    while (i < set1.size() || j < set2.size())
    {
        if (set1[i] == set2[j])
        {
            res.push_back(set1[i]);
            i++;
            j++;
        }
        else if (set1[i] > set2[j])
        {
            j++;
        }
        else if (set1[i] < set2[j])
        {
            i++;
        }
    }

    while (i < set1.size())
    {
        if (set1[i] == set2[set2.size() - 1])
        {
            res.push_back(set1[i]);
        }
        i++;
    }

    while (j < set2.size())
    {
        if (set2[j] == set1[set1.size() - 1])
        {
            res.push_back(set2[j]);
        }
        j++;
    }
    *change = res; // also try finding a better algo, as this copying takes O(n) time itself, try finding a way to do it by reference
    return change->size();
}

int difference(vector<int> set1, vector<int> set2, vector<int> *change)
{
    int i = 0, j = 0;
    while (i < set1.size() || j < set2.size())
    {
        if (set1[i] == set2[j])
        {
            set1[i] = -1;
            i++;
            j++;
        }
        else if (set1[i] > set2[j])
        {
            j++;
        }
        else if (set1[i] < set2[j])
        {
            i++;
        }
    }

    while (i < set1.size())
    {
        if (set1[i] == set2[set2.size() - 1])
        {
            set1[i] = -1;
        }
        i++;
    }

    for (int i = 0; i < set1.size(); i++)
    {
        if (set1[i] == -1)
        {
            set1.erase(set1.begin() + i);
            i--;
        }
    }

    *change = set1; // also try finding a better algo, as this copying takes O(n) time itself, try finding a way to do it by reference
    return change->size();
}

int Union(vector<int> set1, vector<int> set2, vector<int> *change)
{

    difference(set1, set2, &set1);
    vector<int> res = set1;
    for (int i = 0; i < set2.size(); i++)
    {
        for (int j = 0; j < res.size(); j++)
        {
            if (res[j] == set2[i])
            {
                break;
            }
            else if (res[j] > set2[i])
            {
                res.insert(res.begin() + j, set2[i]);
                break;
            }
            if (j == res.size() - 1)
            {
                res.push_back(set2[i]);
            }
        }
    }
    *change = res;

    return change->size();
}

int Sym_diff(vector<int> set1, vector<int> set2, vector<int> *change)
{
    vector<int> temp = set1;

    Union(set1, set2, &set1);        // here our set1 will become the union
    intersection(temp, set2, &temp); // here our temp will become the intersection
    difference(set1, temp, &set1);   // here out set1 will become the symmetric difference

    *change = set1;

    return change->size();
}

void print(vector<int> set1)
{
    for (int i = 0; i < set1.size() - 1; i++)
    {
        cout << set1[i] << ",";
    }
    cout << set1[set1.size() - 1] << endl;
}

int main()
{
    vector<int> set1 = {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25}; // 11
    vector<int> set2 = {1, 3, 5, 6, 7, 9, 12, 15, 52};        // 9

    // 1 5 7 9 12 15

    cout << "\n<---------- intersection -------------->" << endl;
    cout << intersection(set1, set2, &set1) << endl;
    print(set1);

    // 2 4 8 14 25

    set1 = {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25};
    cout << "\n<------------ difference --------------->" << endl;
    cout << difference(set1, set2, &set1) << endl;
    print(set1);

    // 1 2 3 4 5 6 7 8 9 12 14 15 25 52

    set1 = {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25};
    cout << "\n<----------------- Union ----------------->" << endl;
    cout << Union(set1, set2, &set1) << endl;
    print(set1);

    // 2 3 4 6 8 14 25 52

    cout << "\n<---------- Symmetric difference ---------->" << endl;
    set1 = {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25};
    cout << Sym_diff(set1, set2, &set1) << endl;
    print(set1);

    return 0;
}