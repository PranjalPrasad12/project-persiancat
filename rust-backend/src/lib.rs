use std::ffi::{CStr, CString};

#[no_mangle]
pub extern "C" fn render_html(html: *const i8) -> i32 {
    if html.is_null() {
        return -1; // Error: Null pointer
    }

    // Convert the raw C string to a Rust string slice
    let c_str = unsafe { CStr::from_ptr(html) };
    let rust_str = c_str.to_str().unwrap_or("");

    // Here, you'd integrate Servo's rendering code
    println!("Rendering HTML: {}", rust_str);

    // Simulate rendering (replace with real Servo call)
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
