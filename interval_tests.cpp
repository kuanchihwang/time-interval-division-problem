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
 * This function follows the "truncated division" definition.
 * This function throws `domain_error` if `denominator` is 0.
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
	TimeInterval ti0;      // Time interval of zero

	// Check for exceptions
	if (denominator == ti0) {
		if (numerator == ti0) {
			// Case: 0/0
			cerr << "Undefined result" << endl;

			throw domain_error("Undefined result");
		}

		// Case: n/0 where n != 0
		cerr << "Divide by zero" << endl;

		throw domain_error("Divide by zero");
	}

	den = denominator;
	num = numerator;

	if (den < ti0) {
		den = den * (-1);
	}

	if (num < ti0) {
		num = num * (-1);
	}

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

	// Restore signs
	if ((denominator > ti0 && numerator < ti0) || (denominator < ti0 && numerator > ti0)) {
		quotient = quotient * (-1);
	}

	if (numerator < ti0) {
		remainder = remainder * (-1);
	}

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

void printResult(const TimeInterval &numerator,
                 const TimeInterval &denominator,
                 const long &quotient,
                 const TimeInterval &remainder)
{
	cout << denominator << " divides " << numerator << " " << quotient << " times with a remainder of " << remainder << endl;
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
	printResult(numerator, denominator, quotient, remainder);

	// `numerator`   = 0/+/-
	// `denominator` = 0

	numerator.setInterval(0, 0, 0);
	denominator.setInterval(0, 0, 0);

	try {
		divide(numerator, denominator, quotient, remainder);
	} catch (const domain_error &e) {
		cout << "A domain_error exception is caught" << endl;
	}

	numerator.setInterval(100, 10, 1);
	denominator.setInterval(0, 0, 0);

	try {
		divide(numerator, denominator, quotient, remainder);
	} catch (const domain_error &e) {
		cout << "A domain_error exception is caught" << endl;
	}

	numerator.setInterval(-100, -10, -1);
	denominator.setInterval(0, 0, 0);

	try {
		divide(numerator, denominator, quotient, remainder);
	} catch (const domain_error &e) {
		cout << "A domain_error exception is caught" << endl;
	}

	// `numerator`   = 0
	// `denominator` = +/-

	numerator.setInterval(0, 0, 0);
	denominator.setInterval(1, 33, 7);

	divide(numerator, denominator, quotient, remainder);
	printResult(numerator, denominator, quotient, remainder);

	numerator.setInterval(0, 0, 0);
	denominator.setInterval(-1, -33, -7);

	divide(numerator, denominator, quotient, remainder);
	printResult(numerator, denominator, quotient, remainder);

	// `numerator`   = +
	// `denominator` = +

	numerator.setInterval(100, 10, 1);
	denominator.setInterval(1, 33, 7);

	divide(numerator, denominator, quotient, remainder);
	printResult(numerator, denominator, quotient, remainder);

	// `numerator`   = -
	// `denominator` = +

	numerator.setInterval(-100, -10, -1);
	denominator.setInterval(1, 33, 7);

	divide(numerator, denominator, quotient, remainder);
	printResult(numerator, denominator, quotient, remainder);

	// `numerator`   = +
	// `denominator` = -

	numerator.setInterval(100, 10, 1);
	denominator.setInterval(-1, -33, -7);

	divide(numerator, denominator, quotient, remainder);
	printResult(numerator, denominator, quotient, remainder);

	// `numerator`   = -
	// `denominator` = -

	numerator.setInterval(-100, -10, -1);
	denominator.setInterval(-1, -33, -7);

	divide(numerator, denominator, quotient, remainder);
	printResult(numerator, denominator, quotient, remainder);

	return 0;
}
