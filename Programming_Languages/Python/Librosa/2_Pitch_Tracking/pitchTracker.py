import os
import numpy as np
import librosa
import librosa.display
import matplotlib.pyplot as plt

# read file
File = '../Sample/mp3/Puzzle/Puzzle.mp3'
y, sr = librosa.load(File)
print(y.shape)
stftres = librosa.stft(y);
print(stftres.shape)
D = np.abs(stftres)
print(D.shape)
# D = np.abs(librosa.stft(y))
#
# pitches, mags = librosa.piptrack(y,sr)
# print(pitches.shape)
