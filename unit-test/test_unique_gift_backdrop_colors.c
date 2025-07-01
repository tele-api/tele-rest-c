#ifndef unique_gift_backdrop_colors_TEST
#define unique_gift_backdrop_colors_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define unique_gift_backdrop_colors_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/unique_gift_backdrop_colors.h"
unique_gift_backdrop_colors_t* instantiate_unique_gift_backdrop_colors(int include_optional);



unique_gift_backdrop_colors_t* instantiate_unique_gift_backdrop_colors(int include_optional) {
  unique_gift_backdrop_colors_t* unique_gift_backdrop_colors = NULL;
  if (include_optional) {
    unique_gift_backdrop_colors = unique_gift_backdrop_colors_create(
      56,
      56,
      56,
      56
    );
  } else {
    unique_gift_backdrop_colors = unique_gift_backdrop_colors_create(
      56,
      56,
      56,
      56
    );
  }

  return unique_gift_backdrop_colors;
}


#ifdef unique_gift_backdrop_colors_MAIN

void test_unique_gift_backdrop_colors(int include_optional) {
    unique_gift_backdrop_colors_t* unique_gift_backdrop_colors_1 = instantiate_unique_gift_backdrop_colors(include_optional);

	cJSON* jsonunique_gift_backdrop_colors_1 = unique_gift_backdrop_colors_convertToJSON(unique_gift_backdrop_colors_1);
	printf("unique_gift_backdrop_colors :\n%s\n", cJSON_Print(jsonunique_gift_backdrop_colors_1));
	unique_gift_backdrop_colors_t* unique_gift_backdrop_colors_2 = unique_gift_backdrop_colors_parseFromJSON(jsonunique_gift_backdrop_colors_1);
	cJSON* jsonunique_gift_backdrop_colors_2 = unique_gift_backdrop_colors_convertToJSON(unique_gift_backdrop_colors_2);
	printf("repeating unique_gift_backdrop_colors:\n%s\n", cJSON_Print(jsonunique_gift_backdrop_colors_2));
}

int main() {
  test_unique_gift_backdrop_colors(1);
  test_unique_gift_backdrop_colors(0);

  printf("Hello world \n");
  return 0;
}

#endif // unique_gift_backdrop_colors_MAIN
#endif // unique_gift_backdrop_colors_TEST
