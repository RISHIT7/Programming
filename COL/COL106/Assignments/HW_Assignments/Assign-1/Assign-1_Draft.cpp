#include <iostream>
#include <vector>
#define int long long
using namespace std;

class SET
{
public:
    void insertion(int set_num, int data)
    {
        cout << "insertion was called for " << set_num << " with data input " << data << endl;
    }

    void deletion(int set_num, int data)
    {
        cout << "deletion was called for " << set_num << " with data input " << data << endl;
    }

    void belongs_to(int set_num, int data)
    {
        cout << "belongs_to was called for " << set_num << " with data input " << data << endl;
    }

    void Union(int set_num_1, int set_num_2)
    {
        cout << "Union was called for " << set_num_1 << " and " << set_num_2 << endl;
    }

    void Intersection(int set_num_1, int set_num_2)
    {
        cout << "Intersection was called for " << set_num_1 << " and " << set_num_2 << endl;
    }

    int size(int set_num)
    {
        cout << "size was called for " << set_num << endl;
        return 0;
    }

    void difference(int set_num_1, int set_num_2)
    {
        cout << "Difference was called for " << set_num_1 << " and " << set_num_2 << endl;
    }

    void sym_diff(int set_num_1, int set_num_2)
    {
        cout << "sym_diff was called for " << set_num_1 << " and " << set_num_2 << endl;
    }

    void print(int set_num)
    {
        cout << "print was called for " << set_num << endl;
    }
};

/*
------------ insertion --------------

we can isnert the number in O(n), using linear search we can also check for duplicates
but research about O(logn) using binary search

---------------- Delete ------------------

Again same as Insertion in O(n) or O(logn)

----------------- Belongs To --------------

clearly can be done in O(logn) using binary search

---------------- Union -------------------

to calculate union, we can calculate intersection and then use
A U B = A + B - (A ^ B)

---------------- Intersection -------------

Can be done in O(n) using dp, longest common subsequence problem

--------------- Size -----------------------

can be done in O(1) just maintain a call variable called size
and increment and decrement the variable as per need

------------------ Difference ------------------

If set dosent exist create it and return the set 1
else can be done in O(n)
What is difference?

--------------- Symmetric diff -----------------

What is symmetric difference?
must be able to be done in O(n)

------------------ Print ----------------------

easily can be done in O(n) no doubt
*/

bool avail_set(int set_num, vector<pair<int, SET>> vs)
{
    bool in_set = false;
    for (int i = 0; i < vs.size(); i++)
    {
        if (set_num == vs[i].first)
        {
            in_set = true;
        }
    }

    return in_set;
}

signed main()
{
    // creating a vector to store all the sets

    vector<pair<int, SET>> vs;

    // ------------------------------------ INPUT --------------------------------------

    int input[3];
    bool first = true;

    for (int i = 0; i < 3; i++)
    {
        cin >> input[i];
        if ((input[0] == 6 or input[0] == 9) and first == true)
        {
            i++;
            first = false;
        }
    }

    // when we only need two inputs

    if (input[0] == 6 or input[0] == 9)
    {
        input[1] = input[2];
        input[2] = 0;

        bool in_set = avail_set(input[1], vs);

        if (in_set == false)
        {
            SET set = SET();
            vs.push_back({input[1], set});
        }

        if (input[0] == 6)
        {
            for (int i = 0; i < vs.size(); i++)
            {
                if (input[1] == vs[i].first)
                {
                    vs[i].second.size(input[1]);
                    break;
                }
            }
        }

        else if (input[0] == 9)
        {
            for (int i = 0; i < vs.size(); i++)
            {
                if (input[1] == vs[i].first)
                {
                    vs[i].second.print(input[1]);
                    break;
                }
            }
        }
    } // checked

    // ------------------------- calling of functions -------------------------

    // when the second and third input is set_num

    else if (input[0] == 4 or input[0] == 5 or input[0] == 7 or input[0] == 8)
    {

        // ------------------- checking if we already have the set ---------------------

        bool in_set_1 = avail_set(input[1], vs);
        bool in_set_2 = avail_set(input[2], vs);

        // --------------------------- if not we create a set ---------------------------

        if (in_set_1 == false)
        {
            SET set = SET();
            vs.push_back({input[1], set});
        }

        if (in_set_2 == false)
        {
            SET set = SET();
            vs.push_back({input[2], set});
        }

        int index_i, index_j;
        for (int i = 0; i < vs.size(); i++)
        {
            if (input[1] == vs[i].first)
            {
                index_i = i;
                break;
            }
        }

        for (int j = 0; j < vs.size(); j++)
        {
            if (input[2] == vs[j].first)
            {
                index_j = j;
                break;
            }
        }

        if (input[0] == 4)
        {
            vs[index_i].second.Union(index_i, index_j);
        }

        if (input[0] == 5)
        {
            vs[index_i].second.Intersection(index_i, index_j);
        }

        if (input[0] == 7)
        {
            vs[index_i].second.difference(index_i, index_j);
        }

        if (input[0] == 8)
        {
            vs[index_i].second.sym_diff(index_i, index_j);
        }
    }

    // when only the second input is set_num

    else if (input[0] == 1 or input[0] == 2 or input[0] == 3)
    {
        // ------------------- checking if we already have the set ---------------------

        bool in_set = avail_set(input[1], vs);

        // --------------------------- if not we create a set ---------------------------

        if (in_set == false)
        {
            SET set = SET();
            vs.push_back({input[1], set});
        }

        cout << vs[0].first << endl;

        for (int i = 0; i < vs.size(); i++)
        {
            if (input[1] == vs[i].first)
            {
                if (input[0] == 1)
                {
                    vs[i].second.insertion(input[1], input[2]);
                }

                else if (input[0] == 2)
                {
                    vs[i].second.deletion(input[1], input[2]);
                }

                else if (input[0] == 3)
                {
                    vs[i].second.belongs_to(input[1], input[2]);
                }
            }
        }
    }
    return 0;
}