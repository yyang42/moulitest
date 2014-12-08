#include "project.h"

UT_TEST(ft_atoi)
{
	UT_ASSERT_EQ(ft_atoi(" -sfecf"), atoi(" -sfecf"));
	UT_ASSERT_EQ(ft_atoi(""), atoi(""));
	UT_ASSERT_EQ(ft_atoi("+2798"), atoi("+2798"));
	UT_ASSERT_EQ(ft_atoi("  \t\n  \r\r\v\f-899"), atoi("  \t\n  \r\r\v\f-899"));
	UT_ASSERT_EQ(ft_atoi("+0089"), atoi("+0089"));
	UT_ASSERT_EQ(ft_atoi("a56"), atoi("a56"));
	UT_ASSERT_EQ(ft_atoi("      --s8"), atoi("      --s8"));
	UT_ASSERT_EQ(ft_atoi("0001020304"), atoi("0001020304"));
	UT_ASSERT_EQ(ft_atoi("000000000000000110"), atoi("000000000000000110"));
	UT_ASSERT_EQ(ft_atoi("-153"), atoi("-153"));
	UT_ASSERT_EQ(ft_atoi("+132"), atoi("+132"));
	UT_ASSERT_EQ(ft_atoi("++876"), atoi("++876"));
	UT_ASSERT_EQ(ft_atoi("--132"), atoi("--132"));
	UT_ASSERT_EQ(ft_atoi("dwbk "), atoi("dwbk "));
	UT_ASSERT_EQ(ft_atoi(" 1"), atoi(" 1"));
	UT_ASSERT_EQ(ft_atoi("42jk "), atoi("42jk "));
	UT_ASSERT_EQ(ft_atoi(" 21"), atoi(" 21"));
	UT_ASSERT_EQ(ft_atoi("     32 "), atoi("     32 "));
	UT_ASSERT_EQ(ft_atoi("\n          42 24"), atoi("\n          42 24"));
	UT_ASSERT_EQ(ft_atoi("1-2"), atoi("1-2"));
	UT_ASSERT_EQ(ft_atoi("4+2"), atoi("4+2"));
	UT_ASSERT_EQ(ft_atoi("  +442"), atoi("  +442"));
	UT_ASSERT_EQ(ft_atoi("  -4232"), atoi("  -4232"));
	UT_ASSERT_EQ(ft_atoi("4,5"), atoi("4,5"));
	UT_ASSERT_EQ(ft_atoi("+"), atoi("+"));
	UT_ASSERT_EQ(ft_atoi("-"), atoi("-"));
	UT_ASSERT_EQ(ft_atoi("-+1"), atoi("-+1"));
	UT_ASSERT_EQ(ft_atoi("+-1"), atoi("+-1"));
	UT_ASSERT_EQ(ft_atoi("\200123"), atoi("\200123"));
	UT_ASSERT_EQ(ft_atoi("123\200"), atoi("123\200"));

	UT_ASSERT_EQ(ft_atoi("-2147483648"), atoi("-2147483648"));
	UT_ASSERT_EQ(ft_atoi("2147483647"), atoi("2147483647"));

	UT_ASSERT_W(ft_atoi("2147483648") == atoi("2147483648"));
	UT_ASSERT_W(ft_atoi("9223372036854775807") == atoi("9223372036854775807"));
	UT_ASSERT_W(ft_atoi("9223372036854775806") == atoi("9223372036854775806"));
	UT_ASSERT_W(ft_atoi("9223372036854775808") == atoi("9223372036854775808"));
	UT_ASSERT_W(ft_atoi("-9223372036854775807") == atoi("-9223372036854775807"));
	UT_ASSERT_W(ft_atoi("-9223372036854775806") == atoi("-9223372036854775806"));
	UT_ASSERT_W(ft_atoi("-9223372036854775808") == atoi("-9223372036854775808"));
	UT_ASSERT_W(ft_atoi("    555 5555555555555555") == atoi("    555 5555555555555555"));
	UT_ASSERT_W(ft_atoi("2398472983749236582739823758723469826928374") == atoi("2398472983749236582739823758723469826928374"));
	UT_ASSERT_W(ft_atoi("-2398472983749236582739823758723469826928374") == atoi("-2398472983749236582739823758723469826928374"));
}
