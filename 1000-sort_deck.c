#include "deck.h"
#include <stdlib.h>

/**
 * compare_cards - compares the cards by there suit
 *                 and next by value
 * @card_a: 1st card
 * @card_b: second card
 *
 */
int compare_cards(const void *a, const void *b)
{
    const card_t *card_a = *(const card_t **)a;
    const card_t *card_b = *(const card_t **)b;

    /*compare by suit*/
    if (card_a->kind < card_b->kind)
    {
        return -1;
    }
    else if (card_a->kind > card_b->kind)
    {
        return 1;
    }

    /*if their suit are the same compare the cards with value*/
    if (card_a->value < card_b->value)
    {
        return -1;
    }
    else if (card_a->value > card_b->value)
    {
        return 1;
    }

    /*the cards are equal*/
    return 0;
}

/**
 * sort_deck - a function that sorts a deck of cards
 * @count: counts the cards
 *
 * Return: sorted list using qsort function
 */
void sort_deck(deck_node_t **deck)
{
    /*count number of cards in deck*/
    int i = 0;
    int j = 0;
    const card_t *cards[52];
    deck_node_t *current = *deck;

    while (current != NULL)
    {
        i++;
        current = current->next;
    }

    /*array of card pointers to sort*/
    current = *deck;
    for (j = 0; j < i; j++)
    {
        cards[j] = current->card;
        current = current->next;
    }

    /*sort the array using qsort*/
    qsort(cards, i, sizeof(card_t*), compare_cards);

    /*update the linked list as a sorted list*/
    current = *deck;
    for (j = 0; j < i; j++)
    {
        current->card = cards[j];
        current = current->next;
    }
}

