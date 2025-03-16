#include "ladder.h"

void error(string word1, string word2, string ms)
{
    cout << "Error: " << word1 << " " << word2 << " | " << ms << endl;
}

bool edit_distance_within(const std::string &str1, const std::string &str2, int d)
{
    int length1 = str1.length(), length2 = str2.length();
    if (abs(length1 - length2) > d)
    {
        return false;
    }
    int count = 0;
    int i = 0, j = 0;
    while (i < length1 && j < length2)
    {
        if (str1[i] != str2[j])
        {
            if (count == d) {
                return false;
            }
            if (length1 > length2)
                i++;
            else if (length1 < length2)
                j++;
            else
            {
                i++;
                j++;
            }
            count++;
        }
        else
        {
            i++;
            j++;
        }
    }
    cout << "COUNT: " << count << endl;
    if (count < d && abs(length1 - length2) == d)
        count++;
    return count == d;
}

bool is_adjacent(const string &word1, const string &word2)
{
    if (word1 == word2)  { return true; }
    return edit_distance_within(word1, word2, 1);
}

vector<string> generate_word_ladder(const string &begin_word, const string &end_word, const set<string> &word_list)
{
    queue<vector<string>> ladder_queue;
    ladder_queue.push(vector<string>{begin_word});
    set<string> visited;
    visited.insert(begin_word);
    while (!ladder_queue.empty())
    {
        vector<string> ladder = ladder_queue.front();
        ladder_queue.pop();
        string last_word = ladder[ladder.size() - 1];
        for (string word : word_list)
        {
            if (is_adjacent(last_word, word))
            {
                if (visited.find(word) == visited.end())
                {
                    visited.insert(word);
                    vector<string> new_ladder(ladder);
                    new_ladder.push_back(word);
                    if (word == end_word)
                    {
                        // for (auto it = ladder_queue.begin(); it < ladder_queue.end(); ++it) {

                        // }
                        return new_ladder;
                    }
                    ladder_queue.push(new_ladder);
                }
            }
        }
    }
    return vector<string>();
}

void load_words(set<string> &word_list, const string &file_name)
{
    ifstream in(file_name);
    string word;
    while (in >> word)
    {
        word_list.insert(word);
    }
    in.close();
}

void print_word_ladder(const vector<string> &ladder)
{
    if (!ladder.empty()) {
        cout << "Word ladder found: ";
        for (string word : ladder) {
            cout << word << " ";
        }
    } else {
        cout << "No word ladder found.";
    }
    cout << endl;
}
// void verify_word_ladder()
// {
//     return;
// }