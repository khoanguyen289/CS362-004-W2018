/*
 * randomtestadventurer.c
 *
 * This file includes tests for card adventurer
 *
 * Include the following lines in your makefile:
 *
 * randomtestadventurer: randomtestadventurer.c dominion.o rngs.o
 *      gcc -o randomtestadventurer -g  randomtestadventurer.c dominion.o rngs.o $(CFLAGS)
 */

#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"
#include <time.h>
#include <stdlib.h>

int randomtestadventurer( int* test_1a_success, int* test_1a_failure,
                          int* test_1b_success, int* test_1b_failure,
                          int* test_1c_success, int* test_1c_failure,
                          int* test_1d_success, int* test_1d_failure,
                          int* test_1e_success, int* test_1e_failure,
                          int* test_1f_success, int* test_1f_failure,
                          int* test_1g_success, int* test_1g_failure,
                          int* test_2a_success, int* test_2a_failure,
                          int* test_2b_success, int* test_2b_failure,
                          int* test_2c_success, int* test_2c_failure,
                          int* test_2d_success, int* test_2d_failure,
                          int* test_2e_success, int* test_2e_failure,
                          int* test_2f_success, int* test_2f_failure,
                          int* test_2g_success, int* test_2g_failure,
                          int* tcase_1_success, int* tcase_1_failure,
                          int* tcase_2_success, int* tcase_2_failure);

int randBetween(int min, int max);

int main() {

  srand(time(NULL));

  int i;
  int num_tests = 100000;

  // to keep counts of success and failures
  int test_1a_success, test_1a_failure;
  int test_1b_success, test_1b_failure;
  int test_1c_success, test_1c_failure;
  int test_1d_success, test_1d_failure;
  int test_1e_success, test_1e_failure;
  int test_1f_success, test_1f_failure;
  int test_1g_success, test_1g_failure;
  int test_2a_success, test_2a_failure;
  int test_2b_success, test_2b_failure;
  int test_2c_success, test_2c_failure;
  int test_2d_success, test_2d_failure;
  int test_2e_success, test_2e_failure;
  int test_2f_success, test_2f_failure;
  int test_2g_success, test_2g_failure;
  int tcase_1_success, tcase_1_failure;
  int tcase_2_success, tcase_2_failure;

  test_1a_success = test_1a_failure = 0;
  test_1b_success = test_1b_failure = 0;
  test_1c_success = test_1c_failure = 0;
  test_1d_success = test_1d_failure = 0;
  test_1e_success = test_1e_failure = 0;
  test_1f_success = test_1f_failure = 0;
  test_1g_success = test_1g_failure = 0;
  test_2a_success = test_2a_failure = 0;
  test_2b_success = test_2b_failure = 0;
  test_2c_success = test_2c_failure = 0;
  test_2d_success = test_2d_failure = 0;
  test_2e_success = test_2e_failure = 0;
  test_2f_success = test_2f_failure = 0;
  test_2g_success = test_2g_failure = 0;
  tcase_1_success = tcase_1_failure = 0;
  tcase_2_success = tcase_2_failure = 0;

  printf("Random testing cardEffect for Adventurer card for %d iterations\n\n", num_tests);
  for (i = 0; i < num_tests; i++) {
    randomtestadventurer(&test_1a_success, &test_1a_failure, &test_1b_success, &test_1b_failure, &test_1c_success, &test_1c_failure, &test_1d_success, &test_1d_failure, &test_1e_success, &test_1e_failure, &test_1f_success, &test_1f_failure, &test_1g_success, &test_1g_failure, &test_2a_success, &test_2a_failure, &test_2b_success, &test_2b_failure, &test_2c_success, &test_2c_failure, &test_2d_success, &test_2d_failure, &test_2e_success, &test_2e_failure, &test_2f_success, &test_2f_failure, &test_2g_success, &test_2g_failure, &tcase_1_success, &tcase_1_failure, &tcase_2_success, &tcase_2_failure);
  }

  // results
  printf ("Test Case 1: Player has enough cards on deck\n");
  printf("Test 1a - cardEffect() correctly returns 0. Success: %d, Failure: %d\n", test_1a_success, test_1a_failure);
  printf("Test 1b - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded adventurer). Success: %d, Failure: %d\n", test_1b_success, test_1b_failure);
  printf("Test 1c - cardEffect() correctly places adventurer into the played pile. Success: %d, Failure: %d\n", test_1c_success, test_1c_failure);
  printf("Test 1d - cardEffect() correctly increases playedCardCount by 1. Success: %d, Failure: %d\n", test_1d_success, test_1d_failure);
  printf("Test 1e - cardEffect() correctly decreases player's deckCount by 2. Success: %d, Failure: %d\n", test_1e_success, test_1e_failure);
  printf("Test 1f - cardEffect() does not change other players' handCount and deckCount. Success: %d, Failure: %d\n", test_1f_success, test_1f_failure);
  printf("Test 1g - cardEffect() correctly gives player 2 treasures card in hand. Success: %d, Failure: %d\n", test_1g_success, test_1g_failure);
  printf("Test Case 1 COMPLETED! Success: %d, Failure: %d\n\n", tcase_1_success, tcase_1_failure);

  printf ("Test Case 2: Player does not have enough cards on deck\n");
  printf("Test 2a - cardEffect() correctly returns 0. Success: %d, Failure: %d\n", test_2a_success, test_2a_failure);
  printf("Test 2b - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded adventurer). Success: %d, Failure: %d\n", test_2b_success, test_2b_failure);
  printf("Test 2c - cardEffect() correctly places adventurer into the played pile. Success: %d, Failure: %d\n", test_2c_success, test_2c_failure);
  printf("Test 2d - cardEffect() correctly increases playedCardCount by 1. Success: %d, Failure: %d\n", test_2d_success, test_2d_failure);
  printf("Test 2e - cardEffect() correctly updates player's deckCount (equal old discardCount - 2). Success: %d, Failure: %d\n", test_2e_success, test_2e_failure);
  printf("Test 2f - cardEffect() does not change other players' handCount and deckCount. Success: %d, Failure: %d\n", test_2f_success, test_2f_failure);
  printf("Test 2g - cardEffect() correctly gives player 2 treasures card in hand. Success: %d, Failure: %d\n", test_2g_success, test_2g_failure);
  printf("Test Case 2 COMPLETED! Success: %d, Failure: %d\n\n", tcase_2_success, tcase_2_failure);

  return 0;
}

int randomtestadventurer( int* test_1a_success, int* test_1a_failure,
                          int* test_1b_success, int* test_1b_failure,
                          int* test_1c_success, int* test_1c_failure,
                          int* test_1d_success, int* test_1d_failure,
                          int* test_1e_success, int* test_1e_failure,
                          int* test_1f_success, int* test_1f_failure,
                          int* test_1g_success, int* test_1g_failure,
                          int* test_2a_success, int* test_2a_failure,
                          int* test_2b_success, int* test_2b_failure,
                          int* test_2c_success, int* test_2c_failure,
                          int* test_2d_success, int* test_2d_failure,
                          int* test_2e_success, int* test_2e_failure,
                          int* test_2f_success, int* test_2f_failure,
                          int* test_2g_success, int* test_2g_failure,
                          int* tcase_1_success, int* tcase_1_failure,
                          int* tcase_2_success, int* tcase_2_failure) {
    
    int i;
    int seed = randBetween(1, 20);
    int numPlayers = randBetween(2, MAX_PLAYERS);
    int player;
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
    
    // printf ("Test Case 1: Player has enough cards on deck\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    
    choice1 = 0;
    choice2 = 0;
    choice3 = 0;
    bonus = 0;
    player = randBetween(0, numPlayers - 1);
    testG.whoseTurn = player;
    handPos = randBetween(0, 5);
    
    // set card at handPos of the player to adventurer
    testG.hand[player][handPos] = adventurer;
    
    // reserve gameState for later comparision
    memcpy(&G, &testG, sizeof(struct gameState));
    
    returnValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0
    
    success = 1;
    // printf("Test 1a - cardEffect() correctly returns 0. Result: ");
    if (returnValue == 0) {
        // printf("PASSED.\n");
        (*test_1a_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_1a_failure)++;
        success = 0;
    }

    // printf("Test 1b - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded adventurer). Result: ");
    if (testG.handCount[player] == G.handCount[player] + 1) {
        // printf("PASSED.\n");
        (*test_1b_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_1b_failure)++;
        success = 0;
    }
    
    // printf("Test 1c - cardEffect() correctly places adventurer into the played pile. Result: ");
    if (testG.playedCards[G.playedCardCount] == adventurer) {
        // printf("PASSED.\n");
        (*test_1c_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_1c_failure)++;
        success = 0;
    }
    
    // printf("Test 1d - cardEffect() correctly increases playedCardCount by 1. Result: ");
    if (testG.playedCardCount == G.playedCardCount + 1) {
        // printf("PASSED.\n");
        (*test_1d_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_1d_failure)++;
        success = 0;
    }
    
    // printf("Test 1e - cardEffect() correctly decreases player's deckCount by 2. Result: ");
    if (testG.deckCount[player] == G.deckCount[player] - 2) {
        // printf("PASSED.\n");
        (*test_1e_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_1e_failure)++;
        success = 0;
    }
    
    // printf("Test 1f - cardEffect() does not change other players' handCount and deckCount. Result: ");
    changed = 0;
    
    for (i = 0; i < numPlayers && i != player; i++) {
        if (testG.handCount[i] != G.handCount[i] || testG.deckCount[i] != G.deckCount[i]) {
            changed = 1;
        }
    }
    if (!changed) {
        // printf("PASSED.\n");
        (*test_1f_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_1f_failure)++;
        success = 0;
    }
    
    // printf("Test 1g - cardEffect() correctly gives player 2 treasures card in hand. Result: ");
    
    cardDrawn1 = testG.hand[player][testG.handCount[player] - 2];
    cardDrawn2 = testG.hand[player][testG.handCount[player] - 1];
    if ((cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold) &&
        (cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold)) {
        // printf("PASSED.\n");
        (*test_1g_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_1g_failure)++;
        success = 0;
    }
    
    // Test case 1 result
    if (success) {
        // printf("Test Case 1 COMPLETED SUCCESSFULLY! \n\n");
        (*tcase_1_success)++;
    } else {
        // printf("Test Case 1 COMPLETED WITH ERROR(S)! \n\n");
        (*tcase_1_failure)++;
    }
    
    /* -----------------------------------------------------------------------
     *     Test Case 2: Player does not have enough cards on deck
     * -----------------------------------------------------------------------
     */
    
    // printf ("Test Case 2: Player does not have enough cards on deck\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    
    choice1 = 0;
    choice2 = 0;
    choice3 = 0;
    bonus = 0;
    player = randBetween(0, numPlayers - 1);
    testG.whoseTurn = player;
    handPos = randBetween(0, 5);
    
    // set card at handPos of the player to adventurer
    testG.hand[player][handPos] = adventurer;
    
    // discard all cards in deck
    for (i = 0; i < testG.deckCount[player]; i++) {
        testG.discard[player][i] = testG.deck[player][i];
        testG.deck[player][i] = -1;
    }
    testG.discardCount[player] = testG.deckCount[player];
    testG.deckCount[player] = 0;
    
    // reserve gameState for later comparision
    memcpy(&G, &testG, sizeof(struct gameState));
    
    returnValue = cardEffect(adventurer, choice1, choice2, choice3, &testG, handPos, &bonus); // this should return 0
    
    success = 1;
    // printf("Test 2a - cardEffect() correctly returns 0. Result: ");
    if (returnValue == 0) {
        // printf("PASSED.\n");
        (*test_2a_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_2a_failure)++;
        success = 0;
    }
    
    // printf("Test 2b - cardEffect() correctly increases handCount of the player by 1 (drawn 2 cards and discarded adventurer). Result: ");
    if (testG.handCount[player] == G.handCount[player] + 1) {
        // printf("PASSED.\n");
        (*test_2b_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_2b_failure)++;
        success = 0;
    }
    
    // printf("Test 2c - cardEffect() correctly places adventurer into the played pile. Result: ");
    if (testG.playedCards[G.playedCardCount] == adventurer) {
        // printf("PASSED.\n");
        (*test_2c_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_2c_failure)++;
        success = 0;
    }
    
    // printf("Test 2d - cardEffect() correctly increases playedCardCount by 1. Result: ");
    if (testG.playedCardCount == G.playedCardCount + 1) {
        // printf("PASSED.\n");
        (*test_2d_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_2d_failure)++;
        success = 0;
    }
    
    // printf("Test 2e - cardEffect() correctly updates player's deckCount (equal old discardCount - 2). Result: ");
    if (testG.deckCount[player] == G.discardCount[player] - 2) {
        // printf("PASSED.\n");
        (*test_2e_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_2e_failure)++;
        success = 0;
    }
    
    // printf("Test 2f - cardEffect() does not change other players' handCount and deckCount. Result: ");
    changed = 0;
    
    for (i = 0; i < numPlayers && i != player; i++) {
        if (testG.handCount[i] != G.handCount[i] || testG.deckCount[i] != G.deckCount[i]) {
            changed = 1;
        }
    }
    if (!changed) {
        // printf("PASSED.\n");
        (*test_2f_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_2f_failure)++;
        success = 0;
    }
    
    // printf("Test 2g - cardEffect() correctly gives player 2 treasures card in hand. Result: ");
    
    cardDrawn1 = testG.hand[player][testG.handCount[player] - 2];
    cardDrawn2 = testG.hand[player][testG.handCount[player] - 1];
    if ((cardDrawn1 == copper || cardDrawn1 == silver || cardDrawn1 == gold) &&
        (cardDrawn2 == copper || cardDrawn2 == silver || cardDrawn2 == gold)) {
        // printf("PASSED.\n");
        (*test_2g_success)++;
    } else {
        // printf("FAILED.\n");
        (*test_2g_failure)++;
        success = 0;
    }
    
    // Test case 2 result
    if (success) {
        // printf("Test Case 2 COMPLETED SUCCESSFULLY! \n\n");
        (*tcase_2_success)++;
    } else {
        // printf("Test Case 2 COMPLETED WITH ERROR(S)! \n\n");
        (*tcase_2_failure)++;
    }
    
    // printf("----------Card Test 2: Testing adventurer card effect COMPLETED----------\n\n");
    
    return 0;
}

int randBetween(int min, int max) {
  return rand() % (max - min + 1) + min;
}