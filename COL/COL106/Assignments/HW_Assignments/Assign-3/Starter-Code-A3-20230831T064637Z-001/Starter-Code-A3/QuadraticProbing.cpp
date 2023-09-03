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

std::vector<int> LinearProbing::getTopK(int k) // can easily be optimised, to be tested
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
        int factor = 2;
        while (bankStorage1d[idx].id != id and idx != Hash_val)
        {
            idx = (idx + (factor * factor)) % 100001;
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

int main()
{
    LinearProbing *chain = new LinearProbing();
    chain->createAccount("CDAD7786825_7990768648", 648);
    chain->createAccount("DCDA7547234_9919615552", 552);
    chain->createAccount("AACB1850545_7974534788", 788);
    cout << chain->databaseSize() << endl;
    chain->createAccount("CDBD5250777_1124276711", 711);
    chain->createAccount("ABCB8377155_0656808575", 575);
    vector<int> ans;
    ans = chain->getTopK(1);
    for (int i = 0; i < 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    chain->createAccount("CDDC3792028_3313680038", 38);
    chain->createAccount("CBBA9574444_7470182321", 321);
    chain->createAccount("DBCC4334636_8057544188", 188);
    ans = chain->getTopK(3);
    for (int i = 0; i < 3; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    chain->createAccount("BABD5741078_5109455304", 304);
    chain->createAccount("BCBA7529510_0817878868", 868);
    cout << chain->databaseSize() << endl;
    ans = chain->getTopK(1);
    for (int i = 0; i < 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    chain->addTransaction("BCBA7529510_0817878868", -860);
    cout << chain->getBalance("BCBA7529510_0817878868") << endl;
    ans = chain->getTopK(1);
    for (int i = 0; i < 1; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    chain->addTransaction("DCDA7547234_9919615552", 592);
    ans = chain->getTopK(5);
    for (int i = 0; i < 5; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    chain->deleteAccount("DCDA7547234_9919615552");
    ans = chain->getTopK(4);
    for (int i = 0; i < 4; i++)
    {
        cout << ans[i] << " ";
    }
    cout << endl;

    cout << chain->databaseSize() << endl;
    return 0;
}