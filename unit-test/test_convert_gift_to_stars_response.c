#ifndef convert_gift_to_stars_response_TEST
#define convert_gift_to_stars_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define convert_gift_to_stars_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/convert_gift_to_stars_response.h"
convert_gift_to_stars_response_t* instantiate_convert_gift_to_stars_response(int include_optional);



convert_gift_to_stars_response_t* instantiate_convert_gift_to_stars_response(int include_optional) {
  convert_gift_to_stars_response_t* convert_gift_to_stars_response = NULL;
  if (include_optional) {
    convert_gift_to_stars_response = convert_gift_to_stars_response_create(
      1,
      1
    );
  } else {
    convert_gift_to_stars_response = convert_gift_to_stars_response_create(
      1,
      1
    );
  }

  return convert_gift_to_stars_response;
}


#ifdef convert_gift_to_stars_response_MAIN

void test_convert_gift_to_stars_response(int include_optional) {
    convert_gift_to_stars_response_t* convert_gift_to_stars_response_1 = instantiate_convert_gift_to_stars_response(include_optional);

	cJSON* jsonconvert_gift_to_stars_response_1 = convert_gift_to_stars_response_convertToJSON(convert_gift_to_stars_response_1);
	printf("convert_gift_to_stars_response :\n%s\n", cJSON_Print(jsonconvert_gift_to_stars_response_1));
	convert_gift_to_stars_response_t* convert_gift_to_stars_response_2 = convert_gift_to_stars_response_parseFromJSON(jsonconvert_gift_to_stars_response_1);
	cJSON* jsonconvert_gift_to_stars_response_2 = convert_gift_to_stars_response_convertToJSON(convert_gift_to_stars_response_2);
	printf("repeating convert_gift_to_stars_response:\n%s\n", cJSON_Print(jsonconvert_gift_to_stars_response_2));
}

int main() {
  test_convert_gift_to_stars_response(1);
  test_convert_gift_to_stars_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // convert_gift_to_stars_response_MAIN
#endif // convert_gift_to_stars_response_TEST
