// make sure you're aware of the possiblity of negative integers
#include <iostream>
#include <vector>
using namespace std;

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
        // insertion(res, set2[i]);
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
        }
    }
    *change = res;

    return change->size();
}

void print(vector<int> set1)
{
    for (int i = 0; i < set1.size(); i++)
    {
        cout << set1[i] << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> set1 = {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25};
    vector<int> set2 = {1, 3, 5, 6, 7, 9, 12, 15, 52};

    // 1 5 7 9 12 15

    cout << intersection(set1, set2, &set1) << endl;
    print(set1);

    // 2 4 8 14 25

    set1 = {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25};
    cout << difference(set1, set2, &set1) << endl;
    print(set1);

    // 1 2 3 4 5 6 7 8 9 12 14 15 25 52

    set1 = {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25};
    cout << Union(set1, set2, &set1) << endl;
    print(set1); // remeber this is not sorted

    return 0;
}