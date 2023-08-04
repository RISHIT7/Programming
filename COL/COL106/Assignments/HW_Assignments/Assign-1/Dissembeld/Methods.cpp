// are we supposed to return the data, or print it ??

#include <iostream>
#include <vector>
using namespace std;

class SET
{
private:
    vector<int> set;
    int length;

public:
    SET(vector<int> vs, int s)
    {
        set = vs;
        length = s;
    }

    int insertion(int data) // if set does not exist then return -1
    {
        cout << "insertion was called"
             << " with data input " << data << endl;
        for (int i = 0; i < set.size(); i++)
        {
            if (set[i] == data)
            {
                return length;
            }
            else if (set[i] > data)
            {
                set.insert(set.begin() + i, data);
                length++;
                return length;
            }
        }
        return length;
    }

    int deletion(int data) // if set does not exist then return -1
    {
        cout << "deletion was called"
             << " with data input " << data << endl;
        for (int i = 0; i < length; i++)
        {
            if (set[i] == data)
            {
                set.erase(set.begin() + i);
                length--;
                return length;
            }
        }
        return length;
    }

    int belongs_to(int data) // if set does not exist then return -1;
    {
        cout << "belongs_to was called"
             << " with data input " << data << endl;
        for (int i = 0; i < length; i++)
        {
            if (data == set[i])
            {
                return 1;
            }
        }
        return 0;
    }

    void Union(vector<int> set1, vector<int> set2)
    {
        cout << "Union was called" << endl;
        int max_length = max(set1.size(), set2.size());
    }

    int intersection(vector<int> set1, vector<int> set2) // if the set does not exist then create it
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
        set = res;
        return set.size();
    }

    int size()
    {
        cout << "size was called" << endl;
        return length;
    }

    void difference(int set_num_1, int set_num_2)
    {
        cout << "Difference was called for " << set_num_1 << " and " << set_num_2 << endl;
    }

    void sym_diff(int set_num_1, int set_num_2)
    {
        cout << "sym_diff was called for " << set_num_1 << " and " << set_num_2 << endl;
    }

    void print()
    {
        cout << "print was called" << endl;
        for (int i = 0; i < length - 1; i++)
        {
            cout << set[i] << ",";
        }
        cout << set[length - 1] << endl;
    }
};

int main()
{
    vector<int> vs1 = {1, 2, 3, 4};
    vector<int> vs2 = {1, 4, 7, 8};

    SET set1 = SET(vs1, vs1.size());
    SET set2 = SET(vs2, vs2.size());

    set1.print();
    set2.print();

    cout << set1.insertion(3) << endl;
    cout << set2.insertion(3) << endl;

    set1.print();
    set2.print();

    cout << set1.deletion(8) << endl;
    cout << set2.deletion(8) << endl;

    set1.print();
    set2.print();

    cout << set1.belongs_to(2) << endl;
    cout << set2.belongs_to(2) << endl;

    set1.print();
    set2.print();

    cout << set1.size() << endl;
    cout << set2.size() << endl;

    // intersection to be modified for sets, rather than vector inputs

    // cout<<set1.intersection(set1, set2)<<endl;
    // set1.print();

    // union to be modified for sets, rather than vector inputs

    return 0;
}