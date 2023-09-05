#include "Comp.h"
#include <cassert>
using namespace std;

Comp::Comp()
{
    bankStorage1d.resize(100003);
}

int getIndComp(string id, vector<Account> bankStorage1d)
{
    int Hash_val = Comp().hash(id);
    if (bankStorage1d[Hash_val].id != "")
    {
        if (bankStorage1d[Hash_val].id == id)
        {
            return Hash_val;
        }
        int idx = Hash_val + 1;
        while (bankStorage1d[idx].id != id and idx != Hash_val and bankStorage1d[idx].id != "")
        {
            idx = (idx + 1) % 100004;
        }
        if (bankStorage1d[idx].id == id)
        {
            return idx;
        }

        return -1;
    }
    return -1;
}

void Comp::createAccount(std::string id, int count)
{
    int Hash_val = hash(id);
    while (bankStorage1d[Hash_val].id != "" and bankStorage1d[Hash_val].id != "deleted")
    {
        Hash_val = (Hash_val + 1) % 100004;
    }
    bankStorage1d[Hash_val].id = id;
    bankStorage1d[Hash_val].balance = count;
    output.push_back(count);
}

std::vector<int> Comp::getTopK(int k)
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
    int size = output.size();
    for (int i = 0; i < min(k, size); i++)
    {
        ans.push_back(output[i]);
    }

    return ans;
}

int Comp::getBalance(std::string id)
{
    int Hash_val = getIndComp(id, bankStorage1d);
    if (Hash_val != -1)
    {
        return bankStorage1d[Hash_val].balance;
    }
    else
    {
        return -1;
    }
}

void Comp::addTransaction(std::string id, int count)
{
    int Hash_val = getIndComp(id, bankStorage1d);
    if (Hash_val != -1)
    {
        for (int i = 0; i < output.size(); i++)
        {
            if (bankStorage1d[Hash_val].balance == output[i])
            {
                output[i] += count;
                break;
            }
        }
        bankStorage1d[Hash_val].balance += count;
        return;
    }
    else
    {
        createAccount(id, count);
        return;
    }
}

bool Comp::doesExist(std::string id)
{
    if (getIndComp(id, bankStorage1d) == -1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

bool Comp::deleteAccount(std::string id)
{
    int Hash_val = getIndComp(id, bankStorage1d);
    if (Hash_val != -1)
    {
        bankStorage1d[Hash_val].id = "deleted";
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
    else
    {
        return false;
    }
}
int Comp::databaseSize()
{
    return output.size();
}

int Comp::hash(std::string id)
{
    // we will take p as greater than character set, p = A to Z and _ ans 0 to 9 that is, 10+1+26 = 37 so we take 41
    // and we have a 22 length string, so the highest power would be 41^21
    int p = 41;
    long long int hash = 0;
    int factor = 1;

    for (int i = 0; i < id.size(); i++)
    {
        hash = (hash + (id[i] + 1) * factor) % (100004);
        if (hash < 0)
        {
            hash = -1 * hash;
        }
        factor *= factor;
    }
    return hash % (100004);
}

// Feel free to add any other helper functions you need
// Good Luck!

