#pragma once
#include "FakePlayer.hh"
#include <napi.h>

class PlayerWrapper
{
private:
    FakePlayer player;
    int playStatus;
    int volume;
    double speed;

public:
    PlayerWrapper();
    Napi::Number play(const Napi::CallbackInfo &args);
    Napi::Number pause(const Napi::CallbackInfo &args);
    Napi::Number stop(const Napi::CallbackInfo &args);
    Napi::Number resume(const Napi::CallbackInfo &args);
    Napi::Number getPlayStatus(const Napi::CallbackInfo &args);
    Napi::Number setVolume(const Napi::CallbackInfo &args);
    Napi::Number getVolume(const Napi::CallbackInfo &args);
    Napi::Number setSpeed(const Napi::CallbackInfo &args);
    Napi::Number getSpeed(const Napi::CallbackInfo &args);
    Napi::Number setTime(const Napi::CallbackInfo &args);
    Napi::Number getTime(const Napi::CallbackInfo &args);
    Napi::Number getLength(const Napi::CallbackInfo &args);
};