#ifndef paid_media_TEST
#define paid_media_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paid_media_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paid_media.h"
paid_media_t* instantiate_paid_media(int include_optional);

#include "test_video.c"


paid_media_t* instantiate_paid_media(int include_optional) {
  paid_media_t* paid_media = NULL;
  if (include_optional) {
    paid_media = paid_media_create(
      "video",
      list_createList(),
       // false, not to have infinite recursion
      instantiate_video(0),
      56,
      56,
      56
    );
  } else {
    paid_media = paid_media_create(
      "video",
      list_createList(),
      NULL,
      56,
      56,
      56
    );
  }

  return paid_media;
}


#ifdef paid_media_MAIN

void test_paid_media(int include_optional) {
    paid_media_t* paid_media_1 = instantiate_paid_media(include_optional);

	cJSON* jsonpaid_media_1 = paid_media_convertToJSON(paid_media_1);
	printf("paid_media :\n%s\n", cJSON_Print(jsonpaid_media_1));
	paid_media_t* paid_media_2 = paid_media_parseFromJSON(jsonpaid_media_1);
	cJSON* jsonpaid_media_2 = paid_media_convertToJSON(paid_media_2);
	printf("repeating paid_media:\n%s\n", cJSON_Print(jsonpaid_media_2));
}

int main() {
  test_paid_media(1);
  test_paid_media(0);

  printf("Hello world \n");
  return 0;
}

#endif // paid_media_MAIN
#endif // paid_media_TEST
