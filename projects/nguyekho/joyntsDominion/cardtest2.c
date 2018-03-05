/*
 * cardtest2.c
 *
 * This file includes tests for card adventurer
 *
 * Include the following lines in your makefile:
 *
 * cardtest2: cardtest2.c dominion.o rngs.o
 *      gcc -o cardtest2 -g  cardtest2.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int main() {

  srand(time(NULL));
  printf("----------Card Test 2: Testing adventurer card effect----------\n\n");
  int i;
  int seed = 5;
  int numPlayers = 2;
  int player = 0;
  int choice1, choice2, choice3, handPos, bonus;
  int returnValue;
  int changed, success;
  int cardDrawn1, cardDrawn2;
  int k[10] = {adventurer, council_room, feast, gardens, mine, remodel, smithy, village, baron, great_hall};
  struct gameState G, testG;


  /* -----------------------------------------------------------------------
   *     Test Case 1: Player has enough cards on deck
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 1: Player has enough cards on deck\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  choice1 = 0;
  choice2 = 0;
  choice3 = 0;
  player = 0;
  bonus = 0;
  handPos = rand() % 5;

  // set card at handPos of the player to adventurer
  testG.hand[player][handPos] = adventurer;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 1a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1b - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded adventurer). Result: ");
  if (testG.handCount[player] == G.handCount[player] + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1c - cardEffect() correctly places adventurer into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == adventurer) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1d - cardEffect() correctly increases playedCardCount by 1. Result: ");
  if (testG.playedCardCount == G.playedCardCount + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1e - cardEffect() correctly decreases player's deckCount by 2. Result: ");
  if (testG.deckCount[player] == G.deckCount[player] - 2) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1e - cardEffect() does not change other players' handCount and deckCount. Result: ");
  changed = 0;

  for (i = 0; i < numPlayers && i != player; i++) {
    if (testG.handCount[i] != G.handCount[i] || testG.deckCount[i] != G.deckCount[i]) {
      changed = 1;
    }
  }
  if (!changed) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1f - cardEffect() correctly gives player 2 treasures card in hand. Result: ");

  cardDrawn1 = testG.hand[player][testG.handCount[player] - 2];
  cardDrawn2 = testG.hand[player][testG.handCount[player] - 1];
  if ((cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold) &&
      (cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold)) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  // Test case 1 result
  if (success) {
    printf("Test Case 1 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 1 COMPLETED WITH ERROR(S)! \n\n");
  }  

  /* -----------------------------------------------------------------------
   *     Test Case 2: Player does not have enough cards on deck
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 2: Player does not have enough cards on deck\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  choice1 = 0;
  choice2 = 0;
  choice3 = 0;
  player = 0;
  bonus = 0;
  handPos = rand() % 5;

  // set card at handPos of the player to adventurer
  testG.hand[player][handPos] = adventurer;

  // discard all cards in deck
  testG.discardCount[player] = testG.deckCount[player];
  testG.deckCount[player] = 0;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 1a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1b - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded adventurer). Result: ");
  if (testG.handCount[player] == G.handCount[player] + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1c - cardEffect() correctly places adventurer into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == adventurer) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1d - cardEffect() correctly increases playedCardCount by 1. Result: ");
  if (testG.playedCardCount == G.playedCardCount + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1e - cardEffect() correctly updates player's deckCount (equal old discardCount - 2). Result: ");
  if (testG.deckCount[player] == G.discardCount[player] - 2) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1e - cardEffect() does not change other players' handCount and deckCount. Result: ");
  changed = 0;

  for (i = 0; i < numPlayers && i != player; i++) {
    if (testG.handCount[i] != G.handCount[i] || testG.deckCount[i] != G.deckCount[i]) {
      changed = 1;
    }
  }
  if (!changed) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1f - cardEffect() correctly gives player 2 treasures card in hand. Result: ");

  cardDrawn1 = testG.hand[player][testG.handCount[player] - 2];
  cardDrawn2 = testG.hand[player][testG.handCount[player] - 1];
  if ((cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold) &&
      (cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold)) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  // Test case 1 result
  if (success) {
    printf("Test Case 1 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 1 COMPLETED WITH ERROR(S)! \n\n");
  }  

  printf("----------Card Test 2: Testing adventurer card effect COMPLETED----------\n\n");

  return 0;
}