#include "smart_delivery.h"
#include "unity.h"


int result=0;
/* Required by the unity test framework */

void setUp()
{
}
void tearDown()
{
}

void test_account(void)
{
    
    char mail[20]="s.jeev@gmail.com";
    char password[20]="j@12345678J";
    char name[20]="jeev";
    char mobile[20]="9244556669";
    
    TEST_ASSERT_EQUAL(1, account_check(mail,password,name,mobile));
}
void test_validate(void)
{
    char name[20]="jeev";
    TEST_ASSERT_EQUAL(1, validate_name(name));

    char email[20]="s.jeev@gmail.com";
    TEST_ASSERT_EQUAL(1, validate_email(email));

    char mail[20]="s.jeevgmail";
    TEST_ASSERT_EQUAL(0, validate_email(mail));

    char mobil[20]="9244556669";
    TEST_ASSERT_EQUAL(1, validate_mobile(mobil));
    
}

void test_location(void)
{
    TEST_ASSERT_EQUAL(0, location());
}

int main(void)
{
    UNITY_BEGIN();

    RUN_TEST(test_account);
    RUN_TEST(test_validate);
    RUN_TEST(test_location);

    return UNITY_END();
}