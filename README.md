# archive-c-toolkit

2021–2022년에 만든 **C 라이브러리 · 자료구조 · 런타임** 습작 모음입니다.
가비지 컬렉터, 문자열 라이브러리, 동적 메모리 매니저를 직접 구현해보던 시기의 기록입니다.

## 구성

| 디렉터리 | 내용 | 커밋 | 기간 |
|---|---|---:|---|
| [`nugunga-utility/`](nugunga-utility) | 종합 유틸리티 — String / GC / Operator | 13 | 2021.11–2026.08 |
| [`garbage-collection/`](garbage-collection) | 가비지 컬렉터 구현 및 테스트 | 18 | 2021.11 |
| [`nugunga-module/`](nugunga-module) | 모듈 시스템 — List / GC 분리 | 7 | 2021.12–2026.08 |
| [`program-manager/`](program-manager) | 프로그램 라이프사이클 매니저 | 16 | 2021.12 |
| [`delegate-test/`](delegate-test) | C에서 델리게이트(함수 포인터 테이블) 구현 | 4 | 2021.12 |
| [`nlb-utility/`](nlb-utility) | NLB 유틸리티 | 10 | 2021.11 |
| [`dm-memory/`](dm-memory) | 페이지 기반 동적 메모리 매니저 | 1 | 2021.08 |
| [`string-lib/`](string-lib) | 문자열 라이브러리 (String / StringAry) | 1 | 2021.09 |
| [`make-c-sources/`](make-c-sources) | C 소스 자동 생성기 | 1 | 2022.05 |
| [`nobject/`](nobject) | C++ 오브젝트 시스템 실험 | 1 | 2022.06 |
| [`c-user-library/`](c-user-library) | C 유저 라이브러리 — Stack / Network | 1 | 2021.03 |
| [`thread-server/`](thread-server) | pthread 서버 습작 | 1 | 2022.06 |
| [`thread-client/`](thread-client) | pthread 클라이언트 습작 | 1 | 2022.06 |
| [`network-test/`](network-test) | 소켓 통신 테스트 (C++) | 1 | 2022.07 |
| [`linux-develop-test/`](linux-develop-test) | Visual Studio 리눅스 원격 빌드 테스트 | 1 | 2022.08 |
| [`ngc/`](ngc) | 가비지 컬렉터 실험 | 1 | 2021.10 |
| [`gc-rebuild/`](gc-rebuild) | 가비지 컬렉터 재작성 | 1 | 2021.10 |
| [`tuple/`](tuple) | C 튜플 구현 | 1 | 2021.10 |
| [`quantum-compiler-standalone/`](quantum-compiler-standalone) | Quantum 컴파일러 분리본 | 1 | 2022.01 |

## 히스토리 보존 방식

각 프로젝트는 원본 저장소의 커밋 히스토리를 그대로 유지한 채 `git subtree` 방식으로 편입했습니다.
원본의 모든 브랜치 끝점은 `legacy/<프로젝트>/<브랜치>` 태그로 남아 있습니다.

```bash
git tag -l 'legacy/*'              # 보존된 원본 브랜치 목록
git log --follow -- <디렉터리>/     # 특정 프로젝트의 원본 히스토리 추적
```

보존된 태그 14개:

```
  legacy/delegate-test/main
  legacy/delegate-test/tag/snapshot/laptop/main
  legacy/garbage-collection/main
  legacy/garbage-collection/tag/snapshot/laptop/main
  legacy/nlb-utility/main
  legacy/nugunga-module/main
  legacy/nugunga-module/snapshot/laptop
  legacy/nugunga-module/tag/snapshot/laptop/main
  legacy/nugunga-module/wip/archive-import
  legacy/nugunga-utility/main
  legacy/nugunga-utility/snapshot/laptop
  legacy/nugunga-utility/tag/snapshot/laptop/main
  legacy/nugunga-utility/wip/archive-import
  legacy/program-manager/main
```

---

*이 저장소는 아카이브입니다. 유지보수하지 않습니다.*
