#ifndef labeled_price_TEST
#define labeled_price_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define labeled_price_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/labeled_price.h"
labeled_price_t* instantiate_labeled_price(int include_optional);



labeled_price_t* instantiate_labeled_price(int include_optional) {
  labeled_price_t* labeled_price = NULL;
  if (include_optional) {
    labeled_price = labeled_price_create(
      "0",
      56
    );
  } else {
    labeled_price = labeled_price_create(
      "0",
      56
    );
  }

  return labeled_price;
}


#ifdef labeled_price_MAIN

void test_labeled_price(int include_optional) {
    labeled_price_t* labeled_price_1 = instantiate_labeled_price(include_optional);

	cJSON* jsonlabeled_price_1 = labeled_price_convertToJSON(labeled_price_1);
	printf("labeled_price :\n%s\n", cJSON_Print(jsonlabeled_price_1));
	labeled_price_t* labeled_price_2 = labeled_price_parseFromJSON(jsonlabeled_price_1);
	cJSON* jsonlabeled_price_2 = labeled_price_convertToJSON(labeled_price_2);
	printf("repeating labeled_price:\n%s\n", cJSON_Print(jsonlabeled_price_2));
}

int main() {
  test_labeled_price(1);
  test_labeled_price(0);

  printf("Hello world \n");
  return 0;
}

#endif // labeled_price_MAIN
#endif // labeled_price_TEST
