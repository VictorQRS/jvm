#include "converter.hpp"

namespace jvm {

	// TODO: Analyze if this can be made into Conversion Functions (available in C++ 11)

	op8 Converter::to_op8(op4 a, op4 b) {
		op8 ans, high_bytes, low_bytes;

		low_bytes.ull = a.ui4;
		high_bytes.ull = b.ui4;

		ans.ull = high_bytes.ull << 32ul;
		ans.ull = ans.ull | low_bytes.ull;

		return ans;
	}

	std::array<op4, 2> Converter::to_op4(op8 a) {
		std::array<op4, 2> result;

		result[0].ui4  = static_cast<u4>(a.ull & ((1ul << 32ul) - 1));
		result[1].ui4 = static_cast<u4>(a.ull >> 32ul);

		return result;
	};

	u4 Converter::to_u4(u2 a, u2 b) {
		u4 ans = a;

		ans = (ans << 16ul) | b;

		return ans;
	}

	i4 Converter::to_i4(u2 a, u2 b) {
		u4 ans = a;

		ans = (ans << 16ul) | b;

		return static_cast<i4>(ans);
	}

	u4 Converter::to_u4(u1 a, u1 b, u1 c, u1 d) {
		u4 ans = a;

		ans = (ans << 8ul) | b;
		ans = (ans << 8ul) | c;
		ans = (ans << 8ul) | d;

		return ans;
	}

	i4 Converter::to_i4(u1 a, u1 b, u1 c, u1 d) {
		u4 ans = a;

		ans = (ans << 8ul) | b;
		ans = (ans << 8ul) | c;
		ans = (ans << 8ul) | d;

		return static_cast<i4>(ans);
	}

	u2 Converter::to_u2(u1 a, u1 b) {
		u2 ans = a;

		ans = (ans << 8ul) | b;

		return ans;
	}

	i2 Converter::to_i2(u1 a, u1 b) {
		u2 ans = a;

		ans = (ans << 8ul) | b;

		return static_cast<i2>(ans);
	}

	i1 Converter::to_i1(u1 a) {
		return static_cast<i1>(a);
	}

	std::array<u2, 2> Converter::to_u2(u4 a) {
		std::array<u2, 2> result;

		result[0] = static_cast<u2>(a & ((1u << 16u) - 1)); a >>= 16u;
		result[1] = static_cast<u2>(a);

		return result;
	}

	std::array<u1, 2> Converter::to_u1(u2 a) {
		std::array<u1, 2> result;

		result[0] = static_cast<u1>(a & ((1u << 8u) - 1)); a >>= 8u;
		result[1] = static_cast<u1>(a);

		return result;
	}

	std::array<u1, 4> Converter::to_u1(u4 a) {
		std::array<u1, 4> result;

		result[0] = static_cast<u1>(a & ((1u << 8u) - 1)); a >>= 8u;
		result[1] = static_cast<u1>(a & ((1u << 8u) - 1)); a >>= 8u;
		result[2] = static_cast<u1>(a & ((1u << 8u) - 1)); a >>= 8u;
		result[3] = static_cast<u1>(a);

		return result;
	}

	std::u16string Converter::utf8_to_utf16(std::string source){
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
		std::u16string dest = convert.from_bytes(source);
		return dest;
	}

	std::string Converter::utf16_to_utf8(std::u16string source){
		std::wstring_convert<std::codecvt_utf8_utf16<char16_t>,char16_t> convert;
		std::string dest = convert.to_bytes(source);
		return dest;
	}

}
