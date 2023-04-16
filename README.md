# atcoder

## 環境構築

### VSCode devcontainer を使う場合

[Docker for Windows/Mac と Docker Engine (Ubuntu) で owner の扱いが異なる。](https://qiita.com/yohm/items/047b2e68d008ebb0f001)
Docker for Windows/Mac は自動的にホストのユーザとコンテナの root を切り替えるが、
[Docker Engine (Ubuntu) は手動でホストのユーザ設定を作成・マウントする必要がある。](http://wiki.ros.org/docker/Tutorials/GUI#login_as_yourself)

そのため Ubuntu で使用する場合は .devcontainer の内容を書き換えて使用。
.devcontainer/devcontainer.json の　dockerComposeFile を compose-ubuntu.yml に変更。

### ローカル環境を使う場合

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

- [AtCoder Clans](https://kato-hiro.github.io/AtCoderClans/)
- [AtCoder Problems](https://kenkoooo.com/atcoder/#/table/)
- [online-judge-tools/oj](https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md)
- [online-judge-tools/template-generator](https://github.com/online-judge-tools/template-generator/blob/master/README.ja.md)
- [技プログラミングのソース置場](https://oraclesqlpuzzle.ninja-web.net/kyoupro/index.html)
