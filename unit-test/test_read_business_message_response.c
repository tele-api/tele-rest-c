#ifndef read_business_message_response_TEST
#define read_business_message_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define read_business_message_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/read_business_message_response.h"
read_business_message_response_t* instantiate_read_business_message_response(int include_optional);



read_business_message_response_t* instantiate_read_business_message_response(int include_optional) {
  read_business_message_response_t* read_business_message_response = NULL;
  if (include_optional) {
    read_business_message_response = read_business_message_response_create(
      1,
      1
    );
  } else {
    read_business_message_response = read_business_message_response_create(
      1,
      1
    );
  }

  return read_business_message_response;
}


#ifdef read_business_message_response_MAIN

void test_read_business_message_response(int include_optional) {
    read_business_message_response_t* read_business_message_response_1 = instantiate_read_business_message_response(include_optional);

	cJSON* jsonread_business_message_response_1 = read_business_message_response_convertToJSON(read_business_message_response_1);
	printf("read_business_message_response :\n%s\n", cJSON_Print(jsonread_business_message_response_1));
	read_business_message_response_t* read_business_message_response_2 = read_business_message_response_parseFromJSON(jsonread_business_message_response_1);
	cJSON* jsonread_business_message_response_2 = read_business_message_response_convertToJSON(read_business_message_response_2);
	printf("repeating read_business_message_response:\n%s\n", cJSON_Print(jsonread_business_message_response_2));
}

int main() {
  test_read_business_message_response(1);
  test_read_business_message_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // read_business_message_response_MAIN
#endif // read_business_message_response_TEST
