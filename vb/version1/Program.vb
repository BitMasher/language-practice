Imports System

Module Program
    Sub Main(args As String())
        Console.WriteLine("Generating a new deck.")
        Dim card_deck As List(Of String)
        card_deck = NewDeck()
        ShuffleDeck(card_deck)
        DealCards(card_deck)
    End Sub

    Function NewDeck() As List(Of String)
        Dim my_deck As New List(Of String)
        Dim suits As New List(Of String) From {"S","D","C","H"}
        Dim values As New List(of String) From {"A","1","2","3","4","5","6","7","8","9","J","Q","K"}
        For Each s As String In Suits
            For Each v As String In values
                my_deck.Add(v+s)
            Next
        Next
        Return my_deck
    End Function

    Sub ShuffleDeck(ByRef card_deck As List(Of String))
        Dim r As New Random()
        card_deck.Sort(Function(a,b) r.Next(2)-1)
    End Sub

    Sub DealCards(ByRef my_deck As List(Of String))
        Dim choice_one As String = my_deck(0)
        my_deck.RemoveAt(0)
        Dim choice_two As String = my_deck(0)
        my_deck.RemoveAt(0)
        Console.WriteLine($"{choice_one}, {choice_two}, {my_deck.Count}")
    End Sub
End Module
