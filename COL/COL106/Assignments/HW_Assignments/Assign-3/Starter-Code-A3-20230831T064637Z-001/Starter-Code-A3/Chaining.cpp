#include "Chaining.h"
#include <vector>

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
        bankstorage2d[Hash_val].push_back(*new_account);
    }
    catch (std::runtime_error())
    {
        vector<Account> temp;
        temp.push_back(*new_account);
        bankstorage2d.insert(bankstorage2d.begin() + Hash_val, temp);
    }

    size++;

    delete new_account;
}

std::vector<int> Chaining::getTopK(int k)
{
    // IMPLEMENT YOUR CODE HERE
    return std::vector<int>(); // Placeholder return value
}

int Chaining::getBalance(std::string id) // to be tested, what if Hash_val dne
{
    int Hash_val = hash(id);
    vector<Account> temp;
    try
    {
        vector<Account> temp = bankStorage2d[Hash_val];
    }
    catch (std::runtime_error())
    {
        return -1;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].id == id)
        {
            return temp[i].balance;
        }
    }
    return -1;
}

void Chaining::addTransaction(std::string id, int count) // to be tested, could be better implemented
{
    int Hash_val = hash(id);
    vector<Account> temp;
    try
    {
        temp = bankStorage2d[Hash_val];
    }
    catch (std::runtime_error())
    {
        createAccount(id, count);
        return;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].id == id)
        {
            temp[i].balance += count;
            return;
        }
    }
    createAccount(id, count);
    return;
}

bool Chaining::doesExist(std::string id) // to be tested, also does not include when Hash does not exist
{
    int Hash_val = hash(id);
    vector<Account> temp;
    try
    {
        temp = bankStorage2d[Hash_val];
    }
    catch (std::runtime_error())
    {
        return -1;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].id == id)
        {
            return true;
        }
    }

    return false;
}

bool Chaining::deleteAccount(std::string id) // to be tested, does not include case when Has dne
{
    int Hash_val = hash(id);
    vector<Account> temp;
    try
    {
        vector<Account> temp = bankStorage2d[Hash_val];
    }
    catch (std::runtime_error())
    {
        return -1;
    }
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i].id == id)
        {
            size--;
            temp.erase(temp.begin() + i);
            return true;
        }
    }

    return false;
}
int Chaining::databaseSize() // to be tested
{
    return size;
}

int Chaining::hash(std::string id)
{
    int p = 31;
    int hash = 0;
    int factor = 1;

    for (int i = 0; i < id.size(); i++)
    {
        hash += (id[i] - 'A' + 1) * factor;
        factor *= p;
    }

    return hash % (99991);
}

signed main()
{
    return 0;
}