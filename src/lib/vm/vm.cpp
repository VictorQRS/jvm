#include <iostream>
#include <iomanip>
#include "vm/vm.hpp"
#include "vm/frame.hpp"

namespace jvm {

	VM::VM() {
		PC = 0;
	}

	void VM::run(std::vector<_Class> &cl) {}

	void VM::runMethod(_Class &) {}

}