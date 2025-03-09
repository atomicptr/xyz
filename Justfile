test: build
    cd build && meson test --verbose

build:
    meson setup build --reconfigure
    cd build && meson compile

format:
    find src tests -name '*.cpp' -or -name '*.hpp' -exec clang-format -i {} \;
