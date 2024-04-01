# 컴퓨터그래픽스및영상처리 과제 1

- 본 과제의 개발 환경으로는 vscode와 cmake를 사용하였습니다.
- 초기 환경 설정 및 openGL을 다루는 데에 필요한 스킬은 링크를 따라가면 확인하실 수 있는 [유튜브 영상 재생목록](https://www.youtube.com/playlist?list=PLvNHCGtd4kh_cYLKMP_E-jwF3YKpDP4hf)을 참고하여 공부하였습니다.
- 이 외에도 [LearnOpenGL.com](https://learnopengl.com) 및 [Ray Tracing in One Weekend](https://raytracing.github.io/books/RayTracingInOneWeekend.html)를 참고하여 진행하였습니다.

---
### 환경 설정

- vscode version 1.87을 사용하였습니다.
- cmake는 최소한 version 3.14를 사용해야 합니다.
- 본 repository에 있는 CMakeLists.txt와 Dependency.cmake 파일을 통해 필요한 library를 초기 빌드 시 한 번에 다운로드 받을 수 있습니다.

---

### 실행 방법

1. vscode를 실행 후, 해당 project가 있는 directory를 열어 project folder를 load해줍니다.
2. CMake를 위한 vscode extension이 필요하므로, extension이 존재하지 않는다면 vscode 좌측의 Extensions 탭에서 cmake를 검색하여 CMake와 CMake Tools를 install 해줍니다.
3. Windows 환경에서는 ctrl + shift + p, Mac 환경에서는 cmd + p 키를 입력하여 command를 입력할 수 있는 창에서 cmake를 검색 후 CMake:Configure를 선택하고, 운영체제에 맞게 컴파일러 키트를 선택합니다.
(혹은 해당 프로젝트가 있는 폴더에서 cmd 창을 열고 code .를 입력하면 자동으로 CMake project임을 인식하고 configure를 위한 팝업이 뜹니다.)
Configure를 수행하면 vscode 하단의 OUTPUT 탭에 "Configuring project: CGIP_hw1"이라고 출력되는 것을 확인하실 수 있습니다.
4. CMake 프로젝트로 인식이 되었으면, 다시 command를 입력할 수 있는 창을 열고 CMake를 검색하여 CMake:Build를 선택합니다 (혹은 단축키인 F7을 입력합니다).
초기 build라면, 이때 필요한 library가 전부 build 폴더에 다운로드 됩니다.
5. 초기 build를 마친 후, ctrl + F5를 입력하면 Debug 모드로 project가 실행됩니다.
Debug 모드이므로 하단의 DEBUG CONSOLE에서 출력 및 동작을 확인할 수 있습니다.

---

### 결과 화면



---