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
# 問題 DL
ojd $URL
# テストケース生成 (ojd の後)
ojg
# 評価
ojt ./main.cpp
# double 出力評価
ojt ./main.cpp -e 1e-9
# 提出
oj s ./main.cpp
# テスト情報・バイナリ削除
ojc
```

## テンプレート生成機能について

- [online-judge-tools/template-generator](https://github.com/online-judge-tools/template-generator/blob/master/README.ja.md)
- テンプレートの文法は [Mako](https://www.makotemplates.org/)
  - import 文には `<%! hoge %>`
  - プログラム実行には `<% hoge %>`
  - [簡単な説明](https://lab.hde.co.jp/2009/01/pythonmako.html)

## 参考文献

- [AtCoder Clans](https://kato-hiro.github.io/AtCoderClans/)
- [AtCoder Problems](https://kenkoooo.com/atcoder/#/table/)
- [online-judge-tools/oj](https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md)

- [技プログラミングのソース置場](https://oraclesqlpuzzle.ninja-web.net/kyoupro/index.html)
- [競プロ C++ イディオム FAQ](https://rsk0315.hatenablog.com/entry/2020/05/09/170315#stdcintienullptr)

- [C++で問題を解くときにおすすめのコンパイルオプション](https://triple-four.hatenablog.com/entry/20210623/1624458051)
- [競技プログラミングにおける個人的 C++ コーディングスタイル (2020)](https://kmyk.github.io/blog/blog/2020/10/25/coding-style-for-competitive-programming/)