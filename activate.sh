#!/bin/bash

if ! type "conda" >/dev/null 2>&1; then
  echo "conda is not exist."
  exit 1
fi

if ! grep -q "atcoder" <(conda env list); then
  conda env create --file environments.yml
fi

if [[ ! -e /usr/bin/chromedriver ]]; then
  sudo apt-get install -y chromium-chromedriver
fi

conda activate atcoder
oj login https://atcoder.jp/

# cf. https://github.com/online-judge-tools/oj/blob/master/docs/getting-started.ja.md
function ojt() {
  name=$1
  url=$2

  oj download "$url"
  fname=$(echo "$name" | awk -F/ '{print $NF}' | awk -F. '{print $1}')
  g++ -std=gnu++17 -Wall -Wextra -O2 "$name" -o "$fname"
  oj test -N -c ./"$fname"

  rm -f "$fname"
  rm -rf test
}
