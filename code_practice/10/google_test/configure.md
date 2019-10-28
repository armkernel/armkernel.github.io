$ wget https://github.com/google/googletest/archive/release-1.10.0.tar.gz
$ tar xvf release-1.10.0.tar.gz
$ mv google-test-release-1.10.0 googletest
$ rm google-test-release-1.10.0
$ cd googletest/googletest


동적라이브러리 => 라이브러리를 갱신한 후 빌드할 필요 없다.
               => 배포 단점

정적라이브러리 => 배포 장점

* 주의할점
- Google test library는 '정적 라이브러리'로 만드는 것을 권장한다.

$ g++ ./googletest/googletest/src/gtest-all.cc -c -I googletest/googletest/include/ -I googletest/googletest/ -std=c++1z

$ ar rcv libgtest.a gtest-all.o
// 정적라이브러리가 만들어졌다.

$ g++ 1\_시작.cpp -std=c++1z -Igoogletest/googletest/include -lgtest -L . -pthread

--- 

더편하게 할 수 있는 방법이 있음
googletest를 계속 가지고 가야한다.
디렉토리를 계속 잡아야하는 번거로움
다른 임베디드 환경에서 사용하고 싶다면, 통채로 옮겨야한다.


fuse라는 python script를 이용해서 최소한의 코드를 가져올 수 있도록 해준다. 
최소한의 코드와 library를 가지고 수행하면 됨.

테스트 라이브러리를 포함시키는것이 정석..
스크립트를 제공해준다.

$ g++ -c gtest/gtest-all.cc -I. -std=c++1z
$ ar rcv libgtest.a gtest-all.o
$ g++ 1\_시작.cpp -I. -lgtest -L. -pthread -std=c++1z
