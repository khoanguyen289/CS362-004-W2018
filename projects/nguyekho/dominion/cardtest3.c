/*
 * cardtest3.c
 *
 * This file includes tests for card steward
 *
 * Include the following lines in your makefile:
 *
 * cardtest3: cardtest3.c dominion.o rngs.o
 *      gcc -o cardtest3 -g  cardtest3.c dominion.o rngs.o $(CFLAGS)
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

  printf("----------Card Test 3: Testing steward card effect----------\n\n");
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
   *     Test Case 1: Player chooses + 2 cards and has enough cards on deck
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 1: Player chooses + 2 cards and has enough cards on deck\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  choice1 = 1;
  choice2 = 0;
  choice3 = 0;
  player = 0;
  bonus = 0;
  handPos = 0;

  // set card at handPos of the player to steward
  testG.hand[player][handPos] = steward;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(steward, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 1a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1b - cardEffect() does not change the number of coins. Result: ");
  if (testG.coins == G.coins) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1c - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded steward). Result: ");
  if (testG.handCount[player] == G.handCount[player] + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1d - cardEffect() correctly places steward into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == steward) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1e - cardEffect() correctly increases playedCardCount by 1. Result: ");
  if (testG.playedCardCount == G.playedCardCount + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1f - cardEffect() correctly decreases player's deckCount by 2. Result: ");
  if (testG.deckCount[player] == G.deckCount[player] - 2) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1g - cardEffect() does not change other players' handCount and deckCount. Result: ");
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

  // Test case 1 result
  if (success) {
    printf("Test Case 1 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 1 COMPLETED WITH ERROR(S)! \n\n");
  }  


  /* -----------------------------------------------------------------------
   *     Test Case 2: Player chooses + 2 cards and does not have enough cards on deck
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 2: Player chooses + 2 cards and does not have enough cards on deck\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  choice1 = 1;
  choice2 = 0;
  choice3 = 0;
  player = 0;
  bonus = 0;
  handPos = 0;

  // set card at handPos of the player to steward
  testG.hand[player][handPos] = steward;

  // discard all cards in deck
  testG.discardCount[player] = testG.deckCount[player];
  testG.deckCount[player] = 0;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(steward, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 2a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2b - cardEffect() does not change the number of coins. Result: ");
  if (testG.coins == G.coins) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2c - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded steward). Result: ");
  if (testG.handCount[player] == G.handCount[player] + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2d - cardEffect() correctly places steward into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == steward) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2e - cardEffect() correctly increases playedCardCount by 1. Result: ");
  if (testG.playedCardCount == G.playedCardCount + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2f - cardEffect() correctly updates player's deckCount (equal old discardCount - 2). Result: ");
  if (testG.deckCount[player] == G.discardCount[player] - 2) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2g - cardEffect() does not change other players' handCount and deckCount. Result: ");
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

  // Test case 2 result
  if (success) {
    printf("Test Case 2 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 2 COMPLETED WITH ERROR(S)! \n\n");
  }  

  /* -----------------------------------------------------------------------
   *     Test Case 3: Player chooses + 2 coins
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 3: Player chooses + 2 coins\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  choice1 = 2;
  choice2 = 0;
  choice3 = 0;
  player = 0;
  bonus = 0;
  handPos = 0;

  // set card at handPos of the player to smithy
  testG.hand[player][handPos] = steward;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(steward, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 3a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 3b - cardEffect() correctly increases the number of coins by 2. Result: ");
  if (testG.coins == G.coins + 2) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 3c - cardEffect() correctly decreases player's handCount by 1 (discarded steward). Result: ");
  if (testG.handCount[player] == G.handCount[player] - 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 3d - cardEffect() correctly places steward into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == steward) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 3e - cardEffect() correctly increases playedCardCount by 1. Result: ");
  if (testG.playedCardCount == G.playedCardCount + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 3f - cardEffect() does not change player's deckCount. Result: ");
  if (testG.deckCount[player] == G.deckCount[player]) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 3g - cardEffect() does not change other players' handCount and deckCount. Result: ");
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

  // Test case 3 result
  if (success) {
    printf("Test Case 3 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 3 COMPLETED WITH ERROR(S)! \n\n");
  }  


  /* -----------------------------------------------------------------------
   *     Test Case 4: Player chooses trash 2 cards
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 4: Player chooses trash 2 cards\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  choice1 = 3;
  choice2 = 2; // chose which card to discard
  choice3 = 1; // chose which card to discard
  player = 0;
  bonus = 0;
  handPos = 0;

  // set card at handPos of the player to smithy
  testG.hand[player][handPos] = steward;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(steward, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 4a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 4b - cardEffect() does not change the number of coins. Result: ");
  if (testG.coins == G.coins) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 4c - cardEffect() correctly decreases player's handCount by 3 (trashed 2 cards and discarded steward). Result: ");
  if (testG.handCount[player] == G.handCount[player] - 3) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 4d - cardEffect() correctly places steward into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == steward) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 4e - cardEffect() correctly increases playedCardCount by 1. Result: ");
  if (testG.playedCardCount == G.playedCardCount + 1) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 4f - cardEffect() does not change player's deckCount. Result: ");
  if (testG.deckCount[player] == G.deckCount[player]) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 4g - cardEffect() does not change other players' handCount and deckCount. Result: ");
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

  // Test case 4 result
  if (success) {
    printf("Test Case 4 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 4 COMPLETED WITH ERROR(S)! \n\n");
  }  

  printf("----------Card Test 4: Testing steward card effect COMPLETED----------\n\n");

  return 0;
}