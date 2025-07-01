#ifndef response_parameters_TEST
#define response_parameters_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define response_parameters_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/response_parameters.h"
response_parameters_t* instantiate_response_parameters(int include_optional);



response_parameters_t* instantiate_response_parameters(int include_optional) {
  response_parameters_t* response_parameters = NULL;
  if (include_optional) {
    response_parameters = response_parameters_create(
      56,
      56
    );
  } else {
    response_parameters = response_parameters_create(
      56,
      56
    );
  }

  return response_parameters;
}


#ifdef response_parameters_MAIN

void test_response_parameters(int include_optional) {
    response_parameters_t* response_parameters_1 = instantiate_response_parameters(include_optional);

	cJSON* jsonresponse_parameters_1 = response_parameters_convertToJSON(response_parameters_1);
	printf("response_parameters :\n%s\n", cJSON_Print(jsonresponse_parameters_1));
	response_parameters_t* response_parameters_2 = response_parameters_parseFromJSON(jsonresponse_parameters_1);
	cJSON* jsonresponse_parameters_2 = response_parameters_convertToJSON(response_parameters_2);
	printf("repeating response_parameters:\n%s\n", cJSON_Print(jsonresponse_parameters_2));
}

int main() {
  test_response_parameters(1);
  test_response_parameters(0);

  printf("Hello world \n");
  return 0;
}

#endif // response_parameters_MAIN
#endif // response_parameters_TEST
