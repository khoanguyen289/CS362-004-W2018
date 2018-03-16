/*
 * cardtest4.c
 *
 * Include the following lines in your makefile:
 *
 * cardtest4: cardtest4.c dominion.o rngs.o
 *      gcc -o cardtest4 -g  cardtest4.c dominion.o rngs.o $(CFLAGS)
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

  printf("----------Card Test 4: Testing great_hall card----------\n\n");
  int i;
  int seed = 5;
  int numPlayers = 2;
  int player = 0;
  int choice1, choice2, choice3, handPos, bonus;
  int returnValue;
  int changed, success;
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
  handPos = 0;

  // set card at handPos of the player to great_hall
  testG.hand[player][handPos] = great_hall;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(great_hall, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 1a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1b - cardEffect() correctly reserves handCount of the player (drawn 1 card and discarded great_hall). Result: ");
  if (testG.handCount[player] == G.handCount[player]) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1c - cardEffect() correctly places great_hall into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == great_hall) {
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

  printf("Test 1e - cardEffect() correctly decreases player's deckCount by 1. Result: ");
  if (testG.deckCount[player] == G.deckCount[player] - 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1f - cardEffect() does not change other players' handCount and deckCount. Result: ");
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

  printf("Test 1g - cardEffect() correctly increases the number of actions by 1. Result: ");
  if (testG.numActions == G.numActions + 1) {
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
  handPos = 0;

  // set card at handPos of the player to great_hall
  testG.hand[player][handPos] = great_hall;

  // discard all cards in deck
  testG.discardCount[player] = testG.deckCount[player];
  testG.deckCount[player] = 0;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(great_hall, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 2a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2b - cardEffect() correctly reserves handCount of the player (drawn 1 card and discarded great_hall). Result: ");
  if (testG.handCount[player] == G.handCount[player]) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2c - cardEffect() correctly places great_hall into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == great_hall) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2d - cardEffect() correctly increases playedCardCount by 1. Result: ");
  if (testG.playedCardCount == G.playedCardCount + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2e - cardEffect() correctly updates player's deckCount (equal old discardCount - 1). Result: ");
  if (testG.deckCount[player] == G.discardCount[player] - 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2f - cardEffect() does not change other players' handCount and deckCount. Result: ");
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

  printf("Test 2g - cardEffect() correctly increases the number of actions by 1. Result: ");
  if (testG.numActions == G.numActions + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  // Test case 2 result
  if (success) {
    printf("Test Case 2 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 2 COMPLETED WITH ERROR(S)! \n\n");
  }  

  printf("----------Card Test 4: Testing great_hall card COMPLETED----------\n\n");

  return 0;
}