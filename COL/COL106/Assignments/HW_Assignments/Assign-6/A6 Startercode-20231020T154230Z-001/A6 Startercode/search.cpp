// Do NOT add any other includes
#include "search.h"

#define SIZE 300023;

vector<int> computeLPSArray(string pat, int M, vector<int> lps)
{
    int len = 0;

    lps[0] = 0;

    int i = 1;
    while (i < M)
    {
        if (pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if (len != 0)
            {
                len = lps[len - 1];
            }
            else
            {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

vector<int> KMPSearch(string pat, string txt)
{
    vector<int> offset;

    int M = pat.size();
    int N = txt.size();

    vector<int> lps(M);

    lps = computeLPSArray(pat, M, lps);

    int i = 0;
    int j = 0;

    while ((N - i) >= (M - j))
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            printf("Found pattern at index %d\n", i - j); // to be removed
            cout << "In the sentence\n\n"
                 << txt << "\n\n";
            offset.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return offset;
}

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

    sent curr(sentence, book_code, page, paragraph, sentence_no);
    int l = sentence.size();
    sd.push_back({curr, l});
    return;
}

Node *SearchEngine::search(string pattern, int &n_matches) // check for memory leaks
{
    // Implement your function here
    Node *nextnode = NULL; // here
    for (int i = 0; i < pattern.size(); i++)
    {
        if (pattern[i] >= 'A' and pattern[i] <= 'Z')
        {
            pattern[i] = to_lower(pattern[i]);
        }
    }
    int a = pattern.size();

    // int hash = hash_val(pattern);

    for (auto sdi : sd)
    {
        int b = sdi.second;
        string curr_sen = sdi.first.s;
        if (a > b)
        {
            continue;
        }
        else
        {
            vector<int> offsets = KMPSearch(pattern, curr_sen);
            if (offsets.size() == 0)
            {
                // pattern does not match
                continue;
            }
            else
            {
                // pattern matches
                for (int i = 0; i < offsets.size(); i++)
                {
                    // Node *new_node = new Node(sdi.first.book_code, sdi.first.page, sdi.first.paragraph, sdi.first.sentence_no, offsets[i]);
                    // new_node->right = nextnode;
                    // nextnode = new_node;
                }
            }
        }
    }
    return nextnode; // here
}

int main()
{
    SearchEngine *choogle = new SearchEngine();
    choogle->insert_sentence(2, 3, 4, 5, "I am who I am");
    choogle->insert_sentence(2, 3, 4, 6, "I alskdjf aad fad");
    choogle->insert_sentence(2, 3, 4, 7, "I kjlf ashd flsd fad adf");
    choogle->insert_sentence(2, 3, 4, 8, "I  sdfla ldfas ddfja sld");
    choogle->insert_sentence(2, 3, 4, 9, "I s hdkfka lf fladf asfd I s hdkfka lf fladf asfd");
    choogle->insert_sentence(2, 3, 4, 873, "I s hdkfka lf fladf asfd hdkfka lf fladf asfd");
    choogle->insert_sentence(2, 3, 4, 10, "I a sdfh asfhf asffa sd");
    choogle->insert_sentence(2, 3, 4, 11, "I alksd fka fkd a df f");
    choogle->insert_sentence(2, 3, 4, 12, "I kasd hfkah fd kha df f");

    int matches = 0;
    choogle->search("kfka lf fl", matches);

    return 0;
}
