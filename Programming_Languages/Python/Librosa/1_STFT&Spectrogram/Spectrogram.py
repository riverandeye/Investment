import os
import numpy as np
import librosa
import librosa.display
import matplotlib.pyplot as plt

# read file
File = '../Sample/mp3/Puzzle/Puzzle.mp3'
y, sr = librosa.load(File)
D = np.abs(librosa.stft(y))

#draw spectrogram
librosa.display.specshow(librosa.amplitude_to_db(D, ref=np.max),  y_axis='log', x_axis='time')
plt.title('Power spectrogram')
plt.colorbar(format='%+2.0f dB')
plt.tight_layout()
plt.show()