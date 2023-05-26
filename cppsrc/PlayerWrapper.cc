#include "PlayerWrapper.hh"

PlayerWrapper::PlayerWrapper() : player{}, playStatus{0}, volume{100}, speed{1} {}

Napi::Number PlayerWrapper::play(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    if (args.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    if (!args[0].IsString())
    {
        Napi::TypeError::New(env, "Wrong arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    auto fileName = args[0].As<Napi::String>().Utf8Value();
    auto result = player.play(fileName);
    playStatus = 1;
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::pause(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    auto result = player.pause();
    playStatus = 2;
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::stop(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    auto result = player.stop();
    playStatus = 0;
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::resume(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    auto result = player.resume();
    playStatus = 1;
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::getPlayStatus(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    return Napi::Number::New(env, playStatus);
}

Napi::Number PlayerWrapper::setVolume(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    if (args.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    if (!args[0].IsNumber())
    {
        Napi::TypeError::New(env, "Wrong arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    volume = args[0].As<Napi::Number>().Int32Value();
    auto result = player.volume(volume);
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::getVolume(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    return Napi::Number::New(env, volume);
}

Napi::Number PlayerWrapper::setSpeed(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    if (args.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    if (!args[0].IsNumber())
    {
        Napi::TypeError::New(env, "Wrong arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    speed = args[0].As<Napi::Number>().DoubleValue();
    auto result = player.speed(speed);
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::getSpeed(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    return Napi::Number::New(env, speed);
}

Napi::Number PlayerWrapper::setTime(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    if (args.Length() < 1)
    {
        Napi::TypeError::New(env, "Wrong number of arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    if (!args[0].IsNumber())
    {
        Napi::TypeError::New(env, "Wrong arguments")
            .ThrowAsJavaScriptException();
        return Napi::Number::New(env, -1);
    }
    auto time = args[0].As<Napi::Number>().DoubleValue();
    auto result = player.time(time);
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::getTime(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    auto result = player.duration();
    return Napi::Number::New(env, result);
}

Napi::Number PlayerWrapper::getLength(const Napi::CallbackInfo &args)
{
    auto env = args.Env();
    auto result = player.length();
    return Napi::Number::New(env, result);
}
