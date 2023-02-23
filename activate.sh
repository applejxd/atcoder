#!/bin/bash

# Anaconda のチェック
if ! type "conda" >/dev/null 2>&1; then
  echo "conda is not exist."
  exit 1
fi

# 依存ライブラリインストール
if ! grep -q "atcoder" <(conda env list); then
  conda env create --file environments.yml
fi

# Selenium 用ドライバインストール
if ! type "chromedriver" >/dev/null 2>&1; then
  if [[ -e /etc/lsb-release ]]; then
    sudo apt-get install -y chromium-chromedriver
  fi
  if [[ "$OSTYPE" == "darwin"* ]]; then
    # 別途実行許可を出す必要がある
    # cf. https://qiita.com/apukasukabian/items/77832dd42e85ab7aa568
    brew install chromedriver
  fi
fi

if ! type "gtime" >/dev/null 2>&1; then
  if [[ "$OSTYPE" == "darwin"* ]]; then
    brew install gnu-time
  fi
fi

# 仮想環境有効化
conda activate atcoder
# サイトログイン
oj login https://atcoder.jp/

if [[ -f /proc/sys/fs/binfmt_misc/WSLInterop ]]; then
  # WSL でブラウザを開く際のバグフィックス
  # cf. https://qiita.com/iwaiktos/items/33ab69a42c3a1cc35dfb#3init-4010-error-utilconnecttointeropserver300-connect-failed-2
  for i in $(pstree -np -s $$ | grep -o -E '[0-9]+'); do
    if [[ -e "/run/WSL/${i}_interop" ]]; then
      export WSL_INTEROP=/run/WSL/${i}_interop
    fi
  done
fi

# コンパイル・チェック自動化. 追加引数使用可能.
# ojt -> oj s で提出可能
# cf. https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
function ojt() {
  url=$1
  name=$2

  oj download "$url"
  fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o "$fname"
  shift 2
  oj test -c ./"$fname" "$@"

  rm -f "$fname"
  rm -rf test
}
