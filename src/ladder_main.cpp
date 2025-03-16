#include "ladder.h"

void test_load_words() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    for (auto it = word_list.begin(); it != word_list.end(); ++it) {
        cout << *it << endl;
    }
}

void test_edit_distance() {
    cout << edit_distance_within("chat", "cheat", 1) << endl;
}

void test_generate() {
    set<string> word_list;
    load_words(word_list, "src/words.txt");
    vector<string> ladder = generate_word_ladder("cat", "dog", word_list);
    print_word_ladder(ladder);
}

int main() {
    // test_load_words();
    test_generate();
    // test_edit_distance();
}