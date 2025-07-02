#ifndef log_out_response_TEST
#define log_out_response_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define log_out_response_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/log_out_response.h"
log_out_response_t* instantiate_log_out_response(int include_optional);



log_out_response_t* instantiate_log_out_response(int include_optional) {
  log_out_response_t* log_out_response = NULL;
  if (include_optional) {
    log_out_response = log_out_response_create(
      1,
      1
    );
  } else {
    log_out_response = log_out_response_create(
      1,
      1
    );
  }

  return log_out_response;
}


#ifdef log_out_response_MAIN

void test_log_out_response(int include_optional) {
    log_out_response_t* log_out_response_1 = instantiate_log_out_response(include_optional);

	cJSON* jsonlog_out_response_1 = log_out_response_convertToJSON(log_out_response_1);
	printf("log_out_response :\n%s\n", cJSON_Print(jsonlog_out_response_1));
	log_out_response_t* log_out_response_2 = log_out_response_parseFromJSON(jsonlog_out_response_1);
	cJSON* jsonlog_out_response_2 = log_out_response_convertToJSON(log_out_response_2);
	printf("repeating log_out_response:\n%s\n", cJSON_Print(jsonlog_out_response_2));
}

int main() {
  test_log_out_response(1);
  test_log_out_response(0);

  printf("Hello world \n");
  return 0;
}

#endif // log_out_response_MAIN
#endif // log_out_response_TEST
