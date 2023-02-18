# アルゴリズムと数学

- [問題ページ](https://atcoder.jp/contests/math-and-algorithm)
- [得点状況](https://atcoder.jp/contests/math-and-algorithm/score)

## コメント

- 001_Print_5+N: 入出力の練習
- 002_Sum_of_3_Integer: 入出力の練習
- 003_Sum_of_N_Integers: [入出力とループの練習](https://wakabame.hatenablog.com/entry/2019/02/24/141009)
- 004_Product_of_3_Integers: 002 同様
- 005_Modulo_100: 003 と余り演算%
- 006_Print_2N+3: 001 と同様
- 007_Number_of_Multiples_1: 総当りでカウント. 最大で 1e+6 パターン.
- 008_Brute_Force_1: 総当たりでカウント. 最大で 1000x1000 パターン.
- 009_Brute_Force_2
  - 総当りだと最大で 2^60~1e+18 パターン. 到底終わらない.
  - 動的計画法で回答. 漸化式・ダイクストラ法的に重複計算を避ける.
- 010_Factorial: オーバーフローに注意(long long 型を使う)
- 011_Print_Prime_Numbers: エラトステネスの篩. それ以外でも N<=3000 なので計算量は問題ない.
- 012_Primality_Test: sqrt(N)まで割っていくだけ. 桁が多いので注意
- 013_Divisor_Enumeration: N=i*(N/i)の分解でsqrt(N)まで探索
- 014 - Factorization

### Tips

- 整数型の範囲
  - -1e+9.3 <~ int <~ 1e+9.3
  - -1e+18.9 <~ long long <~ 1e+18.9
  - long 型は 32bit/64bit で int/long と同じ長さになるので注意(環境依存)
