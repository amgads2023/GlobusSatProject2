/*
 * SystemC.c
 *
 *  Created on: Dec 22, 2023
 *      Author: Muhammad Zahlqa
 */

#include "system_c_tests.h"

#include "utils/menu_selection.h"
#include "utils/input.h"

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>		// printf format codes


static Boolean endian_test(void)
{
	uint32_t data = 0x12345678;
	printf("Data %" PRIu32 ".\r\n", data);
	uint8_t* p = (uint8_t*) &data;
	printf("Data[0] %x.\r\n", p[0]);
	printf("Data[1] %x.\r\n", p[1]);
	printf(p[0] == 0x12 ? "Big Endian\r\n" : "Little Endian\r\n");
	return TRUE;
}

static Boolean data_types_sizes_test(void)
{
	printf("size of   short: %d\r\n", sizeof(short));
	printf("size of     int: %d\r\n", sizeof(int));
	printf("size of    long: %d\r\n", sizeof(long));
	printf("size of   float: %d\r\n", sizeof(float));
	printf("size of  double: %d\r\n", sizeof(double));
	printf("size of int32_t: %d\r\n", sizeof(int32_t));

	return TRUE;
}

static Boolean square_a_number_test(void)
{
	printf("Square a number test \r\n");
	int number = INPUT_GetINT32("Enter a number: ");

	int square = number * number;
	printf("the square of %d is %d\r\n", number, square);

	return TRUE;
}

static Boolean sum_a_number_test(void)
{
	printf("sum a number test \r\n");
	int number = INPUT_GetINT32("Enter a number: ");
	int number1 = INPUT_GetINT32("Enter a number: ");

	int sum = number + number1;
	printf("the sum of %d is %d is %d\r\n" , number, number1, sum);
	return TRUE;
}

static Boolean absolute_of_number_test(void)
{
	printf("absolute of a number test \r\n");
	int num = INPUT_GetINT32("Enter a number: ");
	int abs = num;

	if (num < 0)
	{
		abs = -1*num;
	}

	printf("the absolute value of %d is %d", num, abs);
	return TRUE;
}

static Boolean mul_test(void)
{
	int a = INPUT_GetINT32("Enter a number: ");
	int b = INPUT_GetINT32("Enter a number: ");
	int r=  a * b ;
	printf("the mul of %d and %d is %d\r\n", a, b, r);
	return TRUE;
}

static Boolean get_number_range_test(void)
{
	printf("Range input test\r\n");
	int min = INPUT_GetINT32("Enter range min: ");
	int max = INPUT_GetINT32("Enter range max: ");
	printf("Enter a number between %d and %d\n", min, max);
	int n = INPUT_GetLong_Range("Number: ", min, max);
	printf("You have entered: %d\n", n);

	return TRUE;
}

static MenuAction system_menu[] = {
			{ endian_test, "Platform Endianess test"},
			{ data_types_sizes_test, "Data types size test"},
			{ square_a_number_test, "Test square a number"},
			{ sum_a_number_test, "Test sum a number"},
			{ absolute_of_number_test, "Test absolute value of a number"},
			{ mul_test, "Test mul of two num"},
			{ get_number_range_test, "get number in range" },
			MENU_ITEM_END
};

Boolean SystemCTest(void)
{
	MenuDisplay(system_menu);
	return TRUE;
}
