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
