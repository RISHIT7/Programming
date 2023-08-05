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
    void insertion(int data)
    {
        cout << "insertion was called with data input " << data << endl;
        for (int i = 0; i < set.size(); i++)
        {
            if (set[i] == data)
            {
                // cout << set.size() << endl;
                return;
            }
            else if (set[i] > data)
            {
                set.insert(set.begin() + i, data);
                // cout << set.size() << endl;
                return;
            }
        }
        set.push_back(data); // if the element is larger than every other element
        // cout << set.size() << endl;
        return;
    }

    void deletion(int data) // if the set does not exist return -1
    {
        cout << "deletion was called with data input " << data << endl;
        for (int i = 0; i < set.size(); i++)
        {
            if (set[i] == data)
            {
                set.erase(set.begin() + i);
                // cout << set.size() << endl;
                return;
            }
        }
        // cout << set.size() << endl;
        return;
    }

    void belongs_to(int data) // return -1 if the set does not exist
    {
        cout << "belongs_to was called with data input " << data << endl;
        for (int i = 0; i < set.size(); i++)
        {
            if (data == set[i])
            {
                // cout << 1 << endl;
                return;
            }
        }
        // cout << 0 << endl;
        return;
    }

    void Union(vector<int> set2)
    {
        cout << "Union was called" << endl;
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
        }
        // cout << set.size() << endl;
    }

    void Intersection(vector<int> set2)
    {
        cout << "Intersection was called" << endl;
        int i = 0, j = 0;
        vector<int> res = {};
        while (i < set.size() || j < set2.size())
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

        while (i < set.size())
        {
            if (set[i] == set2[set2.size() - 1])
            {
                res.push_back(set[i]);
            }
            i++;
        }

        while (j < set2.size())
        {
            if (set2[j] == set[set.size() - 1])
            {
                res.push_back(set2[j]);
            }
            j++;
        }
        set = res;
        // cout << set.size() << endl;
    }

    void size()
    {
        cout << "size function was called" << endl;
        cout << set.size() << endl;
    }

    void difference(vector<int> set2)
    {
        cout << "difference was called" << endl;
        int i = 0, j = 0;
        while (i < set.size() || j < set2.size())
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

        while (i < set.size())
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
        // cout << set.size() << endl;
    }

    void sym_diff(vector<int> set2)
    {
        SET *Union_set = new SET(set, set_num);
        Union_set->Union(set2);

        SET *Intersection_set = new SET(set, set_num);
        Intersection_set->Intersection(set2);

        Union_set->difference(Intersection_set->set);
        set = Union_set->set;

        // cout << set.size() << endl;

        delete Union_set;
        delete Intersection_set;
    }

    void print()
    {
        cout << "print was called" << endl;
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

int main()
{
    vector<pair<int, vector<int>>> set_database;
    set_database.push_back({0, {1, 2, 4, 5, 7, 8, 9, 12, 14, 15, 25}});
    set_database.push_back({1, {1, 3, 5, 6, 7, 9, 12, 15, 52}});

    // SET *new_set = new SET(set_database[0].second, set_database[0].first);
    // new_set->print();

    // SET *new_set1 = new SET(set_database[1].second, set_database[1].first);
    // new_set1->print();
    // // can we not use the same name, and then delete it?

    // new_set->insertion(9);
    // new_set1->insertion(4);

    // new_set->print();
    // new_set1->print();

    // new_set->deletion(8);
    // new_set1->deletion(8);

    // new_set->print();
    // new_set1->print();

    // new_set->belongs_to(2);
    // new_set1->belongs_to(2);

    // new_set->print();
    // new_set1->print();

    // new_set->size();
    // new_set1->size();

    // delete new_set;
    // delete new_set1;

    // SET *new_set = new SET(set_database[0].second, set_database[0].first);
    // new_set->Intersection(set_database[1].second);
    // new_set->print();
    // delete new_set;

    // SET *new_set = new SET(set_database[0].second, set_database[0].first);
    // new_set->difference(set_database[1].second);
    // new_set->print();
    // delete new_set;

    // SET *new_set = new SET(set_database[0].second, set_database[0].first);
    // new_set->Union(set_database[1].second);
    // new_set->print();
    // delete new_set;

    SET *new_set = new SET(set_database[0].second, set_database[0].first);
    new_set->sym_diff(set_database[1].second);
    new_set->print();
    delete new_set;

    return 0;
}