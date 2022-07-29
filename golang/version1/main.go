package main

import (
	"fmt"
	"math/rand"
	"sort"
	"time"
)

func main() {
	fmt.Println("Generating a new deck.")
	card_deck := new_deck()
	shuffle_deck(&card_deck)
	deal_cards(&card_deck)
}

func new_deck() []string {
	my_deck := make([]string, 0)
	for _, s := range []string{"S", "D", "C", "H"} {
		for _, v := range []string{"A", "1", "2", "3", "4", "5", "6", "7", "8", "9", "J", "Q", "K"} {
			my_deck = append(my_deck, fmt.Sprintf("%s%s", v, s))
		}
	}
	return my_deck
}

func shuffle_deck(card_deck *[]string) {
	rand.Seed(time.Now().UTC().UnixMicro())
	sort.Slice(*card_deck, func(a, b int) bool { return rand.Intn(2) == 0 })
}

func deal_cards(my_deck *[]string) {
	choice_one := (*my_deck)[0]
	choice_two := (*my_deck)[1]
	*my_deck = (*my_deck)[2:]
	fmt.Printf("%s, %s, %d", choice_one, choice_two, len(*my_deck))
}
