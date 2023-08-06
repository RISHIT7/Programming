#include <iostream>
#include <vector>
using namespace std;

class SET
{
private:
    vector<int> set;
    int set_num;

public:
    SET(int set_n)
    {
        set = {};
        set_num = set_n;
    }
    SET(vector<int> set_in, int set_n)
    {
        set = set_in;
        set_num = set_n;
    }
    void insertion(int val)
    {
        cout << "insertion was called for " << set_num << " with input " << val << endl;
    }

    void deletion(int val)
    {
        cout << "deletion was called for " << set_num << " with input " << val << endl;
    }

    void belongs_to(int val)
    {
        cout << "belongs_to was called for " << set_num << " with input " << val << endl;
    }

    void Union(vector<int> set2)
    {
        cout << "Union was called for " << set_num << endl;
    }

    void Intersection(vector<int> set2)
    {
        cout << "Intersection was called for " << set_num << endl;
    }

    void size()
    {
        cout << "size function was called for " << set_num << endl;
    }

    void difference(vector<int> set2)
    {
        cout << "Intersection was called for " << set_num << endl;
    }

    void sym_diff(vector<int> set2)
    {
        cout << "Intersection was called for " << set_num << endl;
    }

    void print()
    {
        cout << "print was called for " << set_num << endl;
    }
    ~SET()
    {
    }
};

vector<int> avail_set(int set_num, vector<pair<int, vector<int>>> set_db)
{
    for (int i = 0; i < set_db.size(); i++)
    {
        if (set_num == set_db[i].first)
        {
            return set_db[i].second;
        }
    }

    return {-1};
}

int main()
{
    // creating a vector to store all the sets

    vector<pair<int, vector<int>>> set_database;

    // ---------------------- INPUT ----------------------

    int a, b, c = 0; // a->function, b->set_num, c->(depends on a)
    while ((cin >> a >> b))
    {
        if (a == 6 || a == 9)
        {
            // checking for availability of set
            vector<int> set = avail_set(b, set_database);
            if (set.size() == 1 && set[0] == -1)
            {
                set = {};
                set_database.push_back({b, set});
            }
            // calling some functions
            if (a == 6)
            {
                SET *new_set = new SET(set, b);
                new_set->size();
                // calling size
                delete new_set;
            }
            else if (a == 9)
            {
                SET *new_set = new SET(set, b);
                new_set->print();
                // calling print
                delete new_set;
            }
        }
        else
        {
            cin >> c;
            if (a == 1 || a == 2 || a == 3)
            {
                // checking availability
                vector<int> set = avail_set(b, set_database);
                if (set.size() == 1 && set[0] == -1)
                {
                    set = {};
                    set_database.push_back({b, set});
                }
                // calling functions with 1 set
                if (a == 1)
                {
                    // creating a set element from vector
                    SET *new_set = new SET(set, b);
                    new_set->insertion(c);
                    // calling insertion
                    delete new_set;
                }
                else if (a == 2)
                {
                    SET *new_set = new SET(set, b);
                    new_set->deletion(c);
                    // calling deletion
                    delete new_set;
                }
                else if (a == 3)
                {
                    SET *new_set = new SET(set, b);
                    new_set->belongs_to(c);
                    // calling belongs_to
                    delete new_set;
                }
            }
            else if (a == 4 || a == 5 || a == 7 || a == 8)
            {
                // checking availability
                vector<int> set1 = avail_set(b, set_database);
                vector<int> set2 = avail_set(c, set_database);
                if (set1.size() == 1 && set1[0] == -1)
                {
                    set1 = {};
                    set_database.push_back({b, set1});
                }
                if (set2.size() == 1 && set2[0] == -1)
                {
                    set2 = {};
                    set_database.push_back({c, set2});
                }
                // calling functions with 2 sets
                if (a == 4)
                {
                    // calling Union
                    SET *new_set = new SET(set1, b);
                    new_set->Union(set2);
                    delete new_set;
                }
                else if (a == 5)
                {
                    // calling Intersection
                    SET *new_set = new SET(set1, b);
                    new_set->Intersection(set2);
                    delete new_set;
                }
                else if (a == 7)
                {
                    // calling difference
                    SET *new_set = new SET(set1, b);
                    new_set->difference(set2);
                    delete new_set;
                }
                else if (a == 8)
                {
                    // calling symmetric difference
                    SET *new_set = new SET(set1, b);
                    new_set->sym_diff(set2);
                    delete new_set;
                }
            }
        }
    }

    // for (int i = 0; i < set_database.size(); i++)
    // {
    //     cout << "( " << set_database[i].first << "; ";
    //     for (int j = 0; j < set_database[i].second.size(); j++)
    //     {
    //         cout << set_database[i].second[j] << ", ";
    //     }
    //     cout << " )";
    // }
    // cout << endl;

    return 0;
}