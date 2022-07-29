function main(): void {
    console.log('Generating a new deck.');
    const card_deck: string[] = new_deck();
    shuffle_deck(card_deck);
    deal_cards(card_deck);
}

function new_deck(): string[] {
    const my_deck: string[] = [];
    const suits: string[] = ['S','D','C','H'];
    const values: string[] = ['A','1','2','3','4','5','6','7','8','9','J','Q','K'];
    suits.forEach((e:string)=>values.forEach((e2:string)=>my_deck.push(`${e2}${e}`)));
    return my_deck;
}

function shuffle_deck(card_deck: string[]): void {
    card_deck.sort(()=>Math.random()*2-1);
}

function deal_cards(my_deck: string[]): void {
    const choice_one: string = my_deck.shift() || '';
    const choice_two: string = my_deck.shift() || '';
    console.log(`${choice_one}, ${choice_two}, ${my_deck.length}`);
}

main();