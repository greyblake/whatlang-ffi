extern crate whatlang;
extern crate libc;

use whatlang::{detect, Lang, Info, Script};
use std::ffi::{CStr, CString};
use std::os::raw::c_char;

#[repr(C)]
#[derive(Debug)]
pub struct CInfo {
    lang: Lang,
    script: Script,
    confidence: f64
}

#[no_mangle]
pub extern fn whatlang_detect(ptr: *const c_char, cinfo: &mut CInfo) -> u8 {
    let cs = unsafe { CStr::from_ptr(ptr) };

    match cs.to_str() {
        Ok(s) => {
            let res = detect(s);
            match res {
                Some(info) => {
                    cinfo.lang = info.lang();
                    cinfo.script = info.script();
                    cinfo.confidence = info.confidence();
                    return 0;
                },
                None => {
                    // Could not detect language
                    return 1;
                }
            }
        },
        Err(_) => {
            // Bad string pointer
            return 2;
        }
    }
}

#[no_mangle]
pub extern fn whatlang_lang_eng_name(lang: Lang, buffer_ptr: *mut c_char) {
    // Here unwrap is always safe, because whatlang always returns a valid str
    let s = CString::new(lang.eng_name()).unwrap();
    unsafe {
        libc::strcpy(buffer_ptr, s.as_ptr());
    }
}

#[no_mangle]
pub extern fn whatlang_lang_code(lang: Lang, buffer_ptr: *mut c_char) {
    // Here unwrap is supposed to be safe, because whatlang return valid str
    let s = CString::new(lang.code()).unwrap();
    unsafe {
        libc::strcpy(buffer_ptr, s.as_ptr());
    }
}

#[no_mangle]
pub extern fn whatlang_lang_name(lang: Lang, buffer_ptr: *mut c_char) {
    // Here unwrap is supposed to be safe, because whatlang return valid str
    let s = CString::new(lang.name()).unwrap();
    unsafe {
        libc::strcpy(buffer_ptr, s.as_ptr());
    }
}

#[no_mangle]
pub extern fn whatlang_script_name(script: Script, buffer_ptr: *mut c_char) {
    // Here unwrap is supposed to be safe, because whatlang return valid str
    let s = CString::new(script.name()).unwrap();
    unsafe {
        libc::strcpy(buffer_ptr, s.as_ptr());
    }
}
