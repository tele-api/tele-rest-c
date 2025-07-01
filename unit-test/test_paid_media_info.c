#ifndef paid_media_info_TEST
#define paid_media_info_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define paid_media_info_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/paid_media_info.h"
paid_media_info_t* instantiate_paid_media_info(int include_optional);



paid_media_info_t* instantiate_paid_media_info(int include_optional) {
  paid_media_info_t* paid_media_info = NULL;
  if (include_optional) {
    paid_media_info = paid_media_info_create(
      56,
      list_createList()
    );
  } else {
    paid_media_info = paid_media_info_create(
      56,
      list_createList()
    );
  }

  return paid_media_info;
}


#ifdef paid_media_info_MAIN

void test_paid_media_info(int include_optional) {
    paid_media_info_t* paid_media_info_1 = instantiate_paid_media_info(include_optional);

	cJSON* jsonpaid_media_info_1 = paid_media_info_convertToJSON(paid_media_info_1);
	printf("paid_media_info :\n%s\n", cJSON_Print(jsonpaid_media_info_1));
	paid_media_info_t* paid_media_info_2 = paid_media_info_parseFromJSON(jsonpaid_media_info_1);
	cJSON* jsonpaid_media_info_2 = paid_media_info_convertToJSON(paid_media_info_2);
	printf("repeating paid_media_info:\n%s\n", cJSON_Print(jsonpaid_media_info_2));
}

int main() {
  test_paid_media_info(1);
  test_paid_media_info(0);

  printf("Hello world \n");
  return 0;
}

#endif // paid_media_info_MAIN
#endif // paid_media_info_TEST
