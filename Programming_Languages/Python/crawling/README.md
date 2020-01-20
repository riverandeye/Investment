# Web Crawling

> 웹 크롤링 방법에 대해 알아봅시다.



**기본 세팅**

파이썬에서 웹 크롤링에 이용하는 라이브러리는 BeautifulSoap와 urllib 가 있다.

```python
from bs4 import BeautifulSoup #html의 태그를 다룰 수 있는 라이브러리
from urllib.request import urlopen #urllib 는 URL 작업을 위한 여러 모듈을 모은 패키지
import re # regular expression, 텍스트 처리할때 사용
```

bs4는 요청으로 받아온 element로부터 정보를 가져오는 메소드를 제공하고, urlopen은 말 그대로 url에 대해 요청을 보내고 정적 파일을 받아오는 역할을 한다.



```python
url  = 'https://www.yna.co.kr/search/index?query=%EB%82%B4%EC%9D%BC%EB%82%A0%EC%94%A8&ctype=A&from=20190630&to=20190730&period=diy'
html = urlopen(url)
soup = BeautifulSoup(html, "lxml")
```

해당 url에 요청해서 받은 html을 lxml로 파싱한다.



```python
articles_in_soups = [b.find_all('div', 'cts_atclst') for b in soups]
```

find_all 와 같은 좋은 메소드들을 지원해주기 때문에, 가져다가 편하게 쓰기만 하면 된다. 



#### 페이지가 느리게 구성되는 경우

서버의 요청을 통해 얻어온 정보로 html을 구성하는 경우라면, 첫 페이지의 요청에 적혀잇는 html 만으로는 모든 정보를 얻을 수 없다. 이 경우엔 크롬 웹드라이버를 이용해야 한다.

```python
from selenium import webdriver
```

셀레니움 패키지를 설치하여 사용할 수 있다.



```python
driver = webdriver.Chrome('chromedriver',options=options)
```

크롬드라이버를 사용한다는 뜻. (**로컬에 크롬드라이버가 설치 및 path 지정이 되어있어야 한다**.)



```python
url_page = 'https://www.instagram.com/explore/tags/%EA%B3%A0%EB%A0%A4%EB%8C%80%ED%95%99%EA%B5%90/'
driver.get(url_page)
```

이제 driver.get 을 하면,  driver.page_source에 요청 이후에 생성된 값들에 대해서도 구성된 html을 볼 수 있다.



```python
html = driver.page_source
ku = BeautifulSoup(html, "lxml")
# 각 게시물마다의 글 찾기
text = ku.find_all('div','C4VMK')
text[0].get_text()
```

find_all 메소드를 이용해서 해당 클래스를 갖는 div 태그 element를 모두 찾는다. 이런 방식으로 진행된다.

단점은 driver.page_source라는 전역 변수 하나만을 쓰기 때문에, url 배열에 대해서 list conprehension으로 구현하기는 힘들어 가독성이 좋지 않을 수 있다.