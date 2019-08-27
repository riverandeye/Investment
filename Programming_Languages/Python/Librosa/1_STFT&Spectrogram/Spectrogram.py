import os
import numpy as np
import librosa
import librosa.display
import matplotlib.pyplot as plt

# read file
# File = '../Sample/mp3/Puzzle/Puzzle.mp3'
File = '../voice/voice1.mp3'
y, sr = librosa.load(File)

#draw spectrogram


# tempo, beat_frames = librosa.beat.beat_track(y=y, sr=sr)
# beat_times = librosa.frames_to_time(beat_frames, sr=sr)
# print(tempo)
# print(beat_times)

# D = np.abs(librosa.stft(y))
# log_d = librosa.amplitude_to_db(D, ref=np.max)
# librosa.display.specshow(log_d,  y_axis='log', x_axis='time')
# plt.title('Power spectrogram')
# plt.colorbar(format='%+2.0f dB')
# plt.tight_layout()
# plt.show()

# CQT

constant_Q = np.abs(librosa.cqt(y,sr))
log_Q = librosa.amplitude_to_db(constant_Q)

print(log_Q.shape)
librosa.display.specshow(log_Q,  x_axis='time', y_axis='cqt_note', )
plt.title('CQT spectrogram')
plt.colorbar(format='%+2.0f dB')
plt.tight_layout()
plt.show()