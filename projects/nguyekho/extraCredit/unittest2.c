/*
 * unittest2.c
 *
 * This file includes tests for function isGameOver()
 *
 * Include the following lines in your makefile:
 *
 * unittest2: unittest2.c dominion.o rngs.o
 *      gcc -o unittest2 -g  unittest2.c dominion.o rngs.o $(CFLAGS)
 */


#include "dominion.h"
#include "dominion_helpers.h"
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "rngs.h"

int main() {
    printf("----------Unit Test 2: Testing isGameOver() function----------\n\n");
    int seed = 5;
    int numPlayers = 2;
    int returnValue;
    int success;
    int k[10] = {adventurer, council_room, feast, gardens, mine
               , remodel, smithy, village, baron, great_hall};
    struct gameState testG;

  /* -----------------------------------------------------------------------
   *     Test Case 1: No supply stack is empty
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 1: No supply stack is empty\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);

    returnValue = isGameOver(&testG);

    success = 1;
    printf("Test 1 - isGameOver() correctly determines game is not over and returns 0. Result: ");
    if (returnValue == 0) {
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
   *     Test Case 2: Stack of Province cards is empty
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 2: Stack of Province cards is empty\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    testG.supplyCount[province] = 0; // make province stack empty

    returnValue = isGameOver(&testG);

    success = 1;
    printf("Test 2 - isGameOver() correctly determines game is over and returns 1. Result: ");
    if (returnValue == 1) {
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
   *     Test Case 3: Two stacks are empty, none is Province
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 3: Two stacks are empty, none is Province\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    testG.supplyCount[mine] = 0;
    testG.supplyCount[adventurer] = 0;
    returnValue = isGameOver(&testG);

    success = 1;
    printf("Test 3 - isGameOver() correctly determines game is not over and returns 0. Result: ");
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
   *     Test Case 4: Three stacks are empty, none is Province
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 4: Three stacks are empty, none is Province\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    testG.supplyCount[mine] = 0;
    testG.supplyCount[adventurer] = 0;
    testG.supplyCount[feast] = 0;
    
    returnValue = isGameOver(&testG);

    success = 1;
    printf("Test 4 - isGameOver() correctly determines game is over and returns 1. Result: ");
    if (returnValue == 1) {
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
   *     Test Case 5: Three stacks are empty, one is Province
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 5: Three stacks are empty, one is Province\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    testG.supplyCount[mine] = 0;
    testG.supplyCount[adventurer] = 0;
    testG.supplyCount[province] = 0;
    
    returnValue = isGameOver(&testG);

    success = 1;
    printf("Test 5 - isGameOver() correctly determines game is over and returns 1. Result: ");
    if (returnValue == 1) {
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

  /* -----------------------------------------------------------------------
   *     Test Case 6: Four stacks are empty (more than three non-Province stacks)
   * -----------------------------------------------------------------------
   */

    printf ("Test Case 6: Four (more than three non-Province) stacks are empty\n");
    memset(&testG, 23, sizeof(struct gameState)); // reset gameState
    initializeGame(numPlayers, k, seed, &testG);
    testG.supplyCount[mine] = 0;
    testG.supplyCount[adventurer] = 0;
    testG.supplyCount[feast] = 0;
    testG.supplyCount[baron] = 0;
    
    returnValue = isGameOver(&testG);

    success = 1;
    printf("Test 6 - isGameOver() correctly determines game is over and returns 1. Result: ");
    if (returnValue == 1) {
      printf("PASSED.\n");
    } else {
      printf("FAILED.\n");
      success = 0;
    }

    // Test case 6 result
    if (success) {
      printf("Test Case 6 COMPLETED SUCCESSFULLY! \n\n");
    } else {
      printf("Test Case 6 COMPLETED WITH ERROR(S)! \n\n");
    }

    printf("----------Unit Test 2: Testing isGameOver() function COMPLETED----------\n\n");

    return 0;
}