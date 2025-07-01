#ifndef web_app_info_TEST
#define web_app_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define web_app_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/web_app_info.h"
web_app_info_t* instantiate_web_app_info(int include_optional);



web_app_info_t* instantiate_web_app_info(int include_optional) {
  web_app_info_t* web_app_info = NULL;
  if (include_optional) {
    web_app_info = web_app_info_create(
      "0"
    );
  } else {
    web_app_info = web_app_info_create(
      "0"
    );
  }

  return web_app_info;
}


#ifdef web_app_info_MAIN

void test_web_app_info(int include_optional) {
    web_app_info_t* web_app_info_1 = instantiate_web_app_info(include_optional);

	cJSON* jsonweb_app_info_1 = web_app_info_convertToJSON(web_app_info_1);
	printf("web_app_info :\n%s\n", cJSON_Print(jsonweb_app_info_1));
	web_app_info_t* web_app_info_2 = web_app_info_parseFromJSON(jsonweb_app_info_1);
	cJSON* jsonweb_app_info_2 = web_app_info_convertToJSON(web_app_info_2);
	printf("repeating web_app_info:\n%s\n", cJSON_Print(jsonweb_app_info_2));
}

int main() {
  test_web_app_info(1);
  test_web_app_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // web_app_info_MAIN
#endif // web_app_info_TEST
