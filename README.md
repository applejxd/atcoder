# atcoder

## 環境構築

1. Anaconda インストール
2. 専用スクリプトでヘルパーツール導入

```bash
source ./activate.sh
```

ヘルパーの使い方

```bash
# 通常評価
ojt $URL ./main.cpp
# double 出力評価
ojt $URL ./main.cpp -e 1e-6
# 提出
oj s $URL ./main.cpp
```

## 参考文献

- [online-judge-tools/oj](https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md)
- [online-judge-tools/template-generator](https://github.com/online-judge-tools/template-generator/blob/master/README.ja.md)
