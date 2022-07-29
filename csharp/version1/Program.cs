public static class BlackJack {
    private static List<string> suits = new List<string>(){"S","D","C","H"};
    private static List<string> values = new List<string>(){"A","1","2","3","4","5","6","7","8","9","J","Q","K"};

    public static List<string> NewDeck() {
        var my_deck = new List<string>();
        suits.ForEach((e) => values.ForEach((e2) => my_deck.Add(e2+e)));
        return my_deck;
    }

    public static void ShuffleDeck(in List<string> card_deck) {
        var r = new Random();
        card_deck.Sort((_,_)=>r.Next(2)-1);
    }

    public static void DealCards(in List<string> my_deck) {
        var choice_one = my_deck[0];
        my_deck.RemoveAt(0);
        var choice_two = my_deck[0];
        my_deck.RemoveAt(0);
        Console.WriteLine($"{choice_one}, {choice_two}, {my_deck.Count}");
    }
}


public class Program {
    public static void Main() {
        Console.WriteLine("Generating a new deck.");
        var card_deck = BlackJack.NewDeck();
        BlackJack.ShuffleDeck(card_deck);
        BlackJack.DealCards(card_deck);
    }
}