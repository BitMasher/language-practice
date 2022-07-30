#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
#include <time.h>

char suits[4] = {'S','D','C','H'};
char values[13] = {'A','1','2','3','4','5','6','7','8','9','J','Q','K'};
char deck_size = 52;
char ** new_deck() {
    deck_size = 52;
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
    srand(time(NULL) + rand());
    qsort(card_deck, 52, sizeof(const char *), shuffle_compar);
}

char ** deal_cards(char ** my_deck) {
    char* choice_one = my_deck[0];
    char* choice_two = my_deck[1];
    my_deck = my_deck+2;
    deck_size = deck_size-2;
    printf("%s, %s, %d\n", choice_one, choice_two, deck_size);
    return my_deck;
}

int main() {
    printf("Generating a new deck.\n");
    for(int x = 0; x < 100; x++) {
        char ** cards = new_deck();
        for(int i = 0; i < 26; i++) {
            shuffle_deck(cards);
            deal_cards(cards);
        }
        free(cards);
    }
    return 0;
}