# Fourier Transform

> 푸리에 트랜스폼과 관련된 정보를 담습니다.



### 1. Fourier Transform

시간 축에 대한 임의의 신호를, **서로 다른 주파수를 가진 Sinusoid 들의 합으로 표현하는 것이다. ** 

![](https://miro.medium.com/max/1400/1*zKXmpvJAfWr6kBtClOnoiA.png)



예시를 통해 알아보자.

![](https://siemensplm.i.lithium.com/t5/image/serverpage/image-id/74990i98774D13BE16F1A8?v=1.0)

현실 세계의 보라색 신호는 Fourier Transform을 이용하여 빨강, 회색, 초록색의 파형으로 나눌 수 있다. 곧, 3개의 파형을 합치면 원래 보라색 신호와 근사한 결과가 나오는 것이다. 이때, Transform의 결과는 각 파형의 진동수와 진폭을 각 축으로 하는 그래프로 표현할 수 있다.

Fourier Transform은 특정 신호에 대해 **모든 주파수 영역의** Amplitude를 분석하는 것이 핵심이다.

Fourier Transform은 비주기적인 신호의 주파수 대역을 분석할 때 사용한다.

### 2. Fourier Series

시간축에 대한 **주기적인 신호를**, **특정 배수를 갖는 주파수들의 합** 으로 근사하는 것이다.

![](https://i0.wp.com/www.bragitoff.com/wp-content/uploads/2016/03/fourier-series-coefficients.png)

이때 특정 배수는 함수의 반복되는 구간이 2L일 때 (2pi / 2L) 이다.

Fourier Series는 특정 신호의 **특정 주파수 영역** 으로만 표현하는 것이 핵심이다. 



### 3. DFT (Discrete Fourier Transform)

![](data:image/png;base64,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)

시간 축의 정보가 불연속적인 경우 data point들로 존재하게 되므로, 기존 Signal이 xn인 경우 DFT한 결과는 Xk로 나타난다. 이는 xn 이라는 각 지점에서의 inpulse가 k/N * (2pi) frequency에 대해 미치는 영향의  합으로 각 Xk가 표현된다고 볼 수 있다.

- CFT 로부터 DFT 유도하기

![](https://i.stack.imgur.com/WWuqt.png)

단순히 기존 함수를 샘플링하여 적분한 결과이다. CFT에서 시간축이 무한대였는데 DFT에서 N - 1 로 제한되는 이유는 f[k] = 0 인 부분에 대한 연산 결과를 포함할 필요가 없기 때문이다.



### 4. FFT (Fast Fourier Transform)

푸리에 트랜스폼을 빠르게 계산해주는 알고리즘이다. 자세한 것은 생략한다..



### 5. STFT (Short-time Fourier Transform)

간단히 말하면, 긴 영역의 신호를 **일정한 간격으로 잘라 해당 영역만 FFT 한 결과를 모은 것**이다. 이렇게 하면, 특정 시간대에 존재하는 신호는 어떤 주파수의 성분을 가지는지를 알 수 있다.

![](https://ai2-s2-public.s3.amazonaws.com/figures/2017-08-08/1e102bcada97738bf9ed2e566ec30d260908880d/2-Figure1-1.png)



위 이미지에 STFT의 과정이 간략히 제시되어 있다. 하나의 구간에 K개의 Sample이 있게끔 구간을 설정하고, 해당 구간에 Windowing을 한 후 FFT를 적용시킨다. windowing을 하는 이유는 구간을 자를 때 가장자리가 step function 처럼 신호가 급변하게 되는 것을 방지하기 위함이다. 



#### 5.1 Windowing

Windowing이란, 기존 신호에 해당 신호를 끼얹는 것이다. 밑의 그림을 보며 이해해보자.

![](https://www.electronicdesign.com/sites/electronicdesign.com/files/uploads/2013/11/0114GettingTheSignalFig4.gif)

w(n) 이라는 window를 x(n)에 적용시킨 결과는 밑의 그림과 같다. 이는, x(n)의 Amplitude를 window의 형태에 맞게끔 제한하는 역할을 한다.



#### 5.2 librosa stft 모듈

```python
def stft(y, n_fft=2048, hop_length=None, win_length=None, window='hann',
         center=True, dtype=np.complex64, pad_mode='reflect'):

    # By default, use the entire frame
    if win_length is None:
        win_length = n_fft

    # Set the default hop, if it's not already specified
    if hop_length is None:
        hop_length = int(win_length // 4)

    fft_window = get_window(window, win_length, fftbins=True)

    # Pad the window out to n_fft size
    fft_window = util.pad_center(fft_window, n_fft)

    # Reshape so that the window can be broadcast
    fft_window = fft_window.reshape((-1, 1))

    # Check audio is valid
    util.valid_audio(y)

    # Pad the time series so that frames are centered
    if center:
        y = np.pad(y, int(n_fft // 2), mode=pad_mode)

    # Window the time series.
    y_frames = util.frame(y, frame_length=n_fft, hop_length=hop_length)

    # Pre-allocate the STFT matrix
    stft_matrix = np.empty((int(1 + n_fft // 2), y_frames.shape[1]),
                           dtype=dtype,
                           order='F')

    fft = get_fftlib()

    # how many columns can we fit within MAX_MEM_BLOCK?
    n_columns = int(util.MAX_MEM_BLOCK / (stft_matrix.shape[0] *
                                          stft_matrix.itemsize))

    for bl_s in range(0, stft_matrix.shape[1], n_columns):
        bl_t = min(bl_s + n_columns, stft_matrix.shape[1])

        stft_matrix[:, bl_s:bl_t] = fft.rfft(fft_window *
                                             y_frames[:, bl_s:bl_t],
                                             axis=0)
    return stft_matrix
```

이 모듈이 어떻게 구성되어있는지를 읽어보면, 전체적인 과정이 이해가 될 것이다.



## Reference

https://en.wikipedia.org/wiki/Fourier_series

https://en.wikipedia.org/wiki/Discrete_Fourier_transform

https://topology-blog.tistory.com/6