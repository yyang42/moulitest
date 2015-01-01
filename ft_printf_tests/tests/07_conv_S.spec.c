#include <project.h>

static void test_simple(t_test *test)
{
	// debug_next_assert();
	assert_printf("%S", L"米");
}

static void test_multiple_wchars(t_test *test)
{
	// debug_next_assert();
	assert_printf("%S", L"我是一只猫。");
}

static void test_greek_alphabet_wchars(t_test *test)
{
	// debug_next_assert();
	assert_printf("%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S%S",
	L"Α α", L"Β β", L"Γ γ", L"Δ δ", L"Ε ε", L"Ζ ζ", L"Η η", L"Θ θ", L"Ι ι", L"Κ κ", L"Λ λ", L"Μ μ",
	L"Ν ν", L"Ξ ξ", L"Ο ο", L"Π π", L"Ρ ρ", L"Σ σ", L"Τ τ", L"Υ υ", L"Φ φ", L"Χ χ", L"Ψ ψ", L"Ω ω", L"");
}

// static void test_new(t_test *test)
// {
// 	wchar_t wstr[5];

// 	wstr[0] = L'A';
// 	wstr[1] = 945;
// 	wstr[2] = 0x801;
// 	wstr[3] = 0x10903;
// 	wstr[4] = L'\0';
// 	debug_next_assert();
// 	assert_printf("%S", wstr);
// }

static void test_mix(t_test *test)
{
	// debug_next_assert();
	assert_printf("a%Sb%sc%S", L"我", "42", L"猫");
}

void	suite_07_conv_S(t_suite *suite)
{
	SUITE_ADD_TEST(suite, test_simple);
	SUITE_ADD_TEST(suite, test_multiple_wchars);
	SUITE_ADD_TEST(suite, test_greek_alphabet_wchars);
	// SUITE_ADD_TEST(suite, test_new);
	SUITE_ADD_TEST(suite, test_mix);
}
