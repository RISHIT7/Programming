#include "Chaining.h"
using namespace std;

Chaining::Chaining()
{
    bankStorage2d.resize(99991);
}

void Chaining::createAccount(std::string id, int count)
{
    Account *new_account = new Account();
    new_account->balance = count;
    new_account->id = id;

    int Hash_val = hash(id);

    vector<Account> temp;
    temp.push_back(*new_account);
    try
    {
        bankStorage2d[Hash_val].push_back(*new_account);
    }
    catch (std::runtime_error())
    {
        vector<Account> temp;
        temp.push_back(*new_account);
        bankStorage2d.insert(bankStorage2d.begin() + Hash_val, temp);
    }

    SIZE++;

    delete new_account;
}

std::vector<int> Chaining::getTopK(int k) // easily can be optimised
{
    vector<int> output;
    for (int i = 0; i < bankStorage2d.size(); i++)
    {
        for (int j = 0; j < bankStorage2d[i].size(); j++)
        {
            output.push_back(bankStorage2d[i][j].balance);
        }
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

int Chaining::getBalance(std::string id)
{
    int Hash_val = hash(id);
    try
    {
        vector<Account> temp = bankStorage2d[Hash_val];
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].id == id)
            {
                return temp[i].balance;
            }
        }
    }
    catch (std::runtime_error())
    {
        return -1;
    }

    return -1;
}

void Chaining::addTransaction(std::string id, int count)
{
    int Hash_val = hash(id);
    vector<Account> temp;
    try
    {
        temp = bankStorage2d[Hash_val];
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].id == id)
            {
                bankStorage2d[Hash_val][i].balance += count;
                return;
            }
        }
    }
    catch (std::runtime_error())
    {
        createAccount(id, count);
        return;
    }

    createAccount(id, count);
    return;
}

bool Chaining::doesExist(std::string id)
{
    int Hash_val = hash(id);
    vector<Account> temp;
    try
    {
        temp = bankStorage2d[Hash_val];
        for (int i = 0; i < temp.size(); i++)
        {
            if (temp[i].id == id)
            {
                return true;
            }
        }
    }
    catch (std::runtime_error())
    {
        return false;
    }

    return false;
}

bool Chaining::deleteAccount(std::string id)
{
    int Hash_val = hash(id);
    try
    {
        for (int i = 0; i < bankStorage2d[Hash_val].size(); i++)
        {
            if (bankStorage2d[Hash_val][i].id == id) // can be optimised
            {
                SIZE--;
                bankStorage2d[Hash_val].erase(bankStorage2d[Hash_val].begin() + i);
                return true;
            }
        }
    }
    catch (std::runtime_error())
    {
        return false;
    }

    return false;
}
int Chaining::databaseSize()
{
    return SIZE;
}

int Chaining::hash(std::string id)
{
    int p = 37;
    long long int hash = 0;
    int factor = 1;

    for (int i = 0; i < id.size(); i++)
    {
        hash += (id[i] + 1) * factor;
        factor += 2 * p;
    }
    return hash % (99991);
}