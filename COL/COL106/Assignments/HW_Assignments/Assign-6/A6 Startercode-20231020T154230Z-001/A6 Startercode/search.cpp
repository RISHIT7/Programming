// Do NOT add any other includes
#include "search.h"

#define SIZE 300023;

int hash_val(string id)
{
    int hashkey = 0;
    int pow = 1;

    for (char ch : id)
    {
        hashkey = (hashkey + ch * pow) % SIZE;
        pow = (pow * 37) % SIZE;
    }

    return hashkey;
}

/* bool isequal(string x, string y){
    return x==y;
} */

char to_lower(char c)
{
    return c - 'A' + 'a';
}

SearchEngine::SearchEngine()
{
    // Implement your function here
}

SearchEngine::~SearchEngine()
{
    // Implement your function here
}

void SearchEngine::insert_sentence(int book_code, int page, int paragraph, int sentence_no, string sentence)
{
    // Implement your function here
    for (int i = 0; i < sentence.size(); i++)
    {
        if (sentence[i] >= 'A' and sentence[i] <= 'Z')
        {
            sentence[i] = to_lower(sentence[i]);
        }
    }

    word_instance curr;
    curr.add_instance(sentence, book_code, page, paragraph, sentence_no);
    int l = sentence.size();
    sd.push_back({curr, l});
    return;
}

Node *SearchEngine::search(string pattern, int &n_matches)
{
    // Implement your function here
    // Node* nextnode = new Node(); //here
    for (int i = 0; i < pattern.size(); i++)
    {
        if (pattern[i] >= 'A' and pattern[i] <= 'Z')
        {
            pattern[i] = to_lower(pattern[i]);
        }
    }
    int a = pattern.size();

    // int hash = hash_val(pattern);

    // for (auto sdi : sd)
    // {
    //     int b = sdi.second;
    //     string curr_sen = sdi.first.s;
    //     if (a > b)
    //     {
    //         continue;
    //     }
    //     else
    //     {
    //         for (int j = 0; j < b - a + 1; j++)
    //         {
    //             string current = curr_sen.substr(j, j + a - 1);
    //             int hash1 = hash_val(current);
    //             if (hash != hash1)
    //             {
    //                 continue;
    //             }
    //             else
    //             {
    //                 if (isequal(current, pattern))
    //                 {
    //                     Node *ans = new Node(sdi.first.book_code, sdi.first.page, sdi.first.paragraph, sdi.first.sentence_no, j);
    //                     ans->right = nextnode; // here
    //                     nextnode = ans;        // here
    //                 }
    //             }
    //         }
    //     }
    // }
    // return nullptr; // here
}
