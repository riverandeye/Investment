# Librosa 

- Study of Librosa
- For Project Hanium

### 0. Tutorial

- 설치
```shell
pip3 install librosa
```
- 음원 파일 읽어들이기
```python
import librosa
File = '../Music/Kissin.mp3'
y, sr = librosa.load(File)
```
이때 그냥 이렇게 읽어들이면 **audioread.NoBackendError** 가 발생한다. 이는 FFmpeg가 설치되어 있지 않기 때문에 발생하는 문제이다.

이를 해결하기 위해선 [여기](https://ffmpeg.zeranoe.com/builds/)에 접속하여 본인 OS에 맞는 빌드를 설치한 후, 적절한 장소에 폴더를 옮긴 후 bin 폴더를 PATH에 설정하면 된다. (윈도우는 재부팅 후 PATH 설정이 완료되므로 PATH 설정 후 꼭 껏다 켜주자.)

파일을 읽으면 y와 sr 변수에 나누어 저장되는데, sr은 sampling rate이다. y는 음성의 시계열 데이터이다.

### 1. STFT & Spectrogram

- 

