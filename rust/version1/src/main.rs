use rand::thread_rng;
use rand::seq::SliceRandom;

const SUITS: [char; 4] = ['S','D','C','H'];
const VALUES: [char; 13] = ['A','1','2','3','4','5','6','7','8','9','J','Q','K'];
fn new_deck() -> Vec<String> {
    let mut my_deck: Vec<String> = Vec::new();
    for s in SUITS.iter() {
        for v in VALUES.iter() {
            my_deck.push(v.to_string() + &s.to_string());
        }
    }
    return my_deck;
}

fn shuffle_deck(card_deck: &mut Vec<String>) {
    card_deck.shuffle(&mut thread_rng());
}

fn deal_cards(my_deck: &mut Vec<String>) {
    let choice_one: String = my_deck.pop().unwrap();
    let choice_two: String = my_deck.pop().unwrap();
    println!("{}, {}, {}", choice_one, choice_two, my_deck.len());
}

fn main() {
    println!("Generating a new deck.");
    for _x in 0..100 {
        let mut card_deck: Vec<String> = new_deck();
        for _i in 0..26 {
            shuffle_deck(&mut card_deck);
            deal_cards(&mut card_deck);
        }
    }
}
