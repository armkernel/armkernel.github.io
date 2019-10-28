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

