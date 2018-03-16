/*
 * cardtest1.c
 *
 * This file includes tests for card smithy
 *
 * Include the following lines in your makefile:
 *
 * cardtest1: cardtest1.c dominion.o rngs.o
 *      gcc -o cardtest1 -g  cardtest1.c dominion.o rngs.o $(CFLAGS)
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
  printf("----------Card Test 1: Testing smithy card effect----------\n\n");
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
   *     Test Case 1: Player has enough card on deck
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 1: Player has enough card on deck\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  choice1 = 0;
  choice2 = 0;
  choice3 = 0;
  player = 0;
  bonus = 0;
  handPos = rand() % 5;

  // set card at handPos of the player to smithy
  testG.hand[player][handPos] = smithy;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 1a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1b - cardEffect() correctly increases handCount of the player by 2 (drawn 3 cards and discarded smithy). Result: ");
  if (testG.handCount[player] == G.handCount[player] + 2) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1c - cardEffect() correctly places smithy into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == smithy) {
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

  printf("Test 1e - cardEffect() correctly decreases player's deckCount by 3. Result: ");
  if (testG.deckCount[player] == G.deckCount[player] - 3) {
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

  // set card at handPos of the player to smithy
  testG.hand[player][handPos] = smithy;

  // discard all cards in deck
  testG.discardCount[player] = testG.deckCount[player];
  testG.deckCount[player] = 0;

  // reserve gameState for later comparision
  memcpy(&G, &testG, sizeof(struct gameState));

  returnValue = cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0

  success = 1;
  printf("Test 1a - cardEffect() correctly returns 0. Result: ");
  if (returnValue == 0) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1b - cardEffect() correctly increases handCount of the player by 2 (drawn 3 cards and discarded smithy). Result: ");
  if (testG.handCount[player] == G.handCount[player] + 2) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 1c - cardEffect() correctly places smithy into the played pile. Result: ");
  if (testG.playedCards[G.playedCardCount] == smithy) {
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

  printf("Test 1e - cardEffect() correctly updates player's deckCount (equal old discardCount - 3). Result: ");
  if (testG.deckCount[player] == G.discardCount[player] - 3) {
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

  // Test case 1 result
  if (success) {
    printf("Test Case 1 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 1 COMPLETED WITH ERROR(S)! \n\n");
  }

  // This is better checked in the calling function (playCard())
  // /* -----------------------------------------------------------------------
  //  *     Test Case 2: Player does not have Smithy in hand
  //  * -----------------------------------------------------------------------
  //  */

  // printf ("Test Case 2: Player does not have Smithy in hand\n");
  // memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  // initializeGame(numPlayers, k, seed, &testG);

  // choice1 = 0;
  // choice2 = 0;
  // choice3 = 0;
  // player = 0;
  // bonus = 0;
  // handPos = rand() % 5;

  // // make sure there is no smithy
  // for (i = 0; i < testG.handCount[player]; i++) {
  //   testG.hand[player][i] = feast;
  // }

  // // reserve gameState for later comparision
  // memcpy(&G, &testG, sizeof(struct gameState));

  // returnValue = cardEffect(smithy, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return -1

  // success = 1;
  // printf("Test 2a - cardEffect() correctly returns -1. Result: ");
  // if (returnValue == -1) {
  //   printf("PASSED.\n");
  // } else {
  //   printf("FAILED.\n");
  //   success = 0;
  // }

  // printf("Test 2b - cardEffect() does not change player's handCount. Result: ");
  // if (testG.handCount[player] == G.handCount[player]) {
  //   printf("PASSED.\n");
  // } else {
  //   printf("FAILED.\n");
  //   success = 0;
  // }

  // printf("Test 2c - cardEffect() does not place smithy into the played pile. Result: ");
  // if (testG.playedCards[G.playedCardCount] != smithy) {
  //   printf("PASSED.\n");
  // } else {
  //   printf("FAILED.\n");
  //   success = 0;
  // }

  // printf("Test 2d - cardEffect() does not change playedCardCount. Result: ");
  // if (testG.playedCardCount == G.playedCardCount) {
  //   printf("PASSED.\n");
  // } else {
  //   printf("FAILED.\n");
  //   success = 0;
  // }

  // printf("Test 2e - cardEffect() does not change player's deckCount. Result: ");
  // if (testG.deckCount[player] == G.deckCount[player]) {
  //   printf("PASSED.\n");
  // } else {
  //   printf("FAILED.\n");
  //   success = 0;
  // }

  // printf("Test 2e - cardEffect() does not change other players' handCount and deckCount. Result: ");
  // changed = 0;

  // for (i = 0; i < numPlayers && i != player; i++) {
  //   if (testG.handCount[i] != G.handCount[i] || testG.deckCount[i] != G.deckCount[i]) {
  //     changed = 1;
  //   }
  // }
  // if (!changed) {
  //   printf("PASSED.\n");
  // } else {
  //   printf("FAILED.\n");
  //   success = 0;
  // }

  // // Test case 2 result
  // if (success) {
  //   printf("Test Case 2 COMPLETED SUCCESSFULLY! \n\n");
  // } else {
  //   printf("Test Case 2 COMPLETED WITH ERROR(S)! \n\n");
  // }

  printf("----------Card Test 1: Testing smithy card effect COMPLETED----------\n\n");

  return 0;
}