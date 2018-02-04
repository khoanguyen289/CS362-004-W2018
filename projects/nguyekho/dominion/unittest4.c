/*
 * unittest4.c
 *
 * This file includes tests for function getCost()
 *
 * Include the following lines in your makefile:
 *
 * unittest4: unittest4.c dominion.o rngs.o
 *      gcc -o unittest4 -g  unittest4.c dominion.o rngs.o $(CFLAGS)
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
  printf("----------Unit Test 4: Testing getCost() function----------\n\n");
  int what_is_this = rand() % 30 + 30; // get an int that is out of range of the CARD enum
  int manualCost, result;
  int success;

  /* -----------------------------------------------------------------------
   *     Test Case 1: getCost() correctly returns -1 for unknown cards
   * -----------------------------------------------------------------------
   */

  success = 1;
  printf ("Test Case 1: getCost() correctly returns -1 for unknown cards\n");
  manualCost = -1;
  result = getCost(what_is_this);

  printf("Test 1 - getCost() correctly returns -1. ");
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
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
   *     Test Case 2: getCost() correctly returns cost of known cards
   * -----------------------------------------------------------------------
   */

  result = 1;
  printf ("Test Case 2: getCost() correctly returns cost of known cards\n");

  printf("Test 2 - getCost() correctly returns cost of curse. ");
  manualCost = 0;
  result = getCost(curse);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of estate. ");
  manualCost = 2;
  result = getCost(estate);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of duchy. ");
  manualCost = 5;
  result = getCost(duchy);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of province. ");
  manualCost = 8;
  result = getCost(province);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of copper. ");
  manualCost = 0;
  result = getCost(copper);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of silver. ");
  manualCost = 3;
  result = getCost(silver);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of gold. ");
  manualCost = 6;
  result = getCost(gold);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of adventurer. ");
  manualCost = 6;
  result = getCost(adventurer);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of council_room. ");
  manualCost = 5;
  result = getCost(council_room);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of feast. ");
  manualCost = 4;
  result = getCost(feast);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of gardens. ");
  manualCost = 4;
  result = getCost(gardens);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of mine. ");
  manualCost = 5;
  result = getCost(mine);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of remodel. ");
  manualCost = 4;
  result = getCost(remodel);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of smithy. ");
  manualCost = 4;
  result = getCost(smithy);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of village. ");
  manualCost = 3;
  result = getCost(village);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of baron. ");
  manualCost = 4;
  result = getCost(baron);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of great_hall. ");
  manualCost = 3;
  result = getCost(great_hall);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of minion. ");
  manualCost = 5;
  result = getCost(minion);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of steward. ");
  manualCost = 3;
  result = getCost(steward);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of tribute. ");
  manualCost = 5;
  result = getCost(tribute);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of ambassador. ");
  manualCost = 3;
  result = getCost(ambassador);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of cutpurse. ");
  manualCost = 4;
  result = getCost(cutpurse);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of embargo. ");
  manualCost = 2;
  result = getCost(embargo);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of outpost. ");
  manualCost = 5;
  result = getCost(outpost);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of salvager. ");
  manualCost = 4;
  result = getCost(salvager);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of sea_hag. ");
  manualCost = 4;
  result = getCost(sea_hag);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
    printf("PASSED.\n");
  } else {
    printf("FAILED.\n");
    success = 0;
  }

  printf("Test 2 - getCost() correctly returns cost of treasure_map. ");
  manualCost = 4;
  result = getCost(treasure_map);
  printf("Expected: %d - Actual: %d.", manualCost, result);
  printf(" Result: ");
  if (result == manualCost) {
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

  printf("----------Unit Test 4: Testing getCost() function COMPLETED----------\n\n");

  return 0;
}