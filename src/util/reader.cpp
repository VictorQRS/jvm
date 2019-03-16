#include "reader.hpp"
#include "JvmException.hpp"

namespace jvm {

	uint64_t Reader::size() {
		_class.seekg(0, _class.end);
		auto len = _class.tellg();
		_class.seekg(0, _class.beg);
		return len;
	}

	bool Reader::isValid() {
		auto firstWord = getNextWord();
		return (firstWord == MAGIC_NUMBER);
	}

	void Reader::open(std::string &filename) {
		index = 0;

		_class.open(filename, std::ios::binary);

		if (!_class.is_open()) {
			throw JvmException("Couldn't open file");
		}

		// reserve in memory the space needed for the file
		bytes.resize(size());

		// read the file to memory
		for (auto i = 0; !_class.eof(); i++) {
			_class.read((char*) &bytes[i], 1);
		}

		if (!isValid()) {
			throw JvmException("This file isn't a valid .class file");
		}
	}

	uint8_t Reader::getNextByte() {
		return bytes[index++];
	}

	uint16_t Reader::getNextHalfWord() {
		std::array<uint8_t, 2> result_arr;
		
		std::copy_n(bytes.begin() + index, 2, result_arr.begin());
		std::reverse(result_arr.begin(), result_arr.end());

		index += 2;
		
		return *reinterpret_cast<uint16_t*>(result_arr.data());
	}

	uint32_t Reader::getNextWord() {
		std::array<uint8_t, 4> result_arr;
		
		std::copy_n(bytes.begin() + index, 4, result_arr.begin());
		std::reverse(result_arr.begin(), result_arr.end());

		index += 4;
		
		return *reinterpret_cast<uint32_t*>(result_arr.data());
	}

	void Reader::close() {
		_class.close();
	}

	void Reader::skipBytes(int n) {
		_class.seekg(n, std::ifstream::cur);
		index += n;
	}
}