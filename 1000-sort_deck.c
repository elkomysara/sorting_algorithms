#include "deck.h"
#include <string.h>

/**
* card_value - Convert a card's value to an integer for comparison
* @value: The value string of the card (e.g., "Ace", "King", "2", etc.)
* 
* Return: The integer representation of the card value.
*/
int card_value(const char *value)
{
if (strcmp(value, "Ace") == 0)
return (1);
if (strcmp(value, "2") == 0)
return (2);
if (strcmp(value, "3") == 0)
return (3);
if (strcmp(value, "4") == 0)
return (4);
if (strcmp(value, "5") == 0)
return (5);
if (strcmp(value, "6") == 0)
return (6);
if (strcmp(value, "7") == 0)
return (7);
if (strcmp(value, "8") == 0)
return (8);
if (strcmp(value, "9") == 0)
return (9);
if (strcmp(value, "10") == 0)
return (10);
if (strcmp(value, "Jack") == 0)
return (11);
if (strcmp(value, "Queen") == 0)
return (12);
if (strcmp(value, "King") == 0)
return (13);
return (0);
}

/**
* swap_nodes - Swap two nodes in the doubly linked list
* @a: The first node
* @b: The second node
*/
void swap_nodes(deck_node_t **deck, deck_node_t *a, deck_node_t *b)
{
if (!a->prev)
*deck = b;
else
a->prev->next = b;

if (b->next)
b->next->prev = a;

a->next = b->next;
b->prev = a->prev;
a->prev = b;
b->next = a;
}

/**
* sort_deck - Sort a deck of cards
* @deck: The deck to sort
*/
void sort_deck(deck_node_t **deck)
{
deck_node_t *node, *temp;
int sorted = 0;

if (!deck || !*deck)
return;

while (!sorted)
{
sorted = 1;
node = *deck;
while (node->next)
{
if (node->card->kind > node->next->card->kind ||
(node->card->kind == node->next->card->kind &&
card_value(node->card->value) > card_value(node->next->card->value)))
{
swap_nodes(deck, node, node->next);
sorted = 0;
}
else
node = node->next;
}
}
}
