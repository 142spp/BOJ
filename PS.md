# PS Notes

SQL


---

Algorithm

ios::sync_with_stdio(false);
cin.tie(NULL);
위 두줄은 입출력 시간을 단축시켜주는 효과가 있음.
보충: `cin.tie(NULL)` 대신 `cin.tie(nullptr)`를 더 자주 씀.
보충: 빠른 입출력 설정 시 `printf/scanf`와 섞어 쓰지 않는 편이 안전함.

stl의 자료구조들

array<{type},{size}>
- 정적인 배열을 만들때 씀. 사실상 {type} A[{size}]와 다름없지만, stl에서 약간 더 기능을 제공함
보충: `size()` 사용 가능, 복사/대입이 편하고 range-for와 잘 맞음.
보충: 성능은 C 배열과 거의 동일함.

vector<{type}>
- 힙에 자료를 올려서 좀 더 관리하기 편하게 함. 배열의 크기가 동적으로 바뀌며 인덱스 접근이 쉬움. push_back 명령어로 배열의 마지막에 원소를 넣는건 O(1)이 걸림. 하지만 배열의 앞이나 중간에 삽입하려고 하면 O(N)이 소모됨. 
보충: `push_back`은 평균 O(1)이고, 재할당이 일어나는 순간만 O(N)임.
보충: 인덱스 접근은 O(1), 연속 메모리라 캐시 친화적이라 PS에서 기본 선택지.

queue<{type}>
- FIFO 원칙을 지키는 자료구조. 먼저 들어간 원소가 먼저 나옴. BFS할때 필수인 자료구조인데, 구현 메커니즘은 잘 모르겠음. 동적 배열에다가 인덱스 하나씩 옮기는거랑 뭔차이?
보충: `queue`는 컨테이너 어댑터라 내부 구현을 감추고 `push/pop/front/back`만 제공함.
보충: 보통 내부 컨테이너로 `deque`를 써서 앞 pop이 O(1)로 안정적임.

stack{type}>
- FILO 원칙을 지키는 자료구조. 사실 이거쓸바에 vector나 deque 쓰는데, 그냥 상징성을지닌 자료구조라 생각함. dfs를 구현할때 필요하긴 한데, 함수를 recursive 하게 짜면 그자체가 스택이라서 음... 함수 없이 짤때 쓸듯.
보충: `stack`도 어댑터라 `top/push/pop`만 허용되어 의도가 명확해짐.
보충: iterative DFS, 괄호 검사, 단조 스택 문제에서 자주 사용.

deque<{type}>
- 양방향으로 원소를 꺼내는게 가능한 자료구조. stack과 queue를 합친 형태라 생각하면 됨. stack은 단순히 deque에서 pop_front 기능만 뺀것. 양쪽에서 원소를 뺄 수 있고 인덱스 접근도 가능. O(1)인데 메모리 효율성이 vector에 비해서는 딸려서 접근이 약간 느림. insert/erase도 마찬가지로 O(N)이 걸림. 동적배열이 필요하면 vector를 쓰도록 하자. deque는 그냥 양방향 큐로 생각하는게 좋아.
보충: 앞/뒤 삽입 삭제는 O(1), 인덱스 접근도 O(1)임.
보충: 중간 삽입/삭제만 O(N)이라, 양 끝 연산 많은 문제에 특히 유리함.

priority_queue<{type},vector<{type}>,compare<{type}>>
- 우선순위 큐로, 힙 자료구조를 써서 원소를 삽입할때마다 O(logN)의 연산이 걸림. 맨위에 있는 최대/최소 값만 보장되므로, 중간에 있는 원소를 확인불가함. 인덱스 접근 불가. 그저 맨위의 값만 볼 수 있는 용도. 
보충: 기본은 최대 힙, 최소 힙은 `priority_queue<int, vector<int>, greater<int>>` 형태로 사용.
보충: `top`은 O(1), `push/pop`은 O(logN).

set<{type}>
- 레드-블랙-트리로 구성된 stl 자료구조. 
보충: 정렬 상태 유지, `insert/find/erase`가 O(logN), `lower_bound` 가능.

map<{type}>
보충: key 기준 정렬 유지, `insert/find/erase` O(logN).
보충: 최악 복잡도가 안정적이라 성능 예측이 쉬움.

unordered_set<{type}>
보충: 해시 기반, 평균 O(1), 최악 O(N), 순서 없음.
보충: 존재 여부 체크가 핵심이면 set보다 유리한 경우가 많음.

unordered_map<{type}>
보충: 해시 기반 key-value, 평균 O(1), 최악 O(N).
보충: 해시 충돌/리해시에 따라 체감 성능 변동 가능.

pair<{type},{type}>
보충: 두 값을 묶는 타입. 정렬 시 기본 비교는 `first` -> `second` 순.
보충: 3개 이상 묶을 때는 `tuple`이 더 적합함.
