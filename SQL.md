# SQL Notes

## 시작 전에
- `PLAN.md` 기준 날짜는 `2026-03-09`지만, 실제 오늘은 `2026-03-10`이다.
- 지금 목표는 SQL을 깊게 파는 것보다 `코딩테스트에서 자주 나오는 문법을 다시 손에 익히는 것`이다.
- 처음부터 어려운 문제로 가지 말고 `문법 1개 + 쉬운 문제 2~3개` 식으로 묶어서 반복하는 편이 효율적이다.

## 어떻게 공부하면 좋은가
### 1. 순서를 고정한다
아래 순서로 익히면 된다.

1. `SELECT`, `FROM`
2. `WHERE`
3. `ORDER BY`
4. `LIMIT`
5. 집계 함수: `COUNT`, `SUM`, `AVG`, `MIN`, `MAX`
6. `GROUP BY`
7. `HAVING`
8. `JOIN`
9. `CASE WHEN`
10. `NULL 처리`
11. 문자열 함수, 날짜 함수
12. 서브쿼리

### 2. 문법을 본 뒤 바로 문제를 푼다
- 문법만 읽으면 금방 잊는다.
- 개념 10~15분 보고 바로 쉬운 문제 2~3개를 풀어야 기억에 남는다.
- 지금 단계에서는 `한 문법을 보고 예제 1개를 직접 타이핑`하는 것도 좋다.

### 3. 처음 1주는 속도보다 재현에 집중한다
- 문제를 보고
  - 어떤 테이블을 쓸지
  - 어떤 조건을 걸지
  - 묶어야 하는지
  - 조인이 필요한지
- 이 4가지를 먼저 말로 판단하는 습관을 들이면 좋다.

## 오늘 추천 루틴
오늘은 아래 정도가 적당하다.

1. 이 파일에서 `SELECT ~ LIMIT`까지 읽기
2. 쉬운 SQL 문제 2문제 풀기
3. `GROUP BY`, `HAVING`까지 읽기
4. 집계 문제 1~2문제 풀기
5. 틀린 문법 3줄로 다시 정리하기

## 기본 문법
예시 테이블:

### `users`
| id | name | age | city | score |
|---|---|---:|---|---:|
| 1 | Kim | 25 | Seoul | 80 |
| 2 | Lee | 30 | Busan | 95 |
| 3 | Park | 25 | Seoul | 70 |

### `orders`
| order_id | user_id | price | status | order_date |
|---|---:|---:|---|---|
| 101 | 1 | 12000 | DONE | 2026-03-01 |
| 102 | 1 | 8000 | DONE | 2026-03-02 |
| 103 | 2 | 15000 | CANCEL | 2026-03-03 |

## 1. SELECT, FROM
테이블에서 원하는 컬럼을 조회한다.

```sql
SELECT name, age
FROM users;
```

- `*` 는 모든 컬럼 조회다.
- 실전에서는 필요한 컬럼만 고르는 습관이 좋다.

```sql
SELECT *
FROM users;
```

## 2. WHERE
행을 필터링할 때 사용한다.

```sql
SELECT name, city
FROM users
WHERE age >= 25;
```

자주 쓰는 조건:

```sql
WHERE age >= 20
WHERE city = 'Seoul'
WHERE age BETWEEN 20 AND 29
WHERE city IN ('Seoul', 'Busan')
WHERE name LIKE 'K%'
WHERE score IS NULL
WHERE score IS NOT NULL
```

주의:
- `NULL` 비교는 `= NULL` 이 아니라 `IS NULL` 이다.
- 문자열은 보통 작은따옴표를 쓴다.

## 3. ORDER BY
정렬할 때 사용한다.

```sql
SELECT name, score
FROM users
ORDER BY score DESC, name ASC;
```

- `ASC`: 오름차순
- `DESC`: 내림차순
- 동점일 때 뒤에 적은 기준으로 추가 정렬한다.

## 4. LIMIT
상위 몇 개만 볼 때 사용한다.

```sql
SELECT name, score
FROM users
ORDER BY score DESC
LIMIT 2;
```

## 5. 집계 함수
여러 행을 요약한다.

```sql
SELECT COUNT(*) AS user_count
FROM users;
```

```sql
SELECT AVG(score) AS avg_score
FROM users;
```

자주 쓰는 함수:
- `COUNT(*)`: 행 개수
- `COUNT(column)`: `NULL` 이 아닌 값 개수
- `SUM(column)`: 합계
- `AVG(column)`: 평균
- `MIN(column)`: 최솟값
- `MAX(column)`: 최댓값

## 6. GROUP BY
같은 값끼리 묶어서 집계한다.

```sql
SELECT city, COUNT(*) AS cnt
FROM users
GROUP BY city;
```

도시별 평균 점수:

```sql
SELECT city, AVG(score) AS avg_score
FROM users
GROUP BY city;
```

주의:
- `GROUP BY`를 쓰면 `SELECT`에는 보통
  - 그룹 기준 컬럼
  - 집계 함수 결과
  만 넣는다.

## 7. HAVING
그룹 결과에 조건을 걸 때 사용한다.

```sql
SELECT city, COUNT(*) AS cnt
FROM users
GROUP BY city
HAVING COUNT(*) >= 2;
```

구분:
- `WHERE`: 그룹 만들기 전 필터
- `HAVING`: 그룹 만든 후 필터

## 8. JOIN
여러 테이블을 연결한다.

`users.id = orders.user_id` 로 연결 가능하다.

```sql
SELECT u.name, o.price
FROM users AS u
JOIN orders AS o
ON u.id = o.user_id;
```

완료 주문만 조회:

```sql
SELECT u.name, o.price
FROM users AS u
JOIN orders AS o
ON u.id = o.user_id
WHERE o.status = 'DONE';
```

주문 총액:

```sql
SELECT u.name, SUM(o.price) AS total_price
FROM users AS u
JOIN orders AS o
ON u.id = o.user_id
WHERE o.status = 'DONE'
GROUP BY u.id, u.name;
```

자주 쓰는 JOIN:
- `INNER JOIN`: 양쪽에 매칭되는 행만
- `LEFT JOIN`: 왼쪽 테이블 기준, 없는 값은 `NULL`

```sql
SELECT u.name, o.price
FROM users AS u
LEFT JOIN orders AS o
ON u.id = o.user_id;
```

## 9. CASE WHEN
조건에 따라 값을 나눌 때 사용한다.

```sql
SELECT name,
       CASE
           WHEN score >= 90 THEN 'A'
           WHEN score >= 80 THEN 'B'
           ELSE 'C'
       END AS grade
FROM users;
```

## 10. NULL 처리
`NULL`은 값이 없다는 뜻이다.

```sql
SELECT COUNT(score)
FROM users;
```

- 위 쿼리는 `score`가 `NULL`인 행은 세지 않는다.

자주 쓰는 처리:

```sql
SELECT IFNULL(score, 0) AS score
FROM users;
```

또는 환경에 따라:

```sql
SELECT COALESCE(score, 0) AS score
FROM users;
```

## 11. 문자열 함수
코테에서 자주 보이는 것만 먼저 익히면 된다.

```sql
SELECT UPPER(name)
FROM users;
```

```sql
SELECT LENGTH(name)
FROM users;
```

```sql
SELECT CONCAT(name, '_user')
FROM users;
```

자주 보는 함수:
- `UPPER`, `LOWER`
- `LENGTH`
- `CONCAT`
- `SUBSTRING`

## 12. 날짜 함수
날짜 문제도 자주 나온다.

```sql
SELECT YEAR(order_date) AS year
FROM orders;
```

```sql
SELECT MONTH(order_date) AS month
FROM orders;
```

```sql
SELECT DAY(order_date) AS day
FROM orders;
```

환경에 따라 함수 이름이 조금 다를 수 있다. 코테에서는 문제 예시 쿼리나 플랫폼 문법을 같이 확인하는 습관이 필요하다.

## 13. 서브쿼리
쿼리 안에 또 쿼리를 넣는 방식이다.

평균 점수보다 높은 사용자:

```sql
SELECT name, score
FROM users
WHERE score > (
    SELECT AVG(score)
    FROM users
);
```

처음에는 복잡하게 느껴져도, `안쪽 쿼리 결과를 바깥에서 사용한다` 정도로 이해하면 충분하다.

## 자주 틀리는 포인트
- `WHERE`와 `HAVING`를 헷갈리지 않기
- `NULL` 비교를 `= NULL`로 쓰지 않기
- `GROUP BY`를 쓸 때 집계하지 않은 컬럼을 함부로 `SELECT`하지 않기
- `JOIN`할 때 연결 조건 `ON`을 빠뜨리지 않기
- 정렬이 필요하면 `ORDER BY`를 마지막에 붙이는지 확인하기

## 코테 SQL에서 자주 나오는 유형
- 조건에 맞는 행 조회
- 최댓값, 최솟값, 평균, 개수 구하기
- 그룹별 집계
- 여러 테이블 조인
- 문자열 자르기
- 날짜 조건 필터링
- `NULL` 처리
- 등급 나누기 `CASE WHEN`

## 첫 주 권장 학습 순서
### Day 1
- `SELECT`, `WHERE`, `ORDER BY`, `LIMIT`

### Day 2
- 집계 함수, `GROUP BY`, `HAVING`

### Day 3
- `JOIN`

### Day 4
- `CASE WHEN`, `NULL 처리`

### Day 5
- 문자열 함수, 날짜 함수

### Day 6
- 서브쿼리

### Day 7
- 틀린 문제만 다시 풀기

## 마지막 팁
- SQL은 `영어 문장 해석`처럼 읽는 습관이 중요하다.
- 문제를 보면 바로 쿼리를 쓰기보다
  - 어떤 테이블에서
  - 어떤 조건으로
  - 어떻게 묶고
  - 어떤 값을 출력할지
  이 순서로 먼저 생각하면 훨씬 안정적이다.
- 지금은 모든 문법을 외우려 하지 말고, `자주 나오는 문법을 보고 바로 쓸 수 있는 상태`를 목표로 잡으면 된다.
