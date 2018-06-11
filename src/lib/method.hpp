#pragma once
#include <cstdint>
#include <vector>
#include "bit.hpp"
#include "attribute.hpp"
#include "constant_pool.hpp"

namespace jvm {

	class MethodInfo {
	public:
		uint16_t access_flags;                 ///< Access permission to and properties of this field

		uint16_t name_index;                   ///< Valid index into the constant pool table

		uint16_t descriptor_index;             ///< Type of a class, instance, or local variable

		AttributeInfo attributes;              ///< An attribute structure

		/**
		 * Constructor default
		 */
		MethodInfo() = default;

		/**
		 * Reader
		 */
		explicit MethodInfo(Reader &, ConstantPool &cp);

		/**
		 * Print the content of the class
		 * @param
		 * @param
		 */
		void PrintToStream(std::ostream &, ConstantPool &, const std::string &prefix);

		/**
		 * Read from a file
		 * @param
		 */
		void Read(Reader &, ConstantPool &cp);

	private:

		/**
		 * Print the content the flags of the method
		 * @param
		 * @param
		 */
		void PrintFlags(std::ostream &, uint32_t);
	};

	namespace methods {

		enum Flags : uint16_t {
			PUBLIC       = 0x0001,  // Declared public; may be accessed from outside its package.
			PRIVATE	     = 0x0002,  // Declared private; accessible only within the defining class.
			PROTECTED    = 0x0004,  // Declared protected; may be accessed within subclasses.
			STATIC       = 0x0008,  // Declared static.
			FINAL        = 0x0010,	// Declared final; no subclasses allowed.
			SYNCHRONIZED = 0x0020,	// Declared synchronized; invocation is wrapped by a monitor use.
			BRIDGE       = 0x0040,  // A bridge method, generated by the compiler.
			VARARGS      = 0x0080,  // Declared with variable number of arguments.
			NATIVE       = 0x0100,  // Declared native; implemented in a language other than Java.
			ABSTRACT     = 0x0400,  // Declared abstract; must not be instantiated.
			STRICT       = 0x0800,  // Declared strictfp; floating-point mode is FP-strict.
			SYNTHETIC    = 0x1000   // Declared synthetic; not present in the source code.
		};

	}
}