/*
 * unittest1.c
 *
 * This file includes tests for function gainCard()
 *
 * Include the following lines in your makefile:
 *
 * unittest1: unittest1.c dominion.o rngs.o
 *      gcc -o unittest1 -g  unittest1.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    printf("----------Unit Test 1: Testing gainCard() function----------\n\n");
    int i;
    int seed = 5;
    int numPlayers = 2;
    int supplyPos, toFlag, player;
    int returnValue;
    int changed, success;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState G, testG;

  /* -----------------------------------------------------------------------
   *     Test Case 1: Supply pile is empty
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 1: Supply pile is empty\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    supplyPos = gardens;
    testG.supplyCount[supplyPos] = 0;
    player = 0;
    toFlag = 0;
    
    returnValue = gainCard(supplyPos, &testG, toFlag, player); // this should return -1
    
    success = 1;
    printf("Test 1 - gainCard() correctly returns -1. Result: ");
    if (returnValue == -1) {
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
   *     Test Case 2: Card is not used in game
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 2: Card is not used in game\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    supplyPos = sea_hag; // set supply to a card not used in game
    player = 0;
    toFlag = 0;
    
    returnValue = gainCard(supplyPos, &testG, toFlag, player); // this should return -1
    
    success = 1;
    printf("Test 2 - gainCard() correctly returns -1. Result: ");
    if (returnValue == -1) {
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
   *     Test Case 3: Supply is available and player chooses to add to deck (toFlag is 1)
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 3: Supply is available and player chooses to add to deck (toFlag is 1)\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    memcpy(&G, &testG, sizeof(struct gameState)); // copy gameState
    supplyPos = mine;
    player = 0;
    toFlag = 1;

    returnValue = gainCard(supplyPos, &testG, toFlag, player); // this should return 0

    success = 1;
    // check deckCount of the player is incremented by 1
    printf("Test 3a - gainCard() correctly increments player's deckCount by 1. Result: ");
    if (testG.deckCount[player] == G.deckCount[player] + 1) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check supply stack is decremented by 1
    printf("Test 3b - gainCard() correctly decrements card's supplyCount by 1. Result: ");
    if (testG.supplyCount[supplyPos] == G.supplyCount[supplyPos] - 1) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check if player's deck gained the correct card
    printf("Test 3c - gainCard() adds correct card to player's deck. Result: ");
    if (testG.deck[player][G.deckCount[player]] == supplyPos) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // other players' deckCount not changed
    printf("Test 3d - gainCard() doesn't change other players' deckCounts. Result: ");
    changed = 0;
    for (i = 1; i < numPlayers; i++) {
      if (testG.deckCount[i] != G.deckCount[i]) {
        changed = 1;
      }
    }

    if (!changed) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check return value = 0
    printf("Test 3e - gainCard() correctly returns 0. Result: ");
    if (returnValue == 0) {
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
   *     Test Case 4: Supply is available and player chooses to add to hand (toFlag is 2)
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 4: Supply is available and player chooses to add to hand (toFlag is 2)\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    memcpy(&G, &testG, sizeof(struct gameState)); // copy gameState
    supplyPos = mine;
    player = 0;
    toFlag = 2;

    returnValue = gainCard(supplyPos, &testG, toFlag, player);  // this should return 0

    success = 1;
    // check deckCount of the player is incremented by 1
    printf("Test 4a - gainCard() correctly increments player's handCount by 1. Result: ");
    if (testG.handCount[player] == G.handCount[player] + 1) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check supply stack is decremented by 1
    printf("Test 4b - gainCard() correctly decrements card's supplyCount by 1. Result: ");
    if (testG.supplyCount[supplyPos] == G.supplyCount[supplyPos] - 1) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check if player's hand gained the correct card
    printf("Test 4c - gainCard() adds correct card to player's hand. Result: ");
    if (testG.hand[player][G.handCount[player]] == supplyPos) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // other players' handCount not changed
    printf("Test 4d - gainCard() doesn't change other players' handCount. Result: ");
    changed = 0;
    for (i = 1; i < numPlayers; i++) {
      if (testG.handCount[i] != G.handCount[i]) {
        changed = 1;
      }
    }

    if (!changed) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check return value = 0
    printf("Test 4e - gainCard() correctly returns 0. Result: ");
    if (returnValue == 0) {
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


  /* -----------------------------------------------------------------------
   *     Test Case 5: Supply is available and player chooses to add to discard (toFlag is 0)
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 5: Supply is available and player chooses to add to discard (toFlag is 0)\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    memcpy(&G, &testG, sizeof(struct gameState)); // copy gameState
    supplyPos = mine;
    player = 0;
    toFlag = 0;

    returnValue = gainCard(supplyPos, &testG, toFlag, player); // this should return 0

    success = 1;
    // check deckCount of the player is incremented by 1
    printf("Test 5a - gainCard() correctly increments player's discardCount by 1. Result: ");
    if (testG.discardCount[player] == G.discardCount[player] + 1) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check supply stack is decremented by 1
    printf("Test 5b - gainCard() correctly decrements card's supplyCount by 1. Result: ");
    if (testG.supplyCount[supplyPos] == G.supplyCount[supplyPos] - 1) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check if player's discard pile gained the correct card
    printf("Test 5c - gainCard() adds correct card to player's discard pile. Result: ");
    if (testG.discard[player][G.discardCount[player]] == supplyPos) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // other players' discardCount not changed
    printf("Test 5d - gainCard() doesn't change other players' discardCount. Result: ");
    changed = 0;
    for (i = 1; i < numPlayers; i++) {
      if (testG.discardCount[i] != G.discardCount[i]) {
        changed = 1;
      }
    }

    if (!changed) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // check return value = 0
    printf("Test 5e - gainCard() correctly returns 0. Result: ");
    if (returnValue == 0) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // Test case 5 result
    if (success) {
      printf("Test Case 5 COMPLETED SUCCESSFULLY! \n\n");
    } else {
      printf("Test Case 5 COMPLETED WITH ERROR(S)! \n\n");
    }

    printf("----------Unit Test 1: Testing gainCard() function COMPLETED----------\n\n");

    return 0;
}