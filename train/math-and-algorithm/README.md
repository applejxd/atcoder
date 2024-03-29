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
  - 027_Sorting: 分割統治法でマージソート. ソート済みの配列2つをマージして統合. 各ソート済み配列の先頭のうち小さい方を取り出していく.
- 動的計画法
  - 028_Frog_1: i-番目の足場まで行く最小コストのリストを作成して逐次計算
  - 029_Climb_Stairs: 上記と同様. ただし N=1,2 の場合に注意.
  - 030_Knapsack_1: 行列が(品物数,容量)で値が価値のデータを作成. 品物をつかする重さの合計がW以下とそれより大きいケースで場合分け.
  - 031_Taros_Vacation: 実力の1次元配列を作成すればいい
- 二分探索
  - 032_Binary_Search: 二分探索~二分法

### 4章

- 計算幾何
  - 033_Distance: 2点を通る線ではなく線分との距離であることに注意. 垂線が線分と交わらない場合は端点との距離が求める値となる.
  - 034_Nearest_Points: 高々 N~2e+3 なので総当たりでもOK. 高速に計算するときは kd-tree を自前実装するか, boost の r-tree を利用.
  - 035_Two_Circles: 中心の距離と半径を比較して包含関係を計算
  - 036_Colon: 角速度から丁寧に極座標を計算して距離を取る
  - 037_Intersection: 閉区間の判定にccw関数を利用。詳細は以下
    - [線分が開区間の場合](http://www5d.biglobe.ne.jp/~tomoya03/shtml/algorithm/Intersection.htm):片方の線分を直線にして線分の端点が直線を挟んで別サイド同士になっているか判定. 線分と直線を逆にして同様に判定してANDをとる.
    - [線分が閉区間の場合](https://hcpc-hokudai.github.io/archive/geometry_004.pdf):ccw(counter clockwise)関数を利用. 線分の端点が直線上に存在する場合もきちんと判定.
- 階差と累積和
  - 038_How_Many_Guests: 累積和でデータを保持し差分を計算
  - 039_Snowy_Days: 隣接マスとの差を出力するため、マスの値ではなく隣接マスとの差のみを保存
  - 040_Travel: 駅の間の移動距離は各駅の距離の和なので累積和を計算してキャッシュ. キャッシュを活用して計算回数を省略.
  - 041_Convenience_Store_2: 入力データは階差の形式の保存が適している. 出力は累積和になるので階差から計算.
- エラトステネスの篩
  - 042_Sum_of_Divisors: 問題を読み替え. Nまでの1の倍数・2の倍数・3の倍数・…・Nの倍数の和を計算すると解釈して計算.
- グラフを使ったアルゴリズム
  - 043_Depth_First_Search: 深さ優先探索で連結成分に訪問フラグを立てていく. すべて訪問済になればグラフ全体が連結. 深さ優先探索は stack を使用して実装可能.
  - 044_Shortest_Path_1: 幅優先探索で連結成分に距離を書き込んでいく. 幅優先探索は queue を使用して実装可能.
  - 045_Easy_Graph_Problem: 隣接リストを作成して順次ノード毎に条件をチェック
  - 046_BFS: 名前の通り幅優先探索. 迷路を隣接リストに変換するには1つ小さい行・列が壁かどうか逐次判定. グラフは2次元グリッドを直列化して保存.