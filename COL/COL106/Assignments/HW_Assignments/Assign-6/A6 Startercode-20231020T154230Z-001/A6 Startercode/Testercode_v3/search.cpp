// Do NOT add any other includes
#include <bits/stdc++.h>
#include "search.h"

#define FILENAME "mahatma-gandhi-collected-works-volume-1.txt"

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

            offset.push_back(i - j);
            j = lps[j - 1];
        }

        else if (i < N and pat[j] != txt[i])
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
    }
    return offset;
}

char to_lower(char c)
{
    return c - 'A' + 'a';
}

SearchEngine::SearchEngine()
{
    sd = new sent[4];
    tot_size = 2;
    curr_size = 0;
}

SearchEngine::~SearchEngine()
{
    delete[] sd;
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

    if (curr_size >= tot_size - 1)
    {
        tot_size *= 2;
        sent *temp = new sent[tot_size];

        for (int i = 0; i < curr_size; i++)
        {
            sent t_sent = sd[i];
            temp[i] = t_sent;
        }

        delete[] sd;

        sd = temp;
    }

    sent curr(sentence, book_code, page, paragraph, sentence_no);
    sd[curr_size] = curr;
    curr_size++;
    return;
}

Node *SearchEngine::search(string pattern, int &n_matches) // check for memory leaks
{
    // Implement your function here
    list return_list;

    for (int i = 0; i < pattern.size(); i++)
    {
        if (pattern[i] >= 'A' and pattern[i] <= 'Z')
        {
            pattern[i] = to_lower(pattern[i]);
        }
    }
    int a = pattern.size();

    for (int i = 0; i < curr_size; i++)
    {
        int b = sd[i].length;
        string curr_sen = sd[i].s;
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
                for (int j = 0; j < offsets.size(); j++)
                {
                    Node *curr = new Node(sd[i].book_code, sd[i].page, sd[i].paragraph, sd[i].sentence_no, offsets[j]);
                    return_list.insert_head(curr);
                    n_matches++;
                }
            }
        }
    }
    return return_list.head;
}

int main()
{
    std::ifstream inputFile(FILENAME);

    if (!inputFile.is_open())
    {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        return 1;
    }

    std::string tuple;
    std::string sentence;

    SearchEngine d;

    while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence))
    {
        // Get a line in the sentence
        tuple += ')';

        std::vector<int> metadata;
        std::istringstream iss(tuple);

        // Temporary variables for parsing
        std::string token;

        // Ignore the first character (the opening parenthesis)
        iss.ignore(1);

        // Parse and convert the elements to integers
        while (std::getline(iss, token, ','))
        {
            // Trim leading and trailing white spaces
            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            if (start != std::string::npos && end != std::string::npos)
            {
                token = token.substr(start, end - start + 1);
            }

            // Check if the element is a number or a string
            if (token[0] == '\'')
            {
                // Remove the single quotes and convert to integer
                int num = std::stoi(token.substr(1, token.length() - 2));
                metadata.push_back(num);
            }
            else
            {
                // Convert the element to integer
                int num = std::stoi(token);
                metadata.push_back(num);
            }
        }

        // Now we have the string in sentence
        // And the other info in metadata
        // Add to the dictionary

        // Insert in the dictionary
        d.insert_sentence(metadata[0], metadata[1], metadata[2], metadata[3], sentence);
    }

    inputFile.close();



    return 0;
}