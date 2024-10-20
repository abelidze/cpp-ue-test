#include <utils.hpp>

#include <stdexcept>

namespace utils
{
	int32_t ParseInt(std::string text, bool strict)
	{
		int32_t base = 0;
		int32_t sign = 1;
		bool isWhitespaceSkipped = false;
		for (CharT character : text) {
			if (!isWhitespaceSkipped && IsWhitespace(character)) {
				continue;
			}
			isWhitespaceSkipped = true;
			if (IsNotInAlphabet(character)) {
				UTIL_THROW(std::invalid_argument("[ParseInt] Text contains invalid symbols"));
				break;
			}
			if (character == '-') {
				if (base != 0) {
					UTIL_THROW(std::invalid_argument("[ParseInt] Text has invalid format for integer"));
					break;
				} else if (sign < 0) {
					UTIL_THROW(std::invalid_argument("[ParseInt] Double unary minus encountered"));
					return 0;
				}
				sign = -1;
				continue;
			}
			if (character == '0' && base == 0) {
				UTIL_THROW(std::invalid_argument("[ParseInt] Parsed integer is too big for 32-bit integer type"));
				return 0;
			}
			if (base > INT32_MAX / 10) {
				UTIL_THROW(std::overflow_error("[ParseInt] Parsed integer is too big for 32-bit integer type"));
				base = 0;
				break;
			}
			base = base * 10 + (character - '0');
		}
		return base * sign;
	}

	void SpiralPrint(std::ostream& output, const Array2DT& matrix)
	{
		int height = matrix.size();
		if (height == 0) {
			return;
		}
		int width = matrix[0].size();
		if (width == 0) {
			return;
		}
		for (size_t i = 1; i < height; ++i) {
			if (matrix[i].size() != width) {
				return;
			}
		}
		int top = 0;
		int right = width - 1;
		int bottom = height - 1;
		int left = 0;
		while (true) {
			if (left > right) {
				break;
			}
			// top
			for (int i = left; i <= right; ++i) {
				output << matrix[top][i] << ' ';
			}
			if (++top > bottom) {
				break;
			}
			// right
			for (int i = top; i <= bottom; ++i) {
				output << matrix[i][right] << ' ';
			}
			if (left > --right) {
				break;
			}
			// bottom
			for (int i = right; i >= left; --i) {
				output << matrix[bottom][i] << ' ';
			}
			if (top > --bottom) {
				break;
			}
			// left
			for (int i = bottom; i >= top; --i) {
				output << matrix[i][left] << ' ';
			}
			++left;
		}
		output << std::endl;
	}

	bool IsWhitespace(CharT value)
	{
		return value == ' '
			|| value == '\t'
			|| value == '\n'
			|| value == '\r';
	}

	bool IsNotInAlphabet(CharT value)
	{
		static const CharT Alphabet[] = { '-', 0, 0, '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
		static constexpr CharT AlphabetSize = sizeof(Alphabet) / sizeof(CharT);
		return value < Alphabet[0]
			|| value > Alphabet[AlphabetSize - 1]
			|| !Alphabet[value - Alphabet[0]];
	}
} // namespace utils