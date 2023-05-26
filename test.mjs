import { Nocturne } from './dist/index.js';

const nocturne = new Nocturne();

async function main() {
    await nocturne.init();

    const playLists0 = await nocturne.playListManager.getPlayLists();
    for (const playList of playLists0) {
        await nocturne.playListManager.deletePlayList(playList);
    }

    await nocturne.playListManager.cleanDB();

    await nocturne.playListManager.loadSongs('G:/Nocturne/frontend/local/test1', false);
    const playLists = await nocturne.playListManager.getPlayLists();

    const songs = await nocturne.songManager.getSongs(playLists[0]);
    console.log(songs);
    nocturne.play(songs[0]);
    console.log('song 0');
    console.log(nocturne.ccLib.getPlayStatus());
    console.log(nocturne.ccLib.getLength());
    console.log(nocturne.ccLib.getSpeed());
    console.log(nocturne.ccLib.getVolume());
    console.log(nocturne.ccLib.getTime());
    console.log('song 0 end');

    return new Promise((resolve, _reject) => {
        setTimeout(() => {
            nocturne.ccLib.pause();
            console.log(nocturne.ccLib.getPlayStatus());
            console.log(nocturne.ccLib.getLength());
            console.log(nocturne.ccLib.getSpeed());
            console.log(nocturne.ccLib.getVolume());
            console.log(nocturne.ccLib.getTime());
            resolve();
        }, 1000);
    });
}

await main();
