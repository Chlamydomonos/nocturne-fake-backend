enum PlayStatus {
    STOP = 0,
    PLAY = 1,
    PAUSE = 2,
}

interface CCLib {
    play(file: string): number;
    stop(): number;
    pause(): number;
    resume(): number;
    getPlayStatus(): PlayStatus;
    setVolume(volume: number): number;
    getVolume(): number;
    setSpeed(speed: number): number;
    getSpeed(): number;
    setTime(time: number): number;
    getTime(): number;
    getLength(): number;
}

const ccLib = require('../build/Release/ccLib.node') as CCLib;

export { PlayStatus, type CCLib, ccLib };
