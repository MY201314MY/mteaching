import wave
import pyaudio

if __name__ == '__main__':
    path = "thanks.wav"

    CHUNK = 1024
    FORMAT = pyaudio.paInt16
    CHANNELS = 1
    RATE = 11025
    RECORD_SECONDS = 3
    WAVE_OUTPUT_FILENAME = path

    p = pyaudio.PyAudio()

    stream = p.open(format=FORMAT, channels=CHANNELS, rate=RATE, input=True, frames_per_buffer=CHUNK)
    frame = []

    print("beginning. . .")

    for i in range(0, int(RATE / CHUNK * RECORD_SECONDS)):
        date = stream.read(CHUNK)
        frame.append(date)

    stream.stop_stream()
    stream.close()
    p.terminate()

    wf = wave.open(WAVE_OUTPUT_FILENAME, 'wb')
    wf.setnchannels(CHANNELS)
    wf.setsampwidth(p.get_sample_size(FORMAT))
    wf.setframerate(RATE)
    wf.writeframes(b''.join(frame))
    wf.close()

    print("Date stored!")
