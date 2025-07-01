#ifndef mask_position_TEST
#define mask_position_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define mask_position_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/mask_position.h"
mask_position_t* instantiate_mask_position(int include_optional);



mask_position_t* instantiate_mask_position(int include_optional) {
  mask_position_t* mask_position = NULL;
  if (include_optional) {
    mask_position = mask_position_create(
      telegram_bot_api_mask_position_POINT_forehead,
      1.337,
      1.337,
      1.337
    );
  } else {
    mask_position = mask_position_create(
      telegram_bot_api_mask_position_POINT_forehead,
      1.337,
      1.337,
      1.337
    );
  }

  return mask_position;
}


#ifdef mask_position_MAIN

void test_mask_position(int include_optional) {
    mask_position_t* mask_position_1 = instantiate_mask_position(include_optional);

	cJSON* jsonmask_position_1 = mask_position_convertToJSON(mask_position_1);
	printf("mask_position :\n%s\n", cJSON_Print(jsonmask_position_1));
	mask_position_t* mask_position_2 = mask_position_parseFromJSON(jsonmask_position_1);
	cJSON* jsonmask_position_2 = mask_position_convertToJSON(mask_position_2);
	printf("repeating mask_position:\n%s\n", cJSON_Print(jsonmask_position_2));
}

int main() {
  test_mask_position(1);
  test_mask_position(0);

  printf("Hello world \n");
  return 0;
}

#endif // mask_position_MAIN
#endif // mask_position_TEST
