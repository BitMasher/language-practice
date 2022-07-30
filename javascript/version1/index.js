function main() {
    console.log('Generating a new deck.');
    for(x = 0; x < 100; x++) {
        const card_deck = new_deck();
        for(i = 0; i < 26; i++) {
            shuffle_deck(card_deck);
            deal_cards(card_deck);
        }
    }
}

function new_deck() {
    const my_deck = [];
    const suits = ['S','D','C','H'];
    const values = ['A','1','2','3','4','5','6','7','8','9','J','Q','K'];
    suits.forEach(e=>values.forEach(e2=>my_deck.push(`${e2}${e}`)));
    return my_deck;
}

function shuffle_deck(card_deck) {
    card_deck.sort(()=>Math.random()*2-1);
}

function deal_cards(my_deck) {
    choice_one = my_deck.shift();
    choice_two = my_deck.shift();
    console.log(`${choice_one}, ${choice_two}, ${my_deck.length}`);
}

main();