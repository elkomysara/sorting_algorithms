#ifndef DECK_H
#define DECK_H

#include <stdio.h>

/**
* enum kind_e - Enum for card kinds (suits)
* @SPADE: Spade suit
* @HEART: Heart suit
* @CLUB: Club suit
* @DIAMOND: Diamond suit
*/
typedef enum kind_e
{
SPADE = 0,
HEART,
CLUB,
DIAMOND
} kind_t;

/**
* struct card_s - Playing card structure
* @value: Value of the card, from "Ace" to "King"
* @kind: Suit of the card
*/
typedef struct card_s
{
const char *value;
const kind_t kind;
} card_t;

/**
* struct deck_node_s - Node of the deck, doubly linked list
* @card: Pointer to the card of the node
* @prev: Pointer to the previous node of the list
* @next: Pointer to the next node of the list
*/
typedef struct deck_node_s
{
const card_t *card;
struct deck_node_s *prev;
struct deck_node_s *next;
} deck_node_t;

/* Prototypes */
void sort_deck(deck_node_t **deck);
int card_value(const char *value);

#endif /* DECK_H */
