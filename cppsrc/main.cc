#include "napi.h"
#include "PlayerWrapper.hh"

static PlayerWrapper player;

Napi::Object initMain(Napi::Env env, Napi::Object exports)
{
    exports.Set("play", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                            { return player.play(args); }));
    exports.Set("pause", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                             { return player.pause(args); }));
    exports.Set("stop", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                            { return player.stop(args); }));
    exports.Set("resume", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                              { return player.resume(args); }));
    exports.Set("getPlayStatus", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                                     { return player.getPlayStatus(args); }));
    exports.Set("setVolume", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                                 { return player.setVolume(args); }));
    exports.Set("getVolume", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                                 { return player.getVolume(args); }));
    exports.Set("setSpeed", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                                { return player.setSpeed(args); }));
    exports.Set("getSpeed", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                                { return player.getSpeed(args); }));
    exports.Set("setTime", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                               { return player.setTime(args); }));
    exports.Set("getTime", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                               { return player.getTime(args); }));
    exports.Set("getLength", Napi::Function::New(env, [](const Napi::CallbackInfo &args)
                                                 { return player.getLength(args); }));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODULE_NAME, initMain)