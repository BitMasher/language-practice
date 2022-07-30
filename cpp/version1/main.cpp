#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

char suits[4] = {'S','D','C','H'};
char values[13] = {'A','1','2','3','4','5','6','7','8','9','J','Q','K'};

vector<string> new_deck() {
    vector<string> cards;
    for(int s = 0; s < 4; s++) {
        for(int v = 0; v < 13; v++) {
            cards.push_back(string({values[v], suits[s]}));
        }
    }
    return cards;
}

void shuffle_deck(vector<string> &card_deck) {
    auto rd = std::random_device {}; 
    auto rng = std::default_random_engine { rd() };
    shuffle(begin(card_deck), end(card_deck), rng);
}

void deal_cards(vector<string> & my_deck) {
    string choice_one = my_deck[0];
    string choice_two = my_deck[1];
    my_deck.erase(my_deck.begin(), my_deck.begin()+2);
    cout << choice_one << ", " << choice_two << ", " << my_deck.size() << "\n";
}

int main () {
    cout << "Generating a new deck.\n";
    for(int x = 0; x < 100; x++) {
        vector<string> cards = new_deck();
        for(int i = 0; i < 26; i++) {
            shuffle_deck(cards);
            deal_cards(cards);
        }
    }
}