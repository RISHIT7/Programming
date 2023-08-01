#include <iostream>
#include <vector>
#define int long long
using namespace std;

class SET
{
    void insertion(int set_num, int data)
    {
    }

    void deletion(int set_num, int data)
    {
    }

    void belongs_to(int set_num, int data)
    {
    }

    void Union(int set_num_1, int set_num_2)
    {
    }

    void Intersection(int set_num_1, int set_num_2)
    {
    }

    int size(int set_num)
    {
        return 0;
    }

    void difference(int set_num_1, int set_num_2)
    {
    }

    void sym_diff(int set_num_1, int set_num_2)
    {
    }

    void print(int set_num)
    {
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
    }
    return 0;
}