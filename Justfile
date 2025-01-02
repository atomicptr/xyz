build:
    meson setup build --reconfigure
    cd build && meson compile

test: build
    cd build && meson test --verbose
