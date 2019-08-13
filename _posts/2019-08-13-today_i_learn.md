---
layout : post
title : 190813_TIL (Today I Learn) 
tags : [TIL]
comments: true
---
### 오늘 한 일
- Life of a pixel ppt를 참고해 rasterization 부분까지 정리하였다.
  - paint 과정에서는 어떤 순서로 그려야 할지를 정하는 부분인데, display item list로 순서에 맞춰서 list화 되어있는 것을 알게 되었다. display item 내부에는 paint operation들이 담겨있는데, 여기서 말하는 operation은 property와 연관이 있는 것 같다. 즉 하나의 layout을 그릴 때 background, foreground, outline등을 어떻게 그려야하는지가 담겨있다. paint 동작은 화면을 기준으로 어떤 순서로 그릴지를 순서대로 배치하는데, 배치하는 동작을 staking order라고 정의한다.

- placement new 에 대해 공부했다. 
  - new 동작 같은 경우 3가지 내용을 포함하고 있다.
    1. 메모리 할당 => opertaor new 연산 사용   
    2. 생성자 호출
    3. 주소값 반환

  - 메모리 할당을 하지 않고 오직 생성자만 호출할 수 있는 new 연산을 placement new라고 한다.
    - keyword new가 아닌 operator new 연산자를 사용자 정의로 만든 후 자기 자신을 반환하도록 한다.

#### 사용 예시
  - 기본 생성자가 없는 경우, 객체 배열을 생성할 때 사용한다.
  - IPC에서 객체를 전달할 때 사용

- [Today English](https://armkernel.github.io/TE_190813/)를 10번 읽고 외우고, 외웠던 것들을 복습했다.

* * *
### 개인 회고

- 집중이 잘 된 것 같다. 하루 일과가 끝나고 이후 계획을 좀 여유있게 설정하는 것이 좋을 것 같다. 금일 계획을 너무 타이트하게 짜서 다 하지 못한 것 같다. 내일은 계획을 좀 더 러프하게 짤 필요가 있고, 정리하는 시간을 좀 더 여유롭게 가져야 할 것 같다. 주말에는 모든 것들을 다시 돌아보는 계획을 짤 필요가 있다는 것을 느꼈다. 
  
