#include "Chaining.h"

void Chaining::createAccount(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
    Account *new_account = new Account();
    new_account->balance = count;
    new_account->id = id;



    delete new_account;
}

std::vector<int> Chaining::getTopK(int k) {
    // IMPLEMENT YOUR CODE HERE
    return std::vector<int>(); // Placeholder return value
}

int Chaining::getBalance(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}

void Chaining::addTransaction(std::string id, int count) {
    // IMPLEMENT YOUR CODE HERE
}

bool Chaining::doesExist(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    return false; // Placeholder return value
}

bool Chaining::deleteAccount(std::string id) {
    // IMPLEMENT YOUR CODE HERE
    return false; // Placeholder return value
}
int Chaining::databaseSize() {
    // IMPLEMENT YOUR CODE HERE
    return 0; // Placeholder return value
}

int Chaining::hash(std::string id) {
    int p = 31;
    int hash = 0;
    int factor = 1;

    for (int i = 0; i < id.size(); i++)
    {
        hash += (id[i] - 'A' + 1)*factor;
        factor *= p;
    }
    
    return hash%(100003);
}

