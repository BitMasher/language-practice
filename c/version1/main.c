#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

char suits[4] = {'S','D','C','H'};
char values[13] = {'A','1','2','3','4','5','6','7','8','9','J','Q','K'};
char deck_size = 52;
char ** new_deck() {
    char ** cards = malloc(deck_size * sizeof(char*));
    for(int s = 0, i = 0; s < 4; s++) {
        for(int v = 0; v < 13; v++, i++) {
            cards[i] = malloc(3 * sizeof(char));
            cards[i][0] = values[v];
            cards[i][1] = suits[s];
            cards[i][2] = '\0';
        }
    }
    return cards;
}

int shuffle_compar(const void* p1, const void* p2) {
    return (rand() % 3) - 1;
}

void shuffle_deck(char ** card_deck) {
    srand(time(NULL));
    qsort(card_deck, 52, sizeof(const char *), shuffle_compar);
}

void deal_cards(char ** my_deck) {
    char* choice_one = my_deck[0];
    char* choice_two = my_deck[1];
    deck_size = deck_size-2;
    char**new_deck = malloc(deck_size * sizeof(char*));
    for(int i = 2; i < deck_size+2; i++) {
        new_deck[i-2] = malloc(3*sizeof(char));
        new_deck[i-2] = my_deck[i];
    }
    printf("%s, %s, %d", choice_one, choice_two, deck_size);
}

int main() {
    printf("Generating a new deck.\n");
    char ** cards = new_deck();
    shuffle_deck(cards);
    deal_cards(cards);
    return 0;
}