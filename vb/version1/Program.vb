Imports System

Module Program
    Sub Main(args As String())
        Console.WriteLine("Generating a new deck.")
        Dim card_deck As List(Of String)
        Dim x As Integer = 0
        Dim i As Integer = 0
        For x = 0 to 99
            card_deck = NewDeck()
            For i = 0 to 25
                ShuffleDeck(card_deck)
                DealCards(card_deck)
            Next
        Next
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
        Dim n As Integer = card_deck.Count
        While n > 1
            n = n-1
            Dim k As Integer = r.Next(n + 1)
            Dim value As String = card_deck(k)
            card_deck(k) = card_deck(n)
            card_deck(n) = value
        End While
    End Sub

    Sub DealCards(ByRef my_deck As List(Of String))
        Dim choice_one As String = my_deck(0)
        my_deck.RemoveAt(0)
        Dim choice_two As String = my_deck(0)
        my_deck.RemoveAt(0)
        Console.WriteLine($"{choice_one}, {choice_two}, {my_deck.Count}")
    End Sub
End Module
