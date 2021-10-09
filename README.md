# Whatlang FFI

C bindings for [whatlang](https://github.com/greyblake/whatlang-rs) natural language detection library.

## Running an example

```
make run
```

## Configuration and Use

To use this library from C include the header `whatlang.h` and link against `libwhatlang.so` / `whatlang.dll`.

By default enum values are defined as C constants. This representation can be changed by defining `WHATLANG_USE_C_ENUMS` before including `whatlang.h`. This doesn't change the underlying ABI.

## License

[MIT](https://github.com/greyblake/whatlang-ffi/blob/master/LICENSE) © [Sergey Potapov](http://greyblake.com/)
