#include <iostream>
#include "LinearProbing.h"
#include <vector>
using namespace std;

LinearProbing::LinearProbing()
{
    bankStorage1d.resize(100000);
}

void LinearProbing::createAccount(std::string id, int count) // to be tested, handle the case when size == max
{
    Account new_account = Account();
    new_account.balance = count;
    new_account.id = id;

    int Hash_val = hash(id);
    while (bankStorage1d[Hash_val].id != "")
    {
        Hash_val = (Hash_val + 1) % 100001;
    }
    bankStorage1d[Hash_val].id = id;
    bankStorage1d[Hash_val].balance = count;
    SIZE++;
}

std::vector<int> LinearProbing::getTopK(int k) // can easily be optimised, to be tested
{
    vector<int> output;
    for (int i = 0; i < bankStorage1d.size(); i++)
    {
        output.push_back(bankStorage1d[i].balance);
    }

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

int LinearProbing::getBalance(std::string id) // to be tested, wrong implementation of search, does not check modded values, same for all functions
{
    int Hash_val = hash(id);

    if (bankStorage1d[Hash_val].id != "")
    {
        if (bankStorage1d[Hash_val].id == id)
        {
            return bankStorage1d[Hash_val].balance;
        }
        int idx = Hash_val + 1;
        while (bankStorage1d[idx].id != id && Hash_val != idx)
        {
            idx = (idx + 1) % 100001;
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
    else
    {
        return -1;
    }

    return -1;
}

void LinearProbing::addTransaction(std::string id, int count) // to be tested
{
    int Hash_val = hash(id);
    if (bankStorage1d[Hash_val].id != "")
    {
        if (bankStorage1d[Hash_val].id == id)
        {
            bankStorage1d[Hash_val].balance += count;
            return;
        }
        int idx = Hash_val + 1;
        while (bankStorage1d[idx].id != id and idx != Hash_val)
        {
            idx += 1;
        }
        if (bankStorage1d[idx].id == id)
        {
            bankStorage1d[idx].balance += count;
            return;
        }
        else
        {
            createAccount(id, count);
            return;
        }
    }
    else
    {
        createAccount(id, count);
        return;
    }
    createAccount(id, count);
    return;
}

bool LinearProbing::doesExist(std::string id) // to be tested
{
    int Hash_val = hash(id);
    if (bankStorage1d[Hash_val].id != "")
    {
        if (bankStorage1d[Hash_val].id == id)
        {
            return true;
        }
        int idx = Hash_val + 1;
        while (bankStorage1d[idx].id != id and idx != Hash_val)
        {
            idx = (idx + 1) % 100001;
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
    else
    {
        return false;
    }

    return false;
}

bool LinearProbing::deleteAccount(std::string id)
{
    int Hash_val = hash(id);
    if (bankStorage1d[Hash_val].id != "")
    {
        if (bankStorage1d[Hash_val].id == id)
        {
            SIZE--;
            bankStorage1d[Hash_val].id = "";
            bankStorage1d[Hash_val].balance = 0;
            return true;
        }
        int idx = Hash_val + 1;
        while (bankStorage1d[idx].id != id and idx != Hash_val)
        {
            idx = (idx + 1) % 100001;
        }
        if (bankStorage1d[idx].id == id)
        {
            SIZE--;
            bankStorage1d[idx].id = "";
            bankStorage1d[idx].balance = 0;
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    }

    return false;
}
int LinearProbing::databaseSize()
{
    return SIZE;
}

int LinearProbing::hash(std::string id)
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