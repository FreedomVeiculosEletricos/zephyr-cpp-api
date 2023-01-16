#include <zephyr/zephyr.h>
#include <zephyr/kernel.h>
#include <zepyr/calculator.h>
#include <ztest.h>


void test_function_calculator_addition(void)
{
  zassert_equal(32, add(25, 7));
}

void test_function_calculator_subtraction(void)
{
  zassert_equal(20, sub(23, 3));
}

void test_function_calculator_multiplication(void)
{
  zassert_equal(50, mul(25, 2));
}

void test_function_calculator_division(void)
{
  zassert_equal(33, div(100, 3));
}

void test_main(void)
{
  ztest_test_suite(calculator_api, 
    ztest_unit_test(test_function_calculator_addition),
    ztest_unit_test(test_function_calculator_subtraction),
    ztest_unit_test(test_function_calculator_multiplication),
    ztest_unit_test(test_function_calculator_division));
  ztest_run_test_suite(calculator_api);
}