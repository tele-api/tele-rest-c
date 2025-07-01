#ifndef unique_gift_model_TEST
#define unique_gift_model_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unique_gift_model_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unique_gift_model.h"
unique_gift_model_t* instantiate_unique_gift_model(int include_optional);

#include "test_sticker.c"


unique_gift_model_t* instantiate_unique_gift_model(int include_optional) {
  unique_gift_model_t* unique_gift_model = NULL;
  if (include_optional) {
    unique_gift_model = unique_gift_model_create(
      "0",
       // false, not to have infinite recursion
      instantiate_sticker(0),
      56
    );
  } else {
    unique_gift_model = unique_gift_model_create(
      "0",
      NULL,
      56
    );
  }

  return unique_gift_model;
}


#ifdef unique_gift_model_MAIN

void test_unique_gift_model(int include_optional) {
    unique_gift_model_t* unique_gift_model_1 = instantiate_unique_gift_model(include_optional);

	cJSON* jsonunique_gift_model_1 = unique_gift_model_convertToJSON(unique_gift_model_1);
	printf("unique_gift_model :\n%s\n", cJSON_Print(jsonunique_gift_model_1));
	unique_gift_model_t* unique_gift_model_2 = unique_gift_model_parseFromJSON(jsonunique_gift_model_1);
	cJSON* jsonunique_gift_model_2 = unique_gift_model_convertToJSON(unique_gift_model_2);
	printf("repeating unique_gift_model:\n%s\n", cJSON_Print(jsonunique_gift_model_2));
}

int main() {
  test_unique_gift_model(1);
  test_unique_gift_model(0);

  printf("Hello world \n");
  return 0;
}

#endif // unique_gift_model_MAIN
#endif // unique_gift_model_TEST
