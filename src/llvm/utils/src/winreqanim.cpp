#include "../include/winreqanim.hpp"

// simply calls our dynamic callback - done so that the callback can be changed and is not set to be a static function
extern "C" void __wasm_export_winreqanim_callback_execute() {
	__wasm_winreqanim_callback();
}

// sets the callback to one we'd need and then calls the window.requestAnimationFrame function
void __wasm_set_winreqanim_callback(void (*_cb)()) {
	__wasm_winreqanim_callback = _cb;
	__wasm_import_winreqanim_call();
}