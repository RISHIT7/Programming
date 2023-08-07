#include <iostream>
#include <vector>
using namespace std;

class SET
{
public:
    vector<int> set;
    int set_num;

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
    int insertion(int data)
    {
        for (int i = 0; i < set.size(); i++)
        {
            if (set[i] == data)
            {
                return set.size();
            }
            else if (set[i] > data)
            {
                set.insert(set.begin() + i, data);
                return set.size();
            }
        }
        set.push_back(data);
        return set.size();
    }

    int deletion(int data)
    {
        for (int i = 0; i < set.size(); i++)
        {
            if (set[i] == data)
            {
                set.erase(set.begin() + i);
                return set.size();
            }
        }
        return set.size();
    }

    bool belongs_to(int data)
    {
        for (int i = 0; i < set.size(); i++)
        {
            if (data == set[i])
            {
                return true;
            }
        }
        return false;
    }

    void Union(vector<int> set2)
    {
        SET *temp_set = new SET(set, set_num);
        temp_set->difference(set2);
        set = temp_set->set;
        delete temp_set;
        for (int i = 0; i < set2.size(); i++)
        {
            for (int j = 0; j < set.size(); j++)
            {
                if (set[j] == set2[i])
                {
                    break;
                }
                else if (set[j] > set2[i])
                {
                    set.insert(set.begin() + j, set2[i]);
                    break;
                }
                if (j == set.size() - 1)
                {
                    set.push_back(set2[i]);
                }
            }
            if (set.size() == 0)
            {
                set.push_back(set2[i]);
            }
        }
    }

    void Intersection(vector<int> set2)
    {
        int i = 0, j = 0;
        vector<int> res = {};
        while (i < set.size() && j < set2.size())
        {
            if (set[i] == set2[j])
            {
                res.push_back(set[i]);
                i++;
                j++;
            }
            else if (set[i] > set2[j])
            {
                j++;
            }
            else if (set[i] < set2[j])
            {
                i++;
            }
        }

        while (i < set.size() && set2.size() >= 1)
        {
            if (set[i] == set2[set2.size() - 1])
            {
                res.push_back(set[i]);
            }
            i++;
        }

        while (j < set2.size() && set.size() >= 1)
        {
            if (set2[j] == set[set.size() - 1])
            {
                res.push_back(set2[j]);
            }
            j++;
        }
        set = res;
    }

    void size()
    {
        cout << set.size() << endl;
    }

    void difference(vector<int> set2)
    {
        int i = 0, j = 0;
        while (i < set.size() && j < set2.size())
        {
            if (set[i] == set2[j])
            {
                set[i] = -1;
                i++;
                j++;
            }
            else if (set[i] > set2[j])
            {
                j++;
            }
            else if (set[i] < set2[j])
            {
                i++;
            }
        }

        while (i < set.size() && set2.size() >= 1)
        {
            if (set[i] == set2[set2.size() - 1])
            {
                set[i] = -1;
            }
            i++;
        }

        for (int i = 0; i < set.size(); i++)
        {
            if (set[i] == -1)
            {
                set.erase(set.begin() + i);
                i--;
            }
        }
    }

    void sym_diff(vector<int> set2)
    {
        SET *Union_set = new SET(set, set_num);
        Union_set->Union(set2);

        SET *Intersection_set = new SET(set, set_num);
        Intersection_set->Intersection(set2);

        Union_set->difference(Intersection_set->set);
        set = Union_set->set;

        delete Union_set;
        delete Intersection_set;
    }

    void print()
    {
        if (set.size() == 0)
        {
            cout << endl;
            return;
        }

        for (int i = 0; i < set.size() - 1; i++)
        {
            cout << set[i] << ",";
        }
        cout << set[set.size() - 1] << endl;
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

int find_idx(int set_num, vector<pair<int, vector<int>>> set_db)
{
    for (int i = 0; i < set_db.size(); i++)
    {
        if (set_num == set_db[i].first)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    // fast io
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

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
            int idx = find_idx(b, set_database);
            if (set.size() == 1 && set[0] == -1 && a == 6)
            {
                set = {};
                set_database.push_back({b, set});
            }
            if (set.size() == 1 && set[0] == -1 && a == 9)
            {
                cout << endl;
                continue;
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
                // checking availability for 1
                vector<int> set = avail_set(b, set_database);
                if (a == 1 && set.size() == 1 && set[0] == -1)
                {
                    set = {};
                    set_database.push_back({b, set});
                }
                else if (a != 1 && set.size() == 1 && set[0] == -1)
                {
                    cout << -1 << endl;
                    continue;
                }
                int idx = find_idx(b, set_database);
                // calling functions with 1 set
                if (a == 1)
                {
                    // creating a set element from vector
                    SET *new_set = new SET(set, b);
                    new_set->insertion(c);
                    set = new_set->set;
                    set_database[idx].second = set;
                    cout << set_database[idx].second.size() << endl;
                    // calling insertion
                    delete new_set;
                }
                else if (a == 2)
                {
                    SET *new_set = new SET(set, b);
                    new_set->deletion(c);
                    set = new_set->set;
                    set_database[idx].second = set;
                    cout << set_database[idx].second.size() << endl;
                    // calling deletion
                    delete new_set;
                }
                else if (a == 3)
                {
                    SET *new_set = new SET(set, b);
                    cout << new_set->belongs_to(c) << endl;
                    // calling belongs_to
                    delete new_set;
                }
            }
            else if (a == 4 || a == 5 || a == 7 || a == 8)
            {
                // checking availability
                vector<int> set1 = avail_set(b, set_database);
                int idx1 = find_idx(b, set_database);
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
                    set_database[idx1].second = new_set->set;
                    cout << set_database[idx1].second.size() << endl;
                    delete new_set;
                }
                else if (a == 5)
                {
                    // calling Intersection
                    SET *new_set = new SET(set1, b);
                    new_set->Intersection(set2);
                    set_database[idx1].second = new_set->set;
                    cout << set_database[idx1].second.size() << endl;
                    delete new_set;
                }
                else if (a == 7)
                {
                    // calling difference
                    SET *new_set = new SET(set1, b);
                    new_set->difference(set2);
                    set_database[idx1].second = new_set->set;
                    cout << set_database[idx1].second.size() << endl;
                    delete new_set;
                }
                else if (a == 8)
                {
                    // calling symmetric difference
                    SET *new_set = new SET(set1, b);
                    new_set->sym_diff(set2);
                    set_database[idx1].second = new_set->set;
                    cout << set_database[idx1].second.size() << endl;
                    delete new_set;
                }
            }
        }
    }

    return 0;
}