#pragma once

#include <string>
#include <vector>
#include <ostream>

#define UTIL_THROW(exception) if (strict) { throw (exception); }

namespace utils
{
	typedef char CharT;
	typedef std::vector<std::vector<int>> Array2DT;

	bool IsWhitespace(CharT value);

	bool IsNotInAlphabet(CharT value);

	/** Parse a first encountered integer value from string */
	int32_t ParseInt(std::string text, bool strict = false);

	/** Print 2D array in a spiral traverse order */
	void SpiralPrint(std::ostream& output, const Array2DT& matrix);
} // namespace utils
