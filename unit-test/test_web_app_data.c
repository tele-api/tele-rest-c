#ifndef web_app_data_TEST
#define web_app_data_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define web_app_data_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/web_app_data.h"
web_app_data_t* instantiate_web_app_data(int include_optional);



web_app_data_t* instantiate_web_app_data(int include_optional) {
  web_app_data_t* web_app_data = NULL;
  if (include_optional) {
    web_app_data = web_app_data_create(
      "0",
      "0"
    );
  } else {
    web_app_data = web_app_data_create(
      "0",
      "0"
    );
  }

  return web_app_data;
}


#ifdef web_app_data_MAIN

void test_web_app_data(int include_optional) {
    web_app_data_t* web_app_data_1 = instantiate_web_app_data(include_optional);

	cJSON* jsonweb_app_data_1 = web_app_data_convertToJSON(web_app_data_1);
	printf("web_app_data :\n%s\n", cJSON_Print(jsonweb_app_data_1));
	web_app_data_t* web_app_data_2 = web_app_data_parseFromJSON(jsonweb_app_data_1);
	cJSON* jsonweb_app_data_2 = web_app_data_convertToJSON(web_app_data_2);
	printf("repeating web_app_data:\n%s\n", cJSON_Print(jsonweb_app_data_2));
}

int main() {
  test_web_app_data(1);
  test_web_app_data(0);

  printf("Hello world \n");
  return 0;
}

#endif // web_app_data_MAIN
#endif // web_app_data_TEST
