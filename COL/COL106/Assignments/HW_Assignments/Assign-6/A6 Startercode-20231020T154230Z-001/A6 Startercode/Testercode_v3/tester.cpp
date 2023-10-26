#include <bits/stdc++.h>
#include "dict.h"

#define FILENAME "mahatma-gandhi-collected-works-volume-1.txt"

int main() {
    std::ifstream inputFile(FILENAME);

    if (!inputFile.is_open()) {
        std::cerr << "Error: Unable to open the input file." << std::endl;
        return 1;
    }

    std::string tuple;
    std::string sentence;

    Dict d;

    while (std::getline(inputFile, tuple, ')') && std::getline(inputFile, sentence)) {
        // Get a line in the sentence
        tuple += ')';

        std::vector<int> metadata;    
        std::istringstream iss(tuple);

        // Temporary variables for parsing
        std::string token;

        // Ignore the first character (the opening parenthesis)
        iss.ignore(1);

        // Parse and convert the elements to integers
        while (std::getline(iss, token, ',')) {
            // Trim leading and trailing white spaces
            size_t start = token.find_first_not_of(" ");
            size_t end = token.find_last_not_of(" ");
            if (start != std::string::npos && end != std::string::npos) {
                token = token.substr(start, end - start + 1);
            }
            
            // Check if the element is a number or a string
            if (token[0] == '\'') {
                // Remove the single quotes and convert to integer
                int num = std::stoi(token.substr(1, token.length() - 2));
                metadata.push_back(num);
            } else {
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

    // Get the counts of some words
    std::ifstream dict("counts.txt"); 
    if (!dict.is_open()) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1;
    }

    bool passed = true;
    std::string l;
    while (std::getline(dict, l)) {
        std::istringstream iss(l);
        std::string key;
        int value;

        if (std::getline(iss, key, ',') && iss >> value) {
            if(d.get_word_count(key) != value) {
                cout << "Expected count for word " << key << ": " << value << ", received: " << d.get_word_count(key) << endl;
                passed = false; 
                break;
            }
        }
    }

    if (passed) {
        cout << "Passed" << endl;
    } else {
        cout << "Failed" << endl;
    }

    dict.close();

    return 0;
}
