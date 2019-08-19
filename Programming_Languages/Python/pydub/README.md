# Pydub

파이썬으로 오디오 파일 다루는 모듈에 대한 기본 예제입니다.

> 설치

- pip3 사용

```shell
pip3 install pydub
```



> Splitter.py에 구현된 예시

- Import 해야 할 모듈

```python
import os
from pydub import AudioSegment as AS
```



- 폴더 내 모든 파일명을 리턴 (재귀적으로 모든 폴더  탐색)

```python
def getAllfilepath(folder):
    res = []
    for name in os.listdir(folder):
        abspath = os.path.join(folder, name)
        if os.path.isdir(abspath):
            res += getAllfilepath(abspath)  # recursive
        else:
            res.append(abspath.replace("\\", '/'))
    return res
```



- mp3 파일을 wav 파일로 변경

```python
def mp3towav(mp3filename):
    # input : absolute path of mp3file
    # output : none (wav file saved)

    if len(mp3filename.split('.')) > 2:
        print("Name format is totally wrong")
        return

    wavfilename = mp3filename.split(".")[0].replace("mp3", "wav") + '.wav'
    AS.from_mp3(mp3filename).export(wavfilename, format="wav")
```

AS.from_mp3 로 불러들인 음원 파일은 pydub.audio_segment.AudioSegment 클래스의 객체

export 모듈로 파일을 저장한다. format을 명시할 시 해당하는 format으로 재생한다.



- 각 파일을 1분 단위로 분리하기

```python
def split1minute(filePath, fileFormat=None):
    // 생략
    original = AS.from_file(filePath, fileFormat)
	// 생략 (예외처리)

    for i in range(len(original) // one_minute):
        savepath = os.path.join(savefolderpath, filename + "_" + str(i + 1) + '.' + fileFormat).replace("\\", '/')
        if (i + 1) * one_minute > len(original):
            original[i * one_minute:].export(savepath, format=fileFormat)
        else:
            original[i * one_minute: (i + 1) * one_minute].export(savepath, format=fileFormat)
```

읽은 파일을 1분 단위로 잘라 저장한다. 단순히 slicing 해주면 길이가 조정된다.

