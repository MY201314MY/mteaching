import wave
import pylab as plt
import numpy as np

if __name__ == '__main__':
    f = wave.open(f="thanks.wav", mode="rb")
    params = f.getparams()
    print(params)

    print("channel:{0}".format(f.getnchannels()))
    print("byte width:{0}".format(f.getsampwidth()))
    print("frame rate:{0}".format(f.getframerate()))
    print("frames:{0}".format(f.getnframes()))
    duration = f.getnframes()/f.getframerate()
    frames = f.getnframes()
    print("time:{0}s".format(round(duration, 2)))

    audio = f.readframes(nframes=f.getnframes())
    print("length:{0}".format(audio.__len__()))
    f.close()

    wave_data = np.fromstring(audio, np.short)
    wave_data.shape = -1, 2

    wave_data = wave_data.T
    time = np.arange(0, f.getnframes()) * (1.0 / f.getframerate())

    plt.subplot(111)
    plt.plot(time[0:16384], wave_data[0])

    plt.xlabel('Time(s)')
    plt.ylabel("Amplitude")
    plt.title("Single channel wavedata")
    plt.grid('on')  # 标尺，on：有，off:无。
    plt.show()

