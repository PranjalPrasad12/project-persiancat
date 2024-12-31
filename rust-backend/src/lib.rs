use std::ffi::{CStr, CString};
use std::ptr;

#[no_mangle]
pub extern "C" fn render_html(html: *const i8) -> i32 {
    if html.is_null() {
        return -1; // Error: Null pointer
    }

    // Convert the raw C string to a Rust string slice
    let c_str = unsafe { CStr::from_ptr(html) };
    let rust_str = c_str.to_str().unwrap_or("");

    // For simplicity, just print the HTML content. You can replace this with
    // actual Servo rendering code, using Servo's APIs to render the content.
    println!("Rendering HTML: {}", rust_str);

    // Example: Simulate rendering with Servo (this can be extended to real functionality)
    // This is where you'd normally pass `rust_str` to Servo for actual rendering.

    0 // Success
}

#[no_mangle]
pub extern "C" fn free_html_string(html: *mut i8) {
    if !html.is_null() {
        unsafe {
            // Free the memory allocated for the string if needed
            let _ = CString::from_raw(html);
        }
    }
}
