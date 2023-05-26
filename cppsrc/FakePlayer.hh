#pragma once

#include <string>
#include <memory>
#include <thread>
#include <mutex>

/**
 * @brief 伪播放器
 *
 * 通过开启一个带有定时器的线程，来模拟播放器的播放进度
 */
class FakePlayer
{
private:
    bool hasMusic;
    bool isPlaying;
    double currentSpeed;
    double currentTime;
    double musicLength;
    int currentVolume;
    std::unique_ptr<std::thread> playThread;
    std::mutex mutex;

public:
    FakePlayer();
    int play(const std::string &fileName);
    int pause();
    int stop();
    int resume();
    int volume(int volume);
    int speed(double speed);
    int time(double time);
    double duration();
    double length();
};