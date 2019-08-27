import os
import numpy as np
import librosa
import librosa.display
import matplotlib.pyplot as plt

# noise reeducing packages
import noisereduce as nr
from logmmse import logmmse

File = '../elecpiano/elecpiano2.mp3'
y, sr = librosa.load(File)

# constant_Q = np.abs(librosa.cqt(y,sr))
# log_Q = librosa.amplitude_to_db(constant_Q)

hop_length = 100
# y = nr.reduce_noise(y, y)

onset_env = librosa.onset.onset_strength(y, sr=sr, hop_length=hop_length)

onset_samples = librosa.onset.onset_detect(y,
                                           sr=sr, units='samples',
                                           hop_length=hop_length,
                                           backtrack=False,
                                           pre_max=20,
                                           post_max=20,
                                           pre_avg=100,
                                           post_avg=100,
                                           delta=0.2,
                                           wait=0)
print(onset_samples)
onset_boundaries = np.concatenate([[0], onset_samples, [len(y)]])
onset_times = librosa.samples_to_time(onset_boundaries, sr=sr)
# print(onset_times)
# # no noise canceling
# plt.plot(onset_env)
# plt.xlim(0, len(onset_env))
# plt.title("Onset_strength_no_canceling")
# plt.show()

librosa.display.waveplot(y, sr=sr)
plt.vlines(onset_times, -1, 1, color='r')
plt.show()