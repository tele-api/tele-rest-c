#ifndef dice_TEST
#define dice_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define dice_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/dice.h"
dice_t* instantiate_dice(int include_optional);



dice_t* instantiate_dice(int include_optional) {
  dice_t* dice = NULL;
  if (include_optional) {
    dice = dice_create(
      "0",
      56
    );
  } else {
    dice = dice_create(
      "0",
      56
    );
  }

  return dice;
}


#ifdef dice_MAIN

void test_dice(int include_optional) {
    dice_t* dice_1 = instantiate_dice(include_optional);

	cJSON* jsondice_1 = dice_convertToJSON(dice_1);
	printf("dice :\n%s\n", cJSON_Print(jsondice_1));
	dice_t* dice_2 = dice_parseFromJSON(jsondice_1);
	cJSON* jsondice_2 = dice_convertToJSON(dice_2);
	printf("repeating dice:\n%s\n", cJSON_Print(jsondice_2));
}

int main() {
  test_dice(1);
  test_dice(0);

  printf("Hello world \n");
  return 0;
}

#endif // dice_MAIN
#endif // dice_TEST
