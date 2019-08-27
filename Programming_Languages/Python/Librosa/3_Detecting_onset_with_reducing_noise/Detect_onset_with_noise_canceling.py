import os
import numpy as np
import librosa
import librosa.display
import matplotlib.pyplot as plt

# noise reeducing packages
import noisereduce as nr
from logmmse import logmmse

File = '../elecpiano/elecpiano1.mp3'
y, sr = librosa.load(File)

# constant_Q = np.abs(librosa.cqt(y,sr))
# log_Q = librosa.amplitude_to_db(constant_Q)

print(y.shape)

hop_length = 100
onset_env = librosa.onset.onset_strength(y, sr=sr, hop_length=hop_length)

# no noise canceling
fig = plt.figure()
fig.add_subplot(3,1,1)
plt.plot(onset_env)
plt.xlim(0, len(onset_env))
plt.title("Onset_strength_no_canceling")

# noise canceling with noisereduce

noisereduce_y = nr.reduce_noise(y, y)
noisereduce_onset_env = librosa.onset.onset_strength(noisereduce_y,  sr=sr, hop_length=hop_length)
fig.add_subplot(3,1,2)
plt.plot(noisereduce_onset_env)
plt.xlim(0,len(noisereduce_onset_env))
plt.title("Onset_strength_noisereduce_canceling")

# noise canceling with logmmse

# logmmse_y = logmmse(y,sr)
# logmmse_onset_env = librosa.onset.onset_strength(logmmse_y, sr=sr, hop_length=hop_length)
# fig.add_subplot(3,1,3)
# plt.plot(logmmse_onset_env)
# plt.xlim(0,len(logmmse_onset_env))
# plt.title("Onset_strength_logmmse_canceling")

plt.show()