#pragma once

#include "../base.hpp"
#include "constant_pool.hpp"
#include "../util/converter.hpp"

namespace jvm {

	struct InstructionInfo {
		u1 opcode;
		std::string name;
		uint32_t jmp;

		/**
		 * Print in the stream the name
		 * @param os used to output data
		 * @param prefix string to be printed before the opcodes
		 * @param cl constant pool reference
		 */
		virtual void printToStream(std::ostream &, std::string &, ConstantPool &);

		/**
		 * No params for this instruction
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		virtual uint32_t fillParams(uint32_t, std::vector<u1> &);

		template <typename T>
		static std::shared_ptr<InstructionInfo> instantiate() {
			return std::make_shared<T>();
		}

	protected:
		InstructionInfo(u1 opcode_, std::string&& name_, uint32_t jmp_ = 0)
			: opcode(opcode_), name(name_), jmp(jmp_)
		{}
	};

	//Constants opcodes 0x00,00 -- 0x14,20
	struct OPINFOnop : public InstructionInfo { // 0x00 -- 00
		OPINFOnop() : InstructionInfo(, "nop") {}
	};

	struct OPINFOaconst_null : public InstructionInfo { // 0x01 -- 01
		OPINFOaconst_null() : InstructionInfo(1, "aconst_null") {}
	};

	struct OPINFOiconst_m1 : public InstructionInfo { // 0x02 -- 02
		OPINFOiconst_m1() : InstructionInfo(2, "iconst_m1") {}
	};

	struct OPINFOiconst_0 : public InstructionInfo { // 0x03 -- 03
		OPINFOiconst_0() : InstructionInfo(3, "iconst_0") {}
	};

	struct OPINFOiconst_1 : public InstructionInfo { // 0x04 -- 04
		OPINFOiconst_1() : InstructionInfo(4, "iconst_1") {}
	};

	struct OPINFOiconst_2 : public InstructionInfo { // 0x05 -- 05
		OPINFOiconst_2() : InstructionInfo(5, "iconst_2") {}
	};

	struct OPINFOiconst_3 : public InstructionInfo { // 0x06 -- 06
		OPINFOiconst_3() : InstructionInfo(6, "iconst_3") {}
	};

	struct OPINFOiconst_4 : public InstructionInfo { // 0x07 -- 07
		OPINFOiconst_4() : InstructionInfo(7, "iconst_4") {}
	};

	struct OPINFOiconst_5 : public InstructionInfo { // 0x08 -- 08
		OPINFOiconst_5() : InstructionInfo(8, "iconst_5") {}
	};

	struct OPINFOlconst_0 : public InstructionInfo { // 0x09 -- 09
		OPINFOlconst_0() : InstructionInfo(9, "lconst_0") {}
	};

	struct OPINFOlconst_1 : public InstructionInfo { // 0x0A -- 10
		OPINFOlconst_1() : InstructionInfo(10, "lconst_1") {}
	};

	struct OPINFOfconst_0 : public InstructionInfo { // 0x0B -- 11
		OPINFOfconst_0() : InstructionInfo(11, "fconst_0") {}
	};

	struct OPINFOfconst_1 : public InstructionInfo { // 0x0C -- 12
		OPINFOfconst_1() : InstructionInfo(12, "fconst_1") {}
	};

	struct OPINFOfconst_2 : public InstructionInfo { // 0x0D -- 13
		OPINFOfconst_2() : InstructionInfo(13, "fconst_2") {}
	};

	struct OPINFOdconst_0 : public InstructionInfo { // 0x0E -- 14
		OPINFOdconst_0() : InstructionInfo(14, "dconst_0") {}
	};

	struct OPINFOdconst_1 : public InstructionInfo { // 0x0F -- 15
		OPINFOdconst_1() : InstructionInfo(15, "dconst_1") {}
	};

	struct OPINFObipush : public InstructionInfo { // 0x10 -- 16
		OPINFObipush() : InstructionInfo(16, "bipush", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Operand Stack  ... → ..., <i> , byte
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i1 byte; ///< Byte to be pushed as an integer to the stack
	};

	struct OPINFOsipush : public InstructionInfo { // 0x11 -- 17
		OPINFOsipush() : InstructionInfo(17, "sipush", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Operand Stack ... → ..., value , The immediate unsigned byte1 and byte2 values are assembled into an intermediate short where the value of the short is (byte1 << 8) | byte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 value; ///< Short value to be pushed onto the stack
	};

	struct OPINFOldc : public InstructionInfo { // 0x12 -- 18
		OPINFOldc() : InstructionInfo(18, "ldc", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Operand Stack ... → ..., value , The index is an unsigned byte that must be a valid index into the run-time constant pool
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index in the constant pool
	};

	struct OPINFOldc_w : public InstructionInfo { // 0x13 -- 19
		OPINFOldc_w() : InstructionInfo(19, "ldc_w", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ... → ..., value , indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool
	};

	struct OPINFOldc2_w : public InstructionInfo { // 0x14 -- 20
		OPINFOldc2_w() : InstructionInfo(20, "ldc2_w", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Operand Stack ... → ..., value , indexbyte1 indexbyte2 , the value of the index is calculated as (indexbyte1 << 8) | indexbyte2, run-time constant pool
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool
	};

	//Loads opcodes 0x15,21 -- 0x35,53
	struct OPINFOiload : public InstructionInfo { // 0x15 -- 21
		OPINFOiload() : InstructionInfo(21, "iload", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ... → ..., value , The index is an unsigned byte into local variable array,
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index of the local variable
	};

	struct OPINFOlload : public InstructionInfo { // 0x16 -- 22
		OPINFOlload() : InstructionInfo(22, "lload", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ... → ..., value, The index is an unsigned byte , local variable array
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index to the local variable
	};

	struct OPINFOfload : public InstructionInfo { // 0x17 -- 23
		OPINFOfload() : InstructionInfo(23, "fload", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Op_stack ... → ..., value, The index is an unsigned byte that must be an index into the local variable array
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index of the local float variable
	};

	struct OPINFOdload : public InstructionInfo { // 0x18 -- 24
		OPINFOdload() : InstructionInfo(24, "dload", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ... →..., value, The index is an unsigned byte. Both index and index+1 must be indices into the local variable array
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index to the local double variable
	};

	struct OPINFOaload : public InstructionInfo { // 0x19 -- 25
		OPINFOaload() : InstructionInfo(25, "aload", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * OpStack  ... → ..., objectref, The index is an unsigned byte that must be an index into the local variable array of the current frame
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< index of the reference to the local variable to be loaded
	};

	struct OPINFOiload_0 : public InstructionInfo { // 0x1A -- 26
		OPINFOiload_0() : InstructionInfo(26, "iload_0") {}
	};

	struct OPINFOiload_1 : public InstructionInfo { // 0x1B -- 27
		OPINFOiload_1() : InstructionInfo(27, "iload_1") {}
	};

	struct OPINFOiload_2 : public InstructionInfo { // 0x1C -- 28
		OPINFOiload_2() : InstructionInfo(28, "iload_2") {}
	};

	struct OPINFOiload_3 : public InstructionInfo { // 0x1D -- 29
		OPINFOiload_3() : InstructionInfo(29, "iload_3") {}
	};

	struct OPINFOlload_0 : public InstructionInfo { // 0x1E -- 30
		OPINFOlload_0() : InstructionInfo(30, "lload_0") {}
	};

	struct OPINFOlload_1 : public InstructionInfo { // 0x1F -- 31
		OPINFOlload_1() : InstructionInfo(31, "lload_1") {}
	};

	struct OPINFOlload_2 : public InstructionInfo { // 0x20 -- 32
		OPINFOlload_2() : InstructionInfo(32, "lload_2") {}
	};

	struct OPINFOlload_3 : public InstructionInfo { // 0x21 -- 33
		OPINFOlload_3() : InstructionInfo(33, "lload_3") {}
	};

	struct OPINFOfload_0 : public InstructionInfo { // 0x22 -- 34
		OPINFOfload_0() : InstructionInfo(34, "fload_0") {}
	};

	struct OPINFOfload_1 : public InstructionInfo { // 0x23 -- 35
		OPINFOfload_1() : InstructionInfo(35, "fload_1") {}
	};

	struct OPINFOfload_2 : public InstructionInfo { // 0x24 -- 36
		OPINFOfload_2() : InstructionInfo(36, "fload_2") {}
	};

	struct OPINFOfload_3 : public InstructionInfo { // 0x25 -- 37
		OPINFOfload_3() : InstructionInfo(37, "fload_3") {}
	};

	struct OPINFOdload_0 : public InstructionInfo { // 0x26 -- 38
		OPINFOdload_0() : InstructionInfo(38, "dload_0") {}
	};

	struct OPINFOdload_1 : public InstructionInfo { // 0x27 -- 39
		OPINFOdload_1() : InstructionInfo(39, "dload_1") {}
	};

	struct OPINFOdload_2 : public InstructionInfo { // 0x28 -- 40
		OPINFOdload_2() : InstructionInfo(40, "dload_2") {}
	};

	struct OPINFOdload_3 : public InstructionInfo { // 0x29 -- 41
		OPINFOdload_3() : InstructionInfo(41, "dload_3") {}
	};

	struct OPINFOaload_0 : public InstructionInfo { // 0x2A -- 42
		OPINFOaload_0() : InstructionInfo(42, "aload_0") {}
	};

	struct OPINFOaload_1 : public InstructionInfo { // 0x2B -- 43
		OPINFOaload_1() : InstructionInfo(43, "aload_1") {}
	};

	struct OPINFOaload_2 : public InstructionInfo { // 0x2C -- 44
		OPINFOaload_2() : InstructionInfo(44, "aload_2") {}
	};

	struct OPINFOaload_3 : public InstructionInfo { // 0x2D -- 45
		OPINFOaload_3() : InstructionInfo(45, "aload_3") {}
	};

	struct OPINFOiaload : public InstructionInfo { // 0x2E -- 46
		OPINFOiaload() : InstructionInfo(46, "iaload") {}
	};

	struct OPINFOlaload : public InstructionInfo { // 0x2F -- 47
		OPINFOlaload() : InstructionInfo(47, "laload") {}
	};

	struct OPINFOfaload : public InstructionInfo { // 0x30 -- 48
		OPINFOfaload() : InstructionInfo(48, "faload") {}
	};

	struct OPINFOdaload : public InstructionInfo { // 0x31 -- 49
		OPINFOdaload() : InstructionInfo(49, "daload") {}
	};

	struct OPINFOaaload : public InstructionInfo { // 0x32 -- 50
		OPINFOaaload() : InstructionInfo(50, "aaload") {}
	};

	struct OPINFObaload : public InstructionInfo { // 0x33 -- 51
		OPINFObaload() : InstructionInfo(51, "baload") {}
	};

	struct OPINFOcaload : public InstructionInfo { // 0x34 -- 52
		OPINFOcaload() : InstructionInfo(52, "caload") {}
	};

	struct OPINFOsaload : public InstructionInfo { // 0x35 -- 53
		OPINFOsaload() : InstructionInfo(53, "saload") {}
	};

	//Stores 0x36,54 -> 0x56,86
	struct OPINFOistore : public InstructionInfo { // 0x36 -- 54
		OPINFOistore() : InstructionInfo(54, "istore", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * OpStack ..., value → ... , The index is an unsigned byte that must be an index into the local variable array of the current frame
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index to the local variable
	};

	struct OPINFOlstore : public InstructionInfo { // 0x37 -- 55
		OPINFOlstore() : InstructionInfo(55, "lstore", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * OpStack ..., value → ... , The index is an unsigned byte. Both index and index+1 must be indices into the local variable array of the current frame
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index to the local variable
	};

	struct OPINFOfstore : public InstructionInfo { // 0x38 -- 56
		OPINFOfstore() : InstructionInfo(56, "fstore", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * OpStack ..., value → ... , The index is an unsigned byte that must be an index into the local variable array of the current frame
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index of the local float variable
	};

	struct OPINFOdstore : public InstructionInfo { // 0x39 -- 57
		OPINFOdstore() : InstructionInfo(57, "dstore", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * OpStack ..., value → ... , The index is an unsigned byte. Both index and index+1 must be indices into the local variable array of the current frame

		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index to the local double variable
	};

	struct OPINFOastore : public InstructionInfo { // 0x3A -- 58
		OPINFOastore() : InstructionInfo(58, "astore", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * OpStack ..., objectref → ... , The index is an unsigned byte that must be an index into the local variable array of the current frame
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index of the local variable that will store the reference
	};

	struct OPINFOistore_0 : public InstructionInfo { // 0x3B -- 59
		OPINFOistore_0() : InstructionInfo(, "istore_0") {}
	};

	struct OPINFOistore_1 : public InstructionInfo { // 0x3C -- 60
		OPINFOistore_1() : InstructionInfo(, "istore_1") {}
	};

	struct OPINFOistore_2 : public InstructionInfo { // 0x3D -- 61
		OPINFOistore_2() : InstructionInfo(, "istore_2") {}
	};

	struct OPINFOistore_3 : public InstructionInfo { // 0x3E -- 62
		OPINFOistore_3() : InstructionInfo(, "istore_3") {}
	};

	struct OPINFOlstore_0 : public InstructionInfo { // 0x3F -- 63
		OPINFOlstore_0() : InstructionInfo(, "lstore_0") {}
	};

	struct OPINFOlstore_1 : public InstructionInfo { // 0x40 -- 64
		OPINFOlstore_1() : InstructionInfo(, "lstore_1") {}
	};

	struct OPINFOlstore_2 : public InstructionInfo { // 0x41 -- 65
		OPINFOlstore_2() : InstructionInfo(, "lstore_2") {}
	};

	struct OPINFOlstore_3 : public InstructionInfo { // 0x42 -- 66
		OPINFOlstore_3() : InstructionInfo(, "lstore_3") {}
	};

	struct OPINFOfstore_0 : public InstructionInfo { // 0x43 -- 67
		OPINFOfstore_0() : InstructionInfo(, "fstore_0") {}
	};

	struct OPINFOfstore_1 : public InstructionInfo { // 0x44 -- 68
		OPINFOfstore_1() : InstructionInfo(, "fstore_1") {}
	};

	struct OPINFOfstore_2 : public InstructionInfo { // 0x45 -- 69
		OPINFOfstore_2() : InstructionInfo(, "fstore_2") {}
	};

	struct OPINFOfstore_3 : public InstructionInfo { // 0x46 -- 70
		OPINFOfstore_3() : InstructionInfo(, "fstore_3") {}
	};

	struct OPINFOdstore_0 : public InstructionInfo { // 0x47 -- 71
		OPINFOdstore_0() : InstructionInfo(, "dstore_0") {}
	};

	struct OPINFOdstore_1 : public InstructionInfo { // 0x48 -- 72
		OPINFOdstore_1() : InstructionInfo(, "dstore_1") {}
	};

	struct OPINFOdstore_2 : public InstructionInfo { // 0x49 -- 73
		OPINFOdstore_2() : InstructionInfo(, "dstore_2") {}
	};

	struct OPINFOdstore_3 : public InstructionInfo { // 0x4A -- 74
		OPINFOdstore_3() : InstructionInfo(, "dstore_3") {}
	};

	struct OPINFOastore_0 : public InstructionInfo { // 0x4B -- 75
		OPINFOastore_0() : InstructionInfo(, "astore_0") {}
	};

	struct OPINFOastore_1 : public InstructionInfo { // 0x4C -- 76
		OPINFOastore_1() : InstructionInfo(, "astore_1") {}
	};

	struct OPINFOastore_2 : public InstructionInfo { // 0x4D -- 77
		OPINFOastore_2() : InstructionInfo(, "astore_2") {}
	};

	struct OPINFOastore_3 : public InstructionInfo { // 0x4E -- 78
		OPINFOastore_3() : InstructionInfo(, "astore_3") {}
	};

	struct OPINFOiastore : public InstructionInfo { // 0x4F -- 79
		OPINFOiastore() : InstructionInfo(, "iastore") {}
	};

	struct OPINFOlastore : public InstructionInfo { // 0x50 -- 80
		OPINFOlastore() : InstructionInfo(, "lastore") {}
	};

	struct OPINFOfastore : public InstructionInfo { // 0x51 -- 81
		OPINFOfastore() : InstructionInfo(, "fastore") {}
	};

	struct OPINFOdastore : public InstructionInfo { // 0x52 -- 82
		OPINFOdastore() : InstructionInfo(, "dastore") {}
	};

	struct OPINFOaastore : public InstructionInfo { // 0x53 -- 83
		OPINFOaastore() : InstructionInfo(, "aastore") {}
	};

	struct OPINFObastore : public InstructionInfo { // 0x54 -- 84
		OPINFObastore() : InstructionInfo(, "bastore") {}
	};

	struct OPINFOcastore : public InstructionInfo { // 0x55 -- 85
		OPINFOcastore() : InstructionInfo(, "castore") {}
	};

	struct OPINFOsastore : public InstructionInfo { // 0x56 -- 86
		OPINFOsastore() : InstructionInfo(, "sastore") {}
	};

	// Stack 0x57,87 -> 0x5F,95
	struct OPINFOpop : public InstructionInfo { // 0x57 -- 87
		OPINFOpop() : InstructionInfo(, "pop") {}
	};

	struct OPINFOpop2 : public InstructionInfo { // 0x58 -- 88
		OPINFOpop2() : InstructionInfo(, "pop2") {}
	};

	struct OPINFOdup : public InstructionInfo { // 0x59 -- 89
		OPINFOdup() : InstructionInfo(, "dup") {}
	};

	struct OPINFOdup_x1 : public InstructionInfo { // 0x5A -- 90
		OPINFOdup_x1() : InstructionInfo(, "dup_x1") {}
	};

	struct OPINFOdup_x2 : public InstructionInfo { // 0x5B -- 91
		OPINFOdup_x2() : InstructionInfo(, "dup_x2") {}
	};

	struct OPINFOdup2 : public InstructionInfo { // 0x5C -- 92
		OPINFOdup2() : InstructionInfo(, "dup2") {}
	};

	struct OPINFOdup2_x1 : public InstructionInfo { // 0x5D -- 93
		OPINFOdup2_x1() : InstructionInfo(, "dup2_x1") {}
	};

	struct OPINFOdup2_x2 : public InstructionInfo { // 0x5E -- 94
		OPINFOdup2_x2() : InstructionInfo(, "dup2_x2") {}
	};

	struct OPINFOswap : public InstructionInfo { // 0x5F -- 95
		OPINFOswap() : InstructionInfo(, "swap") {}
	};

	// Math 0x60,96 -> 0x84,132
	struct OPINFOiadd : public InstructionInfo { // 0x60 -- 96
		OPINFOiadd() : InstructionInfo(, "iadd") {}
	};

	struct OPINFOladd : public InstructionInfo { // 0x61 -- 97
		OPINFOladd() : InstructionInfo(, "ladd") {}
	};

	struct OPINFOfadd : public InstructionInfo { // 0x62 -- 98
		OPINFOfadd() : InstructionInfo(, "fadd") {}
	};

	struct OPINFOdadd : public InstructionInfo { // 0x63 -- 99
		OPINFOdadd() : InstructionInfo(, "dadd") {}
	};

	struct OPINFOisub : public InstructionInfo { // 0x64 -- 100
		OPINFOisub() : InstructionInfo(, "isub") {}
	};

	struct OPINFOlsub : public InstructionInfo { // 0x65 -- 101
		OPINFOlsub() : InstructionInfo(, "lsub") {}
	};

	struct OPINFOfsub : public InstructionInfo { // 0x66 -- 102
		OPINFOfsub() : InstructionInfo(, "fsub") {}
	};

	struct OPINFOdsub : public InstructionInfo { // 0x67 -- 103
		OPINFOdsub() : InstructionInfo(, "dsub") {}
	};

	struct OPINFOimul : public InstructionInfo { // 0x68 -- 104
		OPINFOimul() : InstructionInfo(, "imul") {}
	};

	struct OPINFOlmul : public InstructionInfo { // 0x69 -- 105
		OPINFOlmul() : InstructionInfo(, "lmul") {}
	};

	struct OPINFOfmul : public InstructionInfo { // 0x6A -- 106
		OPINFOfmul() : InstructionInfo(, "fmul") {}
	};

	struct OPINFOdmul : public InstructionInfo { // 0x6B -- 107
		OPINFOdmul() : InstructionInfo(, "dmul") {}
	};

	struct OPINFOidiv : public InstructionInfo { // 0x6C -- 108
		OPINFOidiv() : InstructionInfo(, "idiv") {}
	};

	struct OPINFOldiv : public InstructionInfo { // 0x6D -- 109
		OPINFOldiv() : InstructionInfo(, "ldiv") {}
	};

	struct OPINFOfdiv : public InstructionInfo { // 0x6E -- 110
		OPINFOfdiv() : InstructionInfo(, "fdiv") {}
	};

	struct OPINFOddiv : public InstructionInfo { // 0x6F -- 111
		OPINFOddiv() : InstructionInfo(, "ddiv") {}
	};

	struct OPINFOirem : public InstructionInfo { // 0x70 -- 112
		OPINFOirem() : InstructionInfo(, "irem") {}
	};

	struct OPINFOlrem : public InstructionInfo { // 0x71 -- 113
		OPINFOlrem() : InstructionInfo(, "lrem") {}
	};

	struct OPINFOfrem : public InstructionInfo { // 0x72 -- 114
		OPINFOfrem() : InstructionInfo(, "frem") {}
	};

	struct OPINFOdrem : public InstructionInfo { // 0x73 -- 115
		OPINFOdrem() : InstructionInfo(, "drem") {}
	};

	struct OPINFOineg : public InstructionInfo { // 0x74 -- 116
		OPINFOineg() : InstructionInfo(, "ineg") {}
	};

	struct OPINFOlneg : public InstructionInfo { // 0x75 -- 117
		OPINFOlneg() : InstructionInfo(, "lneg") {}
	};

	struct OPINFOfneg : public InstructionInfo { // 0x76 -- 118
		OPINFOfneg() : InstructionInfo(, "fneg") {}
	};

	struct OPINFOdneg : public InstructionInfo { // 0x77 -- 119
		OPINFOdneg() : InstructionInfo(, "dneg") {}
	};

	struct OPINFOishl : public InstructionInfo { // 0x78 -- 120
		OPINFOishl() : InstructionInfo(, "ishl") {}
	};

	struct OPINFOlshl : public InstructionInfo { // 0x79 -- 121
		OPINFOlshl() : InstructionInfo(, "lshl") {}
	};

	struct OPINFOishr : public InstructionInfo { // 0x7A -- 122
		OPINFOishr() : InstructionInfo(, "ishr") {}
	};

	struct OPINFOlshr : public InstructionInfo { // 0x7B -- 123
		OPINFOlshr() : InstructionInfo(, "lshr") {}
	};

	struct OPINFOiushr : public InstructionInfo { // 0x7C -- 124
		OPINFOiushr() : InstructionInfo(, "iushr") {}
	};

	struct OPINFOlushr : public InstructionInfo { // 0x7D -- 125
		OPINFOlushr() : InstructionInfo(, "lushr") {}
	};

	struct OPINFOiand : public InstructionInfo { // 0x7E -- 126
		OPINFOiand() : InstructionInfo(, "iand") {}
	};

	struct OPINFOland : public InstructionInfo { // 0x7F -- 127
		OPINFOland() : InstructionInfo(, "land") {}
	};

	struct OPINFOior : public InstructionInfo { // 0x80 -- 128
		OPINFOior() : InstructionInfo(, "ior") {}
	};

	struct OPINFOlor : public InstructionInfo { // 0x81 --129
		OPINFOlor() : InstructionInfo(, "lor") {}
	};

	struct OPINFOixor : public InstructionInfo { // 0x82 -- 130
		OPINFOixor() : InstructionInfo(, "ixor") {}
	};

	struct OPINFOlxor : public InstructionInfo { // 0x83 -- 131
		OPINFOlxor() : InstructionInfo(, "lxor") {}
	};

	struct OPINFOiinc : public InstructionInfo { // 0x84 -- 132
		OPINFOiinc() : InstructionInfo(132, "iinc", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack -> no changes, int index int 		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index;		///< Index of the local variable
		i1 constant;	///< Value to be incremented to the local variable
	};

	//Conversations 0x85,133 -> 0x93,147
	struct OPINFOi2l : public InstructionInfo { // 0x85 -- 133
		OPINFOi2l() : InstructionInfo(, "i2l") {}
	};

	struct OPINFOi2f : public InstructionInfo { // 0x86 -- 134
		OPINFOi2f() : InstructionInfo(, "i2f") {}
	};

	struct OPINFOi2d : public InstructionInfo { // 0x87 -- 135
		OPINFOi2d() : InstructionInfo(, "i2d") {}
	};

	struct OPINFOl2i : public InstructionInfo { // 0x88 -- 136
		OPINFOl2i() : InstructionInfo(, "l2i") {}
	};

	struct OPINFOl2f : public InstructionInfo { // 0x89 -- 137
		OPINFOl2f() : InstructionInfo(, "l2f") {}
	};

	struct OPINFOl2d : public InstructionInfo { // 0x8A -- 138
		OPINFOl2d() : InstructionInfo(, "l2d") {}
	};

	struct OPINFOf2i : public InstructionInfo { // 0x8B -- 139
		OPINFOf2i() : InstructionInfo(, "f2i") {}
	};

	struct OPINFOf2l : public InstructionInfo { // 0x8C -- 140
		OPINFOf2l() : InstructionInfo(, "f2l") {}
	};

	struct OPINFOf2d : public InstructionInfo { // 0x8D -- 141
		OPINFOf2d() : InstructionInfo(, "f2d") {}
	};

	struct OPINFOd2i : public InstructionInfo { // 0x8E -- 142
		OPINFOd2i() : InstructionInfo(, "d2i") {}
	};

	struct OPINFOd2l : public InstructionInfo { // 0x8F -- 143
		OPINFOd2l() : InstructionInfo(, "d2l") {}
	};

	struct OPINFOd2f : public InstructionInfo { // 0x90 -- 144
		OPINFOd2f() : InstructionInfo(, "d2f") {}
	};

	struct OPINFOi2b : public InstructionInfo { // 0x91 -- 145
		OPINFOi2b() : InstructionInfo(, "i2b") {}
	};

	struct OPINFOi2c : public InstructionInfo { // 0x92 -- 146
		OPINFOi2c() : InstructionInfo(, "i2c") {}
	};

	struct OPINFOi2s : public InstructionInfo { // 0x93 -- 147
		OPINFOi2s() : InstructionInfo(, "i2s") {}
	};

	// Comparisons 0x94,148 -> 0xA6,166
	struct OPINFOlcmp : public InstructionInfo { // 0x94 -- 148
		OPINFOlcmp() : InstructionInfo(, "lcmp") {}
	};

	struct OPINFOfcmpl : public InstructionInfo { // 0x95 -- 149
		OPINFOfcmpl() : InstructionInfo(, "fcmpl") {}
	};

	struct OPINFOfcmpg : public InstructionInfo { // 0x96 -- 150
		OPINFOfcmpg() : InstructionInfo(, "fcmpg") {}
	};

	struct OPINFOdcmpl : public InstructionInfo { // 0x97 -- 151
		OPINFOdcmpl() : InstructionInfo(, "dcmpl") {}
	};

	struct OPINFOdcmpg : public InstructionInfo { // 0x98 -- 152
		OPINFOdcmpg() : InstructionInfo(, "dcmpg") {}
	};

	struct OPINFOifeq : public InstructionInfo { // 0x99 -- 153
		OPINFOifeq() : InstructionInfo(, "ifeq", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ..., branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOifne : public InstructionInfo { // 0x9A -- 154
		OPINFOifne() : InstructionInfo(, "ifne", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ..., branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOiflt : public InstructionInfo { // 0x9B -- 155
		OPINFOiflt() : InstructionInfo(, "iflt", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ..., branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOifge : public InstructionInfo { // 0x9C -- 156
		OPINFOifge() : InstructionInfo(, "ifge", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ..., branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOifgt : public InstructionInfo { // 0x9D -- 157
		OPINFOifgt() : InstructionInfo(, "ifgt", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ..., branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOifle : public InstructionInfo { // 0x9E -- 158
		OPINFOifle() : InstructionInfo(, "ifle", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ..., branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_icmpeq : public InstructionInfo { // 0x9F -- 159
		OPINFOif_icmpeq() : InstructionInfo(, "if_icmpeq", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ..., branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_icmpne : public InstructionInfo { // 0xA0 -- 160
		OPINFOif_icmpne() : InstructionInfo(, "if_icmpne", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value1, value2 → ...,branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_icmplt : public InstructionInfo { // 0xA1 - 161
		OPINFOif_icmplt() : InstructionInfo(, "if_icmplt", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value1, value2 →... , branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_icmpge : public InstructionInfo { // 0xA2 -- 162
		OPINFOif_icmpge() : InstructionInfo(, "if_icmpge", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value1, value2 →... , branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_icmpgt : public InstructionInfo { // 0xA3 -- 163
		OPINFOif_icmpgt() : InstructionInfo(, "if_icmpgt", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value1, value2 →... , branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_icmple : public InstructionInfo { // 0xA4 -- 164
		OPINFOif_icmple() : InstructionInfo(, "if_icmple", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value1, value2 → ... , branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_acmpeq : public InstructionInfo { // 0xA5 -- 165
		OPINFOif_acmpeq() : InstructionInfo(, "if_acmpeq", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value1, value2 → ... , branchbyte1 branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOif_acmpne : public InstructionInfo { // 0xA6 -- 166
		OPINFOif_acmpne() : InstructionInfo(, "if_acmpne", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value1, value2 → ... ,  branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	//Control 0xA7,167 -> 0xB1,177
	struct OPINFOgoto : public InstructionInfo { // 0xA7 -- 167
		OPINFOgoto() : InstructionInfo(, "goto", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack no change , branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOjsr : public InstructionInfo { // 0xA8 -- 168
		OPINFOjsr() : InstructionInfo(, "jsr", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ... → ..., address , branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to a subroutine
	};

	struct OPINFOret : public InstructionInfo { // 0xA9 -- 169
		OPINFOret() : InstructionInfo(, "ret", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack no change
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 index; ///< Index to the local variable
	};

	struct OPINFOtableswitch : public InstructionInfo { // 0xAA -- 170
		OPINFOtableswitch() : InstructionInfo(, "tableswitch", 16) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack  ..., index → ... ,
		 * <0-3 byte pad>
		 * defaultbyte1
		 * defaultbyte2
		 * defaultbyte3
		 * defaultbyte4
		 * lowbyte1
		 *  lowbyte2
		 * lowbyte3
		 * lowbyte4
		 *  highbyte1
		 *  highbyte2
		 *  highbyte3
		 *  highbyte4
		 *   jump offsets...
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		//> default
		i4 defaultbyte;

		//> low
		i4 low;

		//> high
		i4 high;

		//> Jump Offsets
		std::vector<i4> jumpOffsets;
	};

	struct OPINFOlookupswitch : public InstructionInfo { // 0xAB -- 171
		OPINFOlookupswitch() : InstructionInfo(, "lookupswitch", 8) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., key → ...
		 * <0-3 byte pad>
		 * defaultbyte1
		 * defaultbyte2
		 * defaultbyte3
		 * defaultbyte4
		 * npairs1
		 * npairs2
		 * npairs3
		 * npairs4
		 *  match-offset pairs...
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		//> default
		i4 defaultbyte;

		//> qtd of pairs
		i4 npairs;

		//> Jump Offsets
		std::map<i4, i4> pairs;
	};

	struct OPINFOireturn : public InstructionInfo { // 0xAC -- 172
		OPINFOireturn() : InstructionInfo(, "ireturn") {}
	};

	struct OPINFOlreturn : public InstructionInfo { // 0xAD -- 173
		OPINFOlreturn() : InstructionInfo(, "lreturn") {}
	};

	struct OPINFOfreturn : public InstructionInfo { // 0xAE -- 174
		OPINFOfreturn() : InstructionInfo(, "freturn") {}
	};

	struct OPINFOdreturn : public InstructionInfo { // 0xAF -- 175
		OPINFOdreturn() : InstructionInfo(, "dreturn") {}
	};

	struct OPINFOareturn : public InstructionInfo { // 0xB0 -- 176
		OPINFOareturn() : InstructionInfo(, "areturn") {}
	};

	struct OPINFOreturn : public InstructionInfo { // 0xB1 -- 177
		OPINFOreturn() : InstructionInfo(, "return") {}
	};

	//References 0xB2,178 -> 0xC3,195
	struct OPINFOgetstatic : public InstructionInfo { // 0xB2 -- 178
		OPINFOgetstatic() : InstructionInfo(, "getstatic", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., → ..., value,indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index to the field reference in the constant pool
	};

	struct OPINFOputstatic : public InstructionInfo { // 0xB3 -- 179
		OPINFOputstatic() : InstructionInfo(, "putstatic", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ... ,indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool to the field reference
	};

	struct OPINFOgetfield : public InstructionInfo { // 0xB4 -- 180
		OPINFOgetfield() : InstructionInfo(, "getfield", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 *Opstack ..., objectref → ..., value ,indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index to the field reference in the constant pool
	};

	struct OPINFOputfield : public InstructionInfo { // 0xB5 -- 181
		OPINFOputfield() : InstructionInfo(, "putfield", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., objectref, value → ... , indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool to the field reference
	};

	struct OPINFOinvokevirtual : public InstructionInfo { // 0xB6 -- 182
		OPINFOinvokevirtual() : InstructionInfo(, "invokevirtual", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., objectref, [arg1, [arg2 ...]] → ... , indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool to the method reference
	};

	struct OPINFOinvokespecial : public InstructionInfo { // 0xB7 -- 183
		OPINFOinvokespecial() : InstructionInfo(, "invokespecial", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., objectref, [arg1, [arg2 ...]] → ... , indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool to the method reference
	};

	struct OPINFOinvokestatic : public InstructionInfo { // 0xB8 -- 184
		OPINFOinvokestatic() : InstructionInfo(, "invokestatic", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., [arg1, [arg2 ...]] → ...
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool to the method reference
	};

	struct OPINFOinvokeinterface : public InstructionInfo { // 0xB9 -- 185
		OPINFOinvokeinterface() : InstructionInfo(, "invokeinterface", 4) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., objectref, [arg1, [arg2 ...]] → ... , indexbyte1 + indexbyte2 , count , 0
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index;	///< Index in the constant pool to the interface method
		u1 count;	///< Count operand that must not be zero
	};

	struct OPINFOinvokedynamic : public InstructionInfo { // 0xBA - - 186
		OPINFOinvokedynamic() : InstructionInfo(, "invokedynamic", 4) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., [arg1, [arg2 ...]] → ...
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool
	};

	struct OPINFOnew : public InstructionInfo { // 0xBB -- 187
		OPINFOnew() : InstructionInfo(, "new", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ... → ..., objectref indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool to the class reference
	};

	struct OPINFOnewarray : public InstructionInfo { // 0xBC -- 188
		OPINFOnewarray() : InstructionInfo(, "newarray", 1) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., count → ..., arrayref , atype
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u1 atype; ///< Code that indicates the type of array to create
	};

	struct OPINFOanewarray : public InstructionInfo { // 0xBD -- 189
		OPINFOanewarray() : InstructionInfo(, "anewarray", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opcode ..., count → ..., arrayref , indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< index of the reference to the class that identifies the component type
	};

	struct OPINFOarraylength : public InstructionInfo { // 0xBE -- 190
		OPINFOarraylength() : InstructionInfo(, "arraylength") {}
	};

	struct OPINFOathrow : public InstructionInfo { // 0xBF -- 191
		OPINFOathrow() : InstructionInfo(, "athrow") {}
	};

	struct OPINFOcheckcast : public InstructionInfo { // 0xC0 -- 192
		OPINFOcheckcast() : InstructionInfo(, "checkcast", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., objectref → ..., objectref ,  indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index of the class reference in the constant pool
	};

	struct OPINFOinstanceof : public InstructionInfo { // 0xC1 -- 193
		OPINFOinstanceof() : InstructionInfo(, "instanceof", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., objectref → ..., result, indexbyte1 + indexbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index to the class reference in the constant pool
	};

	struct OPINFOmonitorenter : public InstructionInfo { // 0xC2 -- 194
		OPINFOmonitorenter() : InstructionInfo(, "monitorenter") {}
	};

	struct OPINFOmonitorexit : public InstructionInfo { // 0xC3 -- 195
		OPINFOmonitorexit() : InstructionInfo(, "monitorexit") {}
	};

	//Extended 0xC4,196 -> 0xC9,201
	struct OPINFOwide : public InstructionInfo { // 0xC4 -- 196
		OPINFOwide() : InstructionInfo(, "wide", 3) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack Same as modified instruction
		 * iinc
		 * indexbyte1
		 * indexbyte2
		 * constbyte1
		 * constbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		//> the opcode to execute wide
		u1 opcode;

		//> index
		u2 index;

		//> count byte
		u2 countbyte;
	};

	struct OPINFOmultianewarray : public InstructionInfo { // 0xC5 -- 197
		OPINFOmultianewarray() : InstructionInfo(, "multianewarray", 3) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., count1, [count2, ...] → ..., arrayref
		 * indexbyte1
		 * indexbyte2
		 * dimensions
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		u2 index; ///< Index in the constant pool
		u1 dimensions; // Number of dimensions of the array to be created, must be greater than or equal to 1
	};

	struct OPINFOifnull : public InstructionInfo { // 0xC6 -- 198
		OPINFOifnull() : InstructionInfo(, "ifnull", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ..., value → ... , branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;

		i2 branchoffset; ///< Offset to the next instruction
	};

	struct OPINFOifnonnull : public InstructionInfo { // 0xC7 -- 199
		i2 branchoffset; ///< Offset to the next instruction

		OPINFOifnonnull() : InstructionInfo(, "ifnonnull", 2) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack  ..., value → ...,branchbyte1 + branchbyte2
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;
	};

	struct OPINFOgoto_w : public InstructionInfo { // 0xC8 -- 200
		i4 branchoffset; ///< Offset to the next instruction

		OPINFOgoto_w() : InstructionInfo(, "goto_w", 4) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack no changes
		 * branchbyte1 + branchbyte2 + branchbyte3 + branchbyte4
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;
	};

	struct OPINFOjsr_w : public InstructionInfo { // 0xC9 -- 201
		i4 branchoffset; ///< Offset to a subroutine

		OPINFOjsr_w() : InstructionInfo(, "jsr_w", 4) {}

		void printToStream(std::ostream &, std::string &, ConstantPool &) override;

		/**
		 * Opstack ... → ..., address , branchbyte1 + branchbyte2 + branchbyte3 + branchbyte4
		 * @param idx index to the data vector
		 * @param data vector of bytes containing the arguments
		 * @return unsigned int number of arguments read
		 */
		uint32_t fillParams(uint32_t, std::vector<u1> &) override;
	};

	//Reserved 0xca,202 -> 0xff,255
	/**
	 * This opcode have been reserved and may be used only inside a
	 * Java Virtual Machine implementation. It cannot appear in
	 * valid class files. In this case, we didn't implemented this
	 * opcode.
	 */
	struct OPINFObreakpoint : public InstructionInfo { // 0xca -- 202
		OPINFObreakpoint() : InstructionInfo(, "breakpoint") {}
	};

	/**
	 * This opcode have been reserved and may be used only inside a
	 * Java Virtual Machine implementation. It cannot appear in
	 * valid class files. In this case, we didn't implemented this
	 * opcode.
	 */
	struct OPINFOimpdep1 : public InstructionInfo { // 0xFE -- 254
		OPINFOimpdep1() : InstructionInfo(, "impdep1") {}
	};

	/**
	 * This opcode have been reserved and may be used only inside a
	 * Java Virtual Machine implementation. It cannot appear in
	 * valid class files. In this case, we didn't implemented this
	 * opcode.
	 */
	struct OPINFOimpdep2 : public InstructionInfo { // 0xFF -- 255
		OPINFOimpdep2() : InstructionInfo(, "impdep2") {}
	};

}
