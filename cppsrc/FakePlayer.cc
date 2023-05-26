#include "FakePlayer.hh"

FakePlayer::FakePlayer() : hasMusic{false},
                           isPlaying{false},
                           currentSpeed{1},
                           currentTime{0},
                           musicLength{0},
                           currentVolume{512},
                           playThread{nullptr},
                           mutex{} {}

int FakePlayer::play(const std::string &fileName)
{
    stop();
    hasMusic = true;
    isPlaying = true;
    musicLength = 60;
    currentTime = 0;
    playThread = std::make_unique<std::thread>([this]()
                                               {
            for (int i = 0;;i++)
            {
                std::this_thread::sleep_for(std::chrono::milliseconds(100));
                {
                    std::scoped_lock lock(mutex);
                    if (isPlaying)
                    {
                        currentTime += currentSpeed * 0.1;
                    }
                    if (i % 10 == 0)
                    {
                        printf("currentTime: %f\n", currentTime);
                    }
                    if (currentTime > musicLength || !hasMusic)
                    {
                        return;
                    }
                }
            } });
    return 0;
}

int FakePlayer::pause()
{
    std::scoped_lock<std::mutex> lock(mutex);
    isPlaying = false;
    return 0;
}

int FakePlayer::stop()
{
    {
        std::scoped_lock<std::mutex> lock(mutex);
        isPlaying = false;
        hasMusic = false;
    }
    if (playThread != nullptr)
    {
        playThread->join();
        playThread = nullptr;
    }
    return 0;
}

int FakePlayer::resume()
{
    std::scoped_lock<std::mutex> lock(mutex);
    isPlaying = true;
    return 0;
}

int FakePlayer::volume(int volume)
{
    std::scoped_lock<std::mutex> lock(mutex);
    currentVolume = volume;
    return 0;
}

int FakePlayer::speed(double speed)
{
    std::scoped_lock<std::mutex> lock(mutex);
    currentSpeed = speed;
    return 0;
}

int FakePlayer::time(double time)
{
    std::scoped_lock<std::mutex> lock(mutex);
    currentTime = time;
    return 0;
}

double FakePlayer::duration()
{
    std::scoped_lock<std::mutex> lock(mutex);
    return currentTime;
}

double FakePlayer::length()
{
    std::scoped_lock<std::mutex> lock(mutex);
    return musicLength;
}