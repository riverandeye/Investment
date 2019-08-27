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

def estimate_pitch(segment, sr, fmin=50.0, fmax=2000.0):
    # Compute autocorrelation of input segment.
    r = librosa.autocorrelate(segment)

    # Define lower and upper limits for the autocorrelation argmax.
    i_min = sr / fmax
    i_max = sr / fmin
    r[:int(i_min)] = 0
    r[int(i_max):] = 0

    # Find the location of the maximum autocorrelation.
    i = r.argmax()
    f0 = float(sr) / i
    return f0

def generate_sine(f0, sr, n_duration):
    n = np.arange(n_duration)
    return 0.2*np.sin(2*np.pi*f0*n/float(sr))

def estimate_pitch_and_generate_sine(x, onset_samples, i, sr):
    n0 = onset_samples[i]
    n1 = onset_samples[i+1]
    f0 = estimate_pitch(x[n0:n1], sr)
    return generate_sine(f0, sr, n1-n0)

res = np.concatenate([
    estimate_pitch_and_generate_sine(y, onset_boundaries, i, sr=sr)
    for i in range(len(onset_boundaries)-1)
])


constant_Q = np.abs(librosa.cqt(y,sr))
log_Q = librosa.amplitude_to_db(constant_Q)

print(log_Q.shape)

fig = plt.figure()
fig.add_subplot(2,1,1)
librosa.display.specshow(log_Q,  x_axis='time', y_axis='cqt_note', )
plt.title('CQT spectrogram')
# plt.show()

cqt = librosa.cqt(res, sr=sr)
fig.add_subplot(2,1,2)
librosa.display.specshow(np.abs(cqt), sr=sr, x_axis='time', y_axis='cqt_note')
plt.title('Estimated pitch spectrogram')
plt.show()

librosa.output.write_wav("result.wav",res,sr=sr)