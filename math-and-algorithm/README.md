# アルゴリズムと数学

- [問題ページ](https://atcoder.jp/contests/math-and-algorithm)
- [得点状況](https://atcoder.jp/contests/math-and-algorithm/score)

## コメント

### 2章

- 基本計算
  - 001_Print_5+N: 入出力の練習
  - 002_Sum_of_3_Integer: 入出力の練習
  - 003_Sum_of_N_Integers: [入出力とループの練習](https://wakabame.hatenablog.com/entry/2019/02/24/141009)
  - 004_Product_of_3_Integers: 002 同様
  - 005_Modulo_100: 003 と余り演算%
  - 006_Print_2N+3: 001 と同様
- 総当り
  - 007_Number_of_Multiples_1: 総当りでカウント. 最大で 1e+6 パターン.
  - 008_Brute_Force_1: 総当たりでカウント. 最大で 1000x1000 パターン.
  - 009_Brute_Force_2
  - 総当りだと最大で 2^60~1e+18 パターン. 到底終わらない.
  - 動的計画法で回答. 漸化式・ダイクストラ法的に重複計算を避ける.
- 基本計算
  - 010_Factorial: オーバーフローに注意(long long 型を使う)
- 素因数
  - 011_Print_Prime_Numbers: エラトステネスの篩. それ以外でも N<=3000 なので計算量は問題ない.

### 3章

- 素因数
  - 012_Primality_Test: sqrt(N)まで割っていくだけ. 桁が多いので注意
  - 013_Divisor_Enumeration: N=i*(N/i)の分解でsqrt(N)まで探索
  - 014_Factorization: オーバーフローに注意. 全て long long を使用. 篩は sqrt(N) までで十分
  - 015_Calculate GCD: ユークリッドの互除法. 最大公約数が変化しない余り計算で逐次判定対象を小さくしていく.
  - 016_Greatest_Common_Divisor_of_N_Integers: N 個の数字から2個1組ペアを作成して順次判定
  - 017_Least_Common_Multiple_of_N_Integers: `lcm(a,b)*gcm(a,b)=a*b` を利用. この公式は素因数の指数について`max(a,b)+min(a,b)=a+b`をしているのと同じ.
- 組み合わせ
  - 018_Convenience_Store_1: 総当りせずに可能な組み合わせだけカウント. 買う数が2で固定なので500=100+400=200+300のパターンのみ.
  - 019_Choose_Cards_1: nC2 の計算
  - 020_Choose_Cards_2: 100C2 ~ 1e+8 で全探索でも OK. ただし `i<j<k<l<m` で探索.
  - 021_Combination_Easy: 分子・分母毎に計算
  - 022_Choose_Cards_3: 総当りだと(1e+5)^2なのでNG. 各数字が何回出たかカウントする. 1~50000 に対して対応する 50001~99999 がいくつあるか計算.
- 確率
  - 023_Dice_Expectation: 期待値の線形性を利用. iostream の setprecision を忘れずに.
  - 024_Answer_Exam_Randomly: 上記と同じ
  - 025_Jiro's_Vacation: 上記と同じ
  - 026_Coin_Gacha: 問題を「新しいコインを手に入れるまでに使う金額の期待値」の総乗で読み替え。
    1. 既に k 種のコインを引いた状況を考える. 次に新しい種類のコインを手に入れる確率は `(N-k)/N`、外す確率は `k/N`.
    2. 新しいコインを手に入れる期待値は`(1+k/N*2+(k/N)^2*3...)*(N-k)/N=N/(N-k)`. 証明には無限等比級数の公式を使う.
    3. これらを足し合わせる
- ソート
  - 027_Sorting: マージソート. ソート済みの配列2つをマージして統合.
- 動的計画法
  - 028_Frog_1: i-番目の足場まで行く最小コストのリストを作成して逐次計算
  - 029_Climb_Stairs: 上記と同様. ただし N=1,2 の場合に注意.
  - 030_Knapsack_1: 行列が(品物数,容量)で値が価値のデータを作成. 品物をつかする重さの合計がW以下とそれより大きいケースで場合分け.
  - 031_Taros_Vacation: 実力の1次元配列を作成すればいい
- 二分探索
  - 032_Binary_Search: 二分探索~二分法

### Tips

- 整数型の範囲
  - -1e+9.3 <~ int <~ 1e+9.3
  - -1e+18.9 <~ long long <~ 1e+18.9
  - long 型は 32bit/64bit で int/long と同じ長さになるので注意(環境依存)
- 計算量は 1e+9/s が目安
