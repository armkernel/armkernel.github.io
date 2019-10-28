---
layout : post
title : 190812_TIL (Today I Learn) 
tags : [TIL]
comments: true
---
### 오늘 한 일
- Chromium 관련 공부를 했다. paint layer 부분을 공부했다. paint layer 같은 경우 layout에서 compositor로 가기전 단계를 뜻한다. paint layer같은 경우 compositor layer라고 하기에는 정보가 부족하지만 꼭 필요한 중간 다리 역할을 한다. layer같은 경우 1:1 맵핑으로 이루어져있는 게 아니라 1:n 구조로 이루어진다. 1:1 맵핑이면 중간단계가 필요 없지만 1:n 같은 경우 어떤 layer들이 compositor에 필요한지 관리하는 단계가 필요하다. 중간 단계를 paint layer라고 한다. 
- swap 관련된 graphic에서 사용하는 용어를 배웠다. graphic 같은 경우 많은 발전을 거쳐 옛날보다는 성능을 많이 향상 시켰다. 그 중 하나의 예로 인터넷창이 계단형식으로 부분적으로 업데이트 되는 것이 아니라 한번에 "쨘" 하고 나타나도록 한다. 이렇게 할 수 있었던 이유는 double-buffer (front buffer, back buffer) 를 두는데, 먼저 사용자에게 보여주고 이후 back buffer가 완성되면 swap을 통해 쨘하고 나타나는 방식이다. 이때, swap이라는 용어를 사용하며, rendering에서 나오는 swap개념이랑은 다르다.

- 구체적인 공부 계획을 세웠다.
  - C++ 실력 향상
    - A tour of C++ 책을 읽고 내용을 정리한다. (매일 일정 끝나고 조금씩 1장이라도 읽고, 모든 부분을 코딩함) 
      - 따로 블로그 공간을 열어 책읽고 정리하는 부분을 만든다. TIL 공간에는 어떤걸 했는지 적고, link를 이용해 블로그 공간을 내부 링크화 한다. 
    - C++ 강의 듣고 필요한 부분 계속 해서 추가적인 부연 설명. (C++ 책을 읽고 모자란 부분을 강의를 통해 같이 정리함)

  - Chromium open source
    - open source의 기여보다는 10분이라도 design document를 읽고 이해하도록 노력한다. 이것 또한 똑같이 블로그 공간을 열고 chromium 섹션을 정리한다. 
    - TIL 공간은 어떤걸 했는지만 적고, 내부 link 이용 

  - Today English
    - 하루에 한 문장씩이라도 적고 복습하도록 한다. 한 문장을 적기 이전에 3번 이상 말하는 것에 의의를 둔다.
    - 문장을 어느 정도 외우면, 영어 시험을 치르고 나의 객관적인 위치를 파악하도록 한다. (추후 문제.. 우선 외우자)

  - 책
    - 책은 공부가 아니다. 시간 날때 보고 좋은 점들을 정리하자. 이후, 필요한 내용들을 엮을 때 사용하자. 

