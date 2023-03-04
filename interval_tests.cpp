#include <iostream>
#include "TimeInterval.h"

using namespace std;

/**
 * \brief Divides one time interval by another
 *
 * Given two TimeInterval objects -- a numerator and a denominator -- computes
 * the quotient (as a long integer) and the remainder (as another TimeInterval)
 * when numerator is divided by denominator.
 *
 * This function is implemented just like a human carrying out a long division.
 */
void divide(const TimeInterval &numerator,
            const TimeInterval &denominator,
            long &quotient,
            TimeInterval &remainder)
{
	long i;                // Loop index for finding the exact quotient digit
	long quo;              // Current quotient digit
	TimeInterval den, num; // Working copies of `denominator` and `numerator`, respectively

	den = denominator;
	num = numerator;

	quotient = 0;

	while (num >= den) {
		// At least 1
		quo = 1;

		// Advance to the largest quotient digit in steps of 1, 10, 100...
		while (num >= den * quo * 10) {
			quo = quo * 10;
		}

		// Find the exact quotient digit in [1, 9]
		for (i = 1; i < 10; i++) {
			// Found it
			if (den * quo * (i + 1) > num) {
				// Accumulate the result into `quotient`
				quotient = quotient + quo * i;
				// Subtract the result from `num`
				num = num - den * quo * i;

				break;
			}
		}
	}

	remainder = num;

	//
	// The simplest algorithm...
	//
	// while (remainder >= denominator) {
	// 	remainder -= denominator;
	// 	quotient++;
	// }

	//
	// Are there edge cases that aren't handled by the simple algorithm?
	//

	//
	// Are there algorithms that can arrive at the answer much more efficiently?
	//
}


int main(int argc, char **argv)
{
	TimeInterval numerator;
	TimeInterval denominator;
	TimeInterval remainder;
	long quotient;

	//
	// Add tests here to verify the correctness of your implementation
	// of interval division
	//

	numerator.setInterval(500, 0, 0);    // 500 days
	denominator.setInterval(0, 0, 200000);    // 0.2 seconds

	divide(numerator, denominator, quotient, remainder);

	cout << denominator << " divides " << numerator << " " << quotient << " times with a remainder of " << remainder << endl;

	return 0;
}
