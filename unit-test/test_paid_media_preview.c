#ifndef paid_media_preview_TEST
#define paid_media_preview_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paid_media_preview_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paid_media_preview.h"
paid_media_preview_t* instantiate_paid_media_preview(int include_optional);



paid_media_preview_t* instantiate_paid_media_preview(int include_optional) {
  paid_media_preview_t* paid_media_preview = NULL;
  if (include_optional) {
    paid_media_preview = paid_media_preview_create(
      "preview",
      56,
      56,
      56
    );
  } else {
    paid_media_preview = paid_media_preview_create(
      "preview",
      56,
      56,
      56
    );
  }

  return paid_media_preview;
}


#ifdef paid_media_preview_MAIN

void test_paid_media_preview(int include_optional) {
    paid_media_preview_t* paid_media_preview_1 = instantiate_paid_media_preview(include_optional);

	cJSON* jsonpaid_media_preview_1 = paid_media_preview_convertToJSON(paid_media_preview_1);
	printf("paid_media_preview :\n%s\n", cJSON_Print(jsonpaid_media_preview_1));
	paid_media_preview_t* paid_media_preview_2 = paid_media_preview_parseFromJSON(jsonpaid_media_preview_1);
	cJSON* jsonpaid_media_preview_2 = paid_media_preview_convertToJSON(paid_media_preview_2);
	printf("repeating paid_media_preview:\n%s\n", cJSON_Print(jsonpaid_media_preview_2));
}

int main() {
  test_paid_media_preview(1);
  test_paid_media_preview(0);

  printf("Hello world \n");
  return 0;
}

#endif // paid_media_preview_MAIN
#endif // paid_media_preview_TEST
