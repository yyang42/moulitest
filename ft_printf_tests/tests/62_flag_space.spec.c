#include <project.h>
#include <limits.h>
#include <signal.h>

static void test_space_d_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("% d", 9999);
}

static void test_space_d_simple_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("% d", -9999);
}

static void test_space_i_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("% i", 9999);
}

static void test_space_i_simple_minus(t_test *test)
{
	// test->debug = 1;
	assert_printf("% i", -9999);
}

/*
//Disabling this test because -Wformat says undefined behavior
static void test_space_u_simple(t_test *test)
{
	// test->debug = 1;
	assert_printf("% u", 9999);
}
//Disabling this test because -Wformat says undefined behavior
static void test_space_c_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% c}", 0);
}
//Disabling this test because -Wformat says undefined behavior
static void cValidChar_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% c}", 'a');
}
//Disabling this test because -Wformat says undefined behavior
static void sNullString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% s}", NULL);
}
//Disabling this test because -Wformat says undefined behavior
static void sFakeNullString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% s}", "(null)");
}
//Disabling this test because -Wformat says undefined behavior
static void sEmptyString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% s}", "");
}
//Disabling this test because -Wformat says undefined behavior; Also C no longer mandatory
static void test_space_C_zero(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% C}", 0);
}
//Disabling this test because -Wformat says undefined behavior; Also C no longer mandatory
static void CValidChar_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% C}", L'a');
}
//Disabling this test because -Wformat says undefined behavior; Also S no longer mandatory
static void SNullString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% S}", NULL);
}
//Disabling this test because -Wformat says undefined behavior; Also S no longer mandatory
static void SFakeNullString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% S}", L"(null)");
}
//Disabling this test because -Wformat says undefined behavior; Also S no longer mandatory
static void SEmptyString_spaceFlag(t_test *test)
{
	// test->debug = 1;
	assert_printf("{% S}", L"");
}
*/

void	suite_62_flag_space(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_space_d_simple);
	SUITE_ADD_TEST(suite, test_space_d_simple_minus);
	SUITE_ADD_TEST(suite, test_space_i_simple);
	SUITE_ADD_TEST(suite, test_space_i_simple_minus);
	//SUITE_ADD_TEST(suite, test_space_u_simple);
	//SUITE_ADD_TEST(suite, test_space_c_zero);
	//SUITE_ADD_TEST(suite, cValidChar_spaceFlag);
	//SUITE_ADD_TEST(suite, sNullString_spaceFlag);
	//SUITE_ADD_TEST(suite, sFakeNullString_spaceFlag);
	//SUITE_ADD_TEST(suite, sEmptyString_spaceFlag);
	//SUITE_ADD_TEST(suite, test_space_C_zero);
	//SUITE_ADD_TEST(suite, CValidChar_spaceFlag);
	//SUITE_ADD_TEST(suite, SNullString_spaceFlag);
	//SUITE_ADD_TEST(suite, SFakeNullString_spaceFlag);
	//SUITE_ADD_TEST(suite, SEmptyString_spaceFlag);
}
