#ifndef _WHATLANG_HEADER_DEF_
#define _WHATLANG_HEADER_DEF_
#endif

#include <stdint.h>
#include <stdlib.h>

#ifdef WHATLANG_USE_C_ENUMS
# define _C_ENUM_THUNK(key, val) key = val,
# define DEFINE_ENUM(name, cb)			\
	typedef enum name : uint8_t {	    \
		cb(_C_ENUM_THUNK)				\
	} name ## _t;
#else
# define _C_CONST_THUNK(key, val) static const uint8_t key = val;
# define DEFINE_ENUM(name, cb)          \
	cb(_C_CONST_THUNK)                   \
		typedef uint8_t name ## _t;
#endif

#define STATUS_VALUES(_)                         \
    _(WHATLANG_STATUS_OK, 0)                     \
    _(WHATLANG_STATUS_DETECT_FAILURE, 1)         \
    _(WHATLANG_STATUS_BAD_TEXT_PTR,  2)          \
    _(WHATLANG_STATUS_BAD_OUTPUT_PTR, 3)         \

DEFINE_ENUM(whatlang_status, STATUS_VALUES)

#define LANG_VALUES(_)                   \
    _(WHATLANG_LANG_AKA, 0)              \
    _(WHATLANG_LANG_AMH, 1)              \
    _(WHATLANG_LANG_ARB, 2)              \
    _(WHATLANG_LANG_AZJ, 3)              \
    _(WHATLANG_LANG_BEL, 4)              \
    _(WHATLANG_LANG_BEN, 5)              \
    _(WHATLANG_LANG_BHO, 6)              \
    _(WHATLANG_LANG_BUL, 7)              \
    _(WHATLANG_LANG_CEB, 8)              \
    _(WHATLANG_LANG_CES, 9)              \
    _(WHATLANG_LANG_CMN, 10)             \
    _(WHATLANG_LANG_DAN, 11)             \
    _(WHATLANG_LANG_DEU, 12)             \
    _(WHATLANG_LANG_ELL, 13)             \
    _(WHATLANG_LANG_ENG, 14)             \
    _(WHATLANG_LANG_EPO, 15)             \
    _(WHATLANG_LANG_EST, 16)             \
    _(WHATLANG_LANG_FIN, 17)             \
    _(WHATLANG_LANG_FRA, 18)             \
    _(WHATLANG_LANG_GUJ, 19)             \
    _(WHATLANG_LANG_HAT, 20)             \
    _(WHATLANG_LANG_HAU, 21)             \
    _(WHATLANG_LANG_HEB, 22)             \
    _(WHATLANG_LANG_HIN, 23)             \
    _(WHATLANG_LANG_HRV, 24)             \
    _(WHATLANG_LANG_HUN, 25)             \
    _(WHATLANG_LANG_IBO, 26)             \
    _(WHATLANG_LANG_ILO, 27)             \
    _(WHATLANG_LANG_IND, 28)             \
    _(WHATLANG_LANG_ITA, 29)             \
    _(WHATLANG_LANG_JAV, 30)             \
    _(WHATLANG_LANG_JPN, 31)             \
    _(WHATLANG_LANG_KAN, 32)             \
    _(WHATLANG_LANG_KAT, 33)             \
    _(WHATLANG_LANG_KHM, 34)             \
    _(WHATLANG_LANG_KIN, 35)             \
    _(WHATLANG_LANG_KOR, 36)             \
    _(WHATLANG_LANG_KUR, 37)             \
    _(WHATLANG_LANG_LAV, 38)             \
    _(WHATLANG_LANG_LIT, 39)             \
    _(WHATLANG_LANG_MAI, 40)             \
    _(WHATLANG_LANG_MAL, 41)             \
    _(WHATLANG_LANG_MAR, 42)             \
    _(WHATLANG_LANG_MKD, 43)             \
    _(WHATLANG_LANG_MLG, 44)             \
    _(WHATLANG_LANG_MYA, 45)             \
    _(WHATLANG_LANG_NEP, 46)             \
    _(WHATLANG_LANG_NLD, 47)             \
    _(WHATLANG_LANG_NNO, 48)             \
    _(WHATLANG_LANG_NOB, 49)             \
    _(WHATLANG_LANG_NYA, 50)             \
    _(WHATLANG_LANG_ORI, 51)             \
    _(WHATLANG_LANG_ORM, 52)             \
    _(WHATLANG_LANG_PAN, 53)             \
    _(WHATLANG_LANG_PES, 54)             \
    _(WHATLANG_LANG_POL, 55)             \
    _(WHATLANG_LANG_POR, 56)             \
    _(WHATLANG_LANG_RON, 57)             \
    _(WHATLANG_LANG_RUN, 58)             \
    _(WHATLANG_LANG_RUS, 59)             \
    _(WHATLANG_LANG_SIN, 60)             \
    _(WHATLANG_LANG_SKR, 61)             \
    _(WHATLANG_LANG_SLV, 62)             \
    _(WHATLANG_LANG_SNA, 63)             \
    _(WHATLANG_LANG_SOM, 64)             \
    _(WHATLANG_LANG_SPA, 65)             \
    _(WHATLANG_LANG_SRP, 66)             \
    _(WHATLANG_LANG_SWE, 67)             \
    _(WHATLANG_LANG_TAM, 68)             \
    _(WHATLANG_LANG_TEL, 69)             \
    _(WHATLANG_LANG_TGL, 70)             \
    _(WHATLANG_LANG_THA, 71)             \
    _(WHATLANG_LANG_TIR, 72)             \
    _(WHATLANG_LANG_TUK, 73)             \
    _(WHATLANG_LANG_TUR, 74)             \
    _(WHATLANG_LANG_UIG, 75)             \
    _(WHATLANG_LANG_UKR, 76)             \
    _(WHATLANG_LANG_URD, 77)             \
    _(WHATLANG_LANG_UZB, 78)             \
    _(WHATLANG_LANG_VIE, 79)             \
    _(WHATLANG_LANG_YDD, 80)             \
    _(WHATLANG_LANG_YOR, 81)             \
    _(WHATLANG_LANG_ZUL, 82)             \

DEFINE_ENUM(whatlang_lang, LANG_VALUES)

#define SCRIPT_VALUES(_)                 \
    _(WHATLANG_SCRIPT_ARABIC, 0)         \
    _(WHATLANG_SCRIPT_BENGALI, 1)        \
    _(WHATLANG_SCRIPT_CYRILLIC, 2)       \
    _(WHATLANG_SCRIPT_DEVANAGARI, 3)     \
    _(WHATLANG_SCRIPT_ETHIOPIC, 4)       \
    _(WHATLANG_SCRIPT_GEORGIAN, 5)       \
    _(WHATLANG_SCRIPT_GREEK, 6)          \
    _(WHATLANG_SCRIPT_GUJARATI, 7)       \
    _(WHATLANG_SCRIPT_GURMUKHI, 8)       \
    _(WHATLANG_SCRIPT_HANGUL, 9)         \
    _(WHATLANG_SCRIPT_HEBREW, 10)        \
    _(WHATLANG_SCRIPT_HIRAGANA, 11)      \
    _(WHATLANG_SCRIPT_KANNADA, 12)       \
    _(WHATLANG_SCRIPT_KATAKANA, 13)      \
    _(WHATLANG_SCRIPT_KHMER, 14)         \
    _(WHATLANG_SCRIPT_LATIN, 15)         \
    _(WHATLANG_SCRIPT_MALAYALAM, 16)     \
    _(WHATLANG_SCRIPT_MANDARIN, 17)      \
    _(WHATLANG_SCRIPT_MYANMAR, 18)       \
    _(WHATLANG_SCRIPT_ORIYA, 19)         \
    _(WHATLANG_SCRIPT_SINHALA, 20)       \
    _(WHATLANG_SCRIPT_TAMIL, 21)         \
    _(WHATLANG_SCRIPT_TELUGU, 22)        \
    _(WHATLANG_SCRIPT_THAI, 23)

DEFINE_ENUM(whatlang_script, SCRIPT_VALUES)

struct whatlang_info {
  whatlang_lang_t lang;
  whatlang_script_t script;
  double confidence;
};

// Detect the language in the input `text`
//
// param: `text` a null-terminated c-string containing the input text.
// param: `info` output pointer for the `whatlang_info`.
// returns: 0 on success, and non-zero on failure.
whatlang_status_t whatlang_detect(const char* text, struct whatlang_info* info);

// Detect the language in the input `text`
//
// param: `text` a c-string containing the input text.
// param: `len` the length of the string in characters.
// param: `info` output pointer for the `whatlang_info`.
// returns: 0 on success, and non-zero on failure.
whatlang_status_t whatlang_detectn(const char* text, size_t len, struct whatlang_info* info);

// Get the language code from the `whatlang_info.lang`.
//
// It's your responsibility to ensure, that buffer size is at least 30 bytes.
//
// Returns: the number of characters written to the byffer, excluding the null terminator.
size_t whatlang_lang_code(whatlang_lang_t lang, char* buffer);

// Get the english name for the language from the `whatlang_info.lang`.
//
// It's your responsibility to ensure, that buffer size is at least 30 bytes.
//
// Returns: the number of characters written to the byffer, excluding the null terminator.
size_t whatlang_lang_eng_name(whatlang_lang_t lang, char* buffer);

// Get the  name for the language from the `whatlang_info.lang`.
//
// It's your responsibility to ensure, that buffer size is at least 30 bytes.
//
// Returns: the number of characters written to the byffer, excluding the null terminator.
size_t whatlang_lang_name(whatlang_lang_t lang, char* buffer);

// Get the  name for the script from the `whatlang_info.script`.
//
// It's your responsibility to ensure, that buffer size is at least 30 bytes.
//
// Returns: the number of characters written to the byffer, excluding the null terminator.
size_t whatlang_script_name(whatlang_script_t script, char* buffer);
