#ifndef link_preview_options_TEST
#define link_preview_options_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define link_preview_options_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/link_preview_options.h"
link_preview_options_t* instantiate_link_preview_options(int include_optional);



link_preview_options_t* instantiate_link_preview_options(int include_optional) {
  link_preview_options_t* link_preview_options = NULL;
  if (include_optional) {
    link_preview_options = link_preview_options_create(
      1,
      "0",
      1,
      1,
      1
    );
  } else {
    link_preview_options = link_preview_options_create(
      1,
      "0",
      1,
      1,
      1
    );
  }

  return link_preview_options;
}


#ifdef link_preview_options_MAIN

void test_link_preview_options(int include_optional) {
    link_preview_options_t* link_preview_options_1 = instantiate_link_preview_options(include_optional);

	cJSON* jsonlink_preview_options_1 = link_preview_options_convertToJSON(link_preview_options_1);
	printf("link_preview_options :\n%s\n", cJSON_Print(jsonlink_preview_options_1));
	link_preview_options_t* link_preview_options_2 = link_preview_options_parseFromJSON(jsonlink_preview_options_1);
	cJSON* jsonlink_preview_options_2 = link_preview_options_convertToJSON(link_preview_options_2);
	printf("repeating link_preview_options:\n%s\n", cJSON_Print(jsonlink_preview_options_2));
}

int main() {
  test_link_preview_options(1);
  test_link_preview_options(0);

  printf("Hello world \n");
  return 0;
}

#endif // link_preview_options_MAIN
#endif // link_preview_options_TEST
