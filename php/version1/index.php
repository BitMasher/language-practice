#!/usr/bin/php
<?PHP

function main() {
    print('Generating a new deck.' . PHP_EOL);
    for($x = 0; $x < 100; $x++) {
        $card_deck = new_deck();
        for($i = 0; $i < 26; $i++) {
            shuffle_deck($card_deck);
            deal_cards($card_deck);
        }
    }
}

function new_deck() {
    $my_deck = [];
    foreach (['S','D','C','H'] as $suitidx => $suit) {
        foreach(['A','1','2','3','4','5','6','7','8','9','J','Q','K'] as $validx => $value) {
            array_push($my_deck, $value.$suit);
        }
    }
    return $my_deck;
}

function shuffle_deck(&$card_deck) {
    shuffle($card_deck);
}

function deal_cards(&$my_deck) {
    $choice_one = array_shift($my_deck);
    $choice_two = array_shift($my_deck);
    print($choice_one . ', ' . $choice_two . ', ' . count($my_deck) . PHP_EOL);
}

main();

?>