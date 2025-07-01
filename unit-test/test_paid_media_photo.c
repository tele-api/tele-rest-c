#ifndef paid_media_photo_TEST
#define paid_media_photo_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paid_media_photo_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paid_media_photo.h"
paid_media_photo_t* instantiate_paid_media_photo(int include_optional);



paid_media_photo_t* instantiate_paid_media_photo(int include_optional) {
  paid_media_photo_t* paid_media_photo = NULL;
  if (include_optional) {
    paid_media_photo = paid_media_photo_create(
      "photo",
      list_createList()
    );
  } else {
    paid_media_photo = paid_media_photo_create(
      "photo",
      list_createList()
    );
  }

  return paid_media_photo;
}


#ifdef paid_media_photo_MAIN

void test_paid_media_photo(int include_optional) {
    paid_media_photo_t* paid_media_photo_1 = instantiate_paid_media_photo(include_optional);

	cJSON* jsonpaid_media_photo_1 = paid_media_photo_convertToJSON(paid_media_photo_1);
	printf("paid_media_photo :\n%s\n", cJSON_Print(jsonpaid_media_photo_1));
	paid_media_photo_t* paid_media_photo_2 = paid_media_photo_parseFromJSON(jsonpaid_media_photo_1);
	cJSON* jsonpaid_media_photo_2 = paid_media_photo_convertToJSON(paid_media_photo_2);
	printf("repeating paid_media_photo:\n%s\n", cJSON_Print(jsonpaid_media_photo_2));
}

int main() {
  test_paid_media_photo(1);
  test_paid_media_photo(0);

  printf("Hello world \n");
  return 0;
}

#endif // paid_media_photo_MAIN
#endif // paid_media_photo_TEST
