/*
 * unittest3.c
 *
 * This file includes tests for function fullDeckCount()
 *
 * Include the following lines in your makefile:
 *
 * unittest3: unittest3.c dominion.o rngs.o
 *      gcc -o unittest3 -g  unittest3.c dominion.o rngs.o $(CFLAGS)
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
  printf("----------Unit Test 3: Testing fullDeckCount() function----------\n\n");
  int i, j;
  int numTests = 10;
  int seed = 5;
  int numPlayers = 2;
  int player = 0;
  int newHandCount, newDeckCount, newDiscardCount;
  int manualSum, result;
  int success;
  int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall
              };
  struct gameState testG;

  /* -----------------------------------------------------------------------
   *     Test Case 1: Counting Smithy when all cards on hand, deck, and discard are Smithy
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 1: Counting Smithy when all cards on hand, deck, and discard are Smithy\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  success = 1;

  for (j = 0; j < numTests; j++) {
    // randomize new counts for smithy
    newHandCount = rand() % 100;//(MAX_HAND / 2);
    newDeckCount = rand() % 100;//(MAX_DECK / 2);
    newDiscardCount = rand() % 100;//(MAX_DECK / 2);
    manualSum = newHandCount + newDeckCount + newDiscardCount;

    //manually set counts to gameState
    // set all cards on hand to baron
    memset(testG.hand[player], baron, sizeof(testG.hand[player]));

    // place newHandCount of smithy cards on hand
    for (i = 0; i < newHandCount; i++) {
      testG.hand[player][i] = smithy;
    }

    // set new handCount of gameState
    testG.handCount[player] = newHandCount;

    // set all cards on deck to baron
    memset(testG.deck[player], baron, sizeof(testG.deck[player]));

    // place newDeckCount of smithy cards on hand
    for (i = 0; i < newDeckCount; i++) {
      testG.deck[player][i] = smithy;
    }

    // set new deckCount of gameState
    testG.deckCount[player] = newDeckCount;

    // set all cards on deck to baron
    memset(testG.discard[player], baron, sizeof(testG.discard[player]));

    // place newDiscardCount of smithy cards on hand
    for (i = 0; i < newDiscardCount; i++) {
      testG.discard[player][i] = smithy;
    }

    // set new discardCount of gameState
    testG.discardCount[player] = newDiscardCount;

    result = fullDeckCount(player, smithy, &testG);
    printf("Test 1 - fullDeckCount() correctly counts Smithy cards for the whole deck. ");
    printf("Expected: %d - Actual: %d.", manualSum, result);
    printf(" Result: ");
    if (result == manualSum) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }
  }

  // Test case 1 result
  if (success) {
    printf("Test Case 1 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 1 COMPLETED WITH ERROR(S)! \n\n");
  }

  /* -----------------------------------------------------------------------
   *     Test Case 2: Counting Smithy when there are other cards on hand, deck, and discard
   * -----------------------------------------------------------------------
   */

  printf ("Test Case 2: Counting Baron when there are other cards on hand, deck, and discard\n");
  memset(&testG, 23, sizeof(struct gameState)); // reset gameState
  initializeGame(numPlayers, k, seed, &testG);

  success = 1;

  for (j = 0; j < numTests; j++) {
    // randomize new counts for smithy
    newHandCount = rand() % 400;//(MAX_HAND / 2);
    newDeckCount = rand() % 400;//(MAX_DECK / 2);
    newDiscardCount = rand() % 400;//(MAX_DECK / 2);
    manualSum = newHandCount + newDeckCount + newDiscardCount;

    //manually set counts to gameState
    // set all cards on hand to feast
    memset(testG.hand[player], feast, sizeof(testG.hand[player]));

    // place newHandCount of baron cards on hand
    for (i = 0; i < newHandCount; i++) {
      testG.hand[player][i] = baron;
    }

    // set new handCount of gameState
    testG.handCount[player] = MAX_HAND;

    // set all cards on deck to feast
    memset(testG.deck[player], feast, sizeof(testG.deck[player]));

    // place newDeckCount of baron cards on hand
    for (i = 0; i < newDeckCount; i++) {
      testG.deck[player][i] = baron;
    }

    // set new deckCount of gameState
    testG.deckCount[player] = MAX_DECK;

    // set all cards on discard to feast
    memset(testG.discard[player], feast, sizeof(testG.discard[player]));

    // place newDiscardCount of baron cards on hand
    for (i = 0; i < newDiscardCount; i++) {
      testG.discard[player][i] = baron;
    }

    // set new discardCount of gameState
    testG.discardCount[player] = MAX_DECK;

    result = fullDeckCount(player, baron, &testG);
    printf("Test 2 - fullDeckCount() correctly counts Baron cards for the whole deck. ");
    printf("Expected: %d - Actual: %d.", manualSum, result);
    printf(" Result: ");
    if (result == manualSum) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }
  }

  // Test case 2 result
  if (success) {
    printf("Test Case 2 COMPLETED SUCCESSFULLY! \n\n");
  } else {
    printf("Test Case 2 COMPLETED WITH ERROR(S)! \n\n");
  }

  printf("----------Unit Test 3: Testing fullDeckCount() function COMPLETED----------\n\n");

  return 0;
}