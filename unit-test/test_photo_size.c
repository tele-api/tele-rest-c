#ifndef photo_size_TEST
#define photo_size_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define photo_size_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/photo_size.h"
photo_size_t* instantiate_photo_size(int include_optional);



photo_size_t* instantiate_photo_size(int include_optional) {
  photo_size_t* photo_size = NULL;
  if (include_optional) {
    photo_size = photo_size_create(
      "0",
      "0",
      56,
      56,
      56
    );
  } else {
    photo_size = photo_size_create(
      "0",
      "0",
      56,
      56,
      56
    );
  }

  return photo_size;
}


#ifdef photo_size_MAIN

void test_photo_size(int include_optional) {
    photo_size_t* photo_size_1 = instantiate_photo_size(include_optional);

	cJSON* jsonphoto_size_1 = photo_size_convertToJSON(photo_size_1);
	printf("photo_size :\n%s\n", cJSON_Print(jsonphoto_size_1));
	photo_size_t* photo_size_2 = photo_size_parseFromJSON(jsonphoto_size_1);
	cJSON* jsonphoto_size_2 = photo_size_convertToJSON(photo_size_2);
	printf("repeating photo_size:\n%s\n", cJSON_Print(jsonphoto_size_2));
}

int main() {
  test_photo_size(1);
  test_photo_size(0);

  printf("Hello world \n");
  return 0;
}

#endif // photo_size_MAIN
#endif // photo_size_TEST
