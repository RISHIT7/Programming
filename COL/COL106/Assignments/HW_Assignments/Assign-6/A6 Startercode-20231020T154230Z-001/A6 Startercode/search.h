// Do NOT add any other includes
#include <string>
#include <vector>
#include <iostream>
#include "Node.h"
using namespace std;

class SearchEngine
{
private:
    // You can add attributes/helper functions here
    class word_instance
    {
    public:
        vector<int> book_id;
        vector<int> page_no;
        vector<int> paragraph_no;
        vector<int> sent_no;
        word_instance()
        {
        }

        void add_instance(int b, int pg, int pgh, int snt)
        {
            book_id.push_back(b);
            page_no.push_back(pg);
            paragraph_no.push_back(pgh);
            sent_no.push_back(snt);
        }
    };

    vector<pair<string, word_instance>> *words_HashTable;

public:
    /* Please do not touch the attributes and
    functions within the guard lines placed below  */
    /* ------------------------------------------- */
    SearchEngine();

    ~SearchEngine();

    void insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence);

    Node *search(string pattern, int &n_matches);

    /* -----------------------------------------*/
};