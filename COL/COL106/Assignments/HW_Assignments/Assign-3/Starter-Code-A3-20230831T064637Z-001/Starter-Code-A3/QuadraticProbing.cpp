#include "QuadraticProbing.h"
using namespace std;

QuadraticProbing::QuadraticProbing()
{
    bankStorage1d.resize(100003);
}

void QuadraticProbing::createAccount(std::string id, int count) // to be tested, handle the case when size == max
{
    int Hash_val = hash(id);
    int factor = 1;
    while (bankStorage1d[Hash_val].id != "")
    {
        Hash_val = (Hash_val + (factor * factor)) % 100001;
        factor += 1;
    }
    bankStorage1d[Hash_val].id = id;
    bankStorage1d[Hash_val].balance = count;
    output.push_back(count);
    SIZE++;
}

std::vector<int> QuadraticProbing::getTopK(int k) // can easily be optimised, to be tested
{

    int first_idx = 0;
    int idx = 0;
    for (int i = 0; i < output.size(); i++)
    {
        int Max_ele = 0;
        for (int j = i; j < output.size(); j++)
        {
            if (Max_ele < output[j])
            {
                Max_ele = output[j];
                idx = j;
            }
        }
        int temp = output[first_idx];
        output[first_idx] = output[idx];
        output[idx] = temp;
        first_idx++;
    }

    vector<int> ans;
    for (int i = 0; i < min(k, SIZE); i++)
    {
        ans.push_back(output[i]);
    }

    return ans;
}

int QuadraticProbing::getBalance(std::string id) // to be tested, wrong implementation of search, does not check modded values, same for all functions
{
    int Hash_val = hash(id);

    if (bankStorage1d[Hash_val].id == id)
    {
        return bankStorage1d[Hash_val].balance;
    }
    int idx = Hash_val + 1;
    int factor = 2;
    while (bankStorage1d[idx].id != id && Hash_val != idx)
    {
        idx = (idx + (factor * factor)) % 100001;
        factor += 1;
    }
    if (bankStorage1d[idx].id == id)
    {
        return bankStorage1d[idx].balance;
    }
    else
    {
        return -1;
    }
}

void QuadraticProbing::addTransaction(std::string id, int count) // to be tested
{
    int Hash_val = hash(id);
    if (bankStorage1d[Hash_val].id == id)
    {
        for (int i = 0; i < output.size(); i++)
        {
            if (output[i] == bankStorage1d[Hash_val].balance)
            {
                output[i] += count;
                break;
            }
        }
        bankStorage1d[Hash_val].balance += count;
        return;
    }
    int idx = Hash_val + 1;
    int factor = 2;
    while (bankStorage1d[idx].id != id and idx != Hash_val)
    {
        idx = (idx + (factor * factor)) % 100001;
        factor += 1;
    }
    if (bankStorage1d[idx].id == id)
    {
        for (int i = 0; i < output.size(); i++)
        {
            if (output[i] == bankStorage1d[idx].balance)
            {
                output[i] += count;
                break;
            }
        }
        bankStorage1d[idx].balance += count;
        return;
    }
    else
    {
        createAccount(id, count);
        return;
    }
}

bool QuadraticProbing::doesExist(std::string id) // to be tested
{
    int Hash_val = hash(id);
    if (bankStorage1d[Hash_val].id == id)
    {
        return true;
    }
    int idx = Hash_val + 1;
    int factor = 2;
    while (bankStorage1d[idx].id != id and idx != Hash_val)
    {
        idx = (idx + (factor * factor)) % 100001;
        if (idx < 0)
        {
            idx = -1 * idx;
        }
        factor += 1;
    }
    if (bankStorage1d[idx].id == id)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool QuadraticProbing::deleteAccount(std::string id)
{
    int Hash_val = hash(id);
    if (bankStorage1d[Hash_val].id == id)
    {
        SIZE--;
        bankStorage1d[Hash_val].id = "";
        for (int i = 0; i < output.size(); i++)
        {
            if (output[i] == bankStorage1d[Hash_val].balance)
            {
                output.erase(output.begin() + i);
                break;
            }
        }
        bankStorage1d[Hash_val].balance = 0;
        return true;
    }
    int idx = Hash_val + 1;
    int factor = 2;
    while (bankStorage1d[idx].id != id and idx != Hash_val)
    {
        idx = (idx + (factor * factor)) % 100001;
        factor += 1;
    }
    if (bankStorage1d[idx].id == id)
    {
        SIZE--;
        bankStorage1d[idx].id = "";
        for (int i = 0; i < output.size(); i++)
        {
            if (output[i] == bankStorage1d[idx].balance)
            {
                output.erase(output.begin() + i);
                break;
            }
        }
        bankStorage1d[idx].balance = 0;
        return true;
    }
    else
    {
        return false;
    }
}

int QuadraticProbing::databaseSize()
{
    return output.size();
}

int QuadraticProbing::hash(std::string id)
{
    int p = 37;
    long long int hash = 0;
    int factor = 1;

    for (int i = 0; i < id.size(); i++)
    {
        hash += (id[i] + 1) * factor;
        factor += 2 * p;
    }
    return hash % (100001);
    return 0;
}