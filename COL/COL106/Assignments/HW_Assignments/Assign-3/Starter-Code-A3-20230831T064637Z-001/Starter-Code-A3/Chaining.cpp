#include <iostream>
#include "Chaining.h"
#include <vector>
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

std::vector<int> Chaining::getTopK(int k)
{
    
    return std::vector<int>(); 
}

int Chaining::getBalance(std::string id)
{
    int Hash_val = hash(id);
    vector<Account> temp;
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
            if (bankStorage2d[Hash_val][i].id == id)
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
        factor += 2*p;
    }
    return hash % (99991);
}

signed main()
{
    Chaining *chain = new Chaining();
    chain->createAccount("ZZZZ9999999_9999999999", 68464);
    cout << "Balance 1: " << chain->getBalance("ZZZZ9999999_9999999999") << endl;
    cout << "Balance 2: " << chain->getBalance("SBIN6354165_8112283535") << endl;
    chain->addTransaction("SBIN6354165_8112283535", 10000);
    cout << "Balance 2': " << chain->getBalance("SBIN6354165_8112283535") << endl;
    cout << "Exists1: " << chain->doesExist("ZZZZ9999999_9999999999") << endl;
    cout << "Exists2: " << chain->doesExist("SBIN6354165_8212283535") << endl;
    cout << "Size1: " << chain->databaseSize() << endl;
    cout << "Delete 1: " << chain->deleteAccount("SBIN6354165_8112283535") << endl;
    cout << "Delete 2: " << chain->deleteAccount("SBIN6354165_8212283536") << endl;
    cout << "Size2: " << chain->databaseSize() << endl;

    return 0;
}