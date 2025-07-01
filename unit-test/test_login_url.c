#ifndef login_url_TEST
#define login_url_TEST

// the following is to include only the main from the first c file
#ifndef TEST_MAIN
#define TEST_MAIN
#define login_url_MAIN
#endif // TEST_MAIN

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include "../external/cJSON.h"

#include "../model/login_url.h"
login_url_t* instantiate_login_url(int include_optional);



login_url_t* instantiate_login_url(int include_optional) {
  login_url_t* login_url = NULL;
  if (include_optional) {
    login_url = login_url_create(
      "0",
      "0",
      "0",
      1
    );
  } else {
    login_url = login_url_create(
      "0",
      "0",
      "0",
      1
    );
  }

  return login_url;
}


#ifdef login_url_MAIN

void test_login_url(int include_optional) {
    login_url_t* login_url_1 = instantiate_login_url(include_optional);

	cJSON* jsonlogin_url_1 = login_url_convertToJSON(login_url_1);
	printf("login_url :\n%s\n", cJSON_Print(jsonlogin_url_1));
	login_url_t* login_url_2 = login_url_parseFromJSON(jsonlogin_url_1);
	cJSON* jsonlogin_url_2 = login_url_convertToJSON(login_url_2);
	printf("repeating login_url:\n%s\n", cJSON_Print(jsonlogin_url_2));
}

int main() {
  test_login_url(1);
  test_login_url(0);

  printf("Hello world \n");
  return 0;
}

#endif // login_url_MAIN
#endif // login_url_TEST
