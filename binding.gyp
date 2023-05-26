{
    "targets": [{
        "target_name": "ccLib",
        "cflags!": ["-fno-exceptions"],
        "cflags_cc!": ["-fno-exceptions"],
        "sources": [
            "cppsrc/main.cc",
            "cppsrc/FakePlayer.cc",
            "cppsrc/PlayerWrapper.cc"
        ],
        "include_dirs": [
            "<!@(node -p \"require('node-addon-api').include\")",
            "cppsrc"
        ],
        "libraries": [],
        "dependencies": [
            "<!(node -p \"require('node-addon-api').gyp\")"
        ],
        "defines": ["NAPI_DISABLE_CPP_EXCEPTIONS"],
    }]
}
