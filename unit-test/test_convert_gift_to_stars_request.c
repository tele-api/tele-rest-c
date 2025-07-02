#ifndef convert_gift_to_stars_request_TEST
#define convert_gift_to_stars_request_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define convert_gift_to_stars_request_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/convert_gift_to_stars_request.h"
convert_gift_to_stars_request_t* instantiate_convert_gift_to_stars_request(int include_optional);



convert_gift_to_stars_request_t* instantiate_convert_gift_to_stars_request(int include_optional) {
  convert_gift_to_stars_request_t* convert_gift_to_stars_request = NULL;
  if (include_optional) {
    convert_gift_to_stars_request = convert_gift_to_stars_request_create(
      "0",
      "0"
    );
  } else {
    convert_gift_to_stars_request = convert_gift_to_stars_request_create(
      "0",
      "0"
    );
  }

  return convert_gift_to_stars_request;
}


#ifdef convert_gift_to_stars_request_MAIN

void test_convert_gift_to_stars_request(int include_optional) {
    convert_gift_to_stars_request_t* convert_gift_to_stars_request_1 = instantiate_convert_gift_to_stars_request(include_optional);

	cJSON* jsonconvert_gift_to_stars_request_1 = convert_gift_to_stars_request_convertToJSON(convert_gift_to_stars_request_1);
	printf("convert_gift_to_stars_request :\n%s\n", cJSON_Print(jsonconvert_gift_to_stars_request_1));
	convert_gift_to_stars_request_t* convert_gift_to_stars_request_2 = convert_gift_to_stars_request_parseFromJSON(jsonconvert_gift_to_stars_request_1);
	cJSON* jsonconvert_gift_to_stars_request_2 = convert_gift_to_stars_request_convertToJSON(convert_gift_to_stars_request_2);
	printf("repeating convert_gift_to_stars_request:\n%s\n", cJSON_Print(jsonconvert_gift_to_stars_request_2));
}

int main() {
  test_convert_gift_to_stars_request(1);
  test_convert_gift_to_stars_request(0);

  printf("Hello world \n");
  return 0;
}

#endif // convert_gift_to_stars_request_MAIN
#endif // convert_gift_to_stars_request_TEST
