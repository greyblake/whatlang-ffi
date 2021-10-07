extern crate whatlang;
extern crate libc;

use libc::size_t;
use whatlang::{detect, Lang, Script};
use std::ffi::{CStr, CString};
use std::ptr;
use std::os::raw::c_char;

#[repr(C)]
#[derive(Debug)]
pub struct CInfo {
    lang: Lang,
    script: Script,
    confidence: f64
}

#[no_mangle]
pub extern "C" fn whatlang_detectn(ptr: *const c_char, len: libc::size_t, cinfo: &mut CInfo) -> u8 {
    let text = unsafe {
        std::str::from_utf8(core::slice::from_raw_parts(ptr as *const u8, len))
    };
    match text {
        Ok(s) => {
            detect_internal(s, cinfo)
        },
        Err(_) => {
            // Bad string pointer
            return 2;
        }
    }
}

#[no_mangle]
pub extern "C" fn whatlang_detect(ptr: *const c_char, cinfo: &mut CInfo) -> u8 {
    let cs = unsafe { CStr::from_ptr(ptr) };
    match cs.to_str() {
        Ok(s) => {
            detect_internal(s, cinfo)
        },
        Err(_) => {
            // Bad string pointer
            return 2;
        }
    }
}

fn detect_internal(text: &str, cinfo: &mut CInfo) -> u8 {
    let res = detect(text);
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
}

#[no_mangle]
pub extern "C" fn whatlang_lang_eng_name(lang: Lang, buffer_ptr: *mut c_char) -> size_t {
    // Here unwrap is always safe, because whatlang always returns a valid str
    let s = CString::new(lang.eng_name()).unwrap();
    unsafe {
		if buffer_ptr != ptr::null_mut() {
			libc::strncpy(buffer_ptr, s.as_ptr(), 30);
		}
    }
    s.as_bytes().len()
}

#[no_mangle]
pub extern "C" fn whatlang_lang_code(lang: Lang, buffer_ptr: *mut c_char) -> size_t {
    // Here unwrap is supposed to be safe, because whatlang return valid str
    let s = CString::new(lang.code()).unwrap();
    unsafe {
		if buffer_ptr != ptr::null_mut() {
			libc::strncpy(buffer_ptr, s.as_ptr(), 30);
		}
    }
    s.as_bytes().len()
}

#[no_mangle]
pub extern "C" fn whatlang_lang_name(lang: Lang, buffer_ptr: *mut c_char) -> size_t {
    // Here unwrap is supposed to be safe, because whatlang return valid str
    let s = CString::new(lang.name()).unwrap();
    unsafe {
		if buffer_ptr != ptr::null_mut() {
			libc::strncpy(buffer_ptr, s.as_ptr(), 30);
		}
    }
    s.as_bytes().len()
}

#[no_mangle]
pub extern "C" fn whatlang_script_name(script: Script, buffer_ptr: *mut c_char) -> size_t {
    // Here unwrap is supposed to be safe, because whatlang return valid str
    let s = CString::new(script.name()).unwrap();
    unsafe {
		if buffer_ptr != ptr::null_mut() {
			libc::strncpy(buffer_ptr, s.as_ptr(), 30);
		}
    }
    s.as_bytes().len()
}
