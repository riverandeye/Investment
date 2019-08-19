import sys
import os
import librosa
import matplotlib.pyplot as plt
import numpy as np

# read file
File = '../Sample/mp3/Kissin/Kissin_3.mp3'
y, sr = librosa.load(File)

# y는 음성의 시계열 데이터
# Run the default beat tracker (default라서 Beat tracking 방식을 구현체 보고 확인해야함)
tempo, beat_frames = librosa.beat.beat_track(y=y, sr=sr)

print('Estimated tempo: {:.2f} beats per minute'.format(tempo))

#Convert the frame indices of beat events into timestamps
beat_times = librosa.frames_to_time(beat_frames, sr=sr)