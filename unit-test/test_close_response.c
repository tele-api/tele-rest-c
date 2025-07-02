#ifndef close_response_TEST
#define close_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define close_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/close_response.h"
close_response_t* instantiate_close_response(int include_optional);



close_response_t* instantiate_close_response(int include_optional) {
  close_response_t* close_response = NULL;
  if (include_optional) {
    close_response = close_response_create(
      1,
      1
    );
  } else {
    close_response = close_response_create(
      1,
      1
    );
  }

  return close_response;
}


#ifdef close_response_MAIN

void test_close_response(int include_optional) {
    close_response_t* close_response_1 = instantiate_close_response(include_optional);

	cJSON* jsonclose_response_1 = close_response_convertToJSON(close_response_1);
	printf("close_response :\n%s\n", cJSON_Print(jsonclose_response_1));
	close_response_t* close_response_2 = close_response_parseFromJSON(jsonclose_response_1);
	cJSON* jsonclose_response_2 = close_response_convertToJSON(close_response_2);
	printf("repeating close_response:\n%s\n", cJSON_Print(jsonclose_response_2));
}

int main() {
  test_close_response(1);
  test_close_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // close_response_MAIN
#endif // close_response_TEST
